#line 1 "codeforces-workspace\\contest\\1408\\g\\g.cpp"
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

#else

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

  if
    _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_u) {
      constexpr int __diff = _Nd_u - _Nd;
      return __builtin_clz(__x) - __diff;
    }
  else if
    _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_ul) {
      constexpr int __diff = _Nd_ul - _Nd;
      return __builtin_clzl(__x) - __diff;
    }
  else if
    _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_ull) {
      constexpr int __diff = _Nd_ull - _Nd;
      return __builtin_clzll(__x) - __diff;
    }
  else  // (_Nd > _Nd_ull)
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

  if
    _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_u)
  return __builtin_ctz(__x);
  else if _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_ul) return __builtin_ctzl(__x);
  else if _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_ull) return __builtin_ctzll(__x);
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

  if
    _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_u)
  return __builtin_popcount(__x);
  else if _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_ul) return __builtin_popcountl(__x);
  else if _GLIBCXX17_CONSTEXPR(_Nd <= _Nd_ull) return __builtin_popcountll(__x);
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
  if
    _GLIBCXX17_CONSTEXPR(!is_same<__promoted_type, _Tp>::value) {
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

template <typename _Tp> constexpr _Tp __bsf(_Tp __x) noexcept {
  return std::__countr_zero(__x);
}

template <typename _Tp> constexpr _Tp __bsr(_Tp __x) noexcept {
  return std::__bit_width(__x) - 1;
}

}  // namespace workspace
#line 6 "codeforces-workspace\\contest\\1408\\g\\g.cpp"
// #include "lib/cxx20"
#line 1 "Library\\lib\\direct"
#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("unroll-loops")
#endif
#line 8 "codeforces-workspace\\contest\\1408\\g\\g.cpp"
// #include "lib/opt"
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

/*
 * @fn clock.hpp
 * @brief Clock
 */

#line 9 "Library\\src\\sys\\clock.hpp"

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
#line 10 "codeforces-workspace\\contest\\1408\\g\\g.cpp"
// #include "lib/utils"

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
#line 13 "codeforces-workspace\\contest\\1408\\g\\g.cpp"

signed main() {
  using namespace workspace;

  io_setup(15);

  /* given
    case_info.read();  //*/

  /* unspecified
    case_info.total = -1;  //*/

  return case_info.iterate();
}

#line 2 "Library\\src\\algebra\\polynomial.hpp"

/**
 * @file polynomial.hpp
 * @brief Polynomial
 */

#line 11 "Library\\src\\algebra\\polynomial.hpp"

#line 2 "Library\\src\\algebra\\ntt.hpp"

/**
 * @file ntt.hpp
 * @brief Number Theoretic Transform
 * @date 2021-02-20
 *
 *
 */

#line 2 "Library\\src\\number_theory\\ext_gcd.hpp"

/**
 * @file ext_gcd.hpp
 * @brief Extended Euclidean Algorithm
 */

#line 9 "Library\\src\\number_theory\\ext_gcd.hpp"

#line 2 "Library\\src\\utils\\sfinae.hpp"

/**
 * @file sfinae.hpp
 * @brief SFINAE
 */

#line 10 "Library\\src\\utils\\sfinae.hpp"
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
#line 11 "Library\\src\\number_theory\\ext_gcd.hpp"

namespace workspace {

/**
 * @param __a Integer
 * @param __b Integer
 * @return Pair of integers (x, y) s.t. ax + by = g = gcd(a, b), 0 <= x <
 * |b/g|, -|a/g| < y <= 0. Return (0, 0) if (a, b) = (0, 0).
 */
template <typename _T1, typename _T2> constexpr auto ext_gcd(_T1 __a, _T2 __b) {
  static_assert(is_integral_ext<_T1>::value);
  static_assert(is_integral_ext<_T2>::value);

  using result_type = typename std::make_signed<
      typename std::common_type<_T1, _T2>::type>::type;

  result_type a{__a}, b{__b}, p{1}, q{}, r{}, s{1};

  // Euclidean algorithm
  while (b) {
    result_type t = a / b;
    r ^= p ^= r ^= p -= t * r;
    s ^= q ^= s ^= q -= t * s;
    b ^= a ^= b ^= a -= t * b;
  }

  // Normalize
  if (a < 0) p = -p, q = -q;
  if (p < 0) p += __b / a, q -= __a / a;

  return std::make_pair(p, q);
}

}  // namespace workspace
#line 2 "Library\\src\\number_theory\\primitive_root.hpp"

/**
 * @file primitive_root.hpp
 * @brief Primitive Root
 * @date 2020-12-28
 */

#line 10 "Library\\src\\number_theory\\primitive_root.hpp"

namespace workspace {

/**
 * @brief Compile time primitive root.
 *
 * @tparam __mod Positive integer
 * @return Minimum positive one if it exists. Otherwise 0.
 */
template <class Tp>
constexpr typename std::enable_if<(is_integral_ext<Tp>::value), Tp>::type
primitive_root(const Tp __mod) noexcept {
  assert(__mod > 0);
  using int_type = typename multiplicable_uint<Tp>::type;

  int_type __r = __mod, __p[16] = {}, *__q = __p;
  for (int_type __i = 2; __i <= __r / __i; ++__i) {
    if (__r % __i) continue;
    *__q++ = __i;
    while (!(__r % __i)) __r /= __i;
  }
  if (__r != 1) *__q++ = __r;

  int_type __tot = __mod;
  for (__q = __p; *__q; *__q++ = 0) (__tot /= *__q) *= *__q - 1;
  __r = __tot, __q = __p + 1, __p[0] = 1;
  for (int_type __i = 2; __i <= __r / __i; ++__i) {
    if (__r % __i) continue;
    *__q++ = __i;
    while (!(__r % __i)) __r /= __i;
  }
  if (__r != 1) *__q++ = __r;

  for (Tp __r = 1; __r != __mod; ++__r) {
    auto __cnt = 0;
    for (__q = __p; *__q; ++__q) {
      int_type __w = 1;
      for (int_type __e = __tot / *__q, __x = __r; __e;
           __e >>= 1, (__x *= __x) %= __mod)
        if (__e & 1) (__w *= __x) %= __mod;
      if (__w == 1 && ++__cnt > 1) break;
    }
    if (__cnt == 1) return __r;
  }

  return 0;
};

}  // namespace workspace
#line 13 "Library\\src\\algebra\\ntt.hpp"

