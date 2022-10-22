#line 1 "codeforces-workspace/contest/698/f/f.cpp"
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
#line 13 "codeforces-workspace/contest/698/f/f.cpp"
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
#line 2 "Library/src/utils/cat.hpp"

/**
 * @file cat.hpp
 * @brief Cat
 */

#line 9 "Library/src/utils/cat.hpp"

namespace workspace {

template <class C1, class C2>
constexpr C1 &&cat(C1 &&__c1, C2 const &__c2) noexcept {
  __c1.insert(__c1.end(), std::begin(__c2), std::end(__c2));
  return __c1;
}

}  // namespace workspace
#line 2 "Library/src/utils/chval.hpp"

/*
 * @file chval.hpp
 * @brief Change Less/Greater
 */

#line 9 "Library/src/utils/chval.hpp"

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
#line 2 "Library/src/utils/fixed_point.hpp"

/*
 * @file fixed_point.hpp
 * @brief Fixed Point Combinator
 */

#line 9 "Library/src/utils/fixed_point.hpp"

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
#line 2 "Library/src/utils/hash.hpp"

#line 8 "Library/src/utils/hash.hpp"

#line 2 "Library/src/utils/sfinae.hpp"

/*
 * @file sfinae.hpp
 * @brief SFINAE
 */

#line 11 "Library/src/utils/sfinae.hpp"

#ifdef __SIZEOF_INT128__
#define __INT128_DEFINED__ 1
#else
#define __INT128_DEFINED__ 0
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

template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class T, class = std::nullptr_t>
struct has_begin : std::false_type {};

template <class T>
struct has_begin<T, decltype(std::begin(std::declval<T>()), nullptr)>
    : std::true_type {};

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

#if __INT128_DEFINED__

template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};

#endif

#if __cplusplus >= 201402

template <class T>
constexpr static bool is_integral_ext_v = is_integral_ext<T>::value;

#endif

template <typename T, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename T>
struct multiplicable_uint<
    T, typename std::enable_if<(2 < sizeof(T)) &&
                               (!__INT128_DEFINED__ || sizeof(T) <= 4)>::type> {
  using type = uint_least64_t;
};

#if __INT128_DEFINED__

template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(4 < sizeof(T))>::type> {
  using type = __uint128_t;
};

#endif

}  // namespace workspace
#line 10 "Library/src/utils/hash.hpp"
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
#line 2 "Library/src/utils/io/istream.hpp"

/*
 * @file istream.hpp
 * @brief Input Stream
 */

#include <cxxabi.h>

#line 13 "Library/src/utils/io/istream.hpp"

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

template <> struct istream_helper<__int128_t, std::nullptr_t> {
  istream_helper(std::istream &is, __int128_t &x) {
    std::string s;
    is >> s;
    bool negative = s.front() == '-' ? s.erase(s.begin()), true : false;
    x = 0;
    for (char e : s) x = x * 10 + e - '0';
    if (negative) x = -x;
  }
};

