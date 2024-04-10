#line 1 "codeforces-workspace\\contest\\739\\c\\c.cpp"
// #undef _GLIBCXX_DEBUG
// #define NDEBUG
#include <bits/extc++.h>

#line 2 "Library\\lib\\alias"

/**
 * @file alias
 * @brief Alias
 */

#line 10 "Library\\lib\\alias"

#line 2 "Library\\lib\\bit"

#if __cplusplus > 201703L

#include <bit>

#elif __cplusplus > 201402L

#ifndef _GLIBCXX_BIT
#define _GLIBCXX_BIT 1

#include <limits>
#include <type_traits>

namespace std {

template <typename _Tp> constexpr int __countl_zero(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u) {
    constexpr int __diff = _Nd_u - _Nd;
    return __builtin_clz(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul) {
    constexpr int __diff = _Nd_ul - _Nd;
    return __builtin_clzl(__x) - __diff;
  } else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull) {
    constexpr int __diff = _Nd_ull - _Nd;
    return __builtin_clzll(__x) - __diff;
  } else  // (_Nd > _Nd_ull)
  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    unsigned long long __high = __x >> _Nd_ull;
    if (__high != 0) {
      constexpr int __diff = (2 * _Nd_ull) - _Nd;
      return __builtin_clzll(__high) - __diff;
    }
    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    return (_Nd - _Nd_ull) + __builtin_clzll(__low);
  }
}

template <typename _Tp> constexpr int __countr_zero(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return _Nd;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u)
    return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul)
    return __builtin_ctzl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull)
    return __builtin_ctzll(__x);
  else  // (_Nd > _Nd_ull)
  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    if (__low != 0) return __builtin_ctzll(__low);
    unsigned long long __high = __x >> _Nd_ull;
    return __builtin_ctzll(__high) + _Nd_ull;
  }
}

template <typename _Tp> constexpr int __popcount(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;

  if (__x == 0) return 0;

  constexpr auto _Nd_ull = numeric_limits<unsigned long long>::digits;
  constexpr auto _Nd_ul = numeric_limits<unsigned long>::digits;
  constexpr auto _Nd_u = numeric_limits<unsigned>::digits;

  if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_u)
    return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ul)
    return __builtin_popcountl(__x);
  else if _GLIBCXX17_CONSTEXPR (_Nd <= _Nd_ull)
    return __builtin_popcountll(__x);
  else  // (_Nd > _Nd_ull)
  {
    static_assert(_Nd <= (2 * _Nd_ull),
                  "Maximum supported integer size is 128-bit");

    constexpr auto __max_ull = numeric_limits<unsigned long long>::max();
    unsigned long long __low = __x & __max_ull;
    unsigned long long __high = __x >> _Nd_ull;
    return __builtin_popcountll(__low) + __builtin_popcountll(__high);
  }
}

template <typename _Tp> constexpr _Tp __bit_ceil(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0 || __x == 1) return 1;
  auto __shift_exponent = _Nd - __countl_zero((_Tp)(__x - 1u));
#ifdef _GLIBCXX_HAVE_BUILTIN_IS_CONSTANT_EVALUATED
  if (!__builtin_is_constant_evaluated()) {
    __glibcxx_assert(__shift_exponent != numeric_limits<_Tp>::digits);
  }
#endif
  using __promoted_type = decltype(__x << 1);
  if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
    const int __extra_exp = sizeof(__promoted_type) / sizeof(_Tp) / 2;
    __shift_exponent |= (__shift_exponent & _Nd) << __extra_exp;
  }
  return (_Tp)1u << __shift_exponent;
}

template <typename _Tp> constexpr _Tp __bit_floor(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  if (__x == 0) return 0;
  return (_Tp)1u << (_Nd - __countl_zero((_Tp)(__x >> 1)));
}

template <typename _Tp> constexpr _Tp __bit_width(_Tp __x) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  return _Nd - __countl_zero(__x);
}

}  // namespace std

#endif

#endif
#line 2 "Library\\lib\\limits"

#line 4 "Library\\lib\\limits"

namespace workspace {

template <class _Tp> struct numeric_limits : std::numeric_limits<_Tp> {};

#ifdef __SIZEOF_INT128__

template <> struct numeric_limits<__uint128_t> {
  constexpr static __uint128_t max() { return ~__uint128_t(0); }
  constexpr static __uint128_t min() { return 0; }
};

template <> struct numeric_limits<__int128_t> {
  constexpr static __int128_t max() {
    return numeric_limits<__uint128_t>::max() >> 1;
  }
  constexpr static __int128_t min() { return -max() - 1; }
};

#endif

}  // namespace workspace
#line 13 "Library\\lib\\alias"

namespace workspace {

constexpr static char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using u32 = uint_least32_t;
using i64 = int_least64_t;
using u64 = uint_least64_t;

#ifdef __SIZEOF_INT128__
using i128 = __int128_t;
using u128 = __uint128_t;
#else
#warning 128-bit integer is not available.
#endif

template <class _T1, class _T2,
          typename = decltype(std::declval<const _T2 &>() <
                              std::declval<const _T1 &>())>
constexpr
    typename std::conditional<std::is_same<_T1, _T2>::value, const _T1 &,
                              typename std::common_type<_T1, _T2>::type>::type
    min(const _T1 &__x, const _T2 &__y) noexcept {
  return __y < __x ? __y : __x;
}

template <class _T1, class _T2, class _Compare,
          typename = decltype(std::declval<_Compare>()(
              std::declval<const _T2 &>(), std::declval<const _T1 &>()))>
constexpr
    typename std::conditional<std::is_same<_T1, _T2>::value, const _T1 &,
                              typename std::common_type<_T1, _T2>::type>::type
    min(const _T1 &__x, const _T2 &__y, _Compare __comp) noexcept {
  return __comp(__y, __x) ? __y : __x;
}

template <class _Tp, typename = decltype(std::declval<const _Tp &>() <
                                         std::declval<const _Tp &>())>
constexpr _Tp min(std::initializer_list<_Tp> __x) noexcept {
  return *std::min_element(__x.begin(), __x.end());
}

template <class _Tp, class _Compare,
          typename = decltype(std::declval<_Compare>()(
              std::declval<const _Tp &>(), std::declval<const _Tp &>()))>
constexpr _Tp min(std::initializer_list<_Tp> __x, _Compare __comp) noexcept {
  return *std::min_element(__x.begin(), __x.end(), __comp);
}

template <class _T1, class _T2,
          typename = decltype(std::declval<const _T1 &>() <
                              std::declval<const _T2 &>())>

constexpr
    typename std::conditional<std::is_same<_T1, _T2>::value, const _T1 &,
                              typename std::common_type<_T1, _T2>::type>::type
    max(const _T1 &__x, const _T2 &__y) noexcept {
  return __x < __y ? __y : __x;
}

template <class _T1, class _T2, class _Compare,
          typename = decltype(std::declval<_Compare>()(
              std::declval<const _T1 &>(), std::declval<const _T2 &>()))>
constexpr
    typename std::conditional<std::is_same<_T1, _T2>::value, const _T1 &,
                              typename std::common_type<_T1, _T2>::type>::type
    max(const _T1 &__x, const _T2 &__y, _Compare __comp) noexcept {
  return __comp(__x, __y) ? __y : __x;
}

template <class _Tp, typename = decltype(std::declval<const _Tp &>() <
                                         std::declval<const _Tp &>())>
constexpr _Tp max(std::initializer_list<_Tp> __x) noexcept {
  return *std::max_element(__x.begin(), __x.end());
}

template <class _Tp, class _Compare,
          typename = decltype(std::declval<_Compare>()(
              std::declval<const _Tp &>(), std::declval<const _Tp &>()))>
constexpr _Tp max(std::initializer_list<_Tp> __x, _Compare __comp) noexcept {
  return *std::max_element(__x.begin(), __x.end(), __comp);
}

#ifdef _GLIBCXX_BIT

template <typename _Tp> constexpr _Tp __bsf(_Tp __x) noexcept {
  return std::__countr_zero(__x);
}

template <typename _Tp> constexpr _Tp __bsr(_Tp __x) noexcept {
  return std::__bit_width(__x) - 1;
}

#endif

}  // namespace workspace
#line 2 "Library\\lib\\cxx20"

/*
 * @file cxx20
 * @brief C++20 Features
 */

#line 9 "Library\\lib\\cxx20"

#if __cplusplus <= 201703L