namespace workspace {

namespace ntt_impl {

/**
 * @see
 * https://github.com/atcoder/ac-library/blob/master/atcoder/convolution.hpp
 */

template <class _Tp> struct __coef {
  _Tp sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]

  constexpr __coef() : sum_e{} {
    if (_Tp::mod < 2) return;

    int cnt2 = __builtin_ctz(_Tp::mod - 1);
    _Tp e = 1;
    {
      auto p = (_Tp::mod - 1) >> cnt2;
      _Tp w = primitive_root(_Tp::mod);
      while (p) {
        if (p & 1) e *= w;
        p >>= 1;
        w *= w;
      }
    }

    _Tp ie = ext_gcd(decltype(_Tp::mod)(e), _Tp::mod).first;
    _Tp es[30] = {}, ies[30] = {};  // es[i]^(2^(2+i)) == 1
    for (int i = cnt2; i >= 2; i--) {
      // e^(2^i) == 1
      es[i - 2] = e;
      ies[i - 2] = ie;
      e *= e;
      ie *= ie;
    }

    _Tp now = 1;
    for (int i = 0; i <= cnt2 - 2; i++) {
      sum_e[i] = es[i] * now;
      now *= ies[i];
    }
  }
};

template <class _Tp> struct __icoef {
  _Tp sum_ie[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]

  constexpr __icoef() : sum_ie{} {
    if (_Tp::mod < 2) return;

    int cnt2 = __builtin_ctz(_Tp::mod - 1);
    _Tp e = 1;
    {
      auto p = (_Tp::mod - 1) >> cnt2;
      _Tp w = primitive_root(_Tp::mod);
      while (p) {
        if (p & 1) e *= w;
        p >>= 1;
        w *= w;
      }
    }

    _Tp ie = ext_gcd(decltype(_Tp::mod)(e), _Tp::mod).first;
    _Tp es[30] = {}, ies[30] = {};  // es[i]^(2^(2+i)) == 1
    for (int i = cnt2; i >= 2; i--) {
      // e^(2^i) == 1
      es[i - 2] = e;
      ies[i - 2] = ie;
      e *= e;
      ie *= ie;
    }

    _Tp now = 1;
    for (int i = 0; i <= cnt2 - 2; i++) {
      sum_ie[i] = ies[i] * now;
      now *= es[i];
    }
  }
};

template <class _Tp> struct __ipow2 {
  _Tp __ip2[30];
  constexpr __ipow2() : __ip2{1, (1 + _Tp::mod) / 2} {
    for (size_t __i = 1; __i + 1 != std::size(__ip2); ++__i)
      __ip2[__i + 1] = __ip2[__i] * __ip2[1];
  }
};

template <class _FIter>
constexpr void ntt(_FIter __first, _FIter __last) noexcept {
  using value_type = typename std::decay<decltype(*__first)>::type;
  constexpr __coef<value_type> _;

  auto __h = __builtin_ctz(std::distance(__first, __last));

  for (ptrdiff_t __p = 1 << __h; __p >>= 1;) {
    value_type now = -1;
    auto __l = __first;

    for (size_t __s = 1 << __h; __l != __last;
         now *= _.sum_e[__builtin_ctz(--__s)]) {
      auto __r = __l + __p;

      for (auto __mid = __r; __l != __mid; ++__l, ++__r) {
        auto __tmp = *__l;
        *__l -= *__r *= now;
        *__r += __tmp;
      }

      __l = __r;
    }
  }
}

template <class _A> constexpr void ntt(_A &a) noexcept {
  ntt(std::begin(a), std::end(a));
}

template <class _FIter>
constexpr void intt(_FIter __first, _FIter __last) noexcept {
  using value_type = typename std::decay<decltype(*__first)>::type;
  constexpr __icoef<value_type> _;

  auto __h = __builtin_ctz(std::distance(__first, __last));

  for (ptrdiff_t __p = 1; __p >> __h ^ 1; __p <<= 1) {
    value_type inow = 1;
    auto __l = __first;

    for (size_t __s = 1 << __h; __l != __last;
         inow *= _.sum_ie[__builtin_ctz(--__s)]) {
      auto __r = __l + __p;

      for (auto __mid = __r; __l != __mid; ++__l, ++__r) {
        auto __tmp = (*__l - *__r) * inow;
        *__l += *__r;
        *__r = __tmp;
      }

      __l = __r;
    }
  }

  constexpr __ipow2<value_type> __;
  while (__first != __last) *--__last *= __.__ip2[__h];
}  // namespace ntt_impl

template <class _A> constexpr void intt(_A &a) noexcept {
  intt(std::begin(a), std::end(a));
}

}  // namespace ntt_impl

using ntt_impl::intt;
using ntt_impl::ntt;

}  // namespace workspace
#line 14 "Library\\src\\algebra\\polynomial.hpp"

namespace workspace {

/**
 * @brief Polynomial.
 *
 * @tparam _Tp Ring structure
 * @tparam _Conv_threshold Threshold for convolution method
 */
template <class _Tp, std::size_t _Conv_threshold = 64>
class polynomial : public std::vector<_Tp> {
  using vec = std::vector<_Tp>;
  using poly = polynomial;

 public:
  using vec::vec;
  using size_type = typename vec::size_type;

 protected:
  void _erase_leading_zeros() noexcept {
    auto __i = vec::_M_impl._M_finish;
    while (__i != vec::_M_impl._M_start && *(__i - 1) == _Tp(0)) --__i;
    vec::_M_erase_at_end(__i);
  }

  template <class _Iter> void _dft(_Iter __first, _Iter __last) const noexcept {
    if constexpr (has_mod<_Tp>::value)
      ntt(__first, __last);
    else {
      // fft(__first, __last);
      assert(0);  // Not implemented!
    }
  }

  template <class _Iter>
  void _idft(_Iter __first, _Iter __last) const noexcept {
    if constexpr (has_mod<_Tp>::value)
      intt(__first, __last);
    else {
      // ifft(__first, __last);
      assert(0);  // Not implemented!
    }
  }

