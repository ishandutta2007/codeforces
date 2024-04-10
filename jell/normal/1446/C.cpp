#line 1 "codeforces-workspace\\contest\\1446\\c\\c.cpp"
/*
 * @file template.cpp
 * @brief Template
 */

#include <bits/extc++.h>

#line 2 "Library\\alias.hpp"

/*
 * @file alias.hpp
 * @brief Alias
 */

#line 13 "Library\\alias.hpp"

namespace workspace {

constexpr char eol = '\n';

using namespace std;

using i32 = int_least32_t;
using i64 = int_least64_t;
using i128 = __int128_t;
using u32 = uint_least32_t;
using u64 = uint_least64_t;
using u128 = __uint128_t;

template <class T, class Comp = less<T>>
using priority_queue = std::priority_queue<T, vector<T>, Comp>;

template <class T> using stack = std::stack<T, vector<T>>;

}  // namespace workspace
#line 2 "Library\\config.hpp"

/*
 * @file config.hpp
 * @brief Configuration
 */

#line 11 "Library\\config.hpp"

namespace config {

const auto start_time{std::chrono::system_clock::now()};

/*
 * @fn elapsed
 * @return elapsed time of the program
 */
int64_t elapsed() {
  using namespace std::chrono;
  const auto end_time{system_clock::now()};
  return duration_cast<milliseconds>(end_time - start_time).count();
}

/*
 * @fn setup
 * @brief setup I/O before main process.
 */
__attribute__((constructor)) void setup() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);

#ifdef _buffer_check
  atexit([] {
    char bufc;
    if (cin >> bufc)
      cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });
#endif
}

unsigned cases(), caseid = 1;  // current case number, 1-indexed

/*
 * @fn loop
 * @brief iterate cases.
 * @param main called once per case
 */
template <class F> void loop(F main) {
  for (const unsigned total = cases(); caseid <= total; ++caseid) {
    try {
      main();
    } catch (std::nullptr_t) {
    }
  }
}

}  // namespace config
#line 2 "Library\\cxx20.hpp"

/*
 * @file cxx20.hpp
 * @brief C++20 Features
 */

#line 1 "Library\\gcc\\bit"
// <bit> -*- C++ -*-

// Copyright (C) 2018-2020 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file include/bit
 *  This is a Standard C++ Library header.
 */

#ifndef _GLIBCXX_BIT
#define _GLIBCXX_BIT 1

#pragma GCC system_header

#if __cplusplus >= 201402L

#include <type_traits>

namespace std _GLIBCXX_VISIBILITY(default) {
  _GLIBCXX_BEGIN_NAMESPACE_VERSION

  namespace __detail {
  // This template is used for arbitrary signed and unsigned integer types
  // (by headers <bit> and <charconv>) and for specific integer types
  // (by <memory_resource> and <string_view>) but also for char (<charconv>).
  // For simplicity's sake, all integral types except bool are supported.

  // Lightweight alternative to numeric_limits<signed integer type>.
  template <typename _Tp, bool = is_signed<_Tp>::value> struct __int_limits {
    static_assert(is_integral<_Tp>::value, "unsupported specialization");
    using _Up = typename make_unsigned<_Tp>::type;
    static constexpr int digits = sizeof(_Tp) * __CHAR_BIT__ - 1;
    static constexpr _Tp min() noexcept { return _Tp(_Up(1) << digits); }
    static constexpr _Tp max() noexcept { return _Tp(_Up(~_Up(0)) >> 1); }
  };

  // Lightweight alternative to numeric_limits<unsigned integer type>.
  template <typename _Tp> struct __int_limits<_Tp, false> {
    static_assert(is_integral<_Tp>::value, "unsupported specialization");
    static constexpr int digits = sizeof(_Tp) * __CHAR_BIT__;
    static constexpr _Tp min() noexcept { return 0; }
    static constexpr _Tp max() noexcept { return _Tp(-1); }
  };

  template <> struct __int_limits<bool>;  // not defined
  }                                       // namespace __detail