#include <algorithm>
#include <vector>

namespace std {

/**
 * @brief Erase the elements of a container that do not satisfy the condition.
 * @param __cont Container.
 * @param __pred Predicate.
 * @return Number of the erased elements.
 */
template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto __osz = __cont.size();
  __cont.erase(remove_if(__cont.begin(), __cont.end(), __pred), __cont.end());
  return __osz - __cont.size();
}

/**
 * @brief Erase the elements of a container that are equal to the given value.
 * @param __cont Container.
 * @param __value Value.
 * @return Number of the erased elements.
 */
template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto __osz = __cont.size();
  __cont.erase(remove(__cont.begin(), __cont.end(), __value), __cont.end());
  return __osz - __cont.size();
}

}  // namespace std

#endif
#line 1 "Library\\lib\\direct"
#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("unroll-loops")
#endif
#line 2 "Library\\lib\\opt"
// #include "src/opt/binary_search.hpp"
// #include "src/opt/trinary_search.hpp"
// #include "src/opt/exponential_search.hpp"
#line 2 "Library\\src\\opt\\golden_section.hpp"

/**
 * @file golden_section.hpp
 * @brief Golden Section
 */

#include <type_traits>

#line 2 "Library\\src\\algebra\\system\\operation.hpp"

/**
 * @file operation.hpp
 * @brief Operation Traits
 */

#line 9 "Library\\src\\algebra\\system\\operation.hpp"

#line 2 "Library\\lib\\cxx17"

#ifndef _CXX17_CONSTEXPR
#if __cplusplus >= 201703L
#define _CXX17_CONSTEXPR constexpr
#else
#define _CXX17_CONSTEXPR
#endif
#endif

#ifndef _CXX17_STATIC_ASSERT
#if __cplusplus >= 201703L
#define _CXX17_STATIC_ASSERT static_assert
#else
#define _CXX17_STATIC_ASSERT assert
#endif
#endif

#if __cplusplus < 201703L

namespace std {

/**
 *  @brief  Return the size of a container.
 *  @param  __cont  Container.
 */
template <typename _Container>
constexpr auto size(const _Container& __cont) noexcept(noexcept(__cont.size()))
    -> decltype(__cont.size()) {
  return __cont.size();
}

/**
 *  @brief  Return the size of an array.
 */
template <typename _Tp, size_t _Nm>
constexpr size_t size(const _Tp (&)[_Nm]) noexcept {
  return _Nm;
}

}  // namespace std

#endif
#line 11 "Library\\src\\algebra\\system\\operation.hpp"

namespace workspace {

// Unary `+`
template <class _Tp>
using require_unary_plus = std::enable_if_t<
    std::is_convertible<decltype(+std::declval<const _Tp &>()), _Tp>::value>;

template <class _Tp, class = void> struct has_unary_plus : std::false_type {};

template <class _Tp>
struct has_unary_plus<_Tp, require_unary_plus<_Tp>> : std::true_type {};

// Unary `-`
template <class _Tp>
using require_unary_minus = std::enable_if_t<
    std::is_convertible<decltype(-std::declval<const _Tp &>()), _Tp>::value>;

template <class _Tp, class = void> struct has_unary_minus : std::false_type {};

template <class _Tp>
struct has_unary_minus<_Tp, require_unary_minus<_Tp>> : std::true_type {};

// Binary `+`
template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_plus =
    std::enable_if_t<std::is_convertible<decltype(std::declval<const _Tp1 &>() +
                                                  std::declval<const _Tp2 &>()),
                                         _Tp1>::value>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_plus : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_plus<_Tp1, _Tp2, require_binary_plus<_Tp1, _Tp2>>
    : std::true_type {};

// Binary `-`
template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_minus =
    std::__void_t<decltype(std::declval<const _Tp1 &>() -
                           std::declval<const _Tp2 &>())>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_minus : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_minus<_Tp1, _Tp2, require_binary_minus<_Tp1, _Tp2>>
    : std::true_type {};

// Binary `*`
template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_multiplies =
    std::enable_if_t<std::is_convertible<decltype(std::declval<const _Tp1 &>() *
                                                  std::declval<const _Tp2 &>()),
                                         _Tp1>::value>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_multiplies : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_multiplies<_Tp1, _Tp2, require_binary_multiplies<_Tp1, _Tp2>>
    : std::true_type {};

// Binary `/`
template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_divides =
    std::enable_if_t<std::is_convertible<decltype(std::declval<const _Tp1 &>() /
                                                  std::declval<const _Tp2 &>()),
                                         _Tp1>::value>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_divides : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_divides<_Tp1, _Tp2, require_binary_divides<_Tp1, _Tp2>>
    : std::true_type {};

// Binary `%`
template <class _Tp1, class _Tp2 = _Tp1>
using require_binary_modulus =
    std::enable_if_t<std::is_convertible<decltype(std::declval<const _Tp1 &>() %
                                                  std::declval<const _Tp2 &>()),
                                         _Tp1>::value>;

template <class _Tp1, class _Tp2 = _Tp1, class = void>
struct has_binary_modulus : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_binary_modulus<_Tp1, _Tp2, require_binary_modulus<_Tp1, _Tp2>>
    : std::true_type {};

template <class _Tp1, class _Tp2 = _Tp1, class = void, class = void,
          class = void, class = void>
struct has_arithmetic : std::false_type {};

template <class _Tp1, class _Tp2>
struct has_arithmetic<_Tp1, _Tp2, require_binary_plus<_Tp1, _Tp2>,
                      require_binary_minus<_Tp1, _Tp2>,
                      require_binary_multiplies<_Tp1, _Tp2>,
                      require_binary_divides<_Tp1, _Tp2>> : std::true_type {};

template <class _Tp1, class _Tp2 = _Tp1>
using require_arithmetic = std::enable_if_t<has_arithmetic<_Tp1, _Tp2>::value>;

// Binary `<`
template <class _Tp, class = void> struct is_comparable : std::false_type {};

template <class _Tp>
struct is_comparable<_Tp, std::__void_t<decltype(std::declval<const _Tp &>() <
                                                 std::declval<const _Tp &>())>>
    : std::true_type {};

template <class _Tp, bool _Default = false> struct try_less : std::less<_Tp> {
  constexpr bool operator()(const _Tp &__x, const _Tp &__y) noexcept {
    if _CXX17_CONSTEXPR (is_comparable<_Tp>::value)
      return std::less<_Tp>::operator()(__x, __y);
    else
      return _Default;
  }
};

}  // namespace workspace
#line 11 "Library\\src\\opt\\golden_section.hpp"

namespace workspace {

/**
 * @brief Golden section search.
 */
template <class _Iterator, class _Function>
std::enable_if_t<has_binary_minus<_Iterator>::value, _Iterator> golden_section(
    _Iterator __first, _Iterator __last, _Function&& __f) {
  if (__last - __first < 2) return __first;

  decltype(__last - __first) __a{1}, __b{2};
  while (__a + __b <= __last - __first) std::swap(__a += __b, __b);

  auto __f1 = __f(__last - __b), __f2 = __f(__last - __a);

  while (__a != 1) {
    std::swap(__a, __b -= __a);

    if (__f2 < __f1)
      __f1 = __f2, __f2 = __f(__last - __a);

    else if ((__last -= __b) - __first < __b)
      std::swap(__a, __b -= __a), __f2 = __f(__last - __a);

    else
      __f2 = __f1, __f1 = __f(__last - __b);
  }

  return __f1 < __f2 ? __last - __b : __last - __a;
}

}  // namespace workspace
#line 2 "Library\\src\\opt\\bisection.hpp"

/**
 * @file bisection.hpp
 * @brief Bisection
 */

namespace workspace {

/**
 * @brief Bisection method.
 * @param __first
 * @param __last
 * @param __pred
 */
template <class _Iterator, class _Predicate>
_Iterator bisection(_Iterator __first, _Iterator __last, _Predicate &&__pred) {
  _Iterator __mid;
  for (decltype(__last - __first) __w = 0; __w < __last - __first;
       __w = __w << 1 | 1) {
    __mid = __first + __w;
    if (!__pred(__mid)) {
      __last = __mid;
      break;
    }
    __first = __mid;
  }
  while (1 < __last - __first) {
    __mid = __first + (__last - __first) / 2;
    (__pred(__mid) ? __first : __last) = __mid;
  }
  return __last;
}

/**
 * @brief Bisection method.
 * @param __first
 * @param __last
 * @param __pred
 * @param __eps
 */
template <class _Iterator, class _Predicate, class _Difference>
_Iterator bisection(_Iterator __first, _Iterator __last, _Predicate &&__pred,
                    _Difference __eps) {
  while (__eps < _Difference(__last - __first)) {
    _Iterator __mid = __first + (__last - __first) / 2;
    (__pred(__mid) ? __first : __last) = __mid;
  }
  return __last;
}

}  // namespace workspace
#line 2 "Library\\src\\sys\\call_once.hpp"

