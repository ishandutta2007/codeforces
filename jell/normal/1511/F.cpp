#line 1 "codeforces-workspace/contest/1511/f/f.cpp"
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

namespace _alias_impl {

template <class> struct first_arg { using type = void; };

template <class _Tp, class = void> struct parse_comp : first_arg<_Tp> {};

template <class _Tp>
struct parse_comp<_Tp, std::__void_t<decltype(&_Tp::operator())>>
    : first_arg<decltype(&_Tp::operator())> {};

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

}  // namespace _alias_impl

template <class _Tp = void, class _Compare = std::less<_Tp>>
decltype(auto) make_priority_queue(_Compare __x = _Compare()) noexcept {
  using type = std::conditional_t<
      std::is_void<_Tp>::value,
      std::decay_t<typename _alias_impl::parse_comp<_Compare>::type>, _Tp>;

  return std::priority_queue<type, std::vector<type>, _Compare>(__x);
}

template <class _Tp = void, class _Compare = std::less<_Tp>>
decltype(auto) make_set(_Compare __x = _Compare()) noexcept {
  using type = std::conditional_t<
      std::is_void<_Tp>::value,
      std::decay_t<typename _alias_impl::parse_comp<_Compare>::type>, _Tp>;

  return std::set<type, _Compare>(__x);
}

template <class _Key, class _Mapped, class _Compare = std::less<_Key>>
decltype(auto) make_map(_Compare __x = _Compare()) noexcept {
  return std::map<_Key, _Mapped, _Compare>(__x);
}

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
#line 6 "codeforces-workspace/contest/1511/f/f.cpp"
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
#line 8 "codeforces-workspace/contest/1511/f/f.cpp"
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
#line 10 "codeforces-workspace/contest/1511/f/f.cpp"
// #include "lib/utils"

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
#line 2 "Library/src/utils/py-like/range.hpp"

/**
 * @file range.hpp
 * @brief Range
 */

#line 9 "Library/src/utils/py-like/range.hpp"

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
#line 2 "Library/src/utils/py-like/reversed.hpp"

/**
 * @file reversed.hpp
 * @brief Reversed
 */

#include <initializer_list>
#line 10 "Library/src/utils/py-like/reversed.hpp"

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
#line 12 "Library/src/utils/py-like/range.hpp"

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
    using iterator_category = std::bidirectional_iterator_tag;

    constexpr iterator(const _Index &__i = _Index()) noexcept : current(__i) {}

    constexpr bool operator==(const iterator &__x) const noexcept {
      return current == __x.current;
    }
    constexpr bool operator!=(const iterator &__x) const noexcept {
      return current != __x.current;
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

}  // namespace workspace

#endif
#line 14 "codeforces-workspace/contest/1511/f/f.cpp"

signed main() {
  using namespace workspace;

  io_setup(15);

  /* given
    case_info.read();  //*/

  /* unspecified
    case_info.total = -1;  //*/

  return case_info.iterate();
}

#line 2 "Library/src/algebra/linear/matrix.hpp"

/**
 * @file matrix.hpp
 * @brief Matrix
 * @date 2021-02-15
 *
 *
 */

#line 13 "Library/src/algebra/linear/matrix.hpp"

namespace workspace {

/**
 * @brief Fixed size matrix.
 *
 * @tparam _Scalar
 * @tparam _Rows Number of rows
 * @tparam _Cols Number of columns
 */
template <class _Scalar, std::size_t _Rows = 0, std::size_t _Cols = _Rows>
class matrix {
 public:
  _Scalar __data[_Rows][_Cols] = {};

  using value_type = _Scalar;
  using size_type = std::size_t;

  constexpr static matrix eye() {
    static_assert(_Rows == _Cols);

    matrix __e;
    for (size_type __d = 0; __d != _Rows; ++__d) __e.__data[__d][__d] = 1;
    return __e;
  }