  /**
   * @defgroup bit_manip Bit manipulation
   * @ingroup numerics
   *
   * Utilities for examining and manipulating individual bits.
   *
   * @{
   */

  /// @cond undoc

  template <typename _Tp> constexpr _Tp __rotl(_Tp __x, int __s) noexcept {
    constexpr auto _Nd = __detail::__int_limits<_Tp>::digits;
    const int __r = __s % _Nd;
    if (__r == 0)
      return __x;
    else if (__r > 0)
      return (__x << __r) | (__x >> ((_Nd - __r) % _Nd));
    else
      return (__x >> -__r) | (__x << ((_Nd + __r) % _Nd));  // rotr(x, -r)
  }

  template <typename _Tp> constexpr _Tp __rotr(_Tp __x, int __s) noexcept {
    constexpr auto _Nd = __detail::__int_limits<_Tp>::digits;
    const int __r = __s % _Nd;
    if (__r == 0)
      return __x;
    else if (__r > 0)
      return (__x >> __r) | (__x << ((_Nd - __r) % _Nd));
    else
      return (__x << -__r) | (__x >> ((_Nd + __r) % _Nd));  // rotl(x, -r)
  }

  template <typename _Tp> constexpr int __countl_zero(_Tp __x) noexcept {
    using std::__detail::__int_limits;
    constexpr auto _Nd = __int_limits<_Tp>::digits;

    if (__x == 0) return _Nd;

    constexpr auto _Nd_ull = __int_limits<unsigned long long>::digits;
    constexpr auto _Nd_ul = __int_limits<unsigned long>::digits;
    constexpr auto _Nd_u = __int_limits<unsigned>::digits;

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
      constexpr auto __max_ull = __int_limits<unsigned long long>::max();
      unsigned long long __low = __x & __max_ull;
      return (_Nd - _Nd_ull) + __builtin_clzll(__low);
    }
  }

  template <typename _Tp> constexpr int __countl_one(_Tp __x) noexcept {
    if (__x == __detail::__int_limits<_Tp>::max())
      return __detail::__int_limits<_Tp>::digits;
    return std::__countl_zero<_Tp>((_Tp)~__x);
  }

  template <typename _Tp> constexpr int __countr_zero(_Tp __x) noexcept {
    using std::__detail::__int_limits;
    constexpr auto _Nd = __int_limits<_Tp>::digits;

    if (__x == 0) return _Nd;

    constexpr auto _Nd_ull = __int_limits<unsigned long long>::digits;
    constexpr auto _Nd_ul = __int_limits<unsigned long>::digits;
    constexpr auto _Nd_u = __int_limits<unsigned>::digits;

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

      constexpr auto __max_ull = __int_limits<unsigned long long>::max();
      unsigned long long __low = __x & __max_ull;
      if (__low != 0) return __builtin_ctzll(__low);
      unsigned long long __high = __x >> _Nd_ull;
      return __builtin_ctzll(__high) + _Nd_ull;
    }
  }

  template <typename _Tp> constexpr int __countr_one(_Tp __x) noexcept {
    if (__x == __detail::__int_limits<_Tp>::max())
      return __detail::__int_limits<_Tp>::digits;
    return std::__countr_zero((_Tp)~__x);
  }

  template <typename _Tp> constexpr int __popcount(_Tp __x) noexcept {
    using std::__detail::__int_limits;
    constexpr auto _Nd = __int_limits<_Tp>::digits;

    if (__x == 0) return 0;

    constexpr auto _Nd_ull = __int_limits<unsigned long long>::digits;
    constexpr auto _Nd_ul = __int_limits<unsigned long>::digits;
    constexpr auto _Nd_u = __int_limits<unsigned>::digits;

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

      constexpr auto __max_ull = __int_limits<unsigned long long>::max();
      unsigned long long __low = __x & __max_ull;
      unsigned long long __high = __x >> _Nd_ull;
      return __builtin_popcountll(__low) + __builtin_popcountll(__high);
    }
  }

  template <typename _Tp> constexpr bool __has_single_bit(_Tp __x) noexcept {
    return std::__popcount(__x) == 1;
  }

  template <typename _Tp> constexpr _Tp __bit_ceil(_Tp __x) noexcept {
    using std::__detail::__int_limits;
    constexpr auto _Nd = __int_limits<_Tp>::digits;
    if (__x == 0 || __x == 1) return 1;
    auto __shift_exponent = _Nd - std::__countl_zero((_Tp)(__x - 1u));
    // If the shift exponent equals _Nd then the correct result is not
    // representable as a value of _Tp, and so the result is undefined.
    // Want that undefined behaviour to be detected in constant expressions,
    // by UBSan, and by debug assertions.
#ifdef _GLIBCXX_HAVE_BUILTIN_IS_CONSTANT_EVALUATED
    if (!__builtin_is_constant_evaluated()) {
      __glibcxx_assert(__shift_exponent != __int_limits<_Tp>::digits);
    }
#endif
    using __promoted_type = decltype(__x << 1);
    if _GLIBCXX17_CONSTEXPR (!is_same<__promoted_type, _Tp>::value) {
      // If __x undergoes integral promotion then shifting by _Nd is
      // not undefined. In order to make the shift undefined, so that
      // it is diagnosed in constant expressions and by UBsan, we also
      // need to "promote" the shift exponent to be too large for the
      // promoted type.
      const int __extra_exp = sizeof(__promoted_type) / sizeof(_Tp) / 2;
      __shift_exponent |= (__shift_exponent & _Nd) << __extra_exp;
    }
    return (_Tp)1u << __shift_exponent;
  }

  template <typename _Tp> constexpr _Tp __bit_floor(_Tp __x) noexcept {
    constexpr auto _Nd = __detail::__int_limits<_Tp>::digits;
    if (__x == 0) return 0;
    return (_Tp)1u << (_Nd - std::__countl_zero((_Tp)(__x >> 1)));
  }

  template <typename _Tp> constexpr _Tp __bit_width(_Tp __x) noexcept {
    constexpr auto _Nd = __detail::__int_limits<_Tp>::digits;
    return _Nd - std::__countl_zero(__x);
  }

  /// @endcond

