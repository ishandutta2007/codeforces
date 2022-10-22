#line 1 "codeforces-workspace/contest/1469/f/f.cpp"
/**
 * @file template.cpp
 * @brief Template
 */

// #undef _GLIBCXX_DEBUG
// #define NDEBUG
#include <bits/extc++.h>

#line 2 "Library/lib/alias"

/*
 * @file alias
 * @brief Alias
 */

#line 13 "Library/lib/alias"

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

}  // namespace workspace
#line 2 "Library/lib/cxx20"

/*
 * @file cxx20
 * @brief C++20 Features
 */

#line 1 "Library/lib/bit"



#line 5 "Library/lib/bit"
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



/*

namespace workspace {

template <typename _Tp> constexpr _Tp __bsf(_Tp __x) noexcept {
  return std::__countr_zero(__x);
}

template <typename _Tp> constexpr _Tp __bsr(_Tp __x) noexcept {
  return std::__bit_width(__x);
}

}  // namespace workspace

*/
#line 9 "Library/lib/cxx20"

#if __cplusplus <= 201703L

#include <algorithm>
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
  __cont.erase(remove_if(__cont.begin(), __cont.end(), __pred), __cont.end());
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
  __cont.erase(remove(__cont.begin(), __cont.end(), __value), __cont.end());
  return __osz - __cont.size();
}

}  // namespace std

#endif
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
#line 2 "Library/src/opt/binary_search.hpp"

/*
 * @file binary_search.hpp
 * @brief Binary Search
 */

#line 12 "Library/src/opt/binary_search.hpp"

namespace workspace {

/*
 * @fn binary_search
 * @brief binary search on a discrete range.
 * @param ok pred(ok) is true
 * @param ng pred(ng) is false
 * @param pred the predicate
 * @return the closest point to (ng) where pred is true
 */
template <class Iter, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Iter>())),
                        bool>::value,
    Iter>::type
binary_search(Iter ok, Iter ng, Pred pred) {
  assert(ok != ng);
  typename std::make_signed<decltype(ng - ok)>::type dist(ng - ok);
  while (1 < dist || dist < -1) {
    const Iter mid(ok + dist / 2);
    if (pred(mid))
      ok = mid, dist -= dist / 2;
    else
      ng = mid, dist /= 2;
  }
  return ok;
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
template <class Real, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Real>())),
                        bool>::value,
    Real>::type
binary_search(Real ok, Real ng, const Real eps, Pred pred) {
  assert(ok != ng);
  for (auto loops = 0; loops != std::numeric_limits<Real>::digits &&
                       (ok + eps < ng || ng + eps < ok);
       ++loops) {
    const Real mid{(ok + ng) / 2};
    (pred(mid) ? ok : ng) = mid;
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
template <class Array,
          class Iter = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<Pred>()(std::declval<std::vector<Iter>>())[0]),
        bool>::value,
    std::vector<Iter>>::type
parallel_binary_search(Array ends, Pred pred) {
  std::vector<Iter> mids(std::size(ends));
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const Iter &ok = std::get<0>(ends[i]);
      const Iter &ng = std::get<1>(ends[i]);
      const Iter mid(
          ok + typename std::make_signed<decltype(ng - ok)>::type(ng - ok) / 2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    const auto res = pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}

/*
 * @fn parallel_binary_search
 * @brief parallel binary search on the real number line.
 * @param ends a vector of pairs; pred(first) is true, pred(second) is false
 * @param eps the error tolerance
 * @param pred the predicate
 * @return the boundary points
 */
template <class Array,
          class Real = typename std::decay<
              decltype(std::get<0>(std::declval<Array>()[0]))>::type,
          class Pred>
typename std::enable_if<
    std::is_convertible<
        decltype(std::declval<Pred>()(std::declval<std::vector<Real>>())[0]),
        bool>::value,
    std::vector<Real>>::type
parallel_binary_search(Array ends, const Real eps, Pred pred) {
  std::vector<Real> mids(std::size(ends));
  for (auto loops = 0; loops != std::numeric_limits<Real>::digits; ++loops) {
    bool all_found = true;
    for (size_t i{}; i != std::size(ends); ++i) {
      const Real ok = std::get<0>(ends[i]);
      const Real ng = std::get<1>(ends[i]);
      if (ok + eps < ng || ng + eps < ok) {
        all_found = false;
        mids[i] = (ok + ng) / 2;
      }
    }
    if (all_found) break;
    const auto res = pred(mids);
    for (size_t i{}; i != std::size(ends); ++i) {
      (res[i] ? std::get<0>(ends[i]) : std::get<1>(ends[i])) = mids[i];
    }
  }
  return mids;
}

}  // namespace workspace
#line 2 "Library/src/opt/exponential_search.hpp"

/*
 * @file exponential_search.hpp
 * @brief Exponential Search
 */

#line 9 "Library/src/opt/exponential_search.hpp"

namespace workspace {

/*
 * @fn exponential_search
 * @brief Exponential search on a discrete range.
 * @param range Range of search, exclusive
 * @param pred Predicate
 * @return Minimum non-negative integer where pred is false.
 */
template <class Index, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Index>())),
                        bool>::value,
    Index>::type
