#line 1 "codeforces-workspace/contest/1514/a/a.cpp"
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
#line 2 "Library/lib/cxx20"

/*
 * @file cxx20
 * @brief C++20 Features
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
#line 8 "codeforces-workspace/contest/1514/a/a.cpp"
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
#line 2 "Library/src/utils/cached.hpp"

/**
 * @file cached.hpp
 * @brief Cached
 */

#line 10 "Library/src/utils/cached.hpp"

#line 2 "Library/src/utils/fixed_point.hpp"

/**
 * @file fixed_point.hpp
 * @brief Fixed Point Combinator
 */

#line 9 "Library/src/utils/fixed_point.hpp"

namespace workspace {

/**
 * @brief Fixed Point Combinator
 */
template <class _F> class fixed_point {
  _F __fn;

 public:
  /**
   * @brief Construct a new fixed point object
   *
   * @param __fn 1st argument callable with the rest of its arguments.
   * Return type specified.
   */
  fixed_point(_F __fn) noexcept : __fn(std::forward<_F>(__fn)) {}

  /**
   * @brief Apply *this to 1st argument.
   * @param __args Rest of arguments.
   */
  template <class... _Args>
  decltype(auto) operator()(_Args &&...__args) const noexcept {
    return __fn(*this, std::forward<_Args>(__args)...);
  }
};

}  // namespace workspace
#line 12 "Library/src/utils/cached.hpp"

namespace workspace {

namespace _cached_impl {

// Convert keys to tuple.
template <class... _Args> struct get_tuple {
  using type = decltype(
      std::tuple_cat(std::declval<std::tuple<std::conditional_t<
                         std::is_convertible<std::decay_t<_Args>, _Args>::value,
                         std::decay_t<_Args>, _Args>>>()...));
};

// Associative array.
template <class _Value, class... _Keys>
struct assoc
    : std::integral_constant<int, !std::is_void<_Value>::value>,
      std::conditional_t<std::is_void<_Value>::value,
                         std::set<typename get_tuple<_Keys...>::type>,
                         std::map<typename get_tuple<_Keys...>::type, _Value>> {
};

// Non-resursive lambda type.
template <class _F, class = void> struct is_recursive : std::false_type {};

// Resursive lambda type.
template <class _F>
struct is_recursive<
    _F, std::__void_t<decltype(&_F::template operator()<fixed_point<_F> &>)>>
    : std::true_type {};

// Recursive ver.
template <class _F> class _recursive {
  template <class...> struct _cache;

  template <class _G, class _R, class _H, class... _Args>
  struct _cache<_R (_G::*)(_H, _Args...)> : assoc<_R, _Args...> {};

  template <class _G, class _R, class _H, class... _Args>
  struct _cache<_R (_G::*)(_H, _Args...) const> : assoc<_R, _Args...> {};

 public:
  using cache = _cache<decltype(&_F::template operator()<_recursive<_F> &>)>;

  _recursive(_F __x) noexcept : __fn(__x), __cptr(new cache) {}

  /**
   * @brief Apply `*this` to 1st argument of the lambda.
   * @param __args Rest of arguments.
   */
  template <class... _Args>
  decltype(auto) operator()(_Args &&...__args) noexcept {
    typename cache::key_type __key{__args...};

    if constexpr (cache::value) {
      if (auto __i = __cptr->lower_bound(__key);
          __i != __cptr->end() && __i->first == __key)
        return __i->second;

      else
        return __cptr
            ->emplace_hint(__i, std::move(__key),
                           __fn(*this, std::forward<_Args>(__args)...))
            ->second;
    }

    else if (auto __i = __cptr->lower_bound(__key);
             __i == __cptr->end() || *__i != __key)
      __cptr->emplace_hint(__i, std::move(__key)),
          __fn(*this, std::forward<_Args>(__args)...);
  }

 private:
  _F __fn;
  std::shared_ptr<cache> __cptr;
};

// Non-recursive ver.
template <class _F> class _non_recursive {
  template <class _T, class = void> struct _get_func { using type = _T; };

  template <class _T>
  struct _get_func<_T, std::__void_t<decltype(&_T::operator())>> {
    using type = decltype(&_T::operator());
  };

  template <class...> struct _cache;

  template <class _R, class... _Args>
  struct _cache<_R(_Args...)> : assoc<_R, _Args...> {};

  template <class _R, class... _Args>
  struct _cache<_R (*)(_Args...)> : assoc<_R, _Args...> {};

  template <class _G, class _R, class... _Args>
  struct _cache<_R (_G::*)(_Args...)> : assoc<_R, _Args...> {};

  template <class _G, class _R, class... _Args>
  struct _cache<_R (_G::*)(_Args...) const> : assoc<_R, _Args...> {};

 public:
  using cache = _cache<typename _get_func<_F>::type>;

  _non_recursive(_F __x) noexcept : __fn(__x), __cptr(new cache) {}

  /**
   * @param __args
   */
  template <class... _Args>
  decltype(auto) operator()(_Args &&...__args) noexcept {
    typename cache::key_type __key{__args...};

    if constexpr (cache::value) {
      if (auto __i = __cptr->lower_bound(__key);
          __i != __cptr->end() && __i->first == __key)
        return __i->second;

      else
        return __cptr
            ->emplace_hint(__i, std::move(__key),
                           __fn(std::forward<_Args>(__args)...))
            ->second;
    }

    else if (auto __i = __cptr->lower_bound(__key);
             __i == __cptr->end() || *__i != __key)
      __cptr->emplace_hint(__i, std::move(__key)),
          __fn(std::forward<_Args>(__args)...);
  }

 private:
  _F __fn;
  std::shared_ptr<cache> __cptr;
};

template <class _F>
using _cached = std::conditional_t<is_recursive<_F>::value, _recursive<_F>,
                                   _non_recursive<_F>>;

}  // namespace _cached_impl

/**
 * @brief Cached caller of function
 */
template <class _F> class cached : public _cached_impl::_cached<_F> {
 public:
  /**
   * @brief Construct a new cached object
   */
  cached() noexcept : _cached_impl::_cached<_F>(_F{}) {}

  /**
   * @brief Construct a new cached object
   *
   * @param __x Function
   */
  cached(_F __x) noexcept : _cached_impl::_cached<_F>(__x) {}
};

}  // namespace workspace
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
#line 2 "Library/src/utils/hash.hpp"