  void _conv_naive(const poly& __x) noexcept {
    if (vec::_M_impl._M_start == vec::_M_impl._M_finish) return;

    if (__x._M_impl._M_start == __x._M_impl._M_finish) {
      vec::_M_erase_at_end(vec::_M_impl._M_start);
      return;
    }

    vec::_M_default_append(__x._M_impl._M_finish - __x._M_impl._M_start - 1);

    for (auto __i = vec::_M_impl._M_finish; __i-- != vec::_M_impl._M_start;) {
      auto __j = __i, __k = __x._M_impl._M_start;
      *__i *= *__k++;

      while (__j != vec::_M_impl._M_start && __k != __x._M_impl._M_finish)
        *__i += *--__j * *__k++;
    }
  }

  void _conv_dft(poly&& __x) noexcept {
    if constexpr (has_mod<_Tp>::value)
      _conv_ntt(std::move(__x));
    else {
      // _conv_fft(std::move(__x));
      assert(0);  // Not implemented!
    }
  }

  void _conv_fft(poly&& __x) noexcept;

  void _conv_ntt(poly&& __x) noexcept {
    size_type __n = vec::_M_impl._M_finish - vec::_M_impl._M_start,
              __m = __x._M_impl._M_finish - __x._M_impl._M_start,
              __len = 1 << (32 - __builtin_clz(__n + __m - 1));

    vec::_M_default_append(__len - __n);
    __x._M_default_append(__len - __m);

    ntt(vec::_M_impl._M_start, vec::_M_impl._M_finish);
    ntt(__x._M_impl._M_start, __x._M_impl._M_finish);

    for (auto __i = vec::_M_impl._M_start, __j = __x._M_impl._M_start;
         __i != vec::_M_impl._M_finish; ++__i, ++__j)
      *__i *= std::move(*__j);

    intt(vec::_M_impl._M_start, vec::_M_impl._M_finish);

    vec::_M_erase_at_end(vec::_M_impl._M_start + __n + __m - 1);
  }

  /**
   * @brief
   *
   * @param __x
   * @return Degree of __x.
   */
  size_type _divmod_naive(const poly& __x) {
    auto __xfin = __x._M_impl._M_finish;
    auto __xlen = __x.size();
    while (__xfin != __x._M_impl._M_start && *(__xfin - 1) == _Tp(0))
      --__xfin, --__xlen;

    assert(__xlen != 0);
    _erase_leading_zeros();

    auto __p = vec::_M_impl._M_finish;

    while (size_type(__p - vec::_M_impl._M_start) >= __xlen) {
      --__p;

      auto __src = __xfin;
      auto __dst = __p;

      *__dst /= *--__src;
      while (__src != __x._M_impl._M_start) *--__dst -= *--__src * *__p;
    }

    return std::min<size_type>(__xlen - 1, __p - vec::_M_impl._M_start);
  }

  void _div_naive(const poly& __x) { operator>>=(_divmod_naive(__x)); }

  void _div_doubling(poly&& __x) noexcept {
    _erase_leading_zeros();
    __x._erase_leading_zeros();

    auto __n = vec::_M_impl._M_finish - vec::_M_impl._M_start;
    auto __m = __x._M_impl._M_finish - __x._M_impl._M_start;

    if (__n < __m)
      vec::clear();
    else {
      assert(__m != 0);

      std::reverse(__x._M_impl._M_start, __x._M_impl._M_finish);
      __x = __x.inv(__n - __m + 1);

      std::reverse(vec::_M_impl._M_start, vec::_M_impl._M_finish);
      vec::_M_erase_at_end(vec::_M_impl._M_finish - (__m - 1));

      operator*=(__x).resize(__n - __m + 1);
      std::reverse(vec::_M_impl._M_start, vec::_M_impl._M_finish);
    }
  }

 public:
  /**
   * @return Degree of %polynomial. Return -1 if it equals zero.
   */
  size_type deg() const noexcept { return vec::size() - 1; }

  /**
   * @param __i Not exceeding the degree.
   * @return Coefficient of x^i.
   */
  typename vec::reference operator[](size_type __i) noexcept {
    assert(__i < vec::size());
    return *(vec::_M_impl._M_start + __i);
  }

  /**
   * @param __i Not exceeding the degree.
   * @return Coefficient of x^i.
   */
  typename vec::const_reference operator[](size_type __i) const noexcept {
    assert(__i < vec::size());
    return *(vec::_M_impl._M_start + __i);
  }

  /**
   * @brief Evaluate at given point.
   */
  _Tp eval(const _Tp& __a) const noexcept {
    _Tp __v(0), __p(1);

    for (auto __i = vec::_M_impl._M_start; __i != vec::_M_impl._M_finish;
         ++__i, __p *= __a)
      __v += *__i * __p;

    return __v;
  }

  /**
   * @brief In-place multipoint evaluation.
   */
  template <class _Iter, typename = std::_RequireInputIter<_Iter>>
  _Iter eval(_Iter __first, _Iter __last) const noexcept {
    return eval(__first, __last, __first);
  }

  /**
   * @brief Multipoint evaluation.
   */
  template <class _InputIter, class _OutputIter,
            typename = std::_RequireInputIter<_InputIter>>
  _OutputIter eval(_InputIter __first, _InputIter __last,
                   _OutputIter __result) const noexcept {
    size_type __n = std::distance(__first, __last);
    if (!__n) return __result;

    auto __tree = new poly[__n << 1];

    for (auto __p = __tree + __n; __first != __last; ++__p, ++__first)
      *__p = {-*__first, 1};

    for (size_type __i = __n; --__i;)
      __tree[__i] = __tree[__i << 1] * __tree[__i << 1 | 1];

    __tree[1] = operator%(std::move(__tree[1]));

    for (size_type __i = 2; __i != __n << 1; __i += 2)
      __tree[__i] = __tree[__i >> 1] % std::move(__tree[__i]),
      __tree[__i | 1] =
          std::move(__tree[__i >> 1] %= std::move(__tree[__i | 1]));

    for (size_type __i = 0; __i != __n; ++__i)
      *__result++ = std::move(*__tree[__n + __i]._M_impl._M_start);

    delete[] __tree;

    return __result;
  }

  /**
   * @brief Conversion to bool.
   *
   * @return Whether the %polynomial is not zero.
   */
  operator bool() const noexcept {
    auto __first = vec::_M_impl._M_start, __last = vec::_M_impl._M_finish;

    while (__first != __last)
      if (*__first++ != _Tp(0)) return true;

    return false;
  }