/**
 * @file call_once.hpp
 * @brief Call Once
 */

#line 9 "Library\\src\\sys\\call_once.hpp"

namespace workspace {

/**
 * @brief Call once.
 */
template <class _F> void call_once(_F &&__f) {
  static std::unordered_set<void *> __called;
  if (__called.count(std::addressof(__f))) return;
  __called.emplace(std::addressof(__f));
  __f();
}

}  // namespace workspace
#line 2 "Library\\src\\sys\\clock.hpp"

/**
 * @file clock.hpp
 * @brief Clock
 */

#line 9 "Library\\src\\sys\\clock.hpp"

namespace workspace {

using namespace std::chrono;

namespace internal {
// The start time of the program.
const auto start_time{system_clock::now()};
}  // namespace internal

/**
 * @return Elapsed time of the program.
 */
decltype(auto) elapsed() noexcept {
  const auto end_time{system_clock::now()};
  return duration_cast<milliseconds>(end_time - internal::start_time).count();
}

}  // namespace workspace
#line 2 "Library\\src\\sys\\ejection.hpp"

/**
 * @file ejection.hpp
 * @brief Ejection
 */

#line 9 "Library\\src\\sys\\ejection.hpp"

namespace workspace {

namespace internal {

struct ejection {
  bool exit = 0;
};

}  // namespace internal

/**
 * @brief eject from a try block, throw nullptr
 * @param arg output
 */
template <class Tp> void eject(Tp const &arg) {
  std::cout << arg << "\n";
  throw internal::ejection{};
}

void exit() { throw internal::ejection{true}; }

}  // namespace workspace
#line 2 "Library\\src\\sys\\iteration.hpp"

/**
 * @file iteration.hpp
 * @brief Case Iteration
 */

#line 9 "Library\\src\\sys\\iteration.hpp"

#line 11 "Library\\src\\sys\\iteration.hpp"

namespace workspace {

void main();

struct {
  // 1-indexed
  unsigned current{0};
  unsigned total{1};

  void read() { (std::cin >> total).ignore(); }

  int iterate() {
    static bool once = false;
    assert(!once);
    once = true;
    while (current++ < total) {
      try {
        main();
      } catch (internal::ejection const& status) {
        if (status.exit) break;
      }
    }
    return 0;
  }
} case_info;

}  // namespace workspace
#line 1 "Library\\lib\\utils"
// #include "src/utils/cached.hpp"
#line 2 "Library\\src\\utils\\cat.hpp"

/**
 * @file cat.hpp
 * @brief Cat
 */

#line 9 "Library\\src\\utils\\cat.hpp"

#line 11 "Library\\src\\utils\\cat.hpp"

namespace workspace {

/**
 * @brief Concatenate two sequences.
 *
 * @param __c1
 * @param __c2
 * @return Concatenated sequence.
 */
template <class _C1, class _C2>
constexpr decltype(auto) cat(_C1 &&__c1, _C2 &&__c2) noexcept {
  auto __c = std::forward<_C1>(__c1);

  if _CXX17_CONSTEXPR (std::is_rvalue_reference<decltype(__c2)>::value)
    __c.insert(std::end(__c), std::make_move_iterator(std::begin(__c2)),
               std::make_move_iterator(std::end(__c2)));
  else
    __c.insert(std::end(__c), std::cbegin(__c2), std::cend(__c2));

  return __c;
}

/**
 * @return Concatenated sequence.
 */
template <class _C1, class _C2, class... _Args>
constexpr decltype(auto) cat(_C1 &&__c1, _C2 &&__c2,
                             _Args &&...__args) noexcept {
  return cat(cat(std::forward<_C1>(__c1), std::forward<_C2>(__c2)),
             std::forward<_Args>(__args)...);
}

}  // namespace workspace
#line 2 "Library\\src\\utils\\chval.hpp"

/**
 * @file chval.hpp
 * @brief Change Less/Greater
 */

#line 9 "Library\\src\\utils\\chval.hpp"

namespace workspace {

/**
 * @brief Substitute __y for __x if __y < __x.
 * @param __x Reference
 * @param __y Comparison target
 * @return Whether or not __x is updated.
 */
template <class _T1, class _T2,
          typename = decltype(std::declval<_T2>() < std::declval<_T1 &>())>
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chle(
    _T1 &__x, _T2 &&__y) noexcept {
  return __y < __x ? __x = std::forward<_T2>(__y), true : false;
}

/**
 * @brief Substitute __y for __x if __x < __y.
 * @param __x Reference
 * @param __y Comparison target
 * @return Whether or not __x is updated.
 */
template <class _T1, class _T2,
          typename = decltype(std::declval<_T1 &>() < std::declval<_T2>())>
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chgr(
    _T1 &__x, _T2 &&__y) noexcept {
  return __x < __y ? __x = std::forward<_T2>(__y), true : false;
}

/**
 * @brief Substitute __y for __x if __comp(__y, __x) is true.
 * @param __x Reference
 * @param __y Comparison target
 * @param __comp Compare function object
 * @return Whether or not __x is updated.
 */
template <class _T1, class _T2, class _Compare,
          typename = decltype(std::declval<_Compare>()(std::declval<_T2>(),
                                                       std::declval<_T1 &>()))>
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chle(
    _T1 &__x, _T2 &&__y, _Compare __comp) noexcept {
  return __comp(__y, __x) ? __x = std::forward<_T2>(__y), true : false;
}

/**
 * @brief Substitute __y for __x if __comp(__x, __y) is true.
 * @param __x Reference
 * @param __y Comparison target
 * @param __comp Compare function object
 * @return Whether or not __x is updated.
 */
template <class _T1, class _T2, class _Compare,
          typename = decltype(std::declval<_Compare>()(std::declval<_T1 &>(),
                                                       std::declval<_T2>()))>
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chgr(
    _T1 &__x, _T2 &&__y, _Compare __comp) noexcept {
  return __comp(__x, __y) ? __x = std::forward<_T2>(__y), true : false;
}

}  // namespace workspace
#line 1 "Library\\src\\utils\\compare.hpp"
/**
 * @file compare.hpp
 * @brief Compare
 */

#line 2 "Library\\src\\utils\\sfinae.hpp"

/**
 * @file sfinae.hpp
 * @brief SFINAE
 */

#line 11 "Library\\src\\utils\\sfinae.hpp"

#ifndef __INT128_DEFINED__

#ifdef __SIZEOF_INT128__
#define __INT128_DEFINED__ 1
#else
#define __INT128_DEFINED__ 0
#endif

#endif

namespace std {

#if __INT128_DEFINED__

template <> struct make_signed<__uint128_t> { using type = __int128_t; };
template <> struct make_signed<__int128_t> { using type = __int128_t; };

template <> struct make_unsigned<__uint128_t> { using type = __uint128_t; };
template <> struct make_unsigned<__int128_t> { using type = __uint128_t; };

template <> struct is_signed<__uint128_t> : std::false_type {};
template <> struct is_signed<__int128_t> : std::true_type {};

template <> struct is_unsigned<__uint128_t> : std::true_type {};
template <> struct is_unsigned<__int128_t> : std::false_type {};

#endif

}  // namespace std

namespace workspace {

template <class Tp, class... Args> struct variadic_front { using type = Tp; };

template <class... Args> struct variadic_back;

template <class Tp> struct variadic_back<Tp> { using type = Tp; };

template <class Tp, class... Args> struct variadic_back<Tp, Args...> {
  using type = typename variadic_back<Args...>::type;
};

template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;

/**
 * @brief Return type of subscripting ( @c [] ) access.
 */
template <class _Tp>
using subscripted_type =
    typename std::decay<decltype(std::declval<_Tp&>()[0])>::type;

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class _Tp, class = std::nullptr_t>
struct has_begin : std::false_type {};

template <class _Tp>
struct has_begin<_Tp, decltype(std::begin(std::declval<_Tp>()), nullptr)>
    : std::true_type {};

template <class _Tp, class = void> struct has_mod : std::false_type {};

template <class _Tp>
struct has_mod<_Tp, std::__void_t<decltype(_Tp::mod)>> : std::true_type {};

template <class _Tp, class = void> struct is_integral_ext : std::false_type {};
template <class _Tp>
struct is_integral_ext<
    _Tp, typename std::enable_if<std::is_integral<_Tp>::value>::type>
    : std::true_type {};

#if __INT128_DEFINED__

template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};