#if __cplusplus > 201703L

#define __cpp_lib_bitops 201907L

  /// @cond undoc
  template <typename _Tp, typename _Up = _Tp>
  using _If_is_unsigned_integer =
      enable_if_t<__is_unsigned_integer<_Tp>::value, _Up>;
  /// @endcond

  // [bit.rot], rotating

  /// Rotate `x` to the left by `s` bits.
  template <typename _Tp>
  [[nodiscard]] constexpr _If_is_unsigned_integer<_Tp> rotl(_Tp __x,
                                                            int __s) noexcept {
    return std::__rotl(__x, __s);
  }

  /// Rotate `x` to the right by `s` bits.
  template <typename _Tp>
  [[nodiscard]] constexpr _If_is_unsigned_integer<_Tp> rotr(_Tp __x,
                                                            int __s) noexcept {
    return std::__rotr(__x, __s);
  }

  // [bit.count], counting

  /// The number of contiguous zero bits, starting from the highest bit.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> countl_zero(_Tp __x) noexcept {
    return std::__countl_zero(__x);
  }

  /// The number of contiguous one bits, starting from the highest bit.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> countl_one(_Tp __x) noexcept {
    return std::__countl_one(__x);
  }

  /// The number of contiguous zero bits, starting from the lowest bit.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> countr_zero(_Tp __x) noexcept {
    return std::__countr_zero(__x);
  }

  /// The number of contiguous one bits, starting from the lowest bit.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> countr_one(_Tp __x) noexcept {
    return std::__countr_one(__x);
  }

  /// The number of bits set in `x`.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, int> popcount(_Tp __x) noexcept {
    return std::__popcount(__x);
  }

  // [bit.pow.two], integral powers of 2