  constexpr operator decltype((__data))() { return __data; }
  constexpr operator decltype(std::declval<const matrix>().__data)
      const&() const {
    return __data;
  }

  constexpr auto begin() { return __data; }
  constexpr auto begin() const { return __data; }

  constexpr auto end() { return __data + _Rows; }
  constexpr auto end() const { return __data + _Rows; }

  constexpr size_type rows() const { return _Rows; }

  constexpr size_type cols() const { return _Cols; }

  constexpr auto transpose() const {
    matrix<_Scalar, _Cols, _Rows> __t;

    for (size_type __r = 0; __r != _Rows; ++__r)
      for (size_type __c = 0; __c != _Cols; ++__c)
        __t.__data[__c][__r] = __data[__r][__c];

    return __t;
  }

  constexpr matrix operator+() const { return *this; }

  constexpr matrix operator-() const {
    matrix __cp = *this;

    for (auto& __v : __cp.__data)
      for (auto& __e : __v) __e = -__e;

    return __cp;
  }

  template <class _Matrix> constexpr matrix& operator+=(const _Matrix& __x) {
    auto __m = std::min(_Rows, __x.rows());
    auto __n = std::min(_Cols, __x.cols());

    for (size_type __r = 0; __r != __m; ++__r)
      for (size_type __c = 0; __c != __n; ++__c)
        __data[__r][__c] += __x[__r][__c];

    return *this;
  }

  template <class _Matrix>
  constexpr matrix operator+(const _Matrix& __x) const {
    return matrix(*this) += __x;
  }

  template <class _Matrix> constexpr matrix& operator-=(const _Matrix& __x) {
    auto __m = std::min(_Rows, __x.rows());
    auto __n = std::min(_Cols, __x.cols());

    for (size_type __r = 0; __r != __m; ++__r)
      for (size_type __c = 0; __c != __n; ++__c)
        __data[__r][__c] -= __x[__r][__c];

    return *this;
  }

  template <class _Matrix>
  constexpr matrix operator-(const _Matrix& __x) const {
    return matrix(*this) -= __x;
  }

  template <class _Scalar2>
  constexpr matrix& operator*=(const matrix<_Scalar2, _Cols, _Cols>& __x) {
    if (this == &__x) return operator=(operator*(__x));

    for (auto& __r : __data) {
      _Scalar __tmp[_Cols] = {};

      auto __v = *__x.__data;
      for (auto& __w : __tmp) {
        auto __i = __v++;
        for (const auto& __e : __r) __w += __e * *__i, __i += _Cols;
      }

      auto __w = __tmp;
      for (auto& __e : __r) __e = std::move(*__w++);
    }

    return *this;
  }

  template <class _Scalar2, size_type _Rows2, size_type _Cols2>
  constexpr auto operator*(const matrix<_Scalar2, _Rows2, _Cols2>& __x) const {
    matrix<typename std::common_type<_Scalar, _Scalar2>::type, _Rows, _Cols2>
        __m;

    auto __w = *__m.__data;
    for (const auto& __r : __data)
      for (auto __v = *__x.__data, __v_end = __v + _Cols2; __v != __v_end;
           ++__w) {
        auto __i = __v++;
        for (auto __e = __r; __e != __r + std::min(_Cols, _Rows2); ++__e)
          *__w += *__e * *__i, __i += _Cols2;
      }

    return __m;
  }

  template <class _Matrix>
  constexpr
      typename std::enable_if<!std::is_convertible<_Matrix, value_type>::value,
                              matrix<_Scalar>>::type
      operator*(const _Matrix& __x) const {
    matrix<_Scalar> __m(_Rows, __x.cols());

    for (size_type __r = 0; __r != _Rows; ++__r)
      for (size_type __i = 0; __i != __x.cols(); ++__i)
        for (size_type __c = 0; __c != std::min(_Cols, __x.rows()); ++__c)
          __m[__r][__i] += __data[__r][__c] * __x[__c][__i];

    return __m;
  }

