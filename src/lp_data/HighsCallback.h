/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                       */
/*    This file is part of the HiGHS linear optimization suite           */
/*                                                                       */
/*    Written and engineered 2008-2023 by Julian Hall, Ivet Galabova,    */
/*    Leona Gottwald and Michael Feldmeier                               */
/*                                                                       */
/*    Available as open-source under the MIT License                     */
/*                                                                       */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**@file lp_data/HighsCallback.h
 * @brief
 */
#ifndef LP_DATA_HIGHSCALLBACK_H_
#define LP_DATA_HIGHSCALLBACK_H_

#include "lp_data/HStruct.h"

struct HighsCallbackDataOut {
  HighsLogType log_type;
  HighsInt simplex_iteration_count;
  HighsObjectiveSolution objective_solution;
  void clear();
};

struct HighsCallbackDataIn {
  bool user_interrupt;
  void clear();
};

struct HighsCallback {
  void (*highs_user_callback)(const int, const char*, void*,
			      const HighsCallbackDataOut&,
			      HighsCallbackDataIn&) = nullptr;
  void* highs_user_callback_data = nullptr;
  const int num_type = int(NewHighsCallbackType::kMipImprovingSolution) + 1;
  std::vector<bool> active;
  HighsCallbackDataOut highs_callback_data_out;
  HighsCallbackDataIn highs_callback_data_in;
  bool callbackAction(const NewHighsCallbackType type, std::string message = "");
  void clear();
};
#endif /* LP_DATA_HIGHSCALLBACK_H_ */