#define __cpp_lib_int_pow2 202002L

  /// True if `x` is a power of two, false otherwise.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp, bool> has_single_bit(
      _Tp __x) noexcept {
    return std::__has_single_bit(__x);
  }

  /// The smallest power-of-two not less than `x`.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp> bit_ceil(_Tp __x) noexcept {
    return std::__bit_ceil(__x);
  }

  /// The largest power-of-two not greater than `x`.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp> bit_floor(_Tp __x) noexcept {
    return std::__bit_floor(__x);
  }

  /// The smallest integer greater than the base-2 logarithm of `x`.
  template <typename _Tp>
  constexpr _If_is_unsigned_integer<_Tp> bit_width(_Tp __x) noexcept {
    return std::__bit_width(__x);
  }

#define __cpp_lib_endian 201907L

  /// Byte order
  enum class endian {
    little = __ORDER_LITTLE_ENDIAN__,
    big = __ORDER_BIG_ENDIAN__,
    native = __BYTE_ORDER__
  };
#endif  // C++2a

  /// @}

  _GLIBCXX_END_NAMESPACE_VERSION
}  // namespace )

#endif  // C++14
#endif  // _GLIBCXX_BIT
#line 9 "Library\\cxx20.hpp"

#if __cplusplus <= 201703L

#include <vector>

namespace std {

/*
 * @fn erase_if
 * @brief Erase the elements of a container that do not satisfy the condition.
 * @param __cont Container.
 * @param __pred Predicate.
 * @return Number of the erased elements.
 */
template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto __osz = __cont.size();
  __cont.erase(std::remove_if(__cont.begin(), __cont.end(), __pred),
               __cont.end());
  return __osz - __cont.size();
}

/*
 * @fn erase
 * @brief Erase the elements of a container that are equal to the given value.
 * @param __cont Container.
 * @param __value Value.
 * @return Number of the erased elements.
 */
template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto __osz = __cont.size();
  __cont.erase(std::remove(__cont.begin(), __cont.end(), __value),
               __cont.end());
  return __osz - __cont.size();
}

}  // namespace std

#endif
#line 2 "Library\\option.hpp"

/*
 * @file option.hpp
 * @brief Optimize Options
 */

#ifdef ONLINE_JUDGE

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("unroll-loops")

#endif
#line 2 "Library\\utils.hpp"

/*
 * @file utils.hpp
 */

#line 2 "Library\\utils\\binary_search.hpp"

/*
 * @file binary_search.hpp
 * @brief Binary Search
 */

#if __cplusplus >= 201703L

#include <cassert>
#include <cmath>
#include <vector>