  bool operator==(const poly& __x) const noexcept {
    auto __first1 = vec::_M_impl._M_start, __last1 = vec::_M_impl._M_finish;

    auto __first2 = __x._M_impl._M_start, __last2 = __x._M_impl._M_finish;

    if (__last1 - __first1 < __last2 - __first2) {
      while (__first1 != __last1)
        if (*__first1++ != *__first2++) return false;

      while (__first2 != __last2)
        if (*__first2++ != _Tp(0)) return false;
    }

    else {
      while (__first2 != __last2)
        if (*__first1++ != *__first2++) return false;

      while (__first1 != __last1)
        if (*__first1++ != _Tp(0)) return false;
    }

    return true;
  }

  bool operator!=(const poly& __x) const noexcept { return !operator==(__x); }

  /**
   * @brief Multiply by x^i.
   */
  poly& operator<<=(size_type __i) noexcept {
    vec::insert(vec::begin(), __i, _Tp(0));
    return *this;
  }

  /**
   * @brief Divide by x^i.
   */
  poly& operator>>=(size_type __i) noexcept {
    vec::_M_erase_at_end(
        std::move(vec::_M_impl._M_start + std::min(__i, vec::size()),
                  vec::_M_impl._M_finish, vec::_M_impl._M_start));

    return *this;
  }

  /**
   * @brief Multiply by x^i.
   */
  poly operator<<(size_type __i) const noexcept {
    return poly(*this).operator<<=(__i);
  }

  /**
   * @brief Divide by x^i.
   */
  poly operator>>(size_type __i) const noexcept {
    return poly(*this).operator>>=(__i);
  }

  poly operator+() const noexcept { return *this; }

  poly operator-() const noexcept {
    poly __x = *this;
    for (auto __i = __x._M_impl._M_start; __i != __x._M_impl._M_finish; ++__i)
      *__i = -*__i;
    return __x;
  }

  poly& operator+=(const poly& __x) noexcept {
    if (vec::size() < __x.size())
      vec::_M_default_append(__x.size() - vec::size());

    for (auto __i = vec::_M_impl._M_start, __j = __x._M_impl._M_start;
         __j != __x._M_impl._M_finish; ++__i, ++__j)
      *__i += *__j;

    _erase_leading_zeros();
    return *this;
  }

  poly& operator+=(const _Tp& __c) noexcept {
    if (__c != static_cast<_Tp>(0)) {
      if (vec::_M_impl._M_start == vec::_M_impl._M_finish)
        vec::emplace_back(__c);
      else
        *vec::_M_impl._M_start += __c, _erase_leading_zeros();
    }

    return *this;
  }

  poly& operator-=(const poly& __x) noexcept {
    if (vec::size() < __x.size())
      vec::_M_default_append(__x.size() - vec::size());

    for (auto __i = vec::_M_impl._M_start, __j = __x._M_impl._M_start;
         __j != __x._M_impl._M_finish; ++__i, ++__j)
      *__i -= *__j;

    _erase_leading_zeros();
    return *this;
  }

  poly& operator-=(const _Tp& __c) noexcept {
    if (__c != static_cast<_Tp>(0)) {
      if (vec::_M_impl._M_start == vec::_M_impl._M_finish)
        vec::emplace_back(-__c);
      else
        *vec::_M_impl._M_start -= __c, _erase_leading_zeros();
    }

    return *this;
  }

  poly& operator*=(const poly& __x) noexcept {
    std::min(vec::size(), __x.size()) > _Conv_threshold
        ? _conv_dft(poly(__x))
        : _conv_naive(this == std::addressof(__x) ? poly(__x) : __x);

    return *this;
  }

  poly& operator*=(poly&& __x) noexcept {
    std::min(vec::size(), __x.size()) > _Conv_threshold
        ? _conv_dft(std::move(__x))
        : _conv_naive(__x);

    return *this;
  }

  poly& operator*=(const _Tp& __c) noexcept {
    if (__c == static_cast<_Tp>(0))
      vec::_M_erase_at_end(vec::_M_impl._M_start);
    else
      for (auto __i = vec::_M_impl._M_start; __i != vec::_M_impl._M_finish;
           ++__i)
        *__i *= __c;

    return *this;
  }

  poly& operator/=(const _Tp& __c) noexcept {
    assert(__c != static_cast<_Tp>(0));

    for (auto __i = vec::_M_impl._M_start; __i != vec::_M_impl._M_finish; ++__i)
      *__i /= __c;

    return *this;
  }

  poly rev() const noexcept { return rev(vec::size()); }

  poly rev(size_type __n) const noexcept {
    poly __r(__n);

    auto __src = vec::_M_impl._M_start;
    auto __dst = __r._M_impl._M_finish;
    for (size_type __i = std::min(__n, vec::size()); __i; --__i)
      *--__dst = *__src++;

    return __r;
  }

  poly inv() const noexcept { return inv(vec::size()); }

  /**
   * @brief Multiplicative inverse modulo x^n.
   *
   * @param __n Degree of modulus
   * @return
   */
  poly inv(size_type __n) const noexcept {
    if (!__n) return {};
    assert(*vec::_M_impl._M_start != _Tp(0));

    size_type __len = 1;
    while (__len < __n) __len <<= 1;

    poly __y(__len);
    auto __xp = new _Tp[__len], __yp = __y._M_impl._M_start,
         __zp = new _Tp[__len];

    *__yp = _Tp(1) / *vec::_M_impl._M_start;

    for (size_type __i = 1; __i != __len; __i <<= 1) {
      std::fill(std::copy_n(__yp, __i, __zp), __zp + (__i << 1), _Tp(0));

      _dft(__zp, __zp + (__i << 1));

      std::fill(std::copy_n(vec::_M_impl._M_start,
                            std::min(__i << 1, vec::size()), __xp),
                __xp + (__i << 1), _Tp(0));

      _dft(__xp, __xp + (__i << 1));

      for (size_type __j = 0; __j != (__i << 1); ++__j) __xp[__j] *= -__zp[__j];

      _idft(__xp, __xp + (__i << 1));

      std::fill(std::move(__xp + __i, __xp + (__i << 1), __xp),
                __xp + (__i << 1), _Tp(0));

      _dft(__xp, __xp + (__i << 1));

      for (size_type __j = 0; __j != (__i << 1); ++__j)
        __xp[__j] *= static_cast<_Tp&&>(__zp[__j]);

      _idft(__xp, __xp + (__i << 1));

      std::move(__xp, __xp + __i, __yp + __i);
    }

    delete[] __xp;
    delete[] __zp;

    __y._M_erase_at_end(__yp + __n);
    return __y;
  }