#endif

#if __cplusplus >= 201402

template <class _Tp>
constexpr static bool is_integral_ext_v = is_integral_ext<_Tp>::value;

#endif

template <typename _Tp, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename _Tp>
struct multiplicable_uint<
    _Tp,
    typename std::enable_if<(2 < sizeof(_Tp)) &&
                            (!__INT128_DEFINED__ || sizeof(_Tp) <= 4)>::type> {
  using type = uint_least64_t;
};

#if __INT128_DEFINED__

template <typename _Tp>
struct multiplicable_uint<_Tp,
                          typename std::enable_if<(4 < sizeof(_Tp))>::type> {
  using type = __uint128_t;
};

#endif

template <typename _Tp> struct multiplicable_int {
  using type =
      typename std::make_signed<typename multiplicable_uint<_Tp>::type>::type;
};

template <typename _Tp> struct multiplicable {
  using type = std::conditional_t<
      is_integral_ext<_Tp>::value,
      std::conditional_t<std::is_signed<_Tp>::value,
                         typename multiplicable_int<_Tp>::type,
                         typename multiplicable_uint<_Tp>::type>,
      _Tp>;
};

template <class> struct first_arg { using type = void; };

template <class _R, class _Tp, class... _Args>
struct first_arg<_R(_Tp, _Args...)> {
  using type = _Tp;
};

template <class _R, class _Tp, class... _Args>
struct first_arg<_R (*)(_Tp, _Args...)> {
  using type = _Tp;
};

template <class _G, class _R, class _Tp, class... _Args>
struct first_arg<_R (_G::*)(_Tp, _Args...)> {
  using type = _Tp;
};

template <class _G, class _R, class _Tp, class... _Args>
struct first_arg<_R (_G::*)(_Tp, _Args...) const> {
  using type = _Tp;
};

template <class _Tp, class = void> struct parse_compare : first_arg<_Tp> {};

template <class _Tp>
struct parse_compare<_Tp, std::__void_t<decltype(&_Tp::operator())>>
    : first_arg<decltype(&_Tp::operator())> {};

}  // namespace workspace
#line 7 "Library\\src\\utils\\compare.hpp"

#if __cplusplus >= 201703L

namespace workspace {

/**
 * @brief Compare 2 points by their value of `atan2`.
 *
 * @return
 */
template <class _Tp>
bool compare_arg(const _Tp& __p1, const _Tp& __p2) noexcept {
  const auto& [__x1, __y1] = __p1;
  const auto& [__x2, __y2] = __p2;

  using value_type = std::decay_t<decltype(__x1)>;
  using mul_type = typename multiplicable<value_type>::type;

  if (__y1 == value_type(0))
    return value_type(0) <= __x1 &&
           (value_type(0) < __y2 ||
            (__y2 == value_type(0) && __x2 < value_type(0)));

  return value_type(0) < __y1
             ? value_type(0) <= __y2 &&
                   mul_type(__y1) * __x2 < mul_type(__x1) * __y2
             : value_type(0) <= __y2 ||
                   mul_type(__y1) * __x2 < mul_type(__x1) * __y2;
}

}  // namespace workspace

#endif
#line 2 "Library\\src\\utils\\fixed_point.hpp"

/**
 * @file fixed_point.hpp
 * @brief Fixed Point Combinator
 */

#line 9 "Library\\src\\utils\\fixed_point.hpp"

namespace workspace {

/**
 * @brief Fixed Point Combinator.
 */
template <class _F> class fixed_point {
  struct _wrapper {
    _F &__ref;

    template <class... _Args>
    decltype(auto) operator()(_Args &&...__args) noexcept(
        noexcept(__ref(*this, std::forward<_Args>(__args)...))) {
      return __ref(*this, std::forward<_Args>(__args)...);
    }
  };

  _F __fn;

 public:
  // Construct a new fixed-point object.
  fixed_point(_F __x) noexcept : __fn(__x) {}

  // Function call.
  template <class... _Args>
  decltype(auto) operator()(_Args &&...__args) noexcept(noexcept(_wrapper{
      __fn}(std::forward<_Args>(__args)...))) {
    return _wrapper{__fn}(std::forward<_Args>(__args)...);
  }
};

}  // namespace workspace
#line 6 "Library\\lib\\utils"
// #include "src/utils/hash.hpp"
// #include "src/utils/io/istream.hpp"
// #include "src/utils/io/ostream.hpp"
// #include "src/utils/io/read.hpp"
#line 2 "Library\\src\\utils\\grid\\motion.hpp"

/**
 * @file motion.hpp
 * @brief Motion
 */

#line 9 "Library\\src\\utils\\grid\\motion.hpp"

#line 11 "Library\\src\\utils\\grid\\motion.hpp"

namespace workspace {

/**
 * @brief Transpose.
 * @param __grid
 */
template <class _Grid,
          typename = decltype(std::declval<std::decay_t<_Grid>>()[0].resize(0))>
constexpr decltype(auto) transpose(_Grid &&__grid) noexcept {
#if __cplusplus < 201703L
  auto __h = __grid.size(), __w = __grid[0].size();
#else
  auto __h = std::size(__grid), __w = std::size(__grid[0]);
#endif
  std::decay_t<_Grid> __t(__w);
  for (auto &&__r : __t) __r.resize(__h);
  for (size_t __i = 0; __i != __h; ++__i)
    for (size_t __j = 0; __j != __w; ++__j)
      if _CXX17_CONSTEXPR (std::is_rvalue_reference<decltype(__grid)>::value)
        __t[__j][__i] = std::move(__grid[__i][__j]);
      else
        __t[__j][__i] = __grid[__i][__j];
  return __t;
}

/**
 * @brief Transpose.
 * @param __grid
 */
template <class _Tp, size_t _Rows, size_t _Cols>
constexpr decltype(auto) transpose(const _Tp (&__grid)[_Rows][_Cols]) noexcept {
  std::array<std::array<_Tp, _Rows>, _Cols> __t;
  for (size_t __i = 0; __i != _Rows; ++__i)
    for (size_t __j = 0; __j != _Cols; ++__j) __t[__j][__i] = __grid[__i][__j];
  return __t;
}

/**
 * @brief Transpose.
 * @param __grid
 */
template <class _Tp, size_t _Rows, size_t _Cols>
constexpr decltype(auto) transpose(_Tp(&&__grid)[_Rows][_Cols]) noexcept {
  std::array<std::array<_Tp, _Rows>, _Cols> __t;
  for (size_t __i = 0; __i != _Rows; ++__i)
    for (size_t __j = 0; __j != _Cols; ++__j)
      __t[__j][__i] = std::move(__grid[__i][__j]);
  return __t;
}

/**
 * @brief Transpose.
 * @param __grid
 */
template <class _Tp, size_t _Rows, size_t _Cols>
constexpr decltype(auto) transpose(
    const std::array<std::array<_Tp, _Cols>, _Rows> &__grid) noexcept {
  std::array<std::array<_Tp, _Rows>, _Cols> __t;
  for (size_t __i = 0; __i != _Rows; ++__i)
    for (size_t __j = 0; __j != _Cols; ++__j) __t[__j][__i] = __grid[__i][__j];
  return __t;
}

/**
 * @brief Transpose.
 * @param __grid
 */
template <class _Tp, size_t _Rows, size_t _Cols>
constexpr decltype(auto) transpose(
    std::array<std::array<_Tp, _Cols>, _Rows> &&__grid) noexcept {
  std::array<std::array<_Tp, _Rows>, _Cols> __t;
  for (size_t __i = 0; __i != _Rows; ++__i)
    for (size_t __j = 0; __j != _Cols; ++__j)
      __t[__j][__i] = std::move(__grid[__i][__j]);
  return __t;
}

/**
 * @brief Roll the grid counter-clockwise.
 * @param __grid
 */
template <class _Grid> decltype(auto) roll_ccw(_Grid &&__grid) noexcept {
  if _CXX17_CONSTEXPR (std::is_rvalue_reference<decltype(__grid)>::value) {
    auto __t = transpose(std::move(__grid));
    std::reverse(std::begin(__t), std::end(__t));
    return __t;
  } else {
    auto __t = transpose(__grid);
    std::reverse(std::begin(__t), std::end(__t));
    return __t;
  }
}

/**
 * @brief Roll the grid clockwise.
 * @param __grid
 */
template <class _Grid> decltype(auto) roll_cw(_Grid &&__grid) noexcept {
  if _CXX17_CONSTEXPR (std::is_rvalue_reference<decltype(__grid)>::value) {
    std::reverse(std::begin(__grid), std::end(__grid));
    return transpose(std::move(__grid));
  } else {
    auto __t = transpose(__grid);
    for (auto &&__r : __t) std::reverse(std::begin(__r), std::end(__r));
    return __t;
  }
}

}  // namespace workspace
#line 2 "Library\\src\\utils\\io\\setup.hpp"