namespace workspace {

/*
 * @fn binary_search
 * @brief binary search on a discrete range.
 * @param ok pred(ok) is true
 * @param ng pred(ng) is false
 * @param pred the predicate
 * @return the closest point to (ng) where pred is true
 */
template <class iter_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, iter_type>, bool>,
    iter_type>
binary_search(iter_type ok, iter_type ng, pred_type pred) {
  assert(ok != ng);
  std::make_signed_t<decltype(ng - ok)> dist(ng - ok);
  while (1 < dist || dist < -1) {
    iter_type mid(ok + dist / 2);
    if (pred(mid))
      ok = mid, dist -= dist / 2;
    else
      ng = mid, dist /= 2;
  }
  return ok;
}

/*
 * @fn parallel_binary_search
 * @brief parallel binary search on discrete ranges.
 * @param ends a vector of pairs; pred(first) is true, pred(second) is false
 * @param pred the predicate
 * @return the closest points to (second) where pred is true
 */
template <class iter_type, class pred_type>
std::enable_if_t<std::is_convertible_v<
                     std::invoke_result_t<pred_type, std::vector<iter_type>>,
                     std::vector<bool>>,
                 std::vector<iter_type>>
parallel_binary_search(std::vector<std::pair<iter_type, iter_type>> ends,
                       pred_type pred) {
  std::vector<iter_type> mids(ends.size());
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != ends.size(); ++i) {
      auto [ok, ng] = ends[i];
      iter_type mid(ok + (ng - ok) / 2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    auto res = pred(mids);
    for (size_t i{}; i != ends.size(); ++i) {
      (res[i] ? ends[i].first : ends[i].second) = mids[i];
    }
  }
  return mids;
}

/*
 * @fn binary_search
 * @brief binary search on the real number line.
 * @param ok pred(ok) is true
 * @param ng pred(ng) is false
 * @param eps the error tolerance
 * @param pred the predicate
 * @return the boundary point
 */
template <class real_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>,
    real_type>
binary_search(real_type ok, real_type ng, const real_type eps, pred_type pred) {
  assert(ok != ng);
  for (auto loops = 0; loops != std::numeric_limits<real_type>::digits &&
                       (ok + eps < ng || ng + eps < ok);
       ++loops) {
    real_type mid{(ok + ng) / 2};
    (pred(mid) ? ok : ng) = mid;
  }
  return ok;
}

/*
 * @fn parallel_binary_search
 * @brief parallel binary search on the real number line.
 * @param ends a vector of pairs; pred(first) is true, pred(second) is false
 * @param eps the error tolerance
 * @param pred the predicate
 * @return the boundary points
 */
template <class real_type, class pred_type>
std::enable_if_t<std::is_convertible_v<
                     std::invoke_result_t<pred_type, std::vector<real_type>>,
                     std::vector<bool>>,
                 std::vector<real_type>>
parallel_binary_search(std::vector<std::pair<real_type, real_type>> ends,
                       const real_type eps, pred_type pred) {
  std::vector<real_type> mids(ends.size());
  for (auto loops = 0; loops != std::numeric_limits<real_type>::digits;
       ++loops) {
    bool all_found = true;
    for (size_t i{}; i != ends.size(); ++i) {
      auto [ok, ng] = ends[i];
      if (ok + eps < ng || ng + eps < ok) {
        all_found = false;
        mids[i] = (ok + ng) / 2;
      }
    }
    if (all_found) break;
    auto res = pred(mids);
    for (size_t i{}; i != ends.size(); ++i) {
      (res[i] ? ends[i].first : ends[i].second) = mids[i];
    }
  }
  return mids;
}

}  // namespace workspace

#endif
#line 2 "Library\\utils\\chval.hpp"

/*
 * @file chval.hpp
 * @brief Change Less/Greater
 */

#line 9 "Library\\utils\\chval.hpp"

namespace workspace {

/*
 * @fn chle
 * @brief Substitute y for x if comp(y, x) is true.
 * @param x Reference
 * @param y Const reference
 * @param comp Compare function
 * @return Whether or not x is updated
 */
template <class Tp, class Comp = std::less<Tp>>
bool chle(Tp &x, const Tp &y, Comp comp = Comp()) {
  return comp(y, x) ? x = y, true : false;
}

/*
 * @fn chge
 * @brief Substitute y for x if comp(x, y) is true.
 * @param x Reference
 * @param y Const reference
 * @param comp Compare function
 * @return Whether or not x is updated
 */
template <class Tp, class Comp = std::less<Tp>>
bool chge(Tp &x, const Tp &y, Comp comp = Comp()) {
  return comp(x, y) ? x = y, true : false;
}

}  // namespace workspace
#line 5 "Library\\utils\\coordinate_compression.hpp"

template <class T> class coordinate_compression {
  std::vector<T> uniquely;
  std::vector<size_t> compressed;

 public:
  coordinate_compression(const std::vector<T> &raw)
      : uniquely(raw), compressed(raw.size()) {
    std::sort(uniquely.begin(), uniquely.end());
    uniquely.erase(std::unique(uniquely.begin(), uniquely.end()),
                   uniquely.end());
    for (size_t i = 0; i != size(); ++i)
      compressed[i] =
          std::lower_bound(uniquely.begin(), uniquely.end(), raw[i]) -
          uniquely.begin();
  }

  size_t operator[](const size_t idx) const {
    assert(idx < size());
    return compressed[idx];
  }

  size_t size() const { return compressed.size(); }

  size_t count() const { return uniquely.size(); }

  T value(const size_t ord) const {
    assert(ord < count());
    return uniquely[ord];
  }

  size_t order(const T &value) const {
    return std::lower_bound(uniquely.begin(), uniquely.end(), value) -
           uniquely.begin();
  }

  auto begin() { return compressed.begin(); }
  auto end() { return compressed.end(); }
  auto rbegin() { return compressed.rbegin(); }
  auto rend() { return compressed.rend(); }
};
#line 2 "Library\\utils\\ejection.hpp"

