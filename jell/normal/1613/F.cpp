#line 1 "codeforces-workspace\\contest\\1613\\f\\f.cpp"
#if defined(ONLINE_JUDGE)  // && 0
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
#endif

// #undef _GLIBCXX_DEBUG
#include <bits/extc++.h>

#line 2 "Library\\src\\algebra\\modint.hpp"

/**
 * @file modint.hpp
 * @brief Modular Arithmetic
 */

#line 11 "Library\\src\\algebra\\modint.hpp"

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
using element_type = typename std::decay<decltype(*std::begin(
    std::declval<Container&>()))>::type;

template <class _Tp, class = void> struct has_begin : std::false_type {};

template <class _Tp>
struct has_begin<
    _Tp, std::__void_t<decltype(std::begin(std::declval<const _Tp&>()))>>
    : std::true_type {
  using type = decltype(std::begin(std::declval<const _Tp&>()));
};

template <class _Tp, class = void> struct has_size : std::false_type {};

template <class _Tp>
struct has_size<_Tp, std::__void_t<decltype(std::size(std::declval<_Tp>()))>>
    : std::true_type {};

template <class _Tp, class = void> struct has_resize : std::false_type {};

template <class _Tp>
struct has_resize<_Tp, std::__void_t<decltype(std::declval<_Tp>().resize(
                           std::declval<size_t>()))>> : std::true_type {};

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

template <class _Container, class = void> struct get_dimension {
  static constexpr size_t value = 0;
};

template <class _Container>
struct get_dimension<_Container,
                     std::enable_if_t<has_begin<_Container>::value>> {
  static constexpr size_t value =
      1 + get_dimension<typename std::iterator_traits<
              typename has_begin<_Container>::type>::value_type>::value;
};

}  // namespace workspace
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
#line 14 "Library\\src\\algebra\\modint.hpp"