  constexpr matrix& operator*=(const value_type& __x) {
    for (auto& __v : __data)
      for (auto& __e : __v) __e *= __x;

    return *this;
  }

  constexpr matrix operator*(const value_type& __x) const {
    return matrix(*this) *= __x;
  }

  constexpr matrix& operator/=(const value_type& __x) {
    assert(__x != value_type(0));

    for (auto& __v : __data)
      for (auto& __e : __v) __e /= __x;

    return *this;
  }

  constexpr matrix operator/(const value_type& __x) const {
    return matrix(*this) /= __x;
  }

  template <class _Int> constexpr matrix pow(_Int __e) const {
    assert(0 <= __e);

    matrix __m = eye();
    for (matrix __cp = *this; __e; __cp *= __cp, __e >>= 1)
      if (__e & 1) __m *= __cp;

    return __m;
  }

  template <class _Os>
  constexpr friend _Os& operator<<(_Os& __os, const matrix& __x) {
    for (auto __i = __x.begin(); __i != __x.end(); ++__i, __os << '\n')
      for (size_type __c = 0; __c != _Cols; ++__c)
        __c ? void(__os << ' ') : (void)0, __os << *(*__i + __c);

    return __os;
  }
};  // namespace workspace

/**
 * @brief Dynamic matrix.
 *
 * @tparam _Scalar
 * @tparam _Rows Number of rows
 * @tparam _Cols Number of columns
 */
template <class _Scalar>
class matrix<_Scalar, 0, 0> : public std::valarray<std::valarray<_Scalar>> {
  using base = std::valarray<std::valarray<_Scalar>>;
  using row_type = typename base::value_type;

 public:
  using value_type = _Scalar;
  using size_type = std::size_t;

  using base::operator[];

  static matrix eye(size_type __n) {
    matrix __e(__n, __n);
    for (size_type __d = 0; __d != __n; ++__d) __e[__d][__d] = 1;
    return __e;
  }

  matrix() = default;

  matrix(size_type __n) : matrix(__n, __n) {}

  matrix(size_type __m, size_type __n) : base(row_type(__n), __m) {}

  template <class _Tp, typename = typename std::enable_if<
                           std::is_constructible<base, _Tp>::value &&
                           !std::is_constructible<size_type, _Tp>::value>::type>
  matrix(_Tp&& __x) : base(__x) {}

  matrix(std::initializer_list<row_type> __x) : base(__x) {}

  size_type rows() const { return base::size(); }

  size_type cols() const { return rows() ? operator[](0).size() : 0; }

  matrix transpose() const {
    matrix __t(cols(), rows());

    for (size_type __r = 0; __r != rows(); ++__r)
      for (size_type __c = 0; __c != cols(); ++__c)
        __t[__c][__r] = operator[](__r)[__c];

    return __t;
  }

  void resize(size_type __m, size_type __n) {
    matrix __t(__m, __n);

    if (rows() < __m) __m = rows();
    if (cols() < __n) __n = cols();

    for (size_type __r = 0; __r != __m; ++__r)
      for (size_type __c = 0; __c != __n; ++__c)
        __t[__r][__c] = std::move(operator[](__r)[__c]);

    base::swap(__t);
  }

  // binary operators {{

  template <class _Matrix, typename = void>
  struct is_valarray_based : std::false_type {};

  template <class _Matrix>
  struct is_valarray_based<
      _Matrix,
      typename std::enable_if<std::is_same<
          row_type, typename std::decay<decltype(
                        std::declval<_Matrix>()[0])>::type>::value>::type>
      : std::true_type {};

  template <class _Matrix>
  typename std::enable_if<!std::is_convertible<_Matrix, value_type>::value,
                          matrix&>::type
  operator*=(_Matrix&& __x) {
    return *this = operator*(std::forward<_Matrix>(__x));
  }

