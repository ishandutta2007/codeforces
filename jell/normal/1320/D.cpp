#line 1 "codeforces-workspace/contest/1320/d/d.cpp"
// #undef _GLIBCXX_DEBUG
// #define NDEBUG
#include <bits/extc++.h>

#line 2 "Library/lib/alias"

/**
 * @file alias
 * @brief Alias
 */

#line 13 "Library/lib/alias"

#line 2 "Library/lib/bit"

#if __cplusplus > 201703L

#include <bit>

#else

#ifndef _GLIBCXX_BIT
#define _GLIBCXX_BIT 1

#include <limits>
#include <type_traits>

namespace std {

template <typename _Tp> constexpr _Tp __rotl(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x << __r) | (__x >> ((_Nd - __r) % _Nd));
  else
    return (__x >> -__r) | (__x << ((_Nd + __r) % _Nd));  // rotr(x, -r)
}

template <typename _Tp> constexpr _Tp __rotr(_Tp __x, int __s) noexcept {
  constexpr auto _Nd = numeric_limits<_Tp>::digits;
  const int __r = __s % _Nd;
  if (__r == 0)
    return __x;
  else if (__r > 0)
    return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
  else
    return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  // rotl(x, -r)
}

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

template <typename _Tp> constexpr int __countl_one(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return __countl_zero<_Tp>((_Tp)~__x);
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

template <typename _Tp> constexpr int __countr_one(_Tp __x) noexcept {
  if (__x == numeric_limits<_Tp>::max()) return numeric_limits<_Tp>::digits;
  return __countr_zero((_Tp)~__x);
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

template <typename _Tp> constexpr bool __has_single_bit(_Tp __x) noexcept {
  return __popcount(__x) == 1;
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
#line 2 "Library/lib/limits"

#line 4 "Library/lib/limits"

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
#line 16 "Library/lib/alias"

namespace workspace {

constexpr char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using u32 = uint_least32_t;
using i64 = int_least64_t;
using u64 = uint_least64_t;

#ifdef __SIZEOF_INT128__
using i128 = __int128_t;
using u128 = __uint128_t;
#else
#warning 128bit integer is not available.
#endif

template <class T, class Comp = less<T>>
using priority_queue = std::priority_queue<T, vector<T>, Comp>;

template <class T> using stack = std::stack<T, vector<T>>;

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

template <typename _Tp> constexpr _Tp __bsf(_Tp __x) noexcept {
  return std::__countr_zero(__x);
}

template <typename _Tp> constexpr _Tp __bsr(_Tp __x) noexcept {
  return std::__bit_width(__x) - 1;
}

}  // namespace workspace
#line 6 "codeforces-workspace/contest/1320/d/d.cpp"
// #include "lib/cxx20"
#line 2 "Library/lib/direct"

/*
 * @file direct
 * @brief Pragma Directive
 */

#ifdef ONLINE_JUDGE

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("unroll-loops")

#endif
#line 8 "codeforces-workspace/contest/1320/d/d.cpp"
// #include "lib/opt"
#line 2 "Library/src/sys/clock.hpp"

/*
 * @fn clock.hpp
 * @brief Clock
 */

#line 9 "Library/src/sys/clock.hpp"

namespace workspace {

using namespace std::chrono;

namespace internal {
// The start time of the program.
const auto start_time{system_clock::now()};
}  // namespace internal

/*
 * @fn elapsed
 * @return elapsed time of the program
 */
int64_t elapsed() {
  const auto end_time{system_clock::now()};
  return duration_cast<milliseconds>(end_time - internal::start_time).count();
}

}  // namespace workspace
#line 2 "Library/src/sys/ejection.hpp"

/**
 * @file ejection.hpp
 * @brief Ejection
 */

#line 9 "Library/src/sys/ejection.hpp"

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
#line 2 "Library/src/sys/iteration.hpp"

/**
 * @file iteration.hpp
 * @brief Case Iteration
 */

#line 9 "Library/src/sys/iteration.hpp"

#line 11 "Library/src/sys/iteration.hpp"

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
#line 2 "Library/lib/utils"
// #include "src/utils/cached.hpp"
#line 2 "Library/src/utils/cat.hpp"

/**
 * @file cat.hpp
 * @brief Cat
 */

#line 9 "Library/src/utils/cat.hpp"

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

  if constexpr (std::is_rvalue_reference<decltype(__c2)>::value)
    __c.insert(std::end(__c), std::move_iterator(std::begin(__c2)),
               std::move_iterator(std::end(__c2)));

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
#line 2 "Library/src/utils/chval.hpp"

/**
 * @file chval.hpp
 * @brief Change Less/Greater
 */

#line 9 "Library/src/utils/chval.hpp"

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
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chge(
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
typename std::enable_if<std::is_assignable<_T1 &, _T2>::value, bool>::type chge(
    _T1 &__x, _T2 &&__y, _Compare __comp) noexcept {
  return __comp(__x, __y) ? __x = std::forward<_T2>(__y), true : false;
}

}  // namespace workspace
#line 5 "Library/lib/utils"
// #include "src/utils/fixed_point.hpp"
// #include "src/utils/grid.hpp"
// #include "src/utils/hash.hpp"
#line 2 "Library/src/utils/io/istream.hpp"

/**
 * @file istream.hpp
 * @brief Input Stream
 */

#include <cxxabi.h>

#line 13 "Library/src/utils/io/istream.hpp"

#line 2 "Library/src/utils/sfinae.hpp"

/**
 * @file sfinae.hpp
 * @brief SFINAE
 */

#line 10 "Library/src/utils/sfinae.hpp"
#include <type_traits>

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

template <class _Tp, class = std::nullptr_t>
struct has_mod : std::false_type {};

template <class _Tp>
struct has_mod<_Tp, decltype(_Tp::mod, nullptr)> : std::true_type {};

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

}  // namespace workspace
#line 15 "Library/src/utils/io/istream.hpp"

namespace workspace {

namespace internal {

template <class Tp, typename = std::nullptr_t> struct istream_helper {
  istream_helper(std::istream &is, Tp &x) {
    if constexpr (has_begin<Tp>::value)
      for (auto &&e : x)
        istream_helper<typename std::decay<decltype(e)>::type>(is, e);
    else
      static_assert(has_begin<Tp>::value, "istream unsupported type.");
  }
};

template <class Tp>
struct istream_helper<
    Tp,
    decltype(std::declval<std::decay<decltype(std::declval<std::istream &>() >>
                                              std::declval<Tp &>())>>(),
             nullptr)> {
  istream_helper(std::istream &is, Tp &x) { is >> x; }
};

#ifdef __SIZEOF_INT128__

template <> struct istream_helper<__uint128_t, std::nullptr_t> {
  istream_helper(std::istream &__is, __uint128_t &__x) {
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

template <> struct istream_helper<__int128_t, std::nullptr_t> {
  istream_helper(std::istream &__is, __int128_t &__x) {
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

template <class T1, class T2> struct istream_helper<std::pair<T1, T2>> {
  istream_helper(std::istream &is, std::pair<T1, T2> &x) {
    istream_helper<T1>(is, x.first), istream_helper<T2>(is, x.second);
  }
};

template <class... Tps> struct istream_helper<std::tuple<Tps...>> {
  istream_helper(std::istream &is, std::tuple<Tps...> &x) { iterate(is, x); }

 private:
  template <class Tp, size_t N = 0> void iterate(std::istream &is, Tp &x) {
    if constexpr (N == std::tuple_size<Tp>::value)
      return;
    else
      istream_helper<typename std::tuple_element<N, Tp>::type>(is,
                                                               std::get<N>(x)),
          iterate<Tp, N + 1>(is, x);
  }
};

}  // namespace internal

/**
 * @brief A wrapper class for std::istream.
 */
class istream : public std::istream {
 public:
  /**
   * @brief Wrapped operator.
   */
  template <typename Tp> istream &operator>>(Tp &x) {
    internal::istream_helper<Tp>(*this, x);
    if (std::istream::fail()) {
      static auto once = atexit([] {
        std::cerr << "\n\033[43m\033[30mwarning: failed to read \'"
                  << abi::__cxa_demangle(typeid(Tp).name(), 0, 0, 0)
                  << "\'.\033[0m\n\n";
      });
      assert(!once);
    }
    return *this;
  }
};

decltype(auto) cin = static_cast<istream &>(std::cin);

}  // namespace workspace
#line 2 "Library/src/utils/io/ostream.hpp"

/**
 * @file ostream.hpp
 * @brief Output Stream
 */

#line 9 "Library/src/utils/io/ostream.hpp"

namespace workspace {

template <class _Os> struct is_ostream {
  template <typename... _Args>
  static std::true_type __test(std::basic_ostream<_Args...> *);

  static std::false_type __test(void *);

  constexpr static bool value = decltype(__test(std::declval<_Os *>()))::value;
};

template <class _Os>
using ostream_ref =
    typename std::enable_if<is_ostream<_Os>::value, _Os &>::type;

/**
 * @brief Stream insertion operator for C-style array.
 *
 * @param __os Output stream
 * @param __a Array
 * @return Reference to __os.
 */
template <class _Os, class _Tp, size_t _Nm>
typename std::enable_if<bool(sizeof(_Tp) > 2), ostream_ref<_Os>>::type
operator<<(_Os &__os, const _Tp (&__a)[_Nm]) {
  if constexpr (_Nm) {
    __os << *__a;
    for (auto __i = __a + 1, __e = __a + _Nm; __i != __e; ++__i)
      __os << ' ' << *__i;
  }
  return __os;
}

/**
 * @brief Stream insertion operator for std::pair.
 *
 * @param __os Output stream
 * @param __p Pair
 * @return Reference to __os.
 */
template <class _Os, class _T1, class _T2>
ostream_ref<_Os> operator<<(_Os &__os, const std::pair<_T1, _T2> &__p) {
  return __os << __p.first << ' ' << __p.second;
}

/**
 * @brief Stream insertion operator for std::tuple.
 *
 * @param __os Output stream
 * @param __t Tuple
 * @return Reference to __os.
 */
template <class _Os, class _Tp, size_t _Nm = 0>
typename std::enable_if<bool(std::tuple_size<_Tp>::value + 1),
                        ostream_ref<_Os>>::type
operator<<(_Os &__os, const _Tp &__t) {
  if constexpr (_Nm != std::tuple_size<_Tp>::value) {
    if constexpr (_Nm) __os << ' ';
    __os << std::get<_Nm>(__t);
    operator<<<_Os, _Tp, _Nm + 1>(__os, __t);
  }
  return __os;
}

template <class _Os, class _Container,
          typename = decltype(std::begin(std::declval<_Container>()))>
typename std::enable_if<
    !std::is_same<typename std::decay<_Container>::type, std::string>::value &&
        !std::is_same<typename std::decay<_Container>::type, char *>::value,
    ostream_ref<_Os>>::type
operator<<(_Os &__os, const _Container &__cont) {
  bool __h = true;
  for (auto &&__e : __cont) __h ? __h = 0 : (__os << ' ', 0), __os << __e;
  return __os;
}

#ifdef __SIZEOF_INT128__

/**
 * @brief Stream insertion operator for __int128_t.
 *
 * @param __os Output Stream
 * @param __x 128-bit integer
 * @return Reference to __os.
 */
template <class _Os> ostream_ref<_Os> operator<<(_Os &__os, __int128_t __x) {
  if (!__x) return __os << '0';
  if (__x < 0) __os << '-';
  char __s[40], *__p = __s;
  while (__x) {
    auto __d = __x % 10;
    *__p++ = '0' + (__x < 0 ? -__d : __d);
    __x /= 10;
  }
  *__p = 0;
  for (char *__t = __s; __t < --__p; ++__t) *__t ^= *__p ^= *__t ^= *__p;
  return __os << __s;
}

/**
 * @brief Stream insertion operator for __uint128_t.
 *
 * @param __os Output Stream
 * @param __x 128-bit unsigned integer
 * @return Reference to __os.
 */
template <class _Os> ostream_ref<_Os> operator<<(_Os &__os, __uint128_t __x) {
  if (!__x) return __os << '0';
  char __s[40], *__p = __s;
  while (__x) *__p++ = '0' + __x % 10, __x /= 10;
  *__p = 0;
  for (char *__t = __s; __t < --__p; ++__t) *__t ^= *__p ^= *__t ^= *__p;
  return __os << __s;
}

#endif

}  // namespace workspace
#line 10 "Library/lib/utils"
// #include "src/utils/io/read.hpp"
#line 2 "Library/src/utils/io/setup.hpp"

/**
 * @file setup.hpp
 * @brief I/O Setup
 */

#line 10 "Library/src/utils/io/setup.hpp"

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
#line 2 "Library/src/utils/iterator/category.hpp"

/*
 * @file category.hpp
 * @brief Iterator Category
 */

#line 10 "Library/src/utils/iterator/category.hpp"

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
#line 2 "Library/src/utils/iterator/reverse.hpp"

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
#line 2 "Library/src/utils/make_vector.hpp"

/*
 * @file make_vector.hpp
 * @brief Multi-dimensional Vector
 */

#if __cplusplus >= 201703L

#include <tuple>
#include <vector>

namespace workspace {

/*
 * @brief Make a multi-dimensional vector.
 * @tparam Tp type of the elements
 * @tparam N dimension
 * @tparam S integer type
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, size_t N, typename S>
constexpr auto make_vector([[maybe_unused]] S* sizes, Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (N)
    return std::vector(*sizes,
                       make_vector<Tp, N - 1, S>(std::next(sizes), init));
  else
    return init;
}

/*
 * @brief Make a multi-dimensional vector.
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, size_t N, typename S>
constexpr auto make_vector(const S (&sizes)[N], Tp const& init = Tp()) {
  return make_vector<Tp, N, S>((S*)sizes, init);
}

/*
 * @brief Make a multi-dimensional vector.
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, size_t N, typename S, size_t I = 0>
constexpr auto make_vector([[maybe_unused]] std::array<S, N> const& sizes,
                           Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<S, size_t>);
  if constexpr (I == N)
    return init;
  else
    return std::vector(sizes[I], make_vector<Tp, N, S, I + 1>(sizes, init));
}

/*
 * @brief Make a multi-dimensional vector.
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, size_t N = SIZE_MAX, size_t I = 0, class... Args>
constexpr auto make_vector([[maybe_unused]] std::tuple<Args...> const& sizes,
                           Tp const& init = Tp()) {
  using tuple_type = std::tuple<Args...>;
  if constexpr (I == std::tuple_size_v<tuple_type> || I == N)
    return init;
  else {
    static_assert(
        std::is_convertible_v<std::tuple_element_t<I, tuple_type>, size_t>);
    return std::vector(std::get<I>(sizes),
                       make_vector<Tp, N, I + 1>(sizes, init));
  }
}

/*
 * @brief Make a multi-dimensional vector.
 * @param sizes The size of each dimension
 * @param init The initial value
 */
template <typename Tp, class Fst, class Snd>
constexpr auto make_vector(std::pair<Fst, Snd> const& sizes,
                           Tp const& init = Tp()) {
  static_assert(std::is_convertible_v<Fst, size_t>);
  static_assert(std::is_convertible_v<Snd, size_t>);
  return make_vector({(size_t)sizes.first, (size_t)sizes.second}, init);
}

}  // namespace workspace

#endif
#line 15 "Library/lib/utils"
// #include "src/utils/py-like/enumerate.hpp"
#line 2 "Library/src/utils/py-like/range.hpp"

/**
 * @file range.hpp
 * @brief Range
 */

#line 9 "Library/src/utils/py-like/range.hpp"

#line 2 "Library/src/utils/py-like/reversed.hpp"

/**
 * @file reversed.hpp
 * @brief Reversed
 */

#include <initializer_list>
#line 10 "Library/src/utils/py-like/reversed.hpp"

namespace workspace {

namespace internal {

template <class Container> class reversed {
  Container cont;

 public:
  constexpr reversed(Container &&cont) : cont(cont) {}

  constexpr auto begin() { return std::rbegin(cont); }
  constexpr auto end() { return std::rend(cont); }
};

}  // namespace internal

template <class Container> constexpr auto reversed(Container &&cont) noexcept {
  return internal::reversed<Container>{std::forward<Container>(cont)};
}

template <class Tp>
constexpr auto reversed(std::initializer_list<Tp> &&cont) noexcept {
  return internal::reversed<std::initializer_list<Tp>>{
      std::forward<std::initializer_list<Tp>>(cont)};
}

}  // namespace workspace
#line 12 "Library/src/utils/py-like/range.hpp"

#if __cplusplus >= 201703L

namespace workspace {

template <class Index> class range {
  Index first, last;

 public:
  class iterator {
    Index current;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = Index;
    using reference = typename std::add_const<Index>::type &;
    using pointer = iterator;
    using iterator_category = std::bidirectional_iterator_tag;

    constexpr iterator(Index const &__i = Index()) noexcept : current(__i) {}

    constexpr bool operator==(iterator const &rhs) const noexcept {
      return current == rhs.current;
    }
    constexpr bool operator!=(iterator const &rhs) const noexcept {
      return current != rhs.current;
    }

    constexpr iterator &operator++() noexcept {
      ++current;
      return *this;
    }
    constexpr iterator &operator--() noexcept {
      --current;
      return *this;
    }

    constexpr reference operator*() const noexcept { return current; }
  };

  constexpr range(Index first, Index last) noexcept
      : first(first), last(last) {}
  constexpr range(Index last) noexcept : first(), last(last) {}

  constexpr iterator begin() const noexcept { return iterator{first}; }
  constexpr iterator end() const noexcept { return iterator{last}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>(end());
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>(begin());
  }
};

template <class... Args> constexpr auto rrange(Args &&... args) noexcept {
  return internal::reversed(range(std::forward<Args>(args)...));
}

}  // namespace workspace

#endif
#line 18 "Library/lib/utils"
// #include "src/utils/py-like/zip.hpp"
#line 2 "Library/src/utils/rand/rng.hpp"

/**
 * @file rng.hpp
 * @brief Random Number Generator
 */

#line 9 "Library/src/utils/rand/rng.hpp"

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
#line 2 "Library/src/utils/rand/shuffle.hpp"

/**
 * @file shuffle.hpp
 * @brief Shuffle
 */

#line 10 "Library/src/utils/rand/shuffle.hpp"

namespace workspace {

template <class _RAIter, class _Engine = std::mt19937>
void shuffle(_RAIter __first, _RAIter __last) {
  static _Engine __engine(std::random_device{}());
  std::shuffle(__first, __last, __engine);
}

}  // namespace workspace
#line 2 "Library/src/utils/round_div.hpp"

/*
 * @file round_div.hpp
 * @brief Round Integer Division
 */

#line 9 "Library/src/utils/round_div.hpp"

#line 11 "Library/src/utils/round_div.hpp"

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
#line 22 "Library/lib/utils"
// #include "src/utils/sfinae.hpp"
#line 11 "codeforces-workspace/contest/1320/d/d.cpp"

signed main() {
  using namespace workspace;

  io_setup(15);

  /* given
    case_info.read();  //*/

  /* unspecified
    case_info.total = -1;  //*/

  return case_info.iterate();
}

#line 2 "Library/src/data_structure/segment_tree/basic.hpp"

/**
 * @file basic.hpp
 * @brief Segment Tree
 */

#line 10 "Library/src/data_structure/segment_tree/basic.hpp"

#if __cplusplus >= 201703L
#include <optional>
#endif

#line 2 "Library/src/algebra/system/monoid.hpp"

/*
 * @file monoid.hpp
 * @brief Monoid
 */

#line 9 "Library/src/algebra/system/monoid.hpp"

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
#line 16 "Library/src/data_structure/segment_tree/basic.hpp"

namespace workspace {

/**
 * @tparam Monoid `operator+`, `operator=`
 * @tparam Container_tmpl `operator[]`, `size_type`
 */
template <class Monoid, class Endomorphism = void,
          template <class...> class Container_tmpl = std::vector>
class segment_tree {
  static_assert(
      std::is_assignable<Monoid &, decltype(std::declval<Monoid>() +
                                            std::declval<Monoid>())>::value,
      "\'Monoid\' has no proper binary \'operator+\'.");

  constexpr static bool __support_lazy = !std::is_void<Endomorphism>::value;

#if __cplusplus < 201703L
  struct node_base {
    node_base() = default;
    node_base(Monoid const &__x) : __v(__x) {}
    operator bool() const { return __f; }
    void operator=(Monoid const &__x) {
      __v = __x;
      __f = true;
    }
    Monoid &operator*() { return __v; }
    Monoid const &operator*() const { return __v; }
    void reset() { __f = false; }

   private:
    Monoid __v{};
    bool __f{true};
  };
#else
  struct node_base : std::optional<Monoid> {
    using std::optional<Monoid>::operator=;
    node_base() : std::optional<Monoid>(Monoid{}) {}
  };
#endif

  struct node_lazy : node_base {
    using node_base::operator=;
    std::optional<Endomorphism> __z;
  };

  using node =
      typename std::conditional<__support_lazy, node_lazy, node_base>::type;

  using container_type = Container_tmpl<node>;

 public:
  using size_type = typename container_type::size_type;

  class iterator {
    segment_tree *__p;
    size_type __i;

   public:
    using difference_type = typename std::make_signed<size_type>::type;
    using value_type = Monoid;
    using reference = Monoid &;
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

  template <class _End = Endomorphism>
  void apply(node &__nd, _End const &endo) {
    *__nd = *__nd * endo;
    __nd.__z = __nd.__z ? *__nd.__z * endo : endo;
  }

  // template <class _End = Endomorphism>
  // void apply_top(size_t __i, _End const &endo) {
  //   auto &__nd = pull(__i);
  //   *__nd = *__nd * endo;
  //   __nd.__z = __nd.__z ? *__nd.__z * endo : endo;
  // }

  template <class Pred>
  constexpr decltype(std::declval<Pred>()(Monoid{})) pass_args(
      Pred pred, Monoid const &_1, [[maybe_unused]] size_type _2) {
    return pred(_1);
  }

  template <class Pred>
  constexpr decltype(std::declval<Pred>()(Monoid{}, size_type{})) pass_args(
      Pred pred, Monoid const &_1, size_type _2) {
    return pred(_1, _2);
  }

  template <class Pred>
  size_type left_partition_subtree(size_type __i, Monoid mono, size_type step,
                                   Pred pred) {
    assert(__i);
    while (__i < size_ext) {
      if constexpr (__support_lazy) push(__i);
      const Monoid tmp = *pull((__i <<= 1) | 1) + mono;
      if (pass_args(pred, tmp, ((__i | 1) << --step) ^ size_ext))
        mono = tmp;
      else
        ++__i;
    }
    return ++__i -= size_ext;
  }

  template <class Pred>
  size_type right_partition_subtree(size_type __i, Monoid mono, size_type step,
                                    Pred pred) {
    assert(__i);
    while (__i < size_ext) {
      if constexpr (__support_lazy) push(__i);
      const Monoid tmp = mono + *pull(__i <<= 1);
      if (pass_args(pred, tmp, ((__i | 1) << --step) ^ size_ext))
        ++__i, mono = tmp;
    }
    return (__i -= size_ext) < size_orig ? __i : size_orig;
  }

 public:
  /**
   * @brief Construct a new segment tree object
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
   * @brief Construct a new segment tree object
   *
   * @param __n Number of elements.
   * @param init
   */
  segment_tree(size_type __n, Monoid const &init) : segment_tree(__n) {
    for (auto i = begin(); i != end(); ++i) *i = init;
  }

  /**
   * @brief Construct a new segment tree object
   *
   * @tparam Tp
   * @param __n Number of elements.
   * @param init
   */
  template <class Tp, typename std::enable_if<std::is_convertible<
                          Tp, Monoid>::value>::type * = nullptr>
  segment_tree(size_type __n, Tp &&init) : segment_tree(__n) {
    for (auto i = begin(); i != end(); ++i) *i = init;
  }

  /**
   * @brief Construct a new segment tree object
   *
   * @tparam Iterator
   * @param __first
   * @param __last
   */
  template <class Iterator,
            typename std::enable_if<std::is_convertible<
                typename std::iterator_traits<Iterator>::value_type,
                Monoid>::value> * = nullptr>
  segment_tree(Iterator __first, Iterator __last)
      : segment_tree(std::distance(__first, __last)) {
    for (auto i = begin(); __first != __last; ++i, ++__first) *i = *__first;
  }

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

    // if (first >= last) return Monoid{};
    // first += size_ext, last += size_ext - 1;
    // Monoid left{}, right{};
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
  value_type fold() { return fold(0, size_orig); }

  template <class _End = Endomorphism>
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
   * @param pred Predicate in the form of either 'bool(Monoid)' or 'bool(Monoid,
   * size_type)'
   * @return Left end of the extremal interval satisfying the condition,
   * inclusive.
   */
  template <class Pred> size_type left_partition(size_type right, Pred pred) {
    assert(right <= size_orig);
    right += size_ext;

    if constexpr (__support_lazy)
      for (size_t i{height}; i; --i) push(right >> i);

    Monoid mono{};
    for (size_type left{size_ext}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        Monoid tmp = *pull(--right) + mono;
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
   * @param pred Predicate in the form of either 'bool(Monoid)' or 'bool(Monoid,
   * size_type)'
   * @return Right end of the extremal interval satisfying the condition,
   * exclusive.
   */
  template <class Pred> size_type right_partition(size_type left, Pred pred) {
    assert(left <= size_orig);
    left += size_ext;

    if constexpr (__support_lazy)
      for (size_t i{height}; i; --i) push(left >> i);

    Monoid mono{};
    for (size_type right{size_ext << 1}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        Monoid tmp = mono + *pull(left);
        if (!pass_args(pred, tmp, ((left + 1) << step) ^ size_ext))
          return right_partition_subtree(left, mono, step, pred);
        mono = tmp;
        ++left;
      }
    }

    return size_orig;
  }
};

}  // namespace workspace
#line 2 "Library/src/string/rolling_hash.hpp"

/**
 * @file rolling_hash.hpp
 * @brief Rolling Hash
 */

#line 11 "Library/src/string/rolling_hash.hpp"

#line 2 "Library/src/opt/binary_search.hpp"

/**
 * @file binary_search.hpp
 * @brief Binary Search
 */

#line 12 "Library/src/opt/binary_search.hpp"

namespace workspace {

namespace _impl {

template <class _Iter, class _Pred>
_Iter discrete_binary_search(_Iter __first, _Iter __last, _Pred &&__pred,
                             bool __crit) {
  if (__first < __last)
    while (1 < __last - __first) {
      _Iter __mid = __first + ((__last - __first) >> 1);
      (__pred(__mid) == __crit ? __first : __last) = __mid;
    }

  else
    while (1 < __first - __last) {
      _Iter __mid = __last + ((__first - __last) >> 1);
      (__pred(__mid) == __crit ? __first : __last) = __mid;
    }

  return __first;
}

template <class _Real, class _Pred>
_Real continuous_binary_search(_Real __first, _Real __last, _Real __eps,
                               _Pred &&__pred, bool __crit) {
  if (__first < __last)
    for (auto __loop = std::numeric_limits<_Real>::digits;
         __first + __eps < __last && __loop; --__loop) {
      _Real __mid = (__first + __last) / 2;
      (__pred(__mid) == __crit ? __first : __last) = __mid;
    }

  else
    for (auto __loop = std::numeric_limits<_Real>::digits;
         __last + __eps < __first && __loop; --__loop) {
      _Real __mid = (__first + __last) / 2;
      (__pred(__mid) == __crit ? __first : __last) = __mid;
    }

  return __first;
}

}  // namespace _impl

/**
 * @brief Binary search on a discrete range.
 *
 * @param __first Inclusive endpoint
 * @param __last Exclusive endpoint
 * @param __pred Predicate
 * @return Return __x s.t. `__pred(__x) == __pred(__first)` and `__pred(__x) !=
 * __pred(__x +/- 1)`. The sign is `+` iff `__first < __last`.
 */
template <class _Iter, class _Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<_Pred>()(std::declval<_Iter>())),
                        bool>::value,
    _Iter>::type
binary_search(_Iter __first, _Iter __last, _Pred &&__pred) {
  assert(__first != __last);

  return _impl::discrete_binary_search(
      __first, __last, std::forward<_Pred>(__pred), __pred(__first));
}

/**
 * @brief Binary search on the real number line.
 * @param __first __pred(__first) is true
 * @param __last __pred(__last) is false
 * @param eps the error tolerance
 * @param __pred the predicate
 * @return the boundary point
 */
template <class _Real, class _Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<_Pred>()(std::declval<_Real>())),
                        bool>::value,
    _Real>::type
binary_search(_Real __first, _Real __last, _Real __eps, _Pred &&__pred) {
  assert(__first != __last);

  return _impl::continuous_binary_search(
      __first, __last, __eps, std::forward<_Pred>(__pred), __pred(__first));
}

/**
 * @brief Parallel binary search on discrete ranges.
 * @param ends a vector of pairs; __pred(first) is true, __pred(second) is false
 * @param __pred the predicate
 * @return the closest points to (second) where __pred is true
 */
template <class Array,
          class _Iter = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class _Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<_Pred>()(std::declval<std::vector<_Iter>>())[0]),
        bool>::value,
    std::vector<_Iter>>::type
parallel_binary_search(Array ends, _Pred __pred) {
  std::vector<_Iter> mids(std::size(ends));
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const _Iter &__first = std::get<0>(ends[i]);
      const _Iter &__last = std::get<1>(ends[i]);
      const _Iter mid(
          __first + typename std::make_signed<decltype(__last - __first)>::type(
                        __last - __first) /
                        2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    const auto res = __pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}

/**
 * @brief Parallel binary search on the real number line.
 * @param ends a vector of pairs; __pred(first) is true, __pred(second) is false
 * @param eps the error tolerance
 * @param __pred the predicate
 * @return the boundary points
 */
template <class Array,
          class _Real = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class _Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<_Pred>()(std::declval<std::vector<_Real>>())[0]),
        bool>::value,
    std::vector<_Real>>::type
parallel_binary_search(Array ends, const _Real eps, _Pred __pred) {
  std::vector<_Real> mids(std::size(ends));
  for (auto loops = 0; loops != std::numeric_limits<_Real>::digits; ++loops) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const _Real __first = std::get<0>(ends[i]);
      const _Real __last = std::get<1>(ends[i]);
      if (__first + eps < __last || __last + eps < __first) {
        all_found = false;
        mids[i] = (__first + __last) / 2;
      }
    }
    if (all_found) break;
    const auto res = __pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}

}  // namespace workspace
#line 15 "Library/src/string/rolling_hash.hpp"

namespace workspace {

/**
 * @struct rolling_hashed
 * @brief hash data of a string.
 */
struct rolling_hashed {
  using u64 = uint_least64_t;
  using u128 = __uint128_t;

  /**
   * @brief modulus used for hashing.
   */
  constexpr static u64 mod = (1ull << 61) - 1;

  const static u64 base;

  /**
   * @brief hash value.
   */
  u64 value = 0;

  /**
   * @brief length of the string.
   */
  size_t length = 0;

  rolling_hashed() = default;

  /**
   * @brief construct hash data from one character.
   * @param c a character
   */
  template <class char_type, typename std::enable_if<std::is_convertible<
                                 char_type, u64>::value>::type * = nullptr>
  rolling_hashed(char_type c) : value(u64(c) + 1), length(1) {}

  rolling_hashed(u64 value, size_t length) : value(value), length(length) {}

  operator std::pair<u64, size_t>() const { return {value, length}; }

  operator u64() const { return value; }

  /**
   * @return whether or not (*this) and (rhs) are equal
   * @param rhs
   */
  bool operator==(const rolling_hashed &rhs) const {
    return value == rhs.value && length == rhs.length;
  }

  /**
   * @return whether or not (*this) and (rhs) are distinct
   * @param rhs
   */
  bool operator!=(const rolling_hashed &rhs) const { return !operator==(rhs); }

  /**
   * @param rhs the right operand
   * @return hash data of concatenated string
   */
  rolling_hashed operator+(const rolling_hashed &rhs) const {
    return {plus(value, mult(rhs.value, base_pow(length))),
            length + rhs.length};
  }

  /**
   * @param rhs appended to right end
   * @return reference to updated hash data
   */
  rolling_hashed operator+=(const rolling_hashed &rhs) {
    return *this = operator+(rhs);
  }

  /**
   * @param rhs the erased suffix
   * @return hash data of erased string
   */
  rolling_hashed operator-(const rolling_hashed &rhs) const {
    assert(!(length < rhs.length));
    return {minus(value, mult(rhs.value, base_pow(length - rhs.length))),
            length - rhs.length};
  }

  /**
   * @param rhs erased from right end
   * @return reference to updated hash data
   */
  rolling_hashed operator-=(const rolling_hashed &rhs) {
    return *this = operator-(rhs);
  }

  /**
   * @fn base_pow
   * @param exp the exponent
   * @return base ** pow
   */
  static u64 base_pow(size_t exp) {
    static std::vector<u64> pow{1};
    while (pow.size() <= exp) {
      pow.emplace_back(mult(pow.back(), base));
    }
    return pow[exp];
  }

 private:
  static u64 plus(u64 lhs, u64 rhs) {
    return (lhs += rhs) < mod ? lhs : lhs - mod;
  }

  static u64 minus(u64 lhs, u64 rhs) {
    return (lhs -= rhs) < mod ? lhs : lhs + mod;
  }

  static u64 mult(u128 lhs, u64 rhs) {
    lhs *= rhs;
    lhs = (lhs >> 61) + (lhs & mod);
    return lhs < mod ? lhs : lhs - mod;
  }
};

/**
 * @brief base used for hashing
 */
const rolling_hashed::u64 rolling_hashed::base =
    random_number_generator<u64>(1 << 30, mod - 1)();

/**
 * @struct rolling_hash_table
 * @brief make hash data table of suffix.
 */
template <class str_type> struct rolling_hash_table {
  constexpr static size_t npos = -1;

  rolling_hash_table() = default;

  rolling_hash_table(str_type str) {
    std::reverse(std::begin(str), std::end(str));
    for (auto &&c : str) suffix.emplace_back(rolling_hashed{c} + suffix.back());
    std::reverse(suffix.begin(), suffix.end());
  }

  template <class Tp, typename = typename std::enable_if<
                          std::is_convertible<rolling_hashed, Tp>::value>::type>
  operator Tp() const {
    return substr();
  }

  operator rolling_hashed() const { return substr(); }

  /**
   * @return length of the string
   */
  size_t size() const { return suffix.size() - 1; }

  /**
   * @param pos start position
   * @param n length of the substring
   * @return hash data of the substring
   */
  rolling_hashed substr(size_t pos = 0, size_t n = npos) const {
    assert(!(size() < pos));
    return suffix[pos] - suffix[pos + std::min(n, size() - pos)];
  }

  /**
   * @param rhs
   * @return length of the longest common prefix
   */
  size_t lcp(rolling_hash_table const &rhs) const {
    auto n = std::min(size(), rhs.size());
    return binary_search<size_t>(
        0, n + 1, [&](size_t l) { return substr(0, l) == rhs.substr(0, l); });
  }

 private:
  std::vector<rolling_hashed> suffix{{}};
};

}  // namespace workspace
#line 28 "codeforces-workspace/contest/1320/d/d.cpp"

namespace workspace {

void main() {
  // start here!

  int n;
  string s;
  cin >> n >> s;
  random_number_generator<u32> rng;
  u32 subs[] = {998244353, 100007};

  vector<int> acz;  // '0' in [0, i)
  vector<int> zpos;
  vector<int> ones;  // parity
  {
    int run = 0;
    acz.emplace_back(0);
    int idx = 0;
    for (auto &&c : s) {
      if (c == '0') {
        ones.emplace_back(subs[run]);
        run = 0;
        zpos.emplace_back(idx);
      } else
        run ^= 1;
      acz.emplace_back(acz.back() + '1' - c);
      ++idx;
    }
    ones.emplace_back(subs[run]);
  }

  segment_tree<rolling_hashed> sgt(begin(ones), end(ones));

  int q;
  cin >> q;
  while (q--) {
    int i1, i2, len;
    cin >> i1 >> i2 >> len;
    --i1, --i2;
    vector<rolling_hashed> tmp;

    for (auto i : {i1, i2}) {
      auto zl = acz[i];
      auto zr = acz[i + len];
      if (zl != zr) {
        rolling_hashed lft = subs[(zpos[zl] - i) % 2];
        auto mid = sgt.fold(zl + 1, zr);
        rolling_hashed rgt = subs[(i + len - 1 - zpos[zr - 1]) % 2];
        tmp.emplace_back(lft + mid + rgt);
      } else {
        rolling_hashed h = subs[len % 2];
        tmp.emplace_back(h);
      }
    }

    if (tmp[0] == tmp[1]) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}

}  // namespace workspace