  poly& operator/=(const poly& __x) noexcept {
    if (__x.size() > _Conv_threshold)
      _div_doubling(poly(__x));
    else
      _div_naive(__x);

    return *this;
  }

  poly& operator/=(poly&& __x) noexcept {
    if (__x.size() > _Conv_threshold)
      _div_doubling(std::move(__x));
    else
      _div_naive(__x);

    return *this;
  }

  poly& operator%=(const poly& __x) noexcept {
    if (__x.size() > _Conv_threshold)
      return operator-=(__x.operator*(operator/(__x)));

    vec::_M_erase_at_end(vec::_M_impl._M_start + _divmod_naive(__x));
    return *this;
  }

  template <class _T> poly operator+(_T&& __x) const noexcept {
    return poly(*this).operator+=(std::forward<_T>(__x));
  }

  template <class _T> poly operator-(_T&& __x) const noexcept {
    return poly(*this).operator-=(std::forward<_T>(__x));
  }

  template <class _T> poly operator*(_T&& __x) const noexcept {
    return poly(*this).operator*=(std::forward<_T>(__x));
  }

  template <class _T> poly operator/(_T&& __x) const noexcept {
    return poly(*this).operator/=(std::forward<_T>(__x));
  }

  template <class _T> poly operator%(_T&& __x) const noexcept {
    return poly(*this).operator%=(std::forward<_T>(__x));
  }

  std::pair<poly, poly> divmod(const poly& __x) const {
    if (__x.size() > _Conv_threshold) return {operator/(__x), operator%(__x)};

    poly __rem(*this);
    auto __p = __rem._M_impl._M_start + __rem._divmod_naive(__x);

    poly __quot(__p, __rem._M_impl._M_finish);
    __rem._M_erase_at_end(__p);

    return {__quot, __rem};
  }

  /**
   * @brief Differentiate.
   *
   * @return Derivative.
   */
  poly deriv() const noexcept {
    if (auto __s = vec::_M_impl._M_start, __f = vec::_M_impl._M_finish;
        __s != __f) {
      poly __der(++__s, __f);

      __s = __der._M_impl._M_start, __f = __der._M_impl._M_finish;
      for (_Tp __i(1); __s != __f; ++__s, __i += 1) *__s *= __i;

      __der._erase_leading_zeros();
      return __der;
    }

    return {};
  }

  /**
   * @brief Differentiate at given point.
   *
   * @return Derivative coefficient.
   */
  _Tp deriv(const _Tp& __a) const noexcept {
    _Tp __der(0);

    if (auto __s = vec::_M_impl._M_start, __f = vec::_M_impl._M_finish;
        __s != __f)
      for (_Tp __i(1), __p(1); ++__s != __f; __i += 1, __p *= __a)
        __der += *__s * __i * __p;

    return __der;
  }

  /**
   * @brief Integrate.
   *
   * @return Integral indefinite at the degrees divisible by the characteristic
   * of `_Tp`. Coefficients are set as 0 there.
   */
  poly integ() const noexcept {
    if (auto __s = vec::_M_impl._M_start, __f = vec::_M_impl._M_finish;
        __s != __f) {
      poly __int(__f - __s + 1);

      __f = std::copy(__s, __f, __int._M_impl._M_start + 1);
      __s = __int._M_impl._M_start + 1;
      for (_Tp __i(1); __s != __f; ++__s, __i += 1)
        __i == _Tp(0) ? assert(*__s == _Tp(0)) : void(*__s /= __i);

      return __int;
    }

    return {};
  }

  /**
   * @brief Integrate in given range.
   *
   * @return Definite integral over [0, __a].
   */
  _Tp integ(const _Tp& __a) const noexcept {
    _Tp __int(0);

    auto __s = vec::_M_impl._M_start, __f = vec::_M_impl._M_finish;
    for (_Tp __p(__a), __i(1); __s != __f; ++__s, __p *= __a, __i += 1)
      __int += *__s / __i * __p;

    return __int;
  }