/**
 * @file setup.hpp
 * @brief I/O Setup
 */

#line 10 "Library\\src\\utils\\io\\setup.hpp"

namespace workspace {

/**
 * @brief Setup I/O.
 * @param __n Standard output precision
 */
void io_setup(int __n) {
  std::cin.tie(0)->sync_with_stdio(0);
  std::cout << std::fixed << std::setprecision(__n);

#ifdef _buffer_check
  atexit([] {
    char bufc;
    if (std::cin >> bufc)
      std::cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });
#endif
}

}  // namespace workspace
#line 2 "Library\\src\\utils\\iterator\\category.hpp"

/*
 * @file category.hpp
 * @brief Iterator Category
 */

#line 10 "Library\\src\\utils\\iterator\\category.hpp"

namespace workspace {

/*
 * @tparam Tuple Tuple of iterator types
 */
template <class Tuple, size_t N = std::tuple_size<Tuple>::value - 1>
struct common_iterator_category {
  using type = typename std::common_type<
      typename common_iterator_category<Tuple, N - 1>::type,
      typename std::iterator_traits<typename std::tuple_element<
          N, Tuple>::type>::iterator_category>::type;
};

template <class Tuple> struct common_iterator_category<Tuple, 0> {
  using type = typename std::iterator_traits<
      typename std::tuple_element<0, Tuple>::type>::iterator_category;
};

}  // namespace workspace
#line 2 "Library\\src\\utils\\iterator\\reverse.hpp"

/*
 * @file reverse_iterator.hpp
 * @brief Reverse Iterator
 */

#if __cplusplus >= 201703L

#include <iterator>
#include <optional>

namespace workspace {

/*
 * @class reverse_iterator
 * @brief Wrapper class for `std::reverse_iterator`.
 * @see http://gcc.gnu.org/PR51823
 */
template <class Iterator>
class reverse_iterator : public std::reverse_iterator<Iterator> {
  using base_std = std::reverse_iterator<Iterator>;
  std::optional<typename base_std::value_type> deref;

 public:
  using base_std::reverse_iterator;

  constexpr typename base_std::reference operator*() noexcept {
    if (!deref) {
      Iterator tmp = base_std::current;
      deref = *--tmp;
    }
    return deref.value();
  }

  constexpr reverse_iterator &operator++() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator &operator--() noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator++(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
  constexpr reverse_iterator operator--(int) noexcept {
    base_std::operator++();
    deref.reset();
    return *this;
  }
};

}  // namespace workspace

#endif
#line 14 "Library\\lib\\utils"
// #include "src/utils/make_vector.hpp"
// #include "src/utils/py-like/enumerate.hpp"
#line 2 "Library\\src\\utils\\py-like\\range.hpp"

/**
 * @file range.hpp
 * @brief Range
 */

#line 9 "Library\\src\\utils\\py-like\\range.hpp"

#line 2 "Library\\src\\utils\\py-like\\reversed.hpp"

/**
 * @file reversed.hpp
 * @brief Reversed
 */

#include <initializer_list>
#line 10 "Library\\src\\utils\\py-like\\reversed.hpp"

namespace workspace {

namespace _reversed_impl {

template <class _Container> class reversed {
  _Container __cont;

 public:
  constexpr reversed(_Container &&__cont) noexcept : __cont(__cont) {}

  constexpr decltype(auto) begin() noexcept { return std::rbegin(__cont); }
  constexpr decltype(auto) begin() const noexcept {
    return std::rbegin(__cont);
  }

  constexpr decltype(auto) end() noexcept { return std::rend(__cont); }
  constexpr decltype(auto) end() const noexcept { return std::rend(__cont); }

  constexpr decltype(auto) size() const noexcept {
    return
#if __cplusplus < 201703L
        __cont.size();
#else
        std::size(__cont);
#endif
  }
};

}  // namespace _reversed_impl

template <class _Container>
constexpr decltype(auto) reversed(_Container &&__cont) noexcept {
  return _reversed_impl::reversed<_Container>{std::forward<_Container>(__cont)};
}

template <class _Tp>
constexpr decltype(auto) reversed(
    std::initializer_list<_Tp> &&__cont) noexcept {
  return _reversed_impl::reversed<std::initializer_list<_Tp>>{
      std::forward<std::initializer_list<_Tp>>(__cont)};
}

}  // namespace workspace
#line 12 "Library\\src\\utils\\py-like\\range.hpp"

#if __cplusplus >= 201703L

namespace workspace {

template <class _Index> class range {
  _Index __first, __last;

 public:
  class iterator {
    _Index current;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = _Index;
    using reference = typename std::add_const<_Index>::type &;
    using pointer = iterator;
    using iterator_category = std::random_access_iterator_tag;

    constexpr iterator(const _Index &__i = _Index()) noexcept : current(__i) {}

    constexpr bool operator==(const iterator &__x) const noexcept {
      return current == __x.current;
    }
    constexpr bool operator!=(const iterator &__x) const noexcept {
      return current != __x.current;
    }

    constexpr bool operator<(const iterator &__x) const noexcept {
      return current < __x.current;
    }
    constexpr bool operator<=(const iterator &__x) const noexcept {
      return current <= __x.current;
    }

    constexpr bool operator>(const iterator &__x) const noexcept {
      return current > __x.current;
    }
    constexpr bool operator>=(const iterator &__x) const noexcept {
      return current >= __x.current;
    }

    constexpr iterator &operator++() noexcept {
      ++current;
      return *this;
    }
    constexpr iterator &operator++(int) noexcept {
      auto __tmp = *this;
      ++current;
      return __tmp;
    }

    constexpr iterator &operator--() noexcept {
      --current;
      return *this;
    }
    constexpr iterator &operator--(int) noexcept {
      auto __tmp = *this;
      --current;
      return __tmp;
    }

    constexpr difference_type operator-(const iterator &__x) const noexcept {
      return current - __x.current;
    }

    constexpr iterator &operator+=(difference_type __x) noexcept {
      current += __x;
      return *this;
    }
    constexpr iterator operator+(difference_type __x) const noexcept {
      return iterator(*this) += __x;
    }

    constexpr iterator &operator-=(difference_type __x) noexcept {
      current -= __x;
      return *this;
    }
    constexpr iterator operator-(difference_type __x) const noexcept {
      return iterator(*this) -= __x;
    }

    constexpr reference operator*() const noexcept { return current; }
  };

  template <class _Tp1, class _Tp2>
  constexpr range(const _Tp1 &__first, const _Tp2 &__last) noexcept
      : __first(__first), __last(__last) {}

  template <class _Tp>
  constexpr range(const _Tp &__last) noexcept : __first(), __last(__last) {}

  constexpr iterator begin() const noexcept { return iterator{__first}; }
  constexpr iterator end() const noexcept { return iterator{__last}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>(end());
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>(begin());
  }

  constexpr size_t size() const noexcept {
    return std::distance(__first, __last);
  }
};

template <class _Tp1, class _Tp2>
range(const _Tp1 &, const _Tp2 &)
    -> range<std::decay_t<decltype(++std::declval<_Tp1 &>())>>;

template <class _Tp>
range(const _Tp &) -> range<std::decay_t<decltype(++std::declval<_Tp &>())>>;

template <class... _Args>
constexpr decltype(auto) rrange(_Args &&...__args) noexcept {
  return reversed(range(std::forward<_Args>(__args)...));
}

template <class _Container>
constexpr decltype(auto) iterate(_Container &&__cont) noexcept {
  return range(std::begin(__cont), std::end(__cont));
}

template <class _Container>
constexpr decltype(auto) riterate(_Container &&__cont) noexcept {
  return range(std::rbegin(__cont), std::rend(__cont));
}

}  // namespace workspace

#endif
#line 17 "Library\\lib\\utils"
// #include "src/utils/py-like/reversed.hpp"
// #include "src/utils/py-like/zip.hpp"
#line 2 "Library\\src\\utils\\rand\\rng.hpp"

/**
 * @file rng.hpp
 * @brief Random Number Generator
 */

#line 9 "Library\\src\\utils\\rand\\rng.hpp"

namespace workspace {

template <typename _Arithmetic>
using uniform_distribution = typename std::conditional<
    std::is_integral<_Arithmetic>::value,
    std::uniform_int_distribution<_Arithmetic>,
    std::uniform_real_distribution<_Arithmetic>>::type;

template <typename _Arithmetic, class _Engine = std::mt19937>
class random_number_generator : uniform_distribution<_Arithmetic> {
  using base = uniform_distribution<_Arithmetic>;