namespace workspace {

namespace _modint_impl {

template <auto _Mod, unsigned _Storage> struct modint {
  static_assert(is_integral_ext<decltype(_Mod)>::value,
                "_Mod must be integral type.");

  using mod_type = std::make_signed_t<typename std::conditional<
      0 < _Mod, std::add_const_t<decltype(_Mod)>, decltype(_Mod)>::type>;

  using value_type = std::decay_t<mod_type>;

  using reference = value_type &;
  using const_reference = value_type const &;

  using mul_type = typename multiplicable_uint<value_type>::type;

  static mod_type mod;  // Modulus.

  static unsigned storage;

 private:
  template <class _Tp>
  using modint_if = std::enable_if_t<is_integral_ext<_Tp>::value, modint>;

  value_type value = 0;  // within [0, mod).

  struct direct_ctor_t {};
  constexpr static direct_ctor_t direct_ctor_tag{};

  // Direct constructor
  template <class _Tp>
  constexpr modint(_Tp __n, direct_ctor_t) noexcept : value(__n) {}

 public:
  constexpr modint() noexcept = default;

  template <class _Tp, class = std::enable_if_t<
                           std::is_convertible<_Tp, value_type>::value>>
  constexpr modint(_Tp __n) noexcept
      : value((__n %= mod) < _Tp(0) ? static_cast<value_type>(__n) + mod
                                    : static_cast<value_type>(__n)) {}

  constexpr modint(bool __n) noexcept : value(__n) {}

  constexpr operator reference() noexcept { return value; }

  constexpr operator const_reference() const noexcept { return value; }

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

  template <class _Tp> constexpr modint_if<_Tp> &operator+=(_Tp __x) noexcept {
    __x %= mod, value += __x;
    if (value < 0)
      value += mod;
    else if (value >= mod)
      value -= mod;
    return *this;
  }

  // }} operator+=

  // operator+ {{

  template <class _Tp>
  constexpr modint_if<_Tp> operator+(_Tp const &__x) const noexcept {
    return modint{*this} += __x;
  }

  constexpr modint operator+(modint __x) const noexcept { return __x += *this; }

  template <class _Tp>
  constexpr friend modint_if<_Tp> operator+(_Tp const &__x,
                                            modint __y) noexcept {
    return __y += __x;
  }

  // }} operator+

  // operator-= {{

  constexpr modint &operator-=(const modint &__x) noexcept {
    if ((value -= __x.value) < 0) value += mod;
    return *this;
  }

  template <class _Tp> constexpr modint_if<_Tp> &operator-=(_Tp __x) noexcept {
    __x %= mod, value -= __x;
    if (value < 0)
      value += mod;
    else if (value >= mod)
      value -= mod;
    return *this;
  }

  // }} operator-=

  // operator- {{

  template <class _Tp>
  constexpr modint_if<_Tp> operator-(_Tp const &__x) const noexcept {
    return modint{*this} -= __x;
  }

  constexpr modint operator-(const modint &__x) const noexcept {
    return modint{*this} -= __x;
  }

  template <class _Tp>
  constexpr friend modint_if<_Tp> operator-(_Tp __x,
                                            const modint &__y) noexcept {
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

  template <class _Tp> constexpr modint_if<_Tp> &operator*=(_Tp __x) noexcept {
    value = static_cast<value_type>(
        value * ((__x %= mod) < 0 ? mul_type(__x + mod) : mul_type(__x)) % mod);
    return *this;
  }

  // }} operator*=

  // operator* {{

  constexpr modint operator*(const modint &__x) const noexcept {
    return {static_cast<mul_type>(value) * __x.value % mod, direct_ctor_tag};
  }

  template <class _Tp>
  constexpr modint_if<_Tp> operator*(_Tp __x) const noexcept {
    __x %= mod;
    if (__x < 0) __x += mod;
    return {static_cast<mul_type>(value) * __x % mod, direct_ctor_tag};
  }

  template <class _Tp>
  constexpr friend modint_if<_Tp> operator*(_Tp __x,
                                            const modint &__y) noexcept {
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
  static void reserve(unsigned __n) noexcept {
    if (storage < __n) storage = __n;
  }

  // operator/= {{

  constexpr modint &operator/=(const modint &__x) noexcept {
    if (value) value = _div(value, __x.value);
    return *this;
  }

  template <class _Tp> constexpr modint_if<_Tp> &operator/=(_Tp __x) noexcept {
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
  constexpr modint_if<_Tp> operator/(_Tp __x) const noexcept {
    if (!value) return {};
    return {_div(value, __x %= mod), direct_ctor_tag};
  }

  template <class _Tp>
  constexpr friend modint_if<_Tp> operator/(_Tp __x,
                                            const modint &__y) noexcept {
    if (!__x) return {};
    if ((__x %= mod) < 0) __x += mod;
    return {_div(__x, __y.value), direct_ctor_tag};
  }

  // }} operator/

  constexpr modint inv() const noexcept { return _div(1, value); }

  template <class _Tp> constexpr modint pow(_Tp __e) const noexcept {
    static_assert(not std::is_floating_point<_Tp>::value);

    modint __r{mod != 1, direct_ctor_tag};

    for (modint __b{__e < _Tp(0) ? __e = -__e, _div(1, value) : value,
                                   direct_ctor_tag};
         __e; __e /= 2, __b *= __b)
      if (__e % 2) __r *= __b;

    return __r;
  }

  template <class _Tp>
  constexpr friend modint pow(modint __b, _Tp __e) noexcept {
    static_assert(not std::is_floating_point<_Tp>::value);

    if (__e < _Tp(0)) {
      __e = -__e;
      __b.value = _div(1, __b.value);
    }

    modint __r{mod != 1, direct_ctor_tag};

    for (; __e; __e /= 2, __b *= __b)
      if (__e % 2) __r *= __b;

    return __r;
  }

  constexpr modint sqrt() const noexcept {
    return {sqrt_mod(value, mod), direct_ctor_tag};
  }

  friend constexpr modint sqrt(const modint &__x) noexcept {
    return {sqrt_mod(__x.value, mod), direct_ctor_tag};
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

constexpr unsigned _modint_default_storage = 1 << 24;

template <auto _Mod, unsigned _Storage = _modint_default_storage,
          typename = std::enable_if_t<(_Mod > 0)>>
using modint = _modint_impl::modint<_Mod, _Storage>;

template <unsigned _Id = 0, unsigned _Storage = _modint_default_storage>
using runtime_modint = _modint_impl::modint<-(signed)_Id, _Storage>;

template <unsigned _Id = 0, unsigned _Storage = _modint_default_storage>
using runtime_modint64 = _modint_impl::modint<-(int_least64_t)_Id, _Storage>;

}  // namespace workspace
#line 2 "Library\\src\\algebra\\polynomial.hpp"

/**
 * @file polynomial.hpp
 * @brief Polynomial
 */

#line 11 "Library\\src\\algebra\\polynomial.hpp"

#line 2 "Library\\src\\algebra\\fft.hpp"

#line 4 "Library\\src\\algebra\\fft.hpp"

#line 2 "Library\\src\\algebra\\complex.hpp"

/**
 * @file complex.hpp
 * @brief Complex
 */

namespace workspace {

// Complex number.
template <class _Tp> class complex {
  _Tp re, im;

  friend constexpr complex conj(const complex &x) noexcept {
    return {x.re, -x.im};
  }

  friend constexpr _Tp abs(const complex &x) noexcept {
    return hypot(x.re, x.im);
  }

  friend constexpr _Tp arg(const complex &x) noexcept {
    return atan2(x.re, x.im);
  }

  template <class _Is>
  friend constexpr _Is &operator>>(_Is &__is, complex &x) noexcept {
    return __is >> x.re >> x.im;
  }

  template <class _Os>
  friend constexpr _Os &operator<<(_Os &__os, const complex &x) noexcept {
    return __os << x.re << ' ' << x.im;
  }

 public:
  constexpr complex() noexcept : re{}, im{} {}
  constexpr complex(_Tp _re) noexcept : re{_re}, im{} {}
  constexpr complex(_Tp _re, _Tp _im) noexcept : re{_re}, im{_im} {}

  constexpr _Tp real() const noexcept { return re; }
  constexpr void real(_Tp _re) noexcept { re = _re; }

  constexpr _Tp imag() const noexcept { return im; }
  constexpr void imag(_Tp _im) noexcept { im = _im; }

  constexpr complex operator+() const noexcept { return *this; }
  constexpr complex operator-() const noexcept { return {-re, -im}; }

  constexpr complex &operator+=(const complex &x) noexcept {
    return re += x.re, im += x.im, *this;
  }
  constexpr complex &operator-=(const complex &x) noexcept {
    return re -= x.re, im -= x.im, *this;
  }
  constexpr complex &operator*=(const complex &x) noexcept {
    _Tp _re{re * x.re - im * x.im};
    return im = im * x.re + x.im * re, re = _re, *this;
  }
  constexpr complex &operator*=(_Tp x) noexcept {
    return re *= x, im *= x, *this;
  }
  constexpr complex &operator/=(const complex &x) noexcept {
    return (*this *= conj(x)) /= re * re + im * im;
  }
  constexpr complex &operator/=(_Tp x) noexcept {
    return re /= x, im /= x, *this;
  }

  constexpr complex operator+(const complex &x) const noexcept {
    return {re + x.re, im + x.im};
  }
  constexpr complex operator-(const complex &x) const noexcept {
    return {re - x.re, im - x.im};
  }

  constexpr complex operator*(const complex &x) const noexcept {
    return complex(*this) *= x;
  }

  constexpr complex operator*(_Tp x) const noexcept { return {re * x, im * x}; }

  constexpr complex operator/(const complex &x) const noexcept {
    return complex(*this) /= x;
  }

  constexpr complex operator/(_Tp x) const noexcept { return {re / x, im / x}; }
};

}  // namespace workspace
#line 2 "Library\\lib\\cxx17"

#line 2 "Library\\lib\\cxx14"

#ifndef _CXX14_CONSTEXPR
#if __cplusplus >= 201402L
#define _CXX14_CONSTEXPR constexpr
#else
#define _CXX14_CONSTEXPR
#endif
#endif
#line 4 "Library\\lib\\cxx17"

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

#line 22 "Library\\lib\\cxx17"

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

/**
 *  @brief  Return whether a container is empty.
 *  @param  __cont  Container.
 */
template <typename _Container>
[[nodiscard]] constexpr auto empty(const _Container& __cont) noexcept(
    noexcept(__cont.empty())) -> decltype(__cont.empty()) {
  return __cont.empty();
}

/**
 *  @brief  Return whether an array is empty (always false).
 */
template <typename _Tp, size_t _Nm>
[[nodiscard]] constexpr bool empty(const _Tp (&)[_Nm]) noexcept {
  return false;
}

/**
 *  @brief  Return whether an initializer_list is empty.
 *  @param  __il  Initializer list.
 */
template <typename _Tp>
[[nodiscard]] constexpr bool empty(initializer_list<_Tp> __il) noexcept {
  return __il.size() == 0;
}

struct monostate {};

}  // namespace std

#else

#include <variant>

#endif
#line 2 "Library\\src\\number_theory\\ext_gcd.hpp"

/**
 * @file ext_gcd.hpp
 * @brief Extended Euclidean Algorithm
 */

#line 9 "Library\\src\\number_theory\\ext_gcd.hpp"

#line 11 "Library\\src\\number_theory\\ext_gcd.hpp"

namespace workspace {

/**
 * @param __a Integer
 * @param __b Integer
 * @return Pair of integers (x, y) s.t. ax + by = g = gcd(a, b) and (b = 0 or 0
 * <= x < |b/g|) and (a = 0 or -|a/g| < y <= 0). Return (0, 0) if (a, b) = (0,
 * 0).
 */
template <typename _T1, typename _T2>
constexpr auto ext_gcd(_T1 __a, _T2 __b) noexcept {
  static_assert(is_integral_ext<_T1>::value);
  static_assert(is_integral_ext<_T2>::value);

  using value_type = typename std::make_signed<
      typename std::common_type<_T1, _T2>::type>::type;
  using result_type = std::pair<value_type, value_type>;

  value_type a{__a}, b{__b}, p{1}, q{}, r{}, s{1};

  while (b != value_type(0)) {
    auto t = a / b;
    r ^= p ^= r ^= p -= t * r;
    s ^= q ^= s ^= q -= t * s;
    b ^= a ^= b ^= a -= t * b;
  }

  if (a < 0) p = -p, q = -q, a = -a;

  if (p < 0) {
    __a /= a, __b /= a;

    if (__b > 0)
      p += __b, q -= __a;
    else
      p -= __b, q += __a;
  }

  return result_type{p, q};
}

/**
 * @param __a Integer
 * @param __b Integer
 * @param __c Integer
 * @return Pair of integers (x, y) s.t. ax + by = c and (b = 0 or 0 <= x <
 * |b/g|). Return (0, 0) if there is no solution.
 */
template <typename _T1, typename _T2, typename _T3>
constexpr auto ext_gcd(_T1 __a, _T2 __b, _T3 __c) noexcept {
  static_assert(is_integral_ext<_T1>::value);
  static_assert(is_integral_ext<_T2>::value);
  static_assert(is_integral_ext<_T3>::value);

  using value_type = typename std::make_signed<
      typename std::common_type<_T1, _T2, _T3>::type>::type;
  using result_type = std::pair<value_type, value_type>;

  value_type a{__a}, b{__b}, p{1}, q{}, r{}, s{1};

  while (b != value_type(0)) {
    auto t = a / b;
    r ^= p ^= r ^= p -= t * r;
    s ^= q ^= s ^= q -= t * s;
    b ^= a ^= b ^= a -= t * b;
  }

  if (__c % a) return result_type{};

  __a /= a, __b /= a, __c /= a;
  p *= __c, q *= __c;

  if (__b != value_type(0)) {
    auto t = p / __b;
    p -= __b * t;
    q += __a * t;

    if (p < 0) {
      if (__b > 0)
        p += __b, q -= __a;
      else
        p -= __b, q += __a;
    }
  }

  return result_type{p, q};
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
#line 10 "Library\\src\\algebra\\fft.hpp"

namespace workspace {

namespace _fft_impl {

template <class _Tp, bool = std::is_floating_point<_Tp>::value, class = void>
struct to_float {
  using type = double;
};

template <class _Tp> struct to_float<_Tp, true> { using type = _Tp; };

// template <class _Tp>
// struct to_float<_Tp, false, std::enable_if_t<sizeof(_Tp) <= sizeof(float)>> {
//   using type = float;
// };

template <class _Tp>
struct to_float<_Tp, false, std::enable_if_t<(sizeof(_Tp) > sizeof(double))>> {
  using type = long double;
};

// Assume ntt-friendly mod.
template <class _Tp> struct field {
  using type = std::conditional_t<has_mod<_Tp>::value, _Tp,
                                  complex<typename to_float<_Tp>::type>>;
};

template <class _Tp> struct field<complex<_Tp>> : field<_Tp> {};

// Modular
template <class _Tp, int _Nm = 29, bool = has_mod<_Tp>::value> struct coef {
  _Tp s[_Nm], is[_Nm], ip2[_Nm];

  _CXX14_CONSTEXPR coef() : s{}, is{}, ip2{1, (1 + _Tp::mod) / 2} {
    if (_Tp::mod < 2) return;

    int cnt2 = std::min(__builtin_ctz(_Tp::mod - 1), _Nm + 1);

    _Tp e = 1;
    _Tp w = primitive_root(_Tp::mod);
    for (auto p = (_Tp::mod - 1) >> cnt2; p; p >>= 1, w *= w)
      if (p & 1) e *= w;

    _Tp ie = ext_gcd(decltype(_Tp::mod)(e), _Tp::mod).first;
    _Tp es[_Nm]{}, ies[_Nm]{};

    for (int i = cnt2; i >= 2; i--) {
      es[i - 2] = e, e *= e;
      ies[i - 2] = ie, ie *= ie;
    }

    e = ie = 1;
    for (int i = 0; i < cnt2 - 1; i++) {
      s[i] = es[i] * e, e *= ies[i];
      is[i] = ies[i] * ie, ie *= es[i];
    }

    for (int i = 1; i < _Nm - 1; ++i) ip2[i + 1] = ip2[i] * ip2[1];
  }
};

// Complex
template <class _Tp, int _Nm> struct coef<_Tp, _Nm, false> {
  _Tp s[_Nm], is[_Nm], ip2[_Nm];

  static_assert(_Nm < 30);

  _CXX14_CONSTEXPR static _Tp es[29] = {
      {0, 1},
      {0.70710678118654752438189403651, 0.70710678118654752443610414514},
      {0.92387953251128675610142140795, 0.38268343236508977172325753068},
      {0.98078528040323044911909938781, 0.19509032201612826785692544201},
      {0.99518472667219688623102546998, 0.09801714032956060199569840382},
      {0.99879545620517239270077028412, 0.04906767432741801425693899119},
      {0.99969881869620422009748220149, 0.02454122852291228803212346128},
      {0.99992470183914454093764001552, 0.01227153828571992607945510345},
      {0.99998117528260114264494415325, 0.00613588464915447535972750246},
      {0.99999529380957617150137498041, 0.00306795676296597627029751672},
      {0.99999882345170190993313003025, 0.00153398018628476561237225788},
      {0.99999970586288221914474799723, 0.00076699031874270452695124765},
      {0.99999992646571785113833452651, 0.00038349518757139558906815188},
      {0.99999998161642929381167504976, 0.00019174759731070330743679009},
      {0.99999999540410731290905263501, 0.00009587379909597734587360460},
      {0.99999999885102682753608427379, 0.00004793689960306688454884772},
      {0.99999999971275670682981095982, 0.00002396844980841821872882467},
      {0.99999999992818917670745273995, 0.00001198422490506970642183282},
      {0.99999999998204729416331065783, 0.00000599211245264242784278378},
      {0.99999999999551182356793271877, 0.00000299605622633466075058210},
      {0.99999999999887795586487812538, 0.00000149802811316901122883643},
      {0.99999999999971948897977205850, 0.00000074901405658471572113723},
      {0.99999999999992987223139048746, 0.00000037450702829238412391495},
      {0.99999999999998246807140014902, 0.00000018725351414619534486931},
      {0.99999999999999561700429751010, 0.00000009362675707309808280024},
      {0.99999999999999890425107437752, 0.00000004681337853654909269501},
      {0.99999999999999972607632112153, 0.00000002340668926827455275977},
      {0.99999999999999993153263280754, 0.00000001170334463413727718121},
      {0.99999999999999998286960567472, 0.00000000585167231706863869077}};

  constexpr coef() : s{}, is{}, ip2{1, .5} {
    _Tp ies[_Nm];
    for (int i = 0; i < _Nm; ++i) ies[i] = _Tp(1) / es[i];

    _Tp e = 1, ie = 1;
    for (int i = 0; i < _Nm; i++) {
      s[i] = es[i] * e, e *= ies[i];
      is[i] = ies[i] * ie, ie *= es[i];
    }

    for (int i = 1; i < _Nm - 1; ++i) ip2[i + 1] = ip2[i] * ip2[1];
  }
};

}  // namespace _fft_impl

template <bool _Inverse = false, class _Iterator>
void fft(_Iterator __first, _Iterator __last) noexcept {
  using value_type = typename std::iterator_traits<_Iterator>::value_type;
  using difference_type =
      typename std::iterator_traits<_Iterator>::difference_type;

  _CXX14_CONSTEXPR _fft_impl::coef<value_type> c;
  auto __h = __builtin_ctz(std::distance(__first, __last));

  if _CXX17_CONSTEXPR (_Inverse) {
    for (difference_type __p = 1; __p >> __h ^ 1; __p <<= 1) {
      value_type __iw = 1;
      auto __l = __first;

      for (auto __i = 1 << __h; __l != __last;
           __iw *= c.is[__builtin_ctz(--__i)]) {
        auto __r = std::next(__l, __p);

        for (auto __mid = __r; __l != __mid; ++__l, ++__r) {
          auto __tmp = (*__l - *__r) * __iw;
          *__l += *__r;
          *__r = __tmp;
        }

        __l = __r;
      }
    }

    while (__first != __last) *--__last *= c.ip2[__h];
  }

  else {
    for (difference_type __p = 1 << __h; __p >>= 1;) {
      value_type __w = -1;
      auto __l = __first;

      for (auto __i = 1 << __h; __l != __last;
           __w *= c.s[__builtin_ctz(--__i)]) {
        auto __r = std::next(__l, __p);

        for (auto __mid = __r; __l != __mid; ++__l, ++__r) {
          auto __tmp = *__l;
          *__l -= *__r *= __w;
          *__r += __tmp;
        }

        __l = __r;
      }
    }
  }
}

template <class _Iterator>
void fft(_Iterator __first, std::size_t __n) noexcept {
  fft(__first, std::next(__first, __n));
}

template <class _Iterator>
void ifft(_Iterator __first, _Iterator __last) noexcept {
  fft<true>(__first, __last);
}

template <class _Iterator>
void ifft(_Iterator __first, std::size_t __n) noexcept {
  ifft(__first, std::next(__first, __n));
}

template <size_t _Nm, size_t _Dm, class _Container, class _Index>
decltype(auto) access(_Container &__a, const _Index &__i) {
  if constexpr (_Nm != _Dm)
    return access<_Nm + 1, _Dm>(__a[__i[_Nm]], __i);
  else
    return __a;
}

template <bool _Inverse, size_t _Dm, class _Container, class _Tp, class _Index>
void dive(_Container &__a, const _Tp &__t, _Index &__i) {
  if constexpr (has_size<_Tp>::value) {
    for (__i.emplace_back(0); __i.back() != std::size(__t); ++__i.back())
      dive<_Inverse, _Dm + 1>(__a, __t[__i.back()], __i);
    __i.pop_back();
  }

  else {
    static std::vector<_Tp> __work;
    // Resize to a power of 2.

    size_t __len = 1 << (31 - __builtin_clz(std::size(__a)));
    if (__work.size() < __len) __work.resize(__len);

    for (size_t __k = 0; __k != __len; ++__k)
      __work[__k] = std::move(access<0, _Dm>(__a[__k], __i));

    fft<_Inverse>(__work.data(), __work.data() + __len);

    for (size_t __k = 0; __k != __len; ++__k)
      access<0, _Dm>(__a[__k], __i) = std::move(__work[__k]);
  }
}

template <bool _Inverse, class _Container> void fft(_Container &__a) {
  if constexpr (has_size<_Container>::value) {
    if constexpr (has_resize<_Container>::value)
      // Resize to a power of 2.
      __a.resize(1 << (32 - __builtin_clz(__a.size() - 1)));

    std::vector<size_t> __i;
    dive<_Inverse, 0>(__a, __a[0], __i);

    for (size_t __k = 0; __k != std::size(__a); ++__k) fft<_Inverse>(__a[__k]);
  }
}

template <class _Container> auto conv_resize(_Container &__a, _Container &__b) {
  std::array<size_t, get_dimension<_Container>::value> __s;
  rec(__a, __s);
  rec(__b, __s);
  return __s;
}

template <size_t _Nm, class _Container, class _Size>
void rec(const _Container &__a, _Size &__s) {
  if constexpr (_Nm != __s.size()) {
    __s[_Nm] = std::max(__s[_Nm], std::size(__a));
    for (auto &__x : __a) rec<_Nm + 1>(__x, __s);
  }
}

}  // namespace workspace
#line 14 "Library\\src\\algebra\\polynomial.hpp"
// #include "ntt.hpp"
#line 16 "Library\\src\\algebra\\polynomial.hpp"

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

  template <class _Os> friend _Os& operator<<(_Os& __os, const poly& __x) {
    bool __head = true;
    for (const auto& __a : __x) {
      if (!__head) __os << ' ';
      __head = false;
      __os << __a;
    }
    return __os;
  }

 public:
  using typename vec::size_type;
  using typename vec::value_type;
  using vec::vec;

  using field = typename _fft_impl::field<_Tp>::type;

 protected:
  constexpr static _fft_impl::coef<field> __coef{};
  static std::vector<field> __work1, __work2;

  void _erase_leading_zeros() noexcept {
    auto __i = vec::_M_impl._M_finish;
    while (__i != vec::_M_impl._M_start && *(__i - 1) == _Tp(0)) --__i;
    vec::_M_erase_at_end(__i);
  }

  template <class _Iter> void _dft(_Iter __first, _Iter __last) const noexcept {
    // if _CXX17_CONSTEXPR (has_mod<_Tp>::value)
    // _ntt_impl::ntt(__first, __last);
    fft<false>(__first, __last);
    // else
  }

  template <class _Iter>
  void _idft(_Iter __first, _Iter __last) const noexcept {
    // if _CXX17_CONSTEXPR (has_mod<_Tp>::value)
    // _ntt_impl::intt(__first, __last);
    fft<true>(__first, __last);
    // else
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

  template <class _Poly> void _conv_dft(_Poly&& __x) noexcept {
    size_type __n = vec::_M_impl._M_finish - vec::_M_impl._M_start,
              __m = __x._M_impl._M_finish - __x._M_impl._M_start,
              __len = 1 << (32 - __builtin_clz(__n + __m - 1));

    if (__work1.size() < __len) __work1.resize(__len);
    if (__work2.size() < __len) __work2.resize(__len);

    vec::_M_default_append(__m - 1);

    if _CXX17_CONSTEXPR (std::is_same<_Tp, field>::value) {
      std::fill(std::move(vec::_M_impl._M_start, vec::_M_impl._M_finish,
                          __work1.data()),
                __work1.data() + __len, _Tp(0));

      std::fill(std::move(__x._M_impl._M_start, __x._M_impl._M_finish,
                          __work2.data()),
                __work2.data() + __len, _Tp(0));

      fft(__work1.data(), __len);
      fft(__work2.data(), __len);

      for (size_type __i = 0; __i < __len; ++__i)
        __work1[__i] *= std::move(__work2[__i]);

      ifft(__work1.data(), __len);

      std::move(__work1.data(), __work1.data() + __n + __m - 1,
                vec::_M_impl._M_start);
    }

    else {
      std::fill_n(__work1.data(), __len, _Tp(0));
      std::fill_n(__work2.data(), __len, _Tp(0));

      for (size_type __i = 0; __i < __n; ++__i)
        __work1[__i].real(vec::_M_impl._M_start[__i]);

      for (size_type __i = 0; __i < __m; ++__i)
        __work1[__i].imag(__x._M_impl._M_start[__i]);

      fft(__work1.data(), __len);

      __work2[0].imag(__work1[0].real() * __work1[0].imag());

      for (size_type __b = 1; __b != __len; __b <<= 1)
        for (size_type __i = __b, __j = __b << 1; __j-- != __b; ++__i)
          __work2[__i] = (__work1[__i] + conj(__work1[__j])) *
                         (__work1[__i] - conj(__work1[__j])) / 4;

      ifft(__work2.data(), __len);

      for (size_type __i = 0; __i < __n + __m - 1; ++__i)
        if _CXX17_CONSTEXPR (std::is_floating_point<_Tp>::value)
          vec::_M_impl._M_start[__i] = __work2[__i].imag();
        else
          vec::_M_impl._M_start[__i] = roundl(__work2[__i].imag());
    }
  }

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
    if (this == std::addressof(__x))  // with itself
      return operator*=(poly(__x));

    std::min(vec::size(), __x.size()) > _Conv_threshold ? _conv_dft(__x)
                                                        : _conv_naive(__x);

    return *this;
  }

  poly& operator*=(poly&& __x) noexcept {
    if (this == std::addressof(__x))  // with itself
      return operator*=(poly(__x));

    std::min(vec::size(), __x.size()) > _Conv_threshold
        ? _conv_dft(std::move(__x))
        : _conv_naive(std::move(__x));

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

  poly pow(size_type __e) const noexcept {
    if (vec::empty()) return *this;

    if (!__e) return {1};

    if (vec::size() == 1) {
      _Tp __x = vec::front(), __y = 1;
      for (auto __i = __e; __i; __i >>= 1, __x *= __x)
        if (__i & 1) __y *= __x;
      return {__y};
    }

    size_type __deg = (vec::size() - 1) * __e;
    assert(__deg > 0);

    poly __p(1 << (32 - __builtin_clz(__deg)));
    std::copy(vec::_M_impl._M_start, vec::_M_impl._M_finish,
              __p._M_impl._M_start);

    fft(__p._M_impl._M_start, __p._M_impl._M_finish);

    for (auto&& __x : __p) {
      _Tp __y = 1;
      for (auto __i = __e; __i; __i >>= 1, __x *= __x)
        if (__i & 1) __y *= __x;
      __x = __y;
    }

    ifft(__p._M_impl._M_start, __p._M_impl._M_finish);

    __p.resize(__deg + 1);
    return __p;
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

template <class _Tp, size_t _C>
std::vector<typename polynomial<_Tp, _C>::field> polynomial<_Tp, _C>::__work1;

template <class _Tp, size_t _C>
std::vector<typename polynomial<_Tp, _C>::field> polynomial<_Tp, _C>::__work2;

// /**
//  * @brief Rising factorial of degree n.
//  * @return \\prod_{i=0}^{n-1} (x+i)
//  */
// template <class _Tp> auto rising_factorial(_Tp __n) {}

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
 * @brief Generating function of the sum of k-th powers of the first n
 * non-negative integers. O(d \\log d) time in modulo x^d.
 *
 * @return \\sum_{k=0}^{d-1} x^k \\sum_{i=0}^{n-1} i^k.
 */
template <class _Tp> polynomial<_Tp> power_sum(_Tp __n, std::size_t __d) {
  if (!__d) return {};

  polynomial<_Tp> __f(__d), __e(__d);
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
#line 11 "codeforces-workspace\\contest\\1613\\f\\f.cpp"

namespace workspace {

using mint = modint<998244353>;
using poly = polynomial<mint>;

void main() {
  // start here!

  using namespace std;

  int n;
  cin >> n;
  deque fcs(n, poly{1, 1});
  fcs[0][0] = 0;

  for (auto i = 1; i < n; i++) {
    for (auto _ : {0, 1}) {
      int a;
      cin >> a;
      fcs[a - 1] -= 1;
    }
  }

  while (fcs.size() > 1) {
    auto tmp = fcs.back();
    fcs.pop_back();
    tmp *= fcs.back();
    fcs.pop_back();
    fcs.emplace_front(tmp);
  }

  auto res = fcs.back();
  mint fact = 1, ans = 0;

  for (auto i = 0; i <= n; ++i) {
    ans += res[i] * fact;
    fact *= i + 1;
  }

  cout << ans << "\n";
}

}  // namespace workspace

int main() { workspace::main(); }

/**
 * @note
 */