  /**
   * @brief Integrate in given range.
   *
   * @return Definite integral over [__a, __b].
   */
  _Tp integ(const _Tp& __a, const _Tp& __b) const noexcept {
    _Tp __int(0);

    auto __s = vec::_M_impl._M_start, __f = vec::_M_impl._M_finish;
    for (_Tp __pa(__a), __pb(__b), __i(1); __s != __f;
         ++__s, __pa *= __a, __pb *= __b, __i += 1)
      __int += *__s / __i * (__pb - __pa);

    return __int;
  }
};

/**
 * @brief Polynomial interpolation in O(n log(n)^2) time.
 *
 * @param __first
 * @param __last
 * @return
 */
template <class _InputIter, typename = std::_RequireInputIter<_InputIter>>
auto interpolate(_InputIter __first, _InputIter __last) {
  size_t __n = std::distance(__first, __last);

  auto [__1, __2] =
      typename std::iterator_traits<decltype(__first)>::value_type{};

  using poly = polynomial<decltype(__1)>;

  if (!__n) return poly{};

  struct node {
    poly __all, __lack;
  };

  auto __tree = new node[__n << 1];
  auto __iter = __first;

  for (size_t __i = 0; __i != __n; ++__i) {
    auto&& [__a, __b] = *__iter++;
    __tree[__i + __n].__all = {-__a, 1}, __tree[__i + __n].__lack = {1};
  }

  for (size_t __i = __n; --__i;)
    __tree[__i].__all = __tree[__i << 1].__all * __tree[__i << 1 | 1].__all,
    __tree[__i].__lack =
        __tree[__i << 1].__all * std::move(__tree[__i << 1 | 1].__lack) +
        __tree[__i << 1 | 1].__all * std::move(__tree[__i << 1].__lack);

  for (size_t __i = 2; __i != __n << 1; __i += 2)
    __tree[__i].__lack = __tree[__i >> 1].__lack % __tree[__i].__all,
    __tree[__i | 1].__lack =
        std::move(__tree[__i >> 1].__lack %= __tree[__i | 1].__all);

  for (size_t __i = 0; __i != __n; ++__i) {
    auto&& [__a, __b] = *__first++;
    __tree[__i + __n].__lack[0] =
        std::move(__b) / std::move(__tree[__i + __n].__lack[0]);
  }

  for (size_t __i = __n; --__i;)
    __tree[__i].__lack = std::move(__tree[__i << 1].__all) *
                             std::move(__tree[__i << 1 | 1].__lack) +
                         std::move(__tree[__i << 1 | 1].__all) *
                             std::move(__tree[__i << 1].__lack);

  auto __result = std::move(__tree[1].__lack);

  delete[] __tree;

  return __result;
}

// /**
//  * @brief \\prod_{i=0}^{n-1} (x+i) \\bmod x^d.
//  */
// template <class _Tp> auto rising_factorial(_Tp __n, std::size_t __d) {}

// /**
//  * @brief \\prod_{i=0}^{n-1} (x+i).
//  */
// template <class _Tp> auto rising_factorial(_Tp __n) {
//   return rising_factorial(__n, __n);
// }

// /**
//  * @brief \\prod_{i=0}^{n-1} (x-i) \\bmod x^d.
//  */
// template <class _Tp> auto falling_factorial(_Tp __n, std::size_t __d) {
//   auto __f = rising_factorial(__n, __d);
//   for (std::size_t __i = (__n & 1) ^ 1; __i < __d; __i += 2)
//     __f[__i] = -__f[__i];
//   return __f;
// }

// /**
//  * @brief \\prod_{i=0}^{n-1} (x-i).
//  */
// template <class _Tp> auto falling_factorial(_Tp __n) {
//   return falling_factorial(__n, __n);
// }

/**
 * @brief \\sum_{j=0}^{d-1} x^j \\sum_{i=0}^{n-1} i^j.
 */
template <class _Tp> auto power_sums(_Tp __n, std::size_t __d) {
  using return_type = polynomial<_Tp>;
  if (!__d) return return_type{};
  return_type __f(__d), __e(__d);
  __f[0] = __n;
  for (std::size_t __i = 1; __i != __d; ++__i) __f[__i] = __f[__i - 1] * __n;
  _Tp __c{1};
  for (std::size_t __i = 0; __i != __d; ++__i)
    __c /= __i + 1, __f[__i] *= __c, __e[__i] = __c;
  (__f *= __e.inv(__d)).resize(__d);
  __c = 1;
  for (std::size_t __i = 0; __i != __d; __c *= ++__i) __f[__i] *= __c;
  return __f;
}

}  // namespace workspace
#line 2 "Library\\src\\data_structure\\union_find\\basic.hpp"

/**
 * @file basic.hpp
 * @brief Union-Find
 */

#line 10 "Library\\src\\data_structure\\union_find\\basic.hpp"

namespace workspace {

class union_find {
 protected:
  using signed_type = int32_t;
  using unsigned_type = uint32_t;

  mutable std::vector<signed_type> __p;

 public:
  /**
   * @brief Construct a new union find object
   */
  union_find() = default;

  /**
   * @brief Construct a new union-find object
   *
   * @param __n Number of nodes.
   */
  union_find(unsigned_type __n) : __p(__n, 1) {}

  /**
   * @param __x A node.
   *
   * @return The representative of the group.
   */
  virtual unsigned_type find(unsigned_type __x) const {
    assert(__x < size());

    return 0 < __p[__x] ? __x : -(__p[__x] = -(signed_type)find(-__p[__x]));
  }

  bool empty() const { return __p.empty(); }

  /**
   * @return The number of nodes.
   */
  unsigned_type size() const { return __p.size(); }

  /**
   * @param __x A node.
   *
   * @return Number of nodes in the group.
   */
  virtual unsigned_type size(unsigned_type __x) const {
    assert(__x < size());

    return __p[find(__x)];
  }

  /**
   * @param __x 1st node.
   * @param __y 2nd node.
   *
   * @return Whether or not the two nodes belong to the same group.
   */
  bool same(unsigned_type __x, unsigned_type __y) const {
    assert(__x < size());
    assert(__y < size());

    return find(__x) == find(__y);
  }

  /**
   * @param __x 1st node.
   * @param __y 2nd node.
   *
   * @return Whether or not the two groups were merged anew.
   */
  virtual bool unite(unsigned_type __x, unsigned_type __y) {
    assert(__x < size()), __x = find(__x);
    assert(__y < size()), __y = find(__y);

    if (__x == __y) return false;

    if (__p[__x] < __p[__y]) std::swap(__x, __y);

    __p[__x] += __p[__y];
    __p[__y] = -(signed_type)__x;

    return true;
  }
};

}  // namespace workspace
#line 2 "Library\\src\\modular\\modint.hpp"

/**
 * @file modint.hpp
 *
 * @brief Modular Arithmetic
 */

#line 12 "Library\\src\\modular\\modint.hpp"

#line 2 "Library\\src\\number_theory\\sqrt_mod.hpp"

/**
 * @file sqrt_mod.hpp
 * @brief Tonelli-Shanks Algorithm
 */

#line 2 "Library\\src\\number_theory\\pow_mod.hpp"

/**
 * @file mod_pow.hpp
 * @brief Modular Exponentiation
 */

#line 9 "Library\\src\\number_theory\\pow_mod.hpp"

#line 11 "Library\\src\\number_theory\\pow_mod.hpp"

namespace workspace {

/**
 * @brief Compile time modular exponentiation.
 *
 * @param __x
 * @param __n Exponent
 * @param __mod Modulus
 * @return
 */
template <class _Tp>
constexpr std::enable_if_t<(is_integral_ext<_Tp>::value), _Tp> pow_mod(
    _Tp __x, _Tp __n, _Tp __mod) noexcept {
  assert(__mod > 0);

  using mul_type = typename multiplicable_uint<_Tp>::type;

  if ((__x %= __mod) < 0) __x += __mod;

  mul_type __y{1};

  while (__n) {
    if (__n & 1) (__y *= __x) %= __mod;
    __x = (mul_type)__x * __x % __mod;
    __n >>= 1;
  }

  return __y;
};

}  // namespace workspace
#line 10 "Library\\src\\number_theory\\sqrt_mod.hpp"