  _Engine __engine;

 public:
  random_number_generator(_Arithmetic __min, _Arithmetic __max)
      : base(__min, __max), __engine(std::random_device{}()) {}

  random_number_generator(_Arithmetic __max = 1)
      : random_number_generator(0, __max) {}

  random_number_generator(typename base::param_type const& __param)
      : base(__param), __engine(std::random_device{}()) {}

  decltype(auto) operator()() noexcept { return base::operator()(__engine); }
};

}  // namespace workspace
#line 2 "Library\\src\\utils\\rand\\shuffle.hpp"

/**
 * @file shuffle.hpp
 * @brief Shuffle
 */

#line 10 "Library\\src\\utils\\rand\\shuffle.hpp"

namespace workspace {

template <class _RAIter, class _Engine = std::mt19937>
void shuffle(_RAIter __first, _RAIter __last) {
  static _Engine __engine(std::random_device{}());
  std::shuffle(__first, __last, __engine);
}

}  // namespace workspace
#line 2 "Library\\src\\utils\\round_div.hpp"

/*
 * @file round_div.hpp
 * @brief Round Integer Division
 */

#line 9 "Library\\src\\utils\\round_div.hpp"

#line 11 "Library\\src\\utils\\round_div.hpp"

namespace workspace {

/*
 * @fn floor_div
 * @brief floor of fraction.
 * @param x the numerator
 * @param y the denominator
 * @return maximum integer z s.t. z <= x / y
 * @note y must be nonzero.
 */
template <typename T1, typename T2>
constexpr typename std::enable_if<(is_integral_ext<T1>::value &&
                                   is_integral_ext<T2>::value),
                                  typename std::common_type<T1, T2>::type>::type
floor_div(T1 x, T2 y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return x < 0 ? (x - y + 1) / y : x / y;
}

/*
 * @fn ceil_div
 * @brief ceil of fraction.
 * @param x the numerator
 * @param y the denominator
 * @return minimum integer z s.t. z >= x / y
 * @note y must be nonzero.
 */
template <typename T1, typename T2>
constexpr typename std::enable_if<(is_integral_ext<T1>::value &&
                                   is_integral_ext<T2>::value),
                                  typename std::common_type<T1, T2>::type>::type
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return x < 0 ? x / y : (x + y - 1) / y;
}

}  // namespace workspace
#line 22 "Library\\lib\\utils"
// #include "src\utils\rand\tree.hpp"
// #include "src\utils\reference_list.hpp"
#line 2 "Library\\src\\utils\\io\\input.hpp"

/**
 * @file input.hpp
 * @brief Input
 */

#line 2 "Library\\src\\utils\\io\\istream.hpp"

/**
 * @file istream.hpp
 * @brief Input Stream
 */

#include <cxxabi.h>

#line 13 "Library\\src\\utils\\io\\istream.hpp"

#line 16 "Library\\src\\utils\\io\\istream.hpp"

namespace workspace {

namespace _istream_impl {

template <class _Tp, typename = void> struct helper {
  helper(std::istream &__is, _Tp &__x) {
    if _CXX17_CONSTEXPR (has_begin<_Tp &>::value)
      for (auto &&__e : __x) helper<std::decay_t<decltype(__e)>>(__is, __e);
    else
      static_assert(has_begin<_Tp>::value, "istream unsupported type.");
  }
};

template <class _Tp>
struct helper<_Tp, std::__void_t<decltype(std::declval<std::istream &>() >>
                                          std::declval<_Tp &>())>> {
  helper(std::istream &__is, _Tp &__x) { __is >> __x; }
};

#ifdef __SIZEOF_INT128__

template <> struct helper<__uint128_t, void> {
  helper(std::istream &__is, __uint128_t &__x) {
    std::string __s;
    __is >> __s;
    bool __neg = false;
    if (__s.front() == '-') __neg = true, __s.erase(__s.begin());
    __x = 0;
    for (char __d : __s) {
      __x *= 10;
      __d -= '0';
      if (__neg)
        __x -= __d;
      else
        __x += __d;
    }
  }
};

template <> struct helper<__int128_t, void> {
  helper(std::istream &__is, __int128_t &__x) {
    std::string __s;
    __is >> __s;
    bool __neg = false;
    if (__s.front() == '-') __neg = true, __s.erase(__s.begin());
    __x = 0;
    for (char __d : __s) {
      __x *= 10;
      __d -= '0';
      if (__neg)
        __x -= __d;
      else
        __x += __d;
    }
  }
};

#endif  // INT128

template <class _T1, class _T2> struct helper<std::pair<_T1, _T2>> {
  helper(std::istream &__is, std::pair<_T1, _T2> &__x) {
    helper<_T1>(__is, __x.first), helper<_T2>(__is, __x.second);
  }
};

template <class... _Tp> struct helper<std::tuple<_Tp...>> {
  helper(std::istream &__is, std::tuple<_Tp...> &__x) { iterate(__is, __x); }

 private:
  template <class _Tuple, size_t _Nm = 0>
  void iterate(std::istream &__is, _Tuple &__x) {
    if _CXX17_CONSTEXPR (_Nm != std::tuple_size<_Tuple>::value) {
      helper<typename std::tuple_element<_Nm, _Tuple>::type>(
          __is, std::get<_Nm>(__x)),
          iterate<_Tuple, _Nm + 1>(__is, __x);
    }
  }
};

}  // namespace _istream_impl

/**
 * @brief A wrapper class for std::istream.
 */
class istream : public std::istream {
 public:
  /**
   * @brief Wrapped operator.
   */
  template <typename _Tp> istream &operator>>(_Tp &__x) {
    _istream_impl::helper<_Tp>(*this, __x);
    if (std::istream::fail()) {
      static auto once = atexit([] {
        std::cerr << "\n\033[43m\033[30mwarning: failed to read \'"
                  << abi::__cxa_demangle(typeid(_Tp).name(), 0, 0, 0)
                  << "\'.\033[0m\n\n";
      });
      assert(!once);
    }
    return *this;
  }
};

decltype(auto) cin = static_cast<istream &>(std::cin);

}  // namespace workspace
#line 9 "Library\\src\\utils\\io\\input.hpp"

namespace workspace {

namespace _input_impl {

template <class _Tp, bool _Is_class = false> class input {
  _Tp __value;

  template <class _Arg, class... _Args> struct is_same : std::false_type {};
  template <class _Arg> struct is_same<_Arg, _Arg> : std::true_type {};

 public:
  operator _Tp &() noexcept { return __value; }
  operator const _Tp &() const noexcept { return __value; }

  template <class... _Args>
  input(_Args &&...__args) noexcept : __value(std::forward<_Args>(__args)...) {
    if _CXX17_CONSTEXPR (!is_same<decltype(*this), _Args...>::value &&
                         !is_same<_Tp, _Args...>::value)
      cin >> __value;
  }

  input &operator=(const _Tp &__x) noexcept { return __value = __x, *this; }
};

template <class _Tp> class input<_Tp, true> : public _Tp {
  template <class _Arg, class... _Args> struct is_same : std::false_type {};
  template <class _Arg> struct is_same<_Arg, _Arg> : std::true_type {};

 public:
  operator _Tp &() noexcept { return *this; }
  operator const _Tp &() const noexcept { return *this; }

  template <class... _Args>
  input(_Args &&...__args) noexcept : _Tp(std::forward<_Args>(__args)...) {
    if _CXX17_CONSTEXPR (!is_same<decltype(*this), _Args...>::value &&
                         !is_same<_Tp, _Args...>::value)
      cin >> *this;
  }

  input &operator=(const _Tp &__x) noexcept {
    _Tp::operator=(__x);
    return *this;
  }
};

}  // namespace _input_impl

template <class _Tp>
using input = _input_impl::input<_Tp, std::is_class<_Tp>::value>;

}  // namespace workspace
#line 11 "codeforces-workspace\\contest\\739\\c\\c.cpp"