exponential_search(Index range, Pred pred) {
  Index step(1);
  while (step < range && pred(step)) step <<= 1;
  if (range < step) step = range;
  return binary_search(Index(0), step, pred);
}

/*
 * @fn exponential_search
 * @brief Exponential search on the real number line.
 * @param range Range of search
 * @param eps Error tolerance
 * @param pred Predicate
 * @return Boundary point.
 */
template <class Real, class Pred>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Pred>()(std::declval<Real>())),
                        bool>::value,
    Real>::type
exponential_search(Real range, Real const &eps, Pred pred) {
  Real step(1);
  while (step < range && pred(step)) step += step;
  if (range < step) step = range;
  return binary_search(Real(0), step, eps, pred);
}

}  // namespace workspace
#line 2 "Library/src/opt/trinary_search.hpp"

/*
 * @file trinary_search.hpp
 * @brief Trinary Search
 */

#line 10 "Library/src/opt/trinary_search.hpp"

namespace workspace {

/*
 * @brief Trinary search on discrete range.
 * @param first Left end, inclusive
 * @param last Right end, exclusive
 * @param comp Compare function
 * @return Local minimal point.
 */
template <class Iter, class Comp>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Comp>()(std::declval<Iter>(),
                                                      std::declval<Iter>())),
                        bool>::value,
    Iter>::type
trinary_search(Iter first, Iter last, Comp comp) {
  assert(first < last);
  typename std::make_signed<decltype(last - first)>::type dist(last - first);
  while (2 < dist) {
    Iter left(first + dist / 3), right(first + dist * 2 / 3);
    if (comp(left, right))
      last = right, dist = (dist + dist) / 3;
    else
      first = left, dist -= dist / 3;
  }
  if (1 < dist && comp(first + 1, first)) ++first;
  return first;
}

/*
 * @brief Trinary search on discrete range.
 * @param first Left end, inclusive
 * @param last Right end, exclusive
 * @param func Function
 * @return Local minimal point.
 */
template <class Iter, class Func>
typename std::enable_if<
    std::is_same<decltype(std::declval<Func>()(std::declval<Iter>()), nullptr),
                 std::nullptr_t>::value,
    Iter>::type
trinary_search(Iter const &first, Iter const &last, Func func) {
  return trinary_search(first, last, [&](Iter const &__i, Iter const &__j) {
    return func(__i) < func(__j);
  });
}

/*
 * @brief Trinary search on the real number line.
 * @param first Left end
 * @param last Right end
 * @param eps Error tolerance
 * @param comp Compare function
 * @return Local minimal point.
 */
template <class Real, class Comp>
typename std::enable_if<
    std::is_convertible<decltype(std::declval<Comp>()(std::declval<Real>(),
                                                      std::declval<Real>())),
                        bool>::value,
    Real>::type
trinary_search(Real first, Real last, Real const &eps, Comp comp) {
  assert(first < last);
  while (eps < last - first) {
    Real left{(first * 2 + last) / 3}, right{(first + last * 2) / 3};
    if (comp(left, right))
      last = right;
    else
      first = left;
  }
  return first;
}

/*
 * @brief Trinary search on the real number line.
 * @param first Left end
 * @param last Right end
 * @param eps Error tolerance
 * @param func Function
 * @return Local minimal point.
 */