namespace workspace {

/**
 * @brief Compile time modular square root.
 *
 * @param __x
 * @param __mod Modulus
 * @return One if it exists. Otherwise -1.
 */
template <class _Tp>
constexpr std::enable_if_t<(is_integral_ext<_Tp>::value), _Tp> sqrt_mod(
    _Tp __x, _Tp __mod) noexcept {
  assert(__mod > 0);

  using mul_type = typename multiplicable_uint<_Tp>::type;

  if ((__x %= __mod) < 0) __x += __mod;

  if (!__x) return 0;

  if (__mod == 2) return __x;

  if (pow_mod(__x, __mod >> 1, __mod) != 1) return -1;

  _Tp __z = __builtin_ctz(__mod - 1), __q = __mod >> __z;

  mul_type __a = pow_mod(__x, (__q + 1) >> 1, __mod), __b = 2;
  while (pow_mod<_Tp>(__b, __mod >> 1, __mod) == 1) ++__b;
  __b = pow_mod<_Tp>(__b, __q, __mod);

  _Tp __shift = 0;

  for (auto __r = __a * __a % __mod * pow_mod(__x, __mod - 2, __mod) % __mod;
       __r != 1; (__r *= (__b *= __b) %= __mod) %= __mod) {
    auto __bsf = __z;

    for (auto __e = __r; __e != 1; --__bsf) (__e *= __e) %= __mod;

    while (++__shift != __bsf) (__b *= __b) %= __mod;

    (__a *= __b) %= __mod;
  }

  return __a;
};

}  // namespace workspace
#line 15 "Library\\src\\modular\\modint.hpp"

namespace workspace {

namespace _modint_impl {

template <auto _Mod, unsigned _Storage> struct modint {
  static_assert(is_integral_ext<decltype(_Mod)>::value,
                "_Mod must be integral type.");

  using mod_type = std::make_signed_t<typename std::conditional<
      0 < _Mod, std::add_const_t<decltype(_Mod)>, decltype(_Mod)>::type>;

  using value_type = std::decay_t<mod_type>;

  using mul_type = typename multiplicable_uint<value_type>::type;

  // Modulus
  static mod_type mod;

  static unsigned storage;

 private:
  value_type value = 0;

  struct direct_ctor_t {};
  constexpr static direct_ctor_t direct_ctor_tag{};

  // Direct constructor
  template <class _Tp>
  constexpr modint(_Tp __n, direct_ctor_t) noexcept : value(__n) {}

 public:
  constexpr modint() noexcept = default;

  template <class _Tp, typename = std::enable_if_t<is_integral_ext<_Tp>::value>>
  constexpr modint(_Tp __n) noexcept
      : value((__n %= mod) < 0 ? __n += mod : __n) {}

  constexpr modint(bool __n) noexcept : value(__n) {}

  constexpr operator value_type() const noexcept { return value; }

  // unary operators {{
  constexpr modint operator++(int) noexcept {
    modint __t{*this};
    operator++();
    return __t;
  }

  constexpr modint operator--(int) noexcept {
    modint __t{*this};
    operator--();
    return __t;
  }

  constexpr modint &operator++() noexcept {
    if (++value == mod) value = 0;
    return *this;
  }

  constexpr modint &operator--() noexcept {
    if (!value)
      value = mod - 1;
    else
      --value;
    return *this;
  }

  constexpr modint operator+() const noexcept { return *this; }

  constexpr modint operator-() const noexcept {
    return {value ? mod - value : 0, direct_ctor_tag};
  }

  // }} unary operators

  // operator+= {{

  constexpr modint &operator+=(const modint &__x) noexcept {
    if ((value += __x.value) >= mod) value -= mod;
    return *this;
  }

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> &operator+=(
      _Tp const &__x) noexcept {
    if (((value += __x) %= mod) < 0) value += mod;
    return *this;
  }

  // }} operator+=

  // operator+ {{

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> operator+(
      _Tp const &__x) const noexcept {
    return modint{*this} += __x;
  }

  constexpr modint operator+(modint __x) const noexcept { return __x += *this; }

  template <class _Tp>
  constexpr friend std::enable_if_t<is_integral_ext<_Tp>::value, modint>
  operator+(_Tp const &__x, modint __y) noexcept {
    return __y += __x;
  }

  // }} operator+

  // operator-= {{

  constexpr modint &operator-=(const modint &__x) noexcept {
    if ((value -= __x.value) < 0) value += mod;
    return *this;
  }

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> &operator-=(
      _Tp __x) noexcept {
    if (((value -= __x) %= mod) < 0) value += mod;
    return *this;
  }

  // }} operator-=

  // operator- {{

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> operator-(
      _Tp const &__x) const noexcept {
    return modint{*this} -= __x;
  }

  constexpr modint operator-(const modint &__x) const noexcept {
    return modint{*this} -= __x;
  }

  template <class _Tp>
  constexpr friend std::enable_if_t<is_integral_ext<_Tp>::value, modint>
  operator-(_Tp __x, const modint &__y) noexcept {
    if (((__x -= __y.value) %= mod) < 0) __x += mod;
    return {__x, direct_ctor_tag};
  }

  // }} operator-

  // operator*= {{

  constexpr modint &operator*=(const modint &__x) noexcept {
    value =
        static_cast<value_type>(value * static_cast<mul_type>(__x.value) % mod);
    return *this;
  }

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> &operator*=(
      _Tp __x) noexcept {
    value = static_cast<value_type>(
        value * mul_type((__x %= mod) < 0 ? __x + mod : __x) % mod);
    return *this;
  }

  // }} operator*=

  // operator* {{

  constexpr modint operator*(const modint &__x) const noexcept {
    return {static_cast<mul_type>(value) * __x.value % mod, direct_ctor_tag};
  }

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> operator*(
      _Tp __x) const noexcept {
    __x %= mod;
    if (__x < 0) __x += mod;
    return {static_cast<mul_type>(value) * __x % mod, direct_ctor_tag};
  }

  template <class _Tp>
  constexpr friend std::enable_if_t<is_integral_ext<_Tp>::value, modint>
  operator*(_Tp __x, const modint &__y) noexcept {
    __x %= mod;
    if (__x < 0) __x += mod;
    return {static_cast<mul_type>(__x) * __y.value % mod, direct_ctor_tag};
  }

  // }} operator*

 protected:
  static value_type _mem(value_type __x) {
    static std::vector<value_type> __m{0, 1};
    static value_type __i = (__m.reserve(storage), 1);
    while (__i < __x) {
      ++__i;
      __m.emplace_back(mod - mul_type(mod / __i) * __m[mod % __i] % mod);
    }
    return __m[__x];
  }

  static value_type _div(mul_type __r, value_type __x) noexcept {
    assert(__x != value_type(0));
    if (!__r) return 0;

    std::make_signed_t<value_type> __v{};
    bool __neg = __x < 0 ? __x = -__x, true : false;

    if (static_cast<decltype(storage)>(__x) < storage)
      __v = _mem(__x);
    else {
      value_type __y{mod}, __u{1}, __t;

      while (__x)
        __t = __y / __x, __y ^= __x ^= (__y -= __t * __x) ^= __x,
        __v ^= __u ^= (__v -= __t * __u) ^= __u;

      if (__y < 0) __neg ^= 1;
    }

    if (__neg)
      __v = 0 < __v ? mod - __v : -__v;
    else if (__v < 0)
      __v += mod;

    return __r == mul_type(1) ? static_cast<value_type>(__v)
                              : static_cast<value_type>(__r * __v % mod);
  }

 public:
  // operator/= {{

  constexpr modint &operator/=(const modint &__x) noexcept {
    if (value) value = _div(value, __x.value);
    return *this;
  }

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> &operator/=(
      _Tp __x) noexcept {
    if (value) value = _div(value, __x %= mod);
    return *this;
  }

  // }} operator/=

  // operator/ {{

  constexpr modint operator/(const modint &__x) const noexcept {
    if (!value) return {};
    return {_div(value, __x.value), direct_ctor_tag};
  }

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> operator/(
      _Tp __x) const noexcept {
    if (!value) return {};
    return {_div(value, __x %= mod), direct_ctor_tag};
  }

  template <class _Tp>
  constexpr friend std::enable_if_t<is_integral_ext<_Tp>::value, modint>
  operator/(_Tp __x, const modint &__y) noexcept {
    if (!__x) return {};
    if ((__x %= mod) < 0) __x += mod;
    return {_div(__x, __y.value), direct_ctor_tag};
  }

  // }} operator/

  constexpr modint inv() const noexcept { return _div(1, value); }

  template <class _Tp>
  constexpr std::enable_if_t<is_integral_ext<_Tp>::value, modint> pow(
      _Tp __e) const noexcept {
    modint __r{1, direct_ctor_tag};

    for (modint __b{__e < 0 ? __e = -__e, _div(1, value) : value,
                              direct_ctor_tag};
         __e; __e >>= 1, __b *= __b)
      if (__e & 1) __r *= __b;

    return __r;
  }

  template <class _Tp>
  constexpr friend std::enable_if_t<is_integral_ext<_Tp>::value, modint> pow(
      modint __b, _Tp __e) noexcept {
    if (__e < 0) {
      __e = -__e;
      __b.value = _div(1, __b.value);
    }

    modint __r{1, direct_ctor_tag};

    for (; __e; __e >>= 1, __b *= __b)
      if (__e & 1) __r *= __b;

    return __r;
  }

  constexpr modint sqrt() const noexcept {
    return {sqrt_mod(value, mod), direct_ctor_tag};
  }

  friend constexpr modint sqrt(const modint &__x) noexcept {
    return {sqrt_mod(__x.value, mod), direct_ctor_tag};
  }

  template <class _Os>
  friend _Os &operator<<(_Os &__os, const modint &__x) noexcept {
    return __os << __x.value;
  }

  friend std::istream &operator>>(std::istream &__is, modint &__x) noexcept {
    std::string __s;
    __is >> __s;
    bool __neg = false;
    if (__s.front() == '-') {
      __neg = true;
      __s.erase(__s.begin());
    }
    __x = 0;
    for (char __c : __s) __x = __x * 10 + (__c - '0');
    if (__neg) __x = -__x;
    return __is;
  }
};

template <auto _Mod, unsigned _Storage>
typename modint<_Mod, _Storage>::mod_type modint<_Mod, _Storage>::mod =
    _Mod > 0 ? _Mod : 0;

template <auto _Mod, unsigned _Storage>
unsigned modint<_Mod, _Storage>::storage = _Storage;

}  // namespace _modint_impl

template <auto _Mod, unsigned _Storage = 0,
          typename = std::enable_if_t<(_Mod > 0)>>
using modint = _modint_impl::modint<_Mod, _Storage>;

template <unsigned _Id = 0>
using modint_runtime = _modint_impl::modint<-(signed)_Id, 0>;

}  // namespace workspace
#line 2 "Library\\src\\utils\\py-like\\range.hpp"