template <> struct istream_helper<__uint128_t, std::nullptr_t> {
  istream_helper(std::istream &is, __uint128_t &x) {
    std::string s;
    is >> s;
    bool negative = s.front() == '-' ? s.erase(s.begin()), true : false;
    x = 0;
    for (char e : s) x = x * 10 + e - '0';
    if (negative) x = -x;
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

namespace internal {
auto *const cin_ptr = (istream *)&std::cin;
}
auto &cin = *internal::cin_ptr;

}  // namespace workspace
#line 2 "Library/src/utils/io/ostream.hpp"

/*
 * @file ostream.hpp
 * @brief Output Stream
 */

#line 10 "Library/src/utils/io/ostream.hpp"

namespace workspace {

template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
template <class tuple_t, size_t index> struct tuple_os {
  static std::ostream &apply(std::ostream &os, const tuple_t &t) {
    tuple_os<tuple_t, index - 1>::apply(os, t);
    return os << ' ' << std::get<index>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, 0> {
  static std::ostream &apply(std::ostream &os, const tuple_t &t) {
    return os << std::get<0>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, SIZE_MAX> {
  static std::ostream &apply(std::ostream &os, const tuple_t &t) { return os; }
};

template <class... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &t) {
  return tuple_os<std::tuple<T...>,
                  std::tuple_size<std::tuple<T...>>::value - 1>::apply(os, t);
}

template <class Container,
          typename = decltype(std::begin(std::declval<Container>()))>
typename std::enable_if<
    !std::is_same<typename std::decay<Container>::type, std::string>::value &&
        !std::is_same<typename std::decay<Container>::type, char *>::value,
    std::ostream &>::type
operator<<(std::ostream &os, const Container &cont) {
  bool head = true;
  for (auto &&e : cont) head ? head = 0 : (os << ' ', 0), os << e;
  return os;
}

}  // namespace workspace
#line 8 "Library/lib/utils"
// #include "src/utils/io/read.hpp"
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
#line 13 "Library/lib/utils"
// #include "src/utils/py-like/enumerate.hpp"
#line 2 "Library/src/utils/py-like/range.hpp"

/*
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
  return reversal(range(std::forward<Args>(args)...));
}

}  // namespace workspace

#endif
#line 15 "Library/lib/utils"
// #include "src/utils/py-like/reversed.hpp"
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
#line 2 "Library/src/utils/rand/rng.hpp"

/**
 * @file rng.hpp
 * @brief Random Number Generator
 */

#line 9 "Library/src/utils/rand/rng.hpp"

namespace workspace {

template <typename Arithmetic>
using uniform_distribution =
    typename std::conditional<std::is_integral<Arithmetic>::value,
                              std::uniform_int_distribution<Arithmetic>,
                              std::uniform_real_distribution<Arithmetic>>::type;

template <typename Arithmetic>
class random_number_generator : uniform_distribution<Arithmetic> {
  using base = uniform_distribution<Arithmetic>;

  std::mt19937 engine;

 public:
  template <class... Args>
  random_number_generator(Args&&... args)
      : base(args...), engine(std::random_device{}()) {}

  auto operator()() { return base::operator()(engine); }
};

}  // namespace workspace
#line 2 "Library/src/utils/rand/shuffle.hpp"

/**
 * @file shuffle.hpp
 * @brief Shuffle
 */

#line 10 "Library/src/utils/rand/shuffle.hpp"

namespace workspace {

template <class RAIter>
void shuffle(RAIter const& __first, RAIter const& __last) {
  static std::mt19937 engine(std::random_device{}());
  std::shuffle(__first, __last, engine);
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
#line 16 "codeforces-workspace/contest/698/f/f.cpp"

signed main() {
  using namespace workspace;

  io_setup(15);

  /* given
  case_info.read();  //*/

  /* unspecified
  case_info.total = -1; //*/

  return case_info.iterate();
}

#line 2 "Library/src/combinatorics/binomial.hpp"

/*
 * @file binomial.hpp
 * @brief Binomial Coefficient
 */

#line 2 "Library/src/modular/inverse.hpp"

/*
 * @file inverse.hpp
 * @brief Inverse Table
 */

#line 9 "Library/src/modular/inverse.hpp"

#line 2 "Library/src/modular/modint.hpp"

/**
 * @file modint.hpp
 *
 * @brief Modular Arithmetic
 */

#line 12 "Library/src/modular/modint.hpp"

#line 14 "Library/src/modular/modint.hpp"

namespace workspace {

namespace internal {

/**
 * @brief Base of modular arithmetic.
 *
 * @tparam Mod identifier, which represents modulus if positive
 * @tparam Storage Reserved size for inverse calculation
 */
template <auto Mod, unsigned Storage> struct modint_base {
  static_assert(is_integral_ext<decltype(Mod)>::value,
                "Mod must be integral type.");

  using mod_type = typename std::make_signed<typename std::conditional<
      0 < Mod, typename std::add_const<decltype(Mod)>::type,
      decltype(Mod)>::type>::type;

  using value_type = typename std::decay<mod_type>::type;

  using mul_type = typename multiplicable_uint<value_type>::type;

  static mod_type mod;

  static value_type storage;

  constexpr static void reserve(unsigned __n) noexcept { storage = __n; }

 protected:
  value_type value = 0;

 public:
  constexpr modint_base() noexcept = default;

  template <class int_type,
            typename std::enable_if<is_integral_ext<int_type>::value>::type * =
                nullptr>
  constexpr modint_base(int_type n) noexcept
      : value((n %= mod) < 0 ? n += mod : n) {}

  constexpr modint_base(bool n) noexcept : value(n) {}

  constexpr operator value_type() const noexcept { return value; }

  constexpr static modint_base one() noexcept { return 1; }

  // unary operators {{
  constexpr modint_base operator++(int) noexcept {
    modint_base __t{*this};
    operator++();
    return __t;
  }

  constexpr modint_base operator--(int) noexcept {
    modint_base __t{*this};
    operator--();
    return __t;
  }

  constexpr modint_base &operator++() noexcept {
    if (++value == mod) value = 0;
    return *this;
  }

  constexpr modint_base &operator--() noexcept {
    if (!value) value = mod;
    --value;
    return *this;
  }

  constexpr modint_base operator-() const noexcept {
    modint_base __t;
    __t.value = value ? mod - value : 0;
    return __t;
  }

  // }} unary operators

  // operator+= {{

  constexpr modint_base &operator+=(modint_base const &rhs) noexcept {
    if ((value += rhs.value) >= mod) value -= mod;
    return *this;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type &
  operator+=(int_type const &rhs) noexcept {
    if (((value += rhs) %= mod) < 0) value += mod;
    return *this;
  }

  // }} operator+=

  // operator+ {{

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  operator+(int_type const &rhs) const noexcept {
    return modint_base{*this} += rhs;
  }

  constexpr modint_base operator+(modint_base rhs) const noexcept {
    return rhs += *this;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  operator+(int_type const &lhs, modint_base rhs) noexcept {
    return rhs += lhs;
  }

  // }} operator+

  // operator-= {{

  constexpr modint_base &operator-=(modint_base const &rhs) noexcept {
    if ((value -= rhs.value) < 0) value += mod;
    return *this;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type &
  operator-=(int_type rhs) noexcept {
    if (((value -= rhs) %= mod) < 0) value += mod;
    return *this;
  }

  // }} operator-=

  // operator- {{

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  operator-(int_type const &rhs) const noexcept {
    return modint_base{*this} -= rhs;
  }

  constexpr modint_base operator-(modint_base const &rhs) const noexcept {
    modint_base __t;
    if (((__t.value = value) -= rhs.value) < 0) __t.value += mod;
    return __t;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  operator-(int_type lhs, modint_base const &rhs) noexcept {
    if (((lhs -= rhs.value) %= mod) < 0) lhs += mod;
    modint_base __t;
    __t.value = lhs;
    return __t;
  }

  // }} operator-

  // operator*= {{

  constexpr modint_base &operator*=(modint_base const &rhs) noexcept {
    if (!rhs.value) {
      value = 0;
    } else if (value) {
      mul_type __r(value);
      value = static_cast<value_type>((__r *= rhs.value) %= mod);
    }
    return *this;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type &
  operator*=(int_type rhs) noexcept {
    if (!rhs)
      value = 0;
    else if (value) {
      if ((rhs %= mod) < 0) rhs += mod;
      mul_type __r(value);
      value = static_cast<value_type>((__r *= rhs) %= mod);
    }
    return *this;
  }

  // }} operator*=

  // operator* {{

  constexpr modint_base operator*(modint_base const &rhs) const noexcept {
    if (!value or !rhs.value) return {};
    mul_type __r(value);
    modint_base __t;
    __t.value = static_cast<value_type>((__r *= rhs.value) %= mod);
    return __t;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  operator*(int_type rhs) const noexcept {
    if (!value or !rhs) return {};
    if ((rhs %= mod) < 0) rhs += mod;
    mul_type __r(value);
    modint_base __t;
    __t.value = static_cast<value_type>((__r *= rhs) %= mod);
    return __t;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  operator*(int_type lhs, modint_base const &rhs) noexcept {
    if (!lhs or !rhs.value) return {};
    if ((lhs %= mod) < 0) lhs += mod;
    mul_type __r(lhs);
    modint_base __t;
    __t.value = (__r *= rhs.value) %= mod;
    return __t;
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

  template <class int_type>
  constexpr static typename std::enable_if<is_integral_ext<int_type>::value,
                                           value_type>::type
  _div(mul_type __r, int_type __x) noexcept {
    assert(__x);
    if (!__r) return 0;
    int_type __v{};
    bool __neg = __x < 0 ? __x = -__x, true : false;
    if (__x < storage) {
      __v = _mem(__x);
    } else {
      int_type __y{mod}, __u{1}, __t;
      while (__x)
        __t = __y / __x, __y ^= __x ^= (__y -= __t * __x) ^= __x,
        __v ^= __u ^= (__v -= __t * __u) ^= __u;
      if (__y < 0) __neg ^= 1;
    }
    if (__neg)
      __v = 0 < __v ? mod - __v : -__v;
    else if (__v < 0)
      __v += mod;
    if (__r == 1) return static_cast<value_type>(__v);
    return static_cast<value_type>((__r *= __v) %= mod);
  }

 public:
  // operator/= {{

  constexpr modint_base &operator/=(modint_base const &rhs) noexcept {
    if (value) value = _div(value, rhs.value);
    return *this;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type &
  operator/=(int_type rhs) noexcept {
    if (value) value = _div(value, rhs %= mod);
    return *this;
  }

  // }} operator/=

  // operator/ {{

  constexpr modint_base operator/(modint_base const &rhs) const noexcept {
    if (!value) return {};
    modint_base __t;
    __t.value = _div(value, rhs.value);
    return __t;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  operator/(int_type rhs) const noexcept {
    if (!value) return {};
    modint_base __t;
    __t.value = _div(value, rhs %= mod);
    return __t;
  }

  template <class int_type>
  constexpr friend typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  operator/(int_type lhs, modint_base const &rhs) noexcept {
    if (!lhs) return {};
    if ((lhs %= mod) < 0) lhs += mod;
    modint_base __t;
    __t.value = _div(lhs, rhs.value);
    return __t;
  }

  // }} operator/

  constexpr modint_base inv() const noexcept { return _div(1, value); }

  template <class int_type>
  friend constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                           modint_base>::type
  pow(modint_base b, int_type e) noexcept {
    if (e < 0) {
      e = -e;
      b.value = _div(1, b.value);
    }
    modint_base __r;
    for (__r.value = 1; e; e >>= 1, b *= b)
      if (e & 1) __r *= b;
    return __r;
  }

  template <class int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    modint_base>::type
  pow(int_type e) const noexcept {
    modint_base __r, b;
    __r.value = 1;
    for (b.value = e < 0 ? e = -e, _div(1, value) : value; e; e >>= 1, b *= b)
      if (e & 1) __r *= b;
    return __r;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const modint_base &rhs) noexcept {
    return os << rhs.value;
  }

  friend std::istream &operator>>(std::istream &is, modint_base &rhs) noexcept {
    intmax_t value;
    rhs = (is >> value, value);
    return is;
  }
};

template <auto Mod, unsigned Storage>
typename modint_base<Mod, Storage>::mod_type modint_base<Mod, Storage>::mod =
    Mod > 0 ? Mod : 0;

template <auto Mod, unsigned Storage>
typename modint_base<Mod, Storage>::value_type
    modint_base<Mod, Storage>::storage = Storage;

}  // namespace internal

/**
 * @brief Modular arithmetic.
 *
 * @tparam Mod modulus
 * @tparam Storage Reserved size for inverse calculation
 */
template <auto Mod, unsigned Storage = 0,
          typename std::enable_if<(Mod > 0)>::type * = nullptr>
using modint = internal::modint_base<Mod, Storage>;

/**
 * @brief Runtime modular arithmetic.
 *
 * @tparam type_id uniquely assigned
 * @tparam Storage Reserved size for inverse calculation
 */
template <unsigned type_id = 0, unsigned Storage = 0>
using modint_runtime = internal::modint_base<-(signed)type_id, Storage>;

// #define modint_newtype modint_runtime<__COUNTER__>

}  // namespace workspace
#line 11 "Library/src/modular/inverse.hpp"

namespace workspace {

// Modulus must be prime.
template <class Modint> struct inverse_table {
  static_assert(std::is_same<std::nullptr_t,
                             decltype((void *)Modint::mod, nullptr)>::value);

  using value_type = Modint;

  constexpr value_type operator()(int n) const {
    constexpr int_fast64_t mod = value_type::mod;
    assert(n %= mod);
    if (n < 0) n += mod;
    if (inv.empty()) inv = {1, mod != 1};
    for (int m(inv.size()); m <= n; ++m)
      inv.emplace_back(mod / m * -inv[mod % m]);
    return inv[n];
  }

 private:
  static std::vector<value_type> inv;
};

template <class Modint> std::vector<Modint> inverse_table<Modint>::inv;

}  // namespace workspace
#line 2 "Library/src/combinatorics/factorial.hpp"

/*
 * @brief Factorial
 */

#line 10 "Library/src/combinatorics/factorial.hpp"

namespace workspace {

/*
template <class Tp, class Op = std::multiplies<Tp>> class factorial {
  std::vector<Tp> fact;
  Op op;

 public:
  factorial(Tp init = 1, Op op = Op()) : fact{init}, op{op} {}

  Tp operator()(int_least32_t n) noexcept {
    if (n < 0) return 0;
    for (int_least32_t m(fact.size()); m <= n; ++m)
      fact.emplace_back(op(fact.back(), m));
    return fact[n];
  }
};
*/

template <class Tp> Tp factorial(int_fast32_t __x) noexcept {
  if (__x < 0) return 0;
  static std::vector<Tp> __t{1};
  static int_fast32_t __i = (__t.reserve(0x1000000), 0);
  while (__i < __x) {
    ++__i;
    __t.emplace_back(__t.back() * __i);
  }
  return __t[__x];
}

template <class Tp> Tp factorial_inverse(int_fast32_t __x) noexcept {
  if (__x < 0) return 0;
  static std::vector<Tp> __t{1};
  static int_fast32_t __i = (__t.reserve(0x1000000), 0);
  while (__i < __x) {
    ++__i;
    __t.emplace_back(__t.back() / __i);
  }
  return __t[__x];
}

}  // namespace workspace
#line 11 "Library/src/combinatorics/binomial.hpp"

namespace workspace {

/*
template <class, class = int> struct binomial;
template <class Modint> struct binomial<Modint> {
  static_assert(std::is_same<std::nullptr_t,
                             decltype((void *)Modint::mod, nullptr)>::value);

  using value_type = Modint;
  struct mulinv_Op {
    value_type operator()(const value_type &f, const size_t &n) const noexcept {
      return f * inv(n);
    }
  };

  static inverse_table<value_type> inv;
  static factorial<value_type, mulinv_Op> fact_inv;
  static factorial<value_type> fact;

  value_type operator()(int_least32_t n, int_least32_t k) noexcept {
    return fact_inv(k) * fact_inv(n - k) * fact(n);
  }
};

template <class Modint> inverse_table<Modint> binomial<Modint>::inv;
template <class Modint>
factorial<Modint, class binomial<Modint>::mulinv_Op> binomial<Modint>::fact_inv;
template <class Modint> factorial<Modint> binomial<Modint>::fact;
*/

/**
 * @brief Binomial coefficient for integer args
 */
template <class Tp> Tp binomial(int_fast32_t __x, int_fast32_t __y) {
  if (!__y) return 1;
  if (__y < 0 || __x < __y) return 0;
  return factorial<Tp>(__x) * factorial_inverse<Tp>(__y) *
         factorial_inverse<Tp>(__x - __y);
}

}  // namespace workspace
#line 1 "Library/src/combinatorics/factorial_inverse.hpp"

#line 2 "Library/src/number_theory/ext_gcd.hpp"

/*
 * @file ext_gcd
 * @brief Extended Euclidean Algorithm
 */

#line 9 "Library/src/number_theory/ext_gcd.hpp"

#line 11 "Library/src/number_theory/ext_gcd.hpp"

namespace workspace {

/**
 * @param a Integer
 * @param b Integer
 * @return Pair of integers (x, y) s.t. ax + by = g = gcd(a, b), |x| < |b/g|,
 * |y| < |a/g|.
 * @note return (0, 0) if (a, b) = (0, 0)
 */
template <typename T1, typename T2> constexpr auto ext_gcd(T1 a, T2 b) {
  static_assert(is_integral_ext<T1>::value);
  static_assert(is_integral_ext<T2>::value);
  using result_type =
      typename std::make_signed<typename std::common_type<T1, T2>::type>::type;
  result_type p{1}, q{}, r{}, s{1}, t;
  while (b) {
    r ^= p ^= r ^= p -= (t = a / b) * r;
    s ^= q ^= s ^= q -= t * s;
    b ^= a ^= b ^= a %= b;
  }
  if (a < 0) p = -p, q = -q;
  return std::make_pair(p, q);
}

}  // namespace workspace
#line 2 "Library/src/number_theory/least_factor.hpp"

/**
 * @file least_factor.hpp
 * @brief Least Prime Factor
 */

#line 10 "Library/src/number_theory/least_factor.hpp"

#line 12 "Library/src/number_theory/least_factor.hpp"

namespace workspace {

/**
 * @brief Calculate the least prime factor for positive integers.
 *
 * @tparam N Range of calculation, exclusive
 */
template <unsigned N> class least_factor {
  unsigned least[N], prime[N >> 3], n;

 public:
  least_factor() : least{}, prime{}, n{} {
    for (auto i = 2u; i < N; ++i) {
      if (!least[i]) prime[n++] = least[i] = i;
      for (auto *p = prime; *p && *p <= least[i] && *p * i < N; ++p) {
        least[*p * i] = *p;
      }
    }
  }

  /**
   * @param x An integer with 0 < |x| < N
   * @return Least prime factor of x
   */
  template <typename int_type>
  constexpr
      typename std::enable_if<is_integral_ext<int_type>::value, int_type>::type
      operator()(int_type x) const {
    assert(x);
    if (x < 0) x = -x;
    assert((unsigned)x < N);
    return least[x];
  }

  /**
   * @brief Factorize
   *
   * @param x An integer with 0 < |x| < N
   * @return Prime factors in ascending order.
   */
  template <typename int_type>
  constexpr typename std::enable_if<is_integral_ext<int_type>::value,
                                    std::vector<int_type>>::type
  factorize(int_type x) const {
    assert(x);
    if (x < 0) x = -x;
    assert((unsigned)x < N);
    std::vector<int_type> __p;
    while (x != 1) {
      __p.emplace_back(least[x]);
      x /= least[x];
    }
    return __p;
  }

  /**
   * @return Sorted list of prime numbers less than N
   */
  const std::vector<unsigned> &primes() const {
    static const std::vector<unsigned> prime_vector(prime, prime + n);
    return prime_vector;
  }
};

}  // namespace workspace
#line 1 "Library/src/number_theory/primitive_root.hpp"
/**
 * @file primitive_root.hpp
 * @brief Primitive Root
 * @date 2020-12-28
 */

#line 8 "Library/src/number_theory/primitive_root.hpp"

#line 10 "Library/src/number_theory/primitive_root.hpp"

#if __cplusplus >= 201703L

#include <optional>

namespace workspace {

/**
 * @brief Compile time primitive root.
 *
 * @tparam __mod A positive integer
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

  for (int_type __r = 1; __r != __mod; ++__r) {
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

#endif
#line 33 "codeforces-workspace/contest/698/f/f.cpp"

namespace workspace {

using mint = modint<(int)1e9 + 7>;
least_factor<1010101> lst;

void main() {
  // start here!

  int n;
  cin >> n;
  vector<int> t(n + 1);
  map<vector<int>, int> f;
  for (auto i : range(1, n + 1)) {
    auto il = lst.factorize(i);
    il.erase(unique(begin(il), end(il)), end(il));
    int x;
    cin >> x;
    if (!x) {
      f[il]++;
      continue;
    }
    auto xl = lst.factorize(x);
    xl.erase(unique(begin(xl), end(xl)), end(xl));
    if (i > 1) {
      if (x > 1) {
        auto p = xl.back(), q = il.back();
        xl.pop_back();
        il.pop_back();
        if (xl != il) eject(0);
        if (n / p != n / q) eject(0);
        if (t[p] && t[p] != q) eject(0);
        t[p] = q;
      } else {
        if (i > 1 && (lst(i) != i || n / i > 1)) eject(0);
        t[1] = i;
      }
    } else {
      if (x > 1 && (lst(x) != x || n / x > 1)) eject(0);
      t[x] = 1;
    }
  }
  mint ans{1};
  vector<int> c(n + 1);
  for (auto i : range(2, n + 1)) {
    if (lst(i) != i) continue;
    if (!t[i]) c[n / i]++;
  }
  if (!t[1]) c[1]++;
  for (auto x : c) {
    ans *= factorial<mint>(x);
  }
  for (auto &&[v, x] : f) {
    ans *= factorial<mint>(x);
  }
  cout << ans << "\n";
}

}  // namespace workspace