  template <class _Matrix>
  typename std::enable_if<!std::is_convertible<_Matrix, value_type>::value,
                          matrix>::type
  operator*(const _Matrix& __x) const {
    matrix __m(rows(), __x.cols());

    if constexpr (is_valarray_based<_Matrix>::value)
      for (size_type __r = 0; __r != rows(); ++__r)
        for (size_type __c = 0; __c != std::min(cols(), __x.rows()); ++__c)
          __m[__r] += operator[](__r)[__c] * __x[__c];

    else
      for (size_type __r = 0; __r != rows(); ++__r)
        for (size_type __i = 0; __i != __x.cols(); ++__i)
          for (size_type __c = 0; __c != std::min(cols(), __x.rows()); ++__c)
            __m[__r][__i] += operator[](__r)[__c] * __x[__c][__i];

    return __m;
  }

  matrix& operator*=(const value_type& __x) {
    for (size_type __r = 0; __r != rows(); ++__r)
      operator[](__r).operator*=(__x);

    return *this;
  }

  matrix operator*(const value_type& __x) const { return matrix(*this) *= __x; }

  friend matrix operator*(const value_type& __x, matrix __i) {
    for (size_type __r = 0; __r != __i.rows(); ++__r)
      __i.operator[](__r) = __x * __i.operator[](__r);

    return __i;
  }

  matrix& operator/=(const value_type& __x) {
    assert(__x != value_type(0));

    for (size_type __r = 0; __r != rows(); ++__r)
      operator[](__r).operator/=(__x);

    return *this;
  }

  matrix operator/(const value_type& __x) const { return matrix(*this) /= __x; }

  // }} binary operators

  template <class _Int> matrix pow(_Int __e) const {
    assert(0 <= __e);

    matrix __m = eye(rows());
    for (matrix __cp = *this; __e; __cp *= __cp, __e >>= 1)
      if (__e & 1) __m *= __cp;

    return __m;
  }

  // template <class _Is> friend _Is& operator>>(_Is& __is, matrix& __x) {
  //   for (size_type __r = 0; __r != __x.rows(); ++__r)
  //     for (size_type __c = 0; __c != __x.cols(); ++__c)
  //       __is >> __x.operator[](__r).operator[](__c);

  //   return __is;
  // }

  template <class _Os> friend _Os& operator<<(_Os& __os, const matrix& __x) {
    for (size_type __r = 0; __r != __x.rows(); ++__r, __os << '\n')
      for (size_type __c = 0; __c != __x.cols(); ++__c)
        __c ? void(__os << ' ') : (void)0,
            __os << __x.operator[](__r).operator[](__c);

    return __os;
  }
};

}  // namespace workspace
#line 2 "Library/src/modular/modint.hpp"

/**
 * @file modint.hpp
 *
 * @brief Modular Arithmetic
 */

#line 12 "Library/src/modular/modint.hpp"

#line 2 "Library/src/number_theory/sqrt_mod.hpp"

/**
 * @file sqrt_mod.hpp
 * @brief Tonelli-Shanks Algorithm
 */

#line 2 "Library/src/number_theory/pow_mod.hpp"

/**
 * @file mod_pow.hpp
 * @brief Modular Exponentiation
 */

#line 9 "Library/src/number_theory/pow_mod.hpp"

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

template <typename _Tp> struct multiplicable {
  using type = std::conditional_t<
      is_integral_ext<_Tp>::value,
      std::conditional_t<std::is_signed<_Tp>::value,
                         typename multiplicable_int<_Tp>::type,
                         typename multiplicable_uint<_Tp>::type>,
      _Tp>;
};

}  // namespace workspace
#line 11 "Library/src/number_theory/pow_mod.hpp"

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
#line 10 "Library/src/number_theory/sqrt_mod.hpp"

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
#line 15 "Library/src/modular/modint.hpp"