/**
 * @file range.hpp
 * @brief Range
 */

#line 9 "Library\\src\\utils\\py-like\\range.hpp"

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

  constexpr decltype(auto) size() const noexcept { return std::size(__cont); }
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

  constexpr range(_Index __first, _Index __last) noexcept
      : __first(__first), __last(__last) {}
  constexpr range(_Index __last) noexcept : __first(), __last(__last) {}

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
#line 32 "codeforces-workspace\\contest\\1408\\g\\g.cpp"

namespace workspace {

using mint = modint<998244353>;
using poly = polynomial<mint>;

void main() {
  // start here!

  int n;
  cin >> n;
  vector<pair<int, int>> es(n * (n - 1) / 2);
  for (auto i : range(n)) {
    for (auto j : range(n)) {
      int c;
      cin >> c;
      if (i == j) continue;
      --c;
      es[c] = {j, i};
    }
  }

  vector<int> ec(n);
  union_find uf(n);
  vector<poly> ps(n, {1});

  for (auto [x, y] : es) {
    x = uf.find(x);
    y = uf.find(y);
    if (x != y) {
      uf.unite(x, y);
      auto esum = ec[x] + ec[y];
      x = uf.find(x);
      ec[x] = esum + 1;
    } else {
      ec[x]++;
    }

    auto vs = uf.size(x);
    if (ec[x] == vs * (vs - 1) / 2) {
      // clique
      poly tmp{1};
      for (auto i : range(n)) {
        if (uf.find(i) != x) {
          continue;
        }
        tmp *= ps[i];
        ps[i] = {1};
      }
      tmp.resize(vs);
      tmp.back() = 1;
      ps[x] = move(tmp);
    }
  }

  auto res = ps[uf.find(0)];
  reverse(begin(res), end(res));
  for (auto &&x : res) {
    cout << x << " ";
  }
  cout << eol;
}

}  // namespace workspace