// #include "lib/algebra"
// #include "lib/graph"
// #include "lib/modular"
// #include "lib/combinatorics"
// #include "lib/data_structure"
// #include "lib/number_theory"
// #include "lib/string"

signed main() {
  using namespace workspace;

  io_setup(15);

  /* given
    case_info.read();  //*/

  /* unspecified
    case_info.total = -1;  //*/

  return case_info.iterate();
}

#line 2 "Library\\src\\data_structure\\segment_tree\\basic.hpp"

/**
 * @file basic.hpp
 * @brief Segment Tree
 */

#line 10 "Library\\src\\data_structure\\segment_tree\\basic.hpp"

#if __cplusplus >= 201703L
#include <optional>
#endif

#line 2 "Library\\src\\algebra\\system\\monoid.hpp"

/*
 * @file monoid.hpp
 * @brief Monoid
 */

#line 9 "Library\\src\\algebra\\system\\monoid.hpp"

namespace workspace {

template <class T, class E = T> struct min_monoid {
  using value_type = T;
  static T min, max;
  T value;
  min_monoid() : value(max) {}
  min_monoid(const T &value) : value(value) {}
  operator T() const { return value; }
  min_monoid operator+(const min_monoid &rhs) const {
    return value < rhs.value ? *this : rhs;
  }
  min_monoid operator*(const E &rhs) const;
};

template <class T, class E>
T min_monoid<T, E>::min = std::numeric_limits<T>::min() / 2;
template <class T, class E>
T min_monoid<T, E>::max = std::numeric_limits<T>::max() / 2;

template <class T, class E = T> struct max_monoid : min_monoid<T, E> {
  using base = min_monoid<T, E>;
  using base::min_monoid;
  max_monoid() : base(base::min) {}
  max_monoid operator+(const max_monoid &rhs) const {
    return !(base::value < rhs.value) ? *this : rhs;
  }
  max_monoid operator*(const E &rhs) const;
};

}  // namespace workspace
#line 17 "Library\\src\\data_structure\\segment_tree\\basic.hpp"

namespace workspace {

/**
 * @tparam _Monoid `operator+`, `operator=`
 * @tparam Container_tmpl `operator[]`, `size_type`
 */
template <class _Monoid, class _Endomorphism = void,
          template <class...> class Container_tmpl = std::vector>
class segment_tree {
  static_assert(has_binary_plus<_Monoid>::value,
                "\'_Monoid\' has no proper binary \'operator+\'.");

  constexpr static bool __support_lazy = !std::is_void<_Endomorphism>::value;

#if __cplusplus < 201703L
  struct node_base {
    node_base() = default;
    node_base(_Monoid const &__x) : __v(__x) {}
    operator bool() const { return __f; }
    void operator=(_Monoid const &__x) {
      __v = __x;
      __f = true;
    }
    _Monoid &operator*() { return __v; }
    _Monoid const &operator*() const { return __v; }
    void reset() { __f = false; }

   private:
    _Monoid __v{};
    bool __f{true};
  };
#else
  struct node_base : std::optional<_Monoid> {
    using std::optional<_Monoid>::operator=;
    node_base() : std::optional<_Monoid>(_Monoid{}) {}
  };
#endif

  struct node_lazy : node_base {
    using node_base::operator=;
    std::optional<_Endomorphism> __z;
  };

  using node =
      typename std::conditional<__support_lazy, node_lazy, node_base>::type;

  using container_type = Container_tmpl<node>;

 public:
  using size_type = typename container_type::size_type;
  using difference_type = typename container_type::difference_type;

  class iterator {
    segment_tree *__p;
    size_type __i;

   public:
    using difference_type = segment_tree::difference_type;
    using value_type = _Monoid;
    using reference = _Monoid &;
    using pointer = iterator;
    using iterator_category = std::random_access_iterator_tag;

    /**
     * @brief Construct a new iterator object
     *
     */
    iterator() = default;

    /**
     * @brief Construct a new iterator object
     *
     * @param __p Pointer to a segment tree object
     * @param __i Index
     */
    iterator(segment_tree *__p, size_type __i) : __p(__p), __i(__i) {}

    bool operator==(iterator const &rhs) const {
      return __p == rhs.__p && __i == rhs.__i;
    }
    bool operator!=(iterator const &rhs) const { return !operator==(rhs); }

    bool operator<(iterator const &rhs) const { return __i < rhs.__i; }
    bool operator>(iterator const &rhs) const { return __i > rhs.__i; }
    bool operator<=(iterator const &rhs) const { return __i <= rhs.__i; }
    bool operator>=(iterator const &rhs) const { return __i >= rhs.__i; }

    iterator &operator++() { return ++__i, *this; }
    iterator &operator--() { return --__i, *this; }

    difference_type operator-(iterator const &rhs) const {
      return __i - rhs.__i;
    }

    /**
     * @brief
     *
     * @return reference
     */
    reference operator*() const { return __p->operator[](__i); }
  };

  using value_type = typename iterator::value_type;
  using reference = typename iterator::reference;

  iterator begin() { return {this, 0}; }
  iterator end() { return {this, size_orig}; }

  auto rbegin() { return std::make_reverse_iterator(end()); }
  auto rend() { return std::make_reverse_iterator(begin()); }

 protected:
  size_type size_orig, height, size_ext;
  container_type data;

  node &pull(size_type __i) noexcept {
    if (!data[__i]) data[__i] = *pull(__i << 1) + *pull(__i << 1 | 1);
    return data[__i];
  }

  void push(size_type __i) {
    if (auto &__lz = data[__i].__z) {
      apply(data[__i << 1], *__lz);
      apply(data[__i << 1 | 1], *__lz);
      __lz.reset();
    }
  }

  void sync(size_type __i) {
    if (!data[__i])
      data[__i] = *pull(__i << 1) + *pull(__i << 1 | 1);
    else if (data[__i].__z) {
      apply(data[__i << 1], *data[__i].__z);
      apply(data[__i << 1 | 1], *data[__i].__z);
      data[__i].__z.reset();
    }
  }

  template <class _End = _Endomorphism>
  void apply(node &__nd, _End const &endo) {
    *__nd = *__nd * endo;
    __nd.__z = __nd.__z ? *__nd.__z * endo : endo;
  }

  // template <class _End = _Endomorphism>
  // void apply_top(size_t __i, _End const &endo) {
  //   auto &__nd = pull(__i);
  //   *__nd = *__nd * endo;
  //   __nd.__z = __nd.__z ? *__nd.__z * endo : endo;
  // }

  template <class Pred>
  constexpr decltype(std::declval<Pred>()(_Monoid{})) pass_args(
      Pred pred, _Monoid const &_1, [[maybe_unused]] size_type _2) {
    return pred(_1);
  }

  template <class Pred>
  constexpr decltype(std::declval<Pred>()(_Monoid{}, size_type{})) pass_args(
      Pred pred, _Monoid const &_1, size_type _2) {
    return pred(_1, _2);
  }

  template <class Pred>
  size_type left_partition_subtree(size_type __i, _Monoid mono, size_type step,
                                   Pred pred) {
    assert(__i);
    while (__i < size_ext) {
      if constexpr (__support_lazy) push(__i);
      const _Monoid tmp = *pull((__i <<= 1) | 1) + mono;
      if (pass_args(pred, tmp, ((__i | 1) << --step) ^ size_ext))
        mono = tmp;
      else
        ++__i;
    }
    return ++__i -= size_ext;
  }

  template <class Pred>
  size_type right_partition_subtree(size_type __i, _Monoid mono, size_type step,
                                    Pred pred) {
    assert(__i);
    while (__i < size_ext) {
      if constexpr (__support_lazy) push(__i);
      const _Monoid tmp = mono + *pull(__i <<= 1);
      if (pass_args(pred, tmp, ((__i | 1) << --step) ^ size_ext))
        ++__i, mono = tmp;
    }
    return (__i -= size_ext) < size_orig ? __i : size_orig;
  }