template <class Real, class Func>
typename std::enable_if<
    std::is_same<decltype(std::declval<Func>()(std::declval<Real>()), nullptr),
                 std::nullptr_t>::value,
    Real>::type
trinary_search(Real const &first, Real const &last, Real const &eps,
               Func func) {
  return trinary_search(
      first, last, eps,
      [&](Real const &__i, Real const &__j) { return func(__i) < func(__j); });
}

}  // namespace workspace
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

/*
 * @file ejection.hpp
 * @brief Ejection
 */

#line 9 "Library/src/sys/ejection.hpp"

namespace workspace {

struct ejection {
  bool exit = 0;
};

/*
 * @brief eject from a try block, throw nullptr
 * @param arg output
 */
template <class Tp> void eject(Tp const &arg) {
  std::cout << arg << "\n";
  throw ejection{};
}

void exit() { throw ejection{true}; }

}  // namespace workspace
#line 2 "Library/src/sys/iteration.hpp"

/*
 * @file iteration.hpp
 * @brief Case Iteration
 */

#line 9 "Library/src/sys/iteration.hpp"

#line 11 "Library/src/sys/iteration.hpp"

namespace workspace {

void main();

struct {
  unsigned current{0}, total{1};

  void read() { (std::cin >> total).ignore(); }

  int iterate() {
    static bool once = false;
    assert(!once);
    once = true;
    while (current++ < total) {
      try {
        main();
      } catch (ejection const& status) {
        if (status.exit) break;
      }
    }
    return 0;
  }
} case_info;

}  // namespace workspace
#line 15 "codeforces-workspace/contest/1469/f/f.cpp"
// #include "lib/utils"
#line 2 "Library/src/utils/io/setup.hpp"

/*
 * @file setup.hpp
 * @brief I/O Setup
 */

#line 10 "Library/src/utils/io/setup.hpp"

namespace workspace {

/*
 * @fn io_setup
 * @brief Setup I/O.
 * @param precision Standard output precision
 */
void io_setup(int precision) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(precision);

#ifdef _buffer_check
  atexit([] {
    char bufc;
    if (std::cin >> bufc)
      std::cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });
#endif
}

}  // namespace workspace
#line 17 "codeforces-workspace/contest/1469/f/f.cpp"