namespace workspace {

namespace _modint_impl {

/**
 * @brief Modular arithmetic.
 *
 * @tparam Mod identifier, which represents modulus if positive
 * @tparam Storage Reserved size for inverse calculation
 */
template <auto Mod, unsigned Storage> struct modint {
  static_assert(is_integral_ext<decltype(Mod)>::value,
                "Mod must be integral type.");

  using mod_type = typename std::make_signed<typename std::conditional<
      0 < Mod, typename std::add_const<decltype(Mod)>::type,
      decltype(Mod)>::type>::type;

  using value_type = typename std::decay<mod_type>::type;

  using mul_type = typename multiplicable_uint<value_type>::type;

  // Modulus
  static mod_type mod;

  static unsigned storage;

  constexpr static void reserve(unsigned __n) noexcept { storage = __n; }

 private:
  value_type value = 0;

  struct direct_ctor_t {};
  constexpr static direct_ctor_t direct_ctor_tag{};

  // Direct constructor
  template <class _Tp> constexpr modint(_Tp __n, direct_ctor_t) : value(__n) {}

 public:
  constexpr modint() noexcept = default;

  template <class _Tp, typename std::enable_if<
                           is_integral_ext<_Tp>::value>::type * = nullptr>
  constexpr modint(_Tp __n) noexcept
      : value((__n %= mod) < 0 ? __n += mod : __n) {}

  constexpr modint(bool __n) noexcept : value(__n) {}

  constexpr operator value_type() const noexcept { return value; }

  constexpr static modint one() noexcept { return 1; }

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
  constexpr typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type &
  operator+=(_Tp const &__x) noexcept {
    if (((value += __x) %= mod) < 0) value += mod;
    return *this;
  }

  // }} operator+=

  // operator+ {{

  template <class _Tp>
  constexpr typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type
  operator+(_Tp const &__x) const noexcept {
    return modint{*this} += __x;
  }

  constexpr modint operator+(modint __x) const noexcept { return __x += *this; }

  template <class _Tp>
  constexpr friend
      typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type
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
  constexpr typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type &
  operator-=(_Tp __x) noexcept {
    if (((value -= __x) %= mod) < 0) value += mod;
    return *this;
  }

  // }} operator-=

  // operator- {{

  template <class _Tp>
  constexpr typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type
  operator-(_Tp const &__x) const noexcept {
    return modint{*this} -= __x;
  }

  constexpr modint operator-(const modint &__x) const noexcept {
    return modint{*this} -= __x;
  }

  template <class _Tp>
  constexpr friend
      typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type
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
  constexpr typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type &
  operator*=(_Tp __x) noexcept {
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
  constexpr typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type
  operator*(_Tp __x) const noexcept {
    __x %= mod;
    if (__x < 0) __x += mod;
    return {static_cast<mul_type>(value) * __x % mod, direct_ctor_tag};
  }

  template <class _Tp>
  constexpr friend
      typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type
      operator*(_Tp __x, const modint &__y) noexcept {
    __x %= mod;
    if (__x < 0) __x += mod;
    return {static_cast<mul_type>(__x) * __y.value % mod, direct_ctor_tag};
  }

  // }} operator*

 protected:
  static value_type _mem(value_type __x) {
    static std::vector<value_type> __m{0, 1};
    static value_type __i = (__m.reserve(Storage), 1);
    while (__i < __x) {
      ++__i;
      __m.emplace_back(mod - mul_type(mod / __i) * __m[mod % __i] % mod);
    }
    return __m[__x];
  }

  template <class _Tp>
  constexpr static
      typename std::enable_if<is_integral_ext<_Tp>::value, value_type>::type
      _div(mul_type __r, _Tp __x) noexcept {
    assert(__x != _Tp(0));
    if (!__r) return 0;

    std::make_signed_t<_Tp> __v{};
    bool __neg = __x < 0 ? __x = -__x, true : false;

    if (static_cast<decltype(storage)>(__x) < storage)
      __v = _mem(__x);
    else {
      decltype(__v) __y{mod}, __u{1}, __t;

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
  constexpr typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type &
  operator/=(_Tp __x) noexcept {
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
  constexpr typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type
  operator/(_Tp __x) const noexcept {
    if (!value) return {};
    return {_div(value, __x %= mod), direct_ctor_tag};
  }

  template <class _Tp>
  constexpr friend
      typename std::enable_if<is_integral_ext<_Tp>::value, modint>::type
      operator/(_Tp __x, const modint &__y) noexcept {
    if (!__x) return {};
    if ((__x %= mod) < 0) __x += mod;
    return {_div(__x, __y.value), direct_ctor_tag};
  }

  // }} operator/

  constexpr modint inv() const noexcept { return _div(1, value); }

  template <class _Tp>
  constexpr std::__enable_if_t<is_integral_ext<_Tp>::value, modint> pow(
      _Tp __e) const noexcept {
    modint __r{1, direct_ctor_tag};

    for (modint __b{__e < 0 ? __e = -__e, _div(1, value) : value,
                              direct_ctor_tag};
         __e; __e >>= 1, __b *= __b)
      if (__e & 1) __r *= __b;

    return __r;
  }

  template <class _Tp>
  friend constexpr std::__enable_if_t<is_integral_ext<_Tp>::value, modint> pow(
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

template <auto Mod, unsigned Storage>
typename modint<Mod, Storage>::mod_type modint<Mod, Storage>::mod =
    Mod > 0 ? Mod : 0;

template <auto Mod, unsigned Storage>
unsigned modint<Mod, Storage>::storage = Storage;

}  // namespace _modint_impl

/**
 * @brief Modular arithmetic.
 *
 * @tparam Mod modulus
 * @tparam Storage Reserved size for inverse calculation
 */
template <auto Mod, unsigned Storage = 0,
          typename std::enable_if<(Mod > 0)>::type * = nullptr>
using modint = _modint_impl::modint<Mod, Storage>;

/**
 * @brief Runtime modular arithmetic.
 *
 * @tparam type_id uniquely assigned
 * @tparam Storage Reserved size for inverse calculation
 */
template <unsigned type_id = 0, unsigned Storage = 0>
using modint_runtime = _modint_impl::modint<-(signed)type_id, Storage>;

// #define modint_newtype modint_runtime<__COUNTER__>

}  // namespace workspace
#line 31 "codeforces-workspace/contest/1511/f/f.cpp"

namespace workspace {

using mint = modint<998244353>;
using mat = matrix<mint>;

void main() {
  // start here!

  int n, k;
  cin >> n >> k;

  vector<string> wds(n), sufs{""};
  for (auto &&x : wds) {
    cin >> x;
    for (auto i : range(x.size())) {
      sufs.emplace_back(x.substr(i));
    }
  }

  sort(begin(sufs), end(sufs));
  sufs.erase(unique(begin(sufs), end(sufs)), end(sufs));

  const auto m = sufs.size();
  mat a(m * 5);

  for (auto i : range(4)) {
    for (auto j : range(m)) {
      a[i * m + j][(i + 1) * m + j] = 1;
    }
  }

  for (auto j : range(m)) {
    auto suf = sufs[j];
    for (auto w : wds) {
      if (w.substr(0, suf.size()) != suf || suf.size() == w.size()) {
        continue;
      }

      auto len = w.size() - suf.size();
      w = w.substr(suf.size());

      vector<mint> dp(w.size() + 1);
      dp[0] = 1;
      for (auto i : range(w.size())) {
        for (auto &&x : wds) {
          if (w.substr(i, x.size()) == x) dp[i + x.size()] += dp[i];
        }
      }
      for (auto i : range(w.size() + 1)) {
        auto cod = find(begin(sufs), end(sufs), w.substr(i));
        if (cod != sufs.end())
          a[(len - 1) * m + j][cod - sufs.begin()] += dp[i];
      }
    }
  }

  a = a.pow(k);
  cout << a[0][0] << "\n";
}

}  // namespace workspace