/*
 * @file ejection.hpp
 * @brief Ejection
 */

#line 9 "Library\\utils\\ejection.hpp"

namespace workspace {

/*
 * @brief eject from a try block, throw nullptr
 * @param arg output
 */
template <class Tp> void eject(Tp const &arg) {
  std::cout << arg << "\n";
  throw nullptr;
}

}  // namespace workspace
#line 2 "Library\\utils\\fixed_point.hpp"

/*
 * @file fixed_point.hpp
 * @brief Fixed Point Combinator
 */

#line 9 "Library\\utils\\fixed_point.hpp"

namespace workspace {

/*
 * @class fixed_point
 * @brief Recursive calling of lambda expression.
 */
template <class lambda_type> class fixed_point {
  lambda_type func;

 public:
  /*
   * @param func 1st arg callable with the rest of args, and the return type
   * specified.
   */
  fixed_point(lambda_type &&func) : func(std::move(func)) {}

  /*
   * @brief Recursively apply *this to 1st arg of func.
   * @param args Arguments of the recursive method.
   */
  template <class... Args> auto operator()(Args &&... args) const {
    return func(*this, std::forward<Args>(args)...);
  }
};

}  // namespace workspace
#line 6 "Library\\utils\\hash.hpp"

#line 2 "Library\\utils\\sfinae.hpp"

/*
 * @file sfinae.hpp
 * @brief SFINAE
 */

#line 10 "Library\\utils\\sfinae.hpp"
#include <type_traits>

template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class T, class = int> struct mapped_of {
  using type = element_type<T>;
};
template <class T>
struct mapped_of<T,
                 typename std::pair<int, typename T::mapped_type>::first_type> {
  using type = typename T::mapped_type;
};
template <class T> using mapped_type = typename mapped_of<T>::type;

template <class T, class = void> struct is_integral_ext : std::false_type {};
template <class T>
struct is_integral_ext<
    T, typename std::enable_if<std::is_integral<T>::value>::type>
    : std::true_type {};
template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};
#if __cplusplus >= 201402
template <class T>
constexpr static bool is_integral_ext_v = is_integral_ext<T>::value;
#endif

template <typename T, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(2 < sizeof(T))>::type> {
  using type = uint_least64_t;
};
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(4 < sizeof(T))>::type> {
  using type = __uint128_t;
};
#line 8 "Library\\utils\\hash.hpp"
namespace workspace {
template <class T, class = void> struct hash : std::hash<T> {};
#if __cplusplus >= 201703L
template <class Unique_bits_type>
struct hash<Unique_bits_type,
            enable_if_trait_type<Unique_bits_type,
                                 std::has_unique_object_representations>> {
  size_t operator()(uint64_t x) const {
    static const uint64_t m = std::random_device{}();
    x ^= x >> 23;
    x ^= m;
    x ^= x >> 47;
    return x - (x >> 32);
  }
};
#endif
template <class Key> size_t hash_combine(const size_t &seed, const Key &key) {
  return seed ^
         (hash<Key>()(key) + 0x9e3779b9 /* + (seed << 6) + (seed >> 2) */);
}
template <class T1, class T2> struct hash<std::pair<T1, T2>> {
  size_t operator()(const std::pair<T1, T2> &pair) const {
    return hash_combine(hash<T1>()(pair.first), pair.second);
  }
};
template <class... T> class hash<std::tuple<T...>> {
  template <class Tuple, size_t index = std::tuple_size<Tuple>::value - 1>
  struct tuple_hash {
    static uint64_t apply(const Tuple &t) {
      return hash_combine(tuple_hash<Tuple, index - 1>::apply(t),
                          std::get<index>(t));
    }
  };
  template <class Tuple> struct tuple_hash<Tuple, size_t(-1)> {
    static uint64_t apply(const Tuple &t) { return 0; }
  };

 public:
  uint64_t operator()(const std::tuple<T...> &t) const {
    return tuple_hash<std::tuple<T...>>::apply(t);
  }
};
template <class hash_table> struct hash_table_wrapper : hash_table {
  using key_type = typename hash_table::key_type;
  size_t count(const key_type &key) const {
    return hash_table::find(key) != hash_table::end();
  }
  template <class... Args> auto emplace(Args &&... args) {
    return hash_table::insert(typename hash_table::value_type(args...));
  }
};
template <class Key, class Mapped = __gnu_pbds::null_type>
using cc_hash_table =
    hash_table_wrapper<__gnu_pbds::cc_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped = __gnu_pbds::null_type>
using gp_hash_table =
    hash_table_wrapper<__gnu_pbds::gp_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped>
using unordered_map = std::unordered_map<Key, Mapped, hash<Key>>;
template <class Key> using unordered_set = std::unordered_set<Key, hash<Key>>;
}  // namespace workspace
#line 2 "Library\\utils\\io\\casefmt.hpp"