int main() {
  using namespace workspace;

  io_setup(15);

  /* given
  case_info.read();  //*/

  /* unspecified
  case_info.total = -1; //*/

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

namespace segtree_impl {

template <class Monoid, class Node,
          template <class...> class Container_tmpl = std::vector>
struct base {
  static_assert(std::is_same<Monoid, decltype(std::declval<Monoid>() +
                                              std::declval<Monoid>())>::value,
                "\'Monoid\' has no proper binary \'operator+\'.");

  using container_type = Container_tmpl<Node>;
  using size_type = typename container_type::size_type;

  class iterator {
    base *__p;
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
    iterator(base *__p, size_type __i) : __p(__p), __i(__i) {}

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

  iterator begin() { return {this, 0}; }
  iterator end() { return {this, size_orig}; }

  auto rbegin() { return std::make_reverse_iterator(end()); }
  auto rend() { return std::make_reverse_iterator(begin()); }

  using value_type = typename iterator::value_type;
  using reference = typename iterator::reference;

  /**
   * @brief Construct a new segment tree object
   *
   * @param __n Number of elements.
   */
  base(size_type __n = 0)
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
   * @tparam Tp
   * @param __n Number of elements.
   * @param init
   */
  template <class Tp, typename std::enable_if<std::is_convertible<
                          Tp, Monoid>::value>::type * = nullptr>
  base(size_type __n, Tp const &init) : base(__n) {
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
  base(Iterator __first, Iterator __last)
      : base(std::distance(__first, __last)) {
    for (auto i = begin(); __first != __last; ++i, ++__first) *i = *__first;
  }

  /**
   * @return Number of elements.
   */
  size_type size() const { return size_orig; }

  /**
   * @param __i Index of the element
   * @return Reference to the element.
   */
  virtual reference operator[](size_type __i) {
    assert(__i < size_orig);
    reference __ref = *data[__i |= size_ext];
    while (data[__i >>= 1]) data[__i].reset();
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

    if constexpr (lazy_tag)
      for (auto __i{height}, __fp{first}, __lp{last - 1}; __i; --__i)
        push(__fp >> __i), push(__lp >> __i);

    Monoid left{}, right{};

    while (first < last) {
      if (first & 1) left = left + *pull(first++);
      if (last & 1) right = *pull(--last) + right;
      first >>= 1, last >>= 1;

      // if constexpr (lazy_tag) {
      //   if (auto const &__z = data[__fp >>= 1].__z) left = left * *__z;
      //   if (auto const &__z = data[__lp >>= 1].__z) right = right * *__z;
      // }
    }

    // if constexpr (lazy_tag)
    //   while (__fp >>= 1, __lp >>= 1) {
    //     if (auto const &__z = data[__fp].__z) left = left * *__z;
    //     if (auto const &__z = data[__lp].__z) right = right * *__z;
    //   }

    return left + right;
  }

  /**
   * @return The whole sum.
   */
  value_type fold() { return fold(0, size_orig); }

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
    Monoid mono{};
    if constexpr (lazy_tag)
      for (size_t i{height}; i; --i) push(right >> i);
    for (size_type left{size_ext}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        const Monoid tmp = *pull(--right) + mono;
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
    Monoid mono{};
    if constexpr (lazy_tag)
      for (size_t i{height}; i; --i) push(left >> i);
    for (size_type right{size_ext << 1}, step{}; left != right;
         left >>= 1, right >>= 1, ++step) {
      if ((left & 1) != (right & 1)) {
        const Monoid tmp = mono + *pull(left);
        if (!pass_args(pred, tmp, ((left + 1) << step) ^ size_ext))
          return right_partition_subtree(left, mono, step, pred);
        mono = tmp;
        ++left;
      }
    }
    return size_orig;
  }

 protected:
  constexpr static bool lazy_tag = Node::lazy_tag;

  size_type size_orig, height, size_ext;
  container_type data;

  virtual void push(size_type) noexcept {}

  Node &pull(size_type __i) noexcept {
    if (!data[__i]) data[__i] = *pull(__i << 1) + *pull(__i << 1 | 1);
    return data[__i];
  }

  template <class Pred>
  size_type left_partition_subtree(size_type __i, Monoid mono, size_type step,
                                   Pred pred) {
    assert(__i);
    while (__i < size_ext) {
      if constexpr (lazy_tag) push(__i);
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
      if constexpr (lazy_tag) push(__i);
      const Monoid tmp = mono + *pull(__i <<= 1);
      if (pass_args(pred, tmp, ((__i | 1) << --step) ^ size_ext))
        ++__i, mono = tmp;
    }
    return (__i -= size_ext) < size_orig ? __i : size_orig;
  }

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
};

#if __cplusplus < 201703L

template <class Tp> struct node {
  constexpr static bool lazy_tag = false;

  node() = default;
  node(Tp const &__x) : __v(__x) {}
  operator bool() const { return __f; }
  void operator=(Tp const &__x) {
    __v = __x;
    __f = true;
  }
  Tp &operator*() { return __v; }
  Tp const &operator*() const { return __v; }
  void reset() { __f = false; }

 private:
  Tp __v{};
  bool __f{true};
};

template <class Tp1, class Tp2> struct lazy_node : node<Tp1> {
  constexpr static bool lazy_tag = true;
  node<Tp2> __z;
};

#else

template <class Tp> struct node : std::optional<Tp> {
  constexpr static bool lazy_tag = false;
  using std::optional<Tp>::operator=;
  node() : std::optional<Tp>(Tp{}) {}
};

template <class Tp1, class Tp2> struct lazy_node : node<Tp1> {
  constexpr static bool lazy_tag = true;
  using node<Tp1>::operator=;
  std::optional<Tp2> __z;
};

#endif

template <class Monoid, class Endomorphism,
          template <class...> class Container_tmpl = std::vector>
struct [[deprecated]] lazy
    : base<Monoid, lazy_node<Monoid, Endomorphism>, Container_tmpl> {
  using _base = base<Monoid, lazy_node<Monoid, Endomorphism>, Container_tmpl>;
  using size_type = typename _base::size_type;
  using _base::base;

  void update(size_type first, size_type last, Endomorphism const &endo) {
    assert(last <= _base::size_orig);
    if (first >= last) return;
    first += _base::size_ext, last += _base::size_ext - 1;
    for (auto i = _base::height; i; --i) push(first >> i), push(last >> i);
    for (auto l = first, r = last + 1;; l >>= 1, r >>= 1) {
      if (l < r) {
        if (l & 1) apply_top(l++, endo);
        if (r & 1) apply_top(--r, endo);
      }
      if (first >>= 1, last >>= 1) {
        // _base::data[first].reset();
        // _base::data[last].reset();
        pull_f(first);
        pull_f(last);

      } else
        break;
    }
  }

 protected:
  void pull_f(size_type __i) {
    _base::data[__i] = *_base::pull(__i << 1) + *_base::pull(__i << 1 | 1);
  }

  void push(size_type __i) noexcept override {
    if (auto &__lz = _base::data[__i].__z) {
      apply(__i <<= 1, *__lz);
      apply(__i |= 1, *__lz);
      __lz.reset();
    }
  }

  void apply(size_type __i, Endomorphism const &__e) noexcept {
    auto &__nd = _base::data[__i];
    *__nd = *__nd * __e;
    if (__i < _base::size_ext) __nd.__z = __nd.__z ? *__nd.__z * __e : __e;
  }

  void apply_top(size_type __i, Endomorphism const &__e) noexcept {
    auto &__nd = _base::pull(__i);
    *__nd = *__nd * __e;
    if (__i < _base::size_ext) __nd.__z = __nd.__z ? *__nd.__z * __e : __e;
  }
};

}  // namespace segtree_impl

template <class Monoid, class Endomorphism = void,
          template <class...> class Container_tmpl = std::vector>
using _segment_tree = typename std::conditional<
    std::is_void<Endomorphism>::value,
    segtree_impl::base<Monoid, segtree_impl::node<Monoid>, Container_tmpl>,
    segtree_impl::lazy<Monoid, Endomorphism, Container_tmpl>>::type;

/**
 * @tparam Monoid `operator+`, `operator=`
 * @tparam Container_tmpl `operator[]`, `size_type`
 */
template <class Monoid, class Endomorphism = void,
          template <class...> class Container_tmpl = std::vector>
class segment_tree {
  static_assert(std::is_same<Monoid, decltype(std::declval<Monoid>() +
                                              std::declval<Monoid>())>::value,
                "\'Monoid\' has no proper binary \'operator+\'.");

  constexpr static bool __support_lazy = !std::is_void<Endomorphism>::value;
  // template <class Tp = void>
  // using enable_if_lazy = typename std::enable_if<__support_lazy, Tp>::type;

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
   * @tparam Tp
   * @param __n Number of elements.
   * @param init
   */
  template <class Tp, typename std::enable_if<std::is_convertible<
                          Tp, Monoid>::value>::type * = nullptr>
  segment_tree(size_type __n, Tp const &init) : segment_tree(__n) {
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

  /**
   * @return Number of elements.
   */
  size_type size() const { return size_orig; }

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
    Monoid left{}, right{};
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
#line 33 "codeforces-workspace/contest/1469/f/f.cpp"

namespace workspace {

struct mono {
  i64 val = 0;
  int cnt = 0;
  mono operator+(mono y) { return {val + y.val, cnt + y.cnt}; }
};

struct endo {
  i64 val = 0;
  endo operator*(endo y) { return {val + y.val}; }
};

mono operator*(mono x, endo y) {
  x.val += x.cnt * y.val;
  return x;
}

void main() {
  // start here!

  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  for (auto &x : l) cin >> x;
  sort(rbegin(l), rend(l));
  segment_tree<mono, endo> stc(1 << 19, mono{0, 1});
  stc[0].val = 1;
  auto ans = size(stc);
  for (auto x : l) {
    auto nx = stc.right_partition(0, [](auto s) { return !s.val; });
    stc[nx].val--;
    --x;
    if (x & 1) {
      stc.update(nx + 2, nx + 2 + (x / 2), {2});
      stc[nx + (x / 2) + 2].val++;
    } else {
      stc.update(nx + 2, nx + (x / 2) + 2, {2});
    }
    ans = min(ans, stc.right_partition(0, [&](auto s) { return s.val < k; }));
  }
  if (ans == size(stc))
    cout << -1 << '\n';
  else
    cout << ans << eol;
}

}  // namespace workspace