 public:
  /**
   * @brief Construct a new segment tree object.
   *
   * @param __n Number of elements.
   */
  segment_tree(size_type __n = 0)
      : size_orig{__n},
        height(__n > 1 ? 64 - __builtin_clzll(__n - 1) : 0),
        size_ext{size_type{1} << height} {
    if constexpr (std::is_constructible<container_type, size_t>::value)
      data = container_type(size_ext << 1);
    data[0].reset();
  }

  /**
   * @brief Construct a new segment tree object.
   *
   * @param __n Number of elements.
   * @param __x
   */
  segment_tree(size_type __n, const value_type &__x) : segment_tree(__n) {
    for (auto __i = begin(); __i != end(); ++__i) *__i = __x;
  }

  /**
   * @brief Construct a new segment tree object.
   *
   * @param __n Number of elements.
   * @param __x
   */
  template <class _Tp>
  segment_tree(size_type __n, _Tp &&__x) : segment_tree(__n) {
    for (auto __i = begin(); __i != end(); ++__i) *__i = __x;
  }

  /**
   * @brief Construct a new segment tree object.
   *
   * @param __first
   * @param __last
   */
  template <class _Iterator, typename = std::_RequireInputIter<_Iterator>>
  segment_tree(_Iterator __first, _Iterator __last)
      : segment_tree(std::distance(__first, __last)) {
    for (auto __i = begin(); __first != __last; ++__i, ++__first)
      *__i = *__first;
  }

  /**
   * @brief Conversion to container_type.
   */
  operator Container_tmpl<value_type>() const {
    Container_tmpl<value_type> __c(size());
    for (size_type __i = 0; __i != size(); ++__i)
      __c[__i] = *data[__i | size_ext];
    return __c;
  }

  /**
   * @return Number of elements.
   */
  size_type size() const { return size_orig; }

  /**
   * @return Whether %segment_tree is empty.
   */
  bool empty() const { return !size(); }

  /**
   * @brief Subscripting ( @c [] ) access.
   *
   * @param __i Index of the element
   * @return Reference to the element.
   */
  reference operator[](size_type __i) {
    assert(__i < size_orig);
    reference __ref = *data[__i |= size_ext];
    if constexpr (__support_lazy) {
      for (size_t __h{height}; __h; --__h) {
        push(__i >> __h);
        data[__i >> __h].reset();
      }
    } else {
      while (data[__i >>= 1]) data[__i].reset();
    }
    return __ref;
  }

  /**
   * @param first Left end, inclusive
   * @param last Right end, exclusive
   * @return Sum of elements in the interval.
   */
  value_type fold(size_type first, size_type last) {
    assert(last <= size_orig);
    if (!(first < last)) return {};
    first += size_ext, last += size_ext;
    value_type left{}, right{};
    for (size_t l = first, r = last--; l != r; l >>= 1, r >>= 1) {
      if (l & 1) left = left + *pull(l++);
      if (r & 1) right = *pull(--r) + right;
      if constexpr (__support_lazy) {
        if (data[first >>= 1].__z) left = left * *data[first].__z;
        if (data[last >>= 1].__z) right = right * *data[last].__z;
      }
    }
    if constexpr (__support_lazy) {
      while (first >>= 1, last >>= 1) {
        if (data[first].__z) left = left * *data[first].__z;
        if (data[last].__z) right = right * *data[last].__z;
      }
    }

    // if (first >= last) return _Monoid{};
    // first += size_ext, last += size_ext - 1;
    // _Monoid left{}, right{};
    // for (size_t l = first, r = last + 1; last; l >>= 1, r >>= 1) {
    //   if (l < r) {
    //     if (l & 1) left = left + data[l++];
    //     if (r & 1) right = data[--r] + right;
    //   }
    //   if (first >>= 1, last >>= 1) {
    //     left = left * lazy[first];
    //     right = right * lazy[last];
    //   }
    // }
    // return left + right;

    return left + right;
  }

  /**
   * @return The whole sum.
   */
  value_type fold() { return *pull(1); }

  template <class _End = _Endomorphism>
  void update(size_type first, size_type last, _End const &endo) {
    static_assert(__support_lazy);

    assert(last <= size_orig);
    if (!(first < last)) return;
    first += size_ext, last += size_ext;

    --last;
    for (auto i = height; i; --i) push(first >> i), push(last >> i);
    ++last;

    for (auto l = first, r = last; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(pull(l++), endo);
      if (r & 1) apply(pull(--r), endo);
    }

    for (first >>= __builtin_ffs(first); data[first]; first >>= 1)
      data[first].reset();

    for (last >>= __builtin_ffs(last); data[last]; last >>= 1)
      data[last].reset();
  }

  /**
   * @brief Binary search for the partition point.
   * @param right Right fixed end of the interval, exclusive
   * @param pred Predicate in the form of either 'bool(_Monoid)' or
   * 'bool(_Monoid, size_type)'
   * @return Left end of the extremal interval satisfying the condition,
   * inclusive.
   */
  template <class Pred> size_type left_partition(size_type right, Pred pred) {
    assert(right <= size_orig);
    right += size_ext;

    if constexpr (__support_lazy)
      for (size_t i{height}; i; --i) push(right >> i);

    _Monoid mono{};
    for (size_type left{size_ext}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        _Monoid tmp = *pull(--right) + mono;
        if (!pass_args(pred, tmp, (right << step) ^ size_ext))
          return left_partition_subtree(right, mono, step, pred);
        mono = tmp;
      }
    }

    return 0;
  }

  /**
   * @brief Binary search for the partition point.
   * @param left Left fixed end of the interval, inclusive
   * @param pred Predicate in the form of either 'bool(_Monoid)' or
   * 'bool(_Monoid, size_type)'
   * @return Right end of the extremal interval satisfying the condition,
   * exclusive.
   */
  template <class Pred> size_type right_partition(size_type left, Pred pred) {
    assert(left <= size_orig);
    left += size_ext;

    if constexpr (__support_lazy)
      for (size_t i{height}; i; --i) push(left >> i);

    _Monoid mono{};
    for (size_type right{size_ext << 1}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        _Monoid tmp = mono + *pull(left);
        if (!pass_args(pred, tmp, ((left + 1) << step) ^ size_ext))
          return right_partition_subtree(left, mono, step, pred);
        mono = tmp;
        ++left;
      }
    }

    return size_orig;
  }
};

template <class _Iterator, typename = std::_RequireInputIter<_Iterator>>
segment_tree(_Iterator, _Iterator)
    -> segment_tree<typename std::iterator_traits<_Iterator>::value_type>;

template <class _Tp, typename = require_binary_plus<_Tp>>
segment_tree(typename segment_tree<_Tp>::size_type, _Tp &&)
    -> segment_tree<_Tp>;

}  // namespace workspace
#line 35 "codeforces-workspace\\contest\\739\\c\\c.cpp"

namespace workspace {

void main() {
  // start here!

  // constexpr auto inf = i64(1) << 60;

  int n;
  cin >> n;
  vector<i64> d;
  {
    i64 last;
    cin >> last;
    for (auto i : range(n - 1)) {
      i64 x;
      cin >> x;
      d.emplace_back(x - last);
      last = x;
    }
  }

  struct mono : array<int, 6> {
    mono() {}

    mono(i64 x) {
      auto& v = *this;
      v[0] = 1;
      for (auto i : range(1, 6)) {
        v[i] = x != 0;
      }
      v[1] -= x > 0;
      v[2] -= x < 0;
    }

    mono operator+(const mono& r) const {
      const auto& l = *this;
      mono m;

      m[0] = l[0] + r[0];
      m[1] = l[1];
      m[2] = r[2];
      m[3] = l[3];
      m[4] = r[4];
      m[5] = max({l[5], r[5], l[4] + r[1], l[2] + r[3]});

      if (l[3] == l[0]) m[3] += r[1];
      if (r[4] == r[0]) m[4] += l[2];
      if (l[1] == l[0]) m[1] += r[1];
      if (l[2] == l[0]) m[3] = r[3] + l[0];
      if (r[2] == r[0]) m[2] += l[2];
      if (r[1] == r[0]) m[4] = l[4] + r[0];

      return {m};
    }
  };

  segment_tree<mono> sgt(begin(d), end(d));

  int q;
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    --l, --r;
    if (l) sgt[l - 1] = d[l - 1] += x;
    if (r < sgt.size()) sgt[r] = d[r] -= x;
    cout << sgt.fold()[5] + 1 << "\n";
  }
}

}  // namespace workspace