/*
 * @file castfmt
 * @brief Case Output Format
 */

#line 9 "Library\\utils\\io\\casefmt.hpp"

namespace workspace {

/*
 * @brief printf("Case #%u: ", config::caseid)
 * @param os reference to ostream
 * @return os
 */
std::ostream& casefmt(std::ostream& os) {
  return os << "Case #" << config::caseid << ": ";
}

}  // namespace workspace
#line 3 "Library\\utils\\io\\read.hpp"
namespace workspace {
// read with std::cin.
template <class T = void>
struct read
{
    typename std::remove_const<T>::type value;
    template <class... types>
    read(types... args) : value(args...) { std::cin >> value; }
    operator T() const { return value; }
};
template <>
struct read<void>
{
    template <class T>
    operator T() const { T value; std::cin >> value; return value; }
};
} // namespace workspace
#line 4 "Library\\utils\\io\\stream.hpp"

#line 6 "Library\\utils\\io\\stream.hpp"

namespace std {
template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
template <class tuple_t, size_t index> struct tuple_is {
  static istream &apply(istream &is, tuple_t &t) {
    tuple_is<tuple_t, index - 1>::apply(is, t);
    return is >> get<index>(t);
  }
};
template <class tuple_t> struct tuple_is<tuple_t, SIZE_MAX> {
  static istream &apply(istream &is, tuple_t &t) { return is; }
};
template <class... T> istream &operator>>(istream &is, tuple<T...> &t) {
  return tuple_is<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is,
                                                                          t);
}
template <class tuple_t, size_t index> struct tuple_os {
  static ostream &apply(ostream &os, const tuple_t &t) {
    tuple_os<tuple_t, index - 1>::apply(os, t);
    return os << ' ' << get<index>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, 0> {
  static ostream &apply(ostream &os, const tuple_t &t) {
    return os << get<0>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, SIZE_MAX> {
  static ostream &apply(ostream &os, const tuple_t &t) { return os; }
};
template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) {
  return tuple_os<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os,
                                                                          t);
}
template <class Container, typename Value = element_type<Container>>
typename enable_if<!is_same<typename decay<Container>::type, string>::value &&
                       !is_same<typename decay<Container>::type, char *>::value,
                   istream &>::type
operator>>(istream &is, Container &cont) {
  for (auto &&e : cont) is >> e;
  return is;
}
template <class Container, typename Value = element_type<Container>>
typename enable_if<!is_same<typename decay<Container>::type, string>::value &&
                       !is_same<typename decay<Container>::type, char *>::value,
                   ostream &>::type
operator<<(ostream &os, const Container &cont) {
  bool head = true;
  for (auto &&e : cont) head ? head = 0 : (os << ' ', 0), os << e;
  return os;
}
}  // namespace std
#line 2 "Library\\utils\\make_vector.hpp"

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
constexpr auto make_vector(S* sizes, Tp const& init = Tp()) {
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
constexpr auto make_vector(std::array<S, N> const& sizes,
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
constexpr auto make_vector(std::tuple<Args...> const& sizes,
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
#line 3 "Library\\utils\\random_number_generator.hpp"
template <typename num_type> class random_number_generator {
  typename std::conditional<std::is_integral<num_type>::value,
                            std::uniform_int_distribution<num_type>,
                            std::uniform_real_distribution<num_type>>::type
      unif;

  std::mt19937 engine;

 public:
  random_number_generator(num_type min = std::numeric_limits<num_type>::min(),
                          num_type max = std::numeric_limits<num_type>::max())
      : unif(min, max), engine(std::random_device{}()) {}

  num_type min() const { return unif.min(); }

  num_type max() const { return unif.max(); }

  // generate a random number in [min(), max()].
  num_type operator()() { return unif(engine); }
};
#line 2 "Library\\utils\\round_div.hpp"

/*
 * @file round_div.hpp
 * @brief Round Integer Division
 */

#line 9 "Library\\utils\\round_div.hpp"

#line 11 "Library\\utils\\round_div.hpp"

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
#line 4 "Library\\utils\\trinary_search.hpp"
// trinary search on discrete range.
template <class iter_type, class comp_type>
iter_type trinary(iter_type first, iter_type last, comp_type comp)
{
    assert(first < last);
    intmax_t dist(last - first);
    while(dist > 2)
    {
        iter_type left(first + dist / 3), right(first + dist * 2 / 3);
        if(comp(left, right)) last = right, dist = dist * 2 / 3;
        else first = left, dist -= dist / 3;
    }
    if(dist > 1 && comp(first + 1, first)) ++first;
    return first;
}
// trinary search on real numbers.
template <class comp_type>
long double trinary(long double first, long double last, const long double eps, comp_type comp)
{
    assert(first < last);
    while(last - first > eps)
    {
        long double left{(first * 2 + last) / 3}, right{(first + last * 2) / 3};
        if(comp(left, right)) last = right;
        else first = left;
    }
    return first;
}
#line 2 "Library\\utils\\wrapper.hpp"
template <class Container> class reversed {
  Container &ref, copy;

 public:
  constexpr reversed(Container &ref) : ref(ref) {}
  constexpr reversed(Container &&ref = Container()) : ref(copy), copy(ref) {}
  constexpr auto begin() const { return ref.rbegin(); }
  constexpr auto end() const { return ref.rend(); }
  constexpr operator Container() const { return ref; }
};
#line 13 "codeforces-workspace\\contest\\1446\\c\\c.cpp"

namespace workspace {
void main();
}
int main() { config::loop(workspace::main); }

unsigned config::cases() {
  // return -1; // unspecified
  // int t; std::cin >> t; std::cin.ignore(); return t; // given
  return 1;
}

namespace workspace {
void main() {
  // start here!
  const int h = 30;

  auto solve = fixed_point([&](auto self, vector<int> v) -> int {
    if (size(v) < 4) return (int)size(v);
    vector<vector<int>> grp(h + 1);
    vector<bool> exist(h + 1);
    for (auto &&e : v) {
      for (auto i = 0; i <= h; ++i) {
        if (e < (1 << i)) {
          grp[i].emplace_back(e);
          exist[i] = true;
          break;
        }
      }
    }
    int cnt = count(begin(exist), end(exist), true);
    int ans = cnt;
    for (auto i = 0, j = 0; i <= h; ++i) {
      if (exist[i]) {
        auto nx = grp[i];
        if (i) {
          for (auto &&e : nx) {
            e ^= 1 << (i - 1);
          }
          auto tmp = j;
          for (auto x = h; x > i; --x) {
            if (exist[x]) ++tmp;
          }
          tmp += self(nx);
          chge(ans, tmp);
        } else {
          chge<int>(ans, cnt - 1 + size(grp[i]));
        }
        j = true;
      }
    }
    return ans;
  });

  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  // sort(begin(a), end(a));
  cout << n - solve(a) << eol;
}
}  // namespace workspace