#line 8 "Library/src/utils/hash.hpp"

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
#line 10 "Library/src/utils/hash.hpp"
namespace workspace {
template <class T, class = void> struct hash : std::hash<T> {};

template <class _Tp> struct hash<_Tp *> : std::hash<_Tp *> {};

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
#line 2 "Library/src/utils/io/istream.hpp"

/**
 * @file istream.hpp
 * @brief Input Stream
 */

#include <cxxabi.h>

#line 13 "Library/src/utils/io/istream.hpp"

#line 15 "Library/src/utils/io/istream.hpp"

namespace workspace {

namespace _istream_impl {

template <class _Tp, typename = std::nullptr_t> struct istream_helper {
  istream_helper(std::istream &__is, _Tp &__x) {
    if constexpr (has_begin<_Tp>::value)
      for (auto &&__e : __x)
        istream_helper<std::decay_t<decltype(__e)>>(__is, __e);
    else
      static_assert(has_begin<_Tp>::value, "istream unsupported type.");
  }
};

template <class _Tp>
struct istream_helper<
    _Tp,
    decltype(std::declval<std::decay_t<decltype(
                 std::declval<std::istream &>() >> std::declval<_Tp &>())>>(),
             nullptr)> {
  istream_helper(std::istream &__is, _Tp &__x) { __is >> __x; }
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
  istream_helper(std::istream &__is, std::pair<T1, T2> &__x) {
    istream_helper<T1>(__is, __x.first), istream_helper<T2>(__is, __x.second);
  }
};

template <class... Tps> struct istream_helper<std::tuple<Tps...>> {
  istream_helper(std::istream &__is, std::tuple<Tps...> &__x) {
    iterate(__is, __x);
  }

 private:
  template <class _Tp, size_t N = 0>
  void iterate(std::istream &__is, _Tp &__x) {
    if constexpr (N == std::tuple_size<_Tp>::value)
      return;
    else
      istream_helper<typename std::tuple_element<N, _Tp>::type>(
          __is, std::get<N>(__x)),
          iterate<_Tp, N + 1>(__is, __x);
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
    _istream_impl::istream_helper<_Tp>(*this, __x);
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
 * @brief Stream insertion operator for std::array.
 *
 * @param __os Output stream
 * @param __a Array
 * @return Reference to __os.
 */
template <class _Os, class _Tp, size_t _Nm>
ostream_ref<_Os> operator<<(_Os &__os, const std::array<_Tp, _Nm> &__a) {
  if constexpr (_Nm) {
    __os << __a[0];
    for (size_t __i = 1; __i != _Nm; ++__i) __os << ' ' << __a[__i];
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
    !std::is_same<std::decay_t<_Container>, std::string>::value &&
        !std::is_same<std::decay_t<_Container>, char *>::value,
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
#line 9 "Library/lib/utils"
// #include "src/utils/io/read.hpp"
#line 2 "Library/src/utils/grid/motion.hpp"

/**
 * @file motion.hpp
 * @brief Motion
 */

#line 9 "Library/src/utils/grid/motion.hpp"

namespace workspace {

/**
 * @brief Transpose.
 *
 * @param __grid
 */
template <class _Grid,
          typename = decltype(std::declval<std::decay_t<_Grid>>()[0].resize(0))>
constexpr decltype(auto) transpose(_Grid &&__grid) noexcept {
  auto __h = std::size(__grid), __w = std::size(__grid[0]);

  std::decay_t<_Grid> __t(__w);
  for (auto &&__r : __t) __r.resize(__h);

  for (size_t __i = 0; __i != __h; ++__i)
    for (size_t __j = 0; __j != __w; ++__j)
      if constexpr (std::is_rvalue_reference<decltype(__grid)>::value)
        __t[__j][__i] = std::move(__grid[__i][__j]);
      else
        __t[__j][__i] = __grid[__i][__j];

  return __t;
}

/**
 * @brief Transpose.
 *
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
 *
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
 *
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
 *
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
 *
 * @param __grid
 * @return
 */
template <class _Grid> decltype(auto) roll_ccw(_Grid &&__grid) noexcept {
  if constexpr (std::is_rvalue_reference<decltype(__grid)>::value) {
    auto __t = transpose(std::move(__grid));
    std::reverse(std::begin(__t), std::end(__t));
    return __t;
  }

  else {
    auto __t = transpose(__grid);
    std::reverse(std::begin(__t), std::end(__t));
    return __t;
  }
}

/**
 * @brief Roll the grid clockwise.
 *
 * @param __grid
 * @return
 */
template <class _Grid> decltype(auto) roll_cw(_Grid &&__grid) noexcept {
  if constexpr (std::is_rvalue_reference<decltype(__grid)>::value) {
    std::reverse(std::begin(__grid), std::end(__grid));
    return transpose(std::move(__grid));
  }

  else {
    auto __t = transpose(__grid);
    for (auto &&__r : __t) std::reverse(std::begin(__r), std::end(__r));
    return __t;
  }
}

}  // namespace workspace
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

/**
 * @file make_vector.hpp
 * @brief Multi-dimensional Vector
 */

#if __cplusplus >= 201703L

#include <tuple>
#include <vector>

namespace workspace {

/**
 * @brief Make a multi-dimensional vector.
 *
 * @param __dim Dimension
 * @param __x Initial value
 */
template <typename _Tp, class _Dim, size_t _Nm>
constexpr decltype(auto) make_vector([[maybe_unused]] _Dim* __dim,
                                     const _Tp& __x = _Tp()) {
  static_assert(std::is_convertible<_Dim, size_t>::value);

  if constexpr (_Nm)
    return std::vector(*__dim,
                       make_vector<_Tp, _Dim, _Nm - 1>(std::next(__dim), __x));
  else
    return __x;
}

/**
 * @brief Make a multi-dimensional vector.
 *
 * @param __dim Dimension
 * @param __x Initial value
 */
template <typename _Tp, class _Dim, size_t _Nm>
constexpr decltype(auto) make_vector(const _Dim (&__dim)[_Nm],
                                     const _Tp& __x = _Tp()) {
  return make_vector<_Tp, _Dim, _Nm>((_Dim*)__dim, __x);
}

/**
 * @brief Make a multi-dimensional vector.
 *
 * @param __dim Dimension
 * @param __x Initial value
 */
template <typename _Tp, class _Dim, size_t _Nm = 0>
constexpr decltype(auto) make_vector([[maybe_unused]] const _Dim& __dim,
                                     const _Tp& __x = _Tp()) {
  if constexpr (_Nm == std::tuple_size<_Dim>::value)
    return __x;

  else {
    static_assert(
        std::is_convertible<std::tuple_element_t<_Nm, _Dim>, size_t>::value);

    return std::vector(std::get<_Nm>(__dim),
                       make_vector<_Tp, _Dim, _Nm + 1>(__dim, __x));
  }
}

}  // namespace workspace

#endif
#line 2 "Library/src/utils/py-like/enumerate.hpp"

/**
 * @file enumerate.hpp
 * @brief Enumerate
 */

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
#line 2 "Library/src/utils/py-like/zip.hpp"

/**
 * @file zip.hpp
 * @brief Zip
 */

#line 11 "Library/src/utils/py-like/zip.hpp"

#line 14 "Library/src/utils/py-like/zip.hpp"

#if __cplusplus >= 201703L

namespace workspace {

namespace internal {

template <class> struct zipped_iterator;

template <class...> struct zipped_iterator_tuple;

template <class... Args> class zipped {
  using ref_tuple = std::tuple<Args...>;
  ref_tuple args;

  template <size_t N = 0> constexpr auto begin_cat() const noexcept {
    if constexpr (N != std::tuple_size<ref_tuple>::value) {
      return std::tuple_cat(std::tuple(std::begin(std::get<N>(args))),
                            begin_cat<N + 1>());
    } else
      return std::tuple<>();
  }

  template <size_t N = 0> constexpr auto end_cat() const noexcept {
    if constexpr (N != std::tuple_size<ref_tuple>::value) {
      return std::tuple_cat(std::tuple(std::end(std::get<N>(args))),
                            end_cat<N + 1>());
    } else
      return std::tuple<>();
  }

 public:
  constexpr zipped(Args &&... args) noexcept : args(args...) {}

  class iterator {
    using base_tuple = typename zipped_iterator_tuple<Args...>::type;

   public:
    using iterator_category =
        typename common_iterator_category<base_tuple>::type;
    using difference_type = std::ptrdiff_t;
    using value_type = zipped_iterator<base_tuple>;
    using reference = zipped_iterator<base_tuple> &;
    using pointer = iterator;

   protected:
    value_type current;

    template <size_t N = 0>
    constexpr bool equal(const iterator &rhs) const noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        return std::get<N>(current) == std::get<N>(rhs.current) ||
               equal<N + 1>(rhs);
      } else
        return false;
    }

    template <size_t N = 0> constexpr void increment() noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        ++std::get<N>(current);
        increment<N + 1>();
      }
    }

    template <size_t N = 0> constexpr void decrement() noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        --std::get<N>(current);
        decrement<N + 1>();
      }
    }

    template <size_t N = 0>
    constexpr void advance(difference_type __d) noexcept {
      if constexpr (N != std::tuple_size<base_tuple>::value) {
        std::get<N>(current) += __d;
        advance<N + 1>(__d);
      }
    }

   public:
    constexpr iterator() noexcept = default;
    constexpr iterator(base_tuple const &current) noexcept : current(current) {}

    constexpr bool operator==(const iterator &rhs) const noexcept {
      return equal(rhs);
    }
    constexpr bool operator!=(const iterator &rhs) const noexcept {
      return !equal(rhs);
    }

    constexpr iterator &operator++() noexcept {
      increment();
      return *this;
    }
    constexpr iterator &operator--() noexcept {
      decrement();
      return *this;
    }

    constexpr bool operator<(const iterator &rhs) const noexcept {
      return std::get<0>(current) < std::get<0>(rhs.current);
    }

    constexpr bool operator<=(const iterator &rhs) const noexcept {
      return std::get<0>(current) <= std::get<0>(rhs.current);
    }

    constexpr iterator &operator+=(difference_type __d) noexcept {
      advance(__d);
      return *this;
    }

    constexpr iterator &operator-=(difference_type __d) noexcept {
      advance(-__d);
      return *this;
    }

    constexpr iterator operator+(difference_type __d) const noexcept {
      return iterator{*this} += __d;
    }

    constexpr iterator operator-(difference_type __d) const noexcept {
      return iterator{*this} -= __d;
    }

    constexpr difference_type operator-(const iterator &rhs) const noexcept {
      return std::get<0>(current) - std::get<0>(rhs.current);
    }

    constexpr reference operator*() noexcept { return current; }
  };

  constexpr iterator begin() const noexcept { return iterator{begin_cat()}; }
  constexpr iterator end() const noexcept { return iterator{end_cat()}; }

  constexpr reverse_iterator<iterator> rbegin() const noexcept {
    return reverse_iterator<iterator>{end()};
  }
  constexpr reverse_iterator<iterator> rend() const noexcept {
    return reverse_iterator<iterator>{begin()};
  }
};

template <class Tp, class... Args> struct zipped_iterator_tuple<Tp, Args...> {
  using type = decltype(std::tuple_cat(
      std::declval<std::tuple<decltype(std::begin(std::declval<Tp>()))>>(),
      std::declval<typename zipped_iterator_tuple<Args...>::type>()));
};

template <> struct zipped_iterator_tuple<> { using type = std::tuple<>; };

template <class Iter_tuple> struct zipped_iterator : Iter_tuple {
  constexpr zipped_iterator(Iter_tuple const &__t) noexcept
      : Iter_tuple::tuple(__t) {}

  constexpr zipped_iterator(zipped_iterator const &__t) = default;

  constexpr zipped_iterator &operator=(zipped_iterator const &__t) = default;

  // Avoid move initialization.
  constexpr zipped_iterator(zipped_iterator &&__t)
      : zipped_iterator(static_cast<zipped_iterator const &>(__t)) {}

  // Avoid move assignment.
  zipped_iterator &operator=(zipped_iterator &&__t) {
    return operator=(static_cast<zipped_iterator const &>(__t));
  }

  template <size_t N>
  friend constexpr auto &get(zipped_iterator<Iter_tuple> const &__z) noexcept {
    return *std::get<N>(__z);
  }

  template <size_t N>
  friend constexpr auto get(zipped_iterator<Iter_tuple> &&__z) noexcept {
    return *std::get<N>(__z);
  }
};

}  // namespace internal

}  // namespace workspace

namespace std {

template <size_t N, class Iter_tuple>
struct tuple_element<N, workspace::internal::zipped_iterator<Iter_tuple>> {
  using type = typename remove_reference<typename iterator_traits<
      typename tuple_element<N, Iter_tuple>::type>::reference>::type;
};

template <class Iter_tuple>
struct tuple_size<workspace::internal::zipped_iterator<Iter_tuple>>
    : tuple_size<Iter_tuple> {};

}  // namespace std

namespace workspace {

template <class... Args> constexpr auto zip(Args &&... args) noexcept {
  return internal::zipped<Args...>(std::forward<Args>(args)...);
}

template <class... Args>
constexpr auto zip(std::initializer_list<Args> const &... args) noexcept {
  return internal::zipped<const std::initializer_list<Args>...>(args...);
}

}  // namespace workspace

#endif
#line 10 "Library/src/utils/py-like/enumerate.hpp"

#if __cplusplus >= 201703L

namespace workspace {

namespace _enumerate_impl {

constexpr size_t min_size() noexcept { return SIZE_MAX; }

template <class _Container, class... _Args>
constexpr size_t min_size(_Container const &__cont,
                          _Args &&... __args) noexcept {
  return std::min(std::size(__cont), min_size(std::forward<_Args>(__args)...));
}

}  // namespace _enumerate_impl

template <class... _Args>
constexpr decltype(auto) enumerate(_Args &&... __args) noexcept {
  return zip(range(_enumerate_impl::min_size(__args...)),
             std::forward<_Args>(__args)...);
}

template <class... _Args>
constexpr decltype(auto) enumerate(
    std::initializer_list<_Args> const &... __args) noexcept {
  return zip(range(_enumerate_impl::min_size(__args...)),
             std::vector(__args)...);
}

}  // namespace workspace

#endif
#line 17 "Library/lib/utils"
// #include "src/utils/py-like/reversed.hpp"
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
#line 11 "codeforces-workspace/contest/1514/a/a.cpp"

signed main() {
  using namespace workspace;

  io_setup(15);

  //* given
  case_info.read();  //*/

  /* unspecified
    case_info.total = -1;  //*/

  return case_info.iterate();
}

namespace workspace {

void main() {
  // start here!

  int n;
  cin >> n;
  bool yes = 0;
  for (auto i : range(n)) {
    int a;
    cin >> a;
    int b = round(sqrt(a));
    if (a != b * b) {
      yes = 1;
    }
  }
  cout << (yes ? "YES" : "NO") << "\n";
}

}  // namespace workspace