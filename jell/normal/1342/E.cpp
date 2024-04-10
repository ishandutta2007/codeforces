/* preprocessor start */
#ifdef LOCAL
//*
    #define _GLIBCXX_DEBUG  // gcc
/*/
    #define _LIBCPP_DEBUG 0 // clang
//*/
    #define __clock__
    // #define __buffer_check__
#else
    #pragma GCC optimize("Ofast")
/*
    #define _GLIBCXX_DEBUG  // gcc
/*/
//    #define _LIBCPP_DEBUG 0 // clang
//*/
    // #define __buffer_check__
    // #define NDEBUG
#endif
#define __precision__ 10
#define iostream_untie true
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <ext/rope>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#define __all(v) std::begin(v), std::end(v)
#define __rall(v) std::rbegin(v), std::rend(v)
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)
/* preprocessor end */

namespace std
{
    // hash
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T, U>> { size_t operator()(pair<T, U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1> struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class... T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    // iostream
    template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << ' ' << p.second; }
    template <class tuple_t, size_t index> struct tupleis { static istream &apply(istream &is, tuple_t &t) { tupleis<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tupleis<tuple_t, SIZE_MAX> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t) { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} // namespace std

namespace setting
{
    using namespace std;
    using namespace chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { cerr << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n\n"; }
    void buffer_check() { char bufc; if(cin >> bufc) cerr << "\n\033[1;35mwarning\033[0m: buffer not empty.\n"; }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) ios::sync_with_stdio(false), cin.tie(nullptr);
            cout << fixed << setprecision(__precision__);
    #ifdef stderr_path
            if(freopen(stderr_path, "a", stderr)) cerr << fixed << setprecision(__precision__);
    #endif
    #ifdef LOCAL
            cerr << boolalpha << "\n----- stderr at LOCAL -----\n\n";
    #endif
    #ifdef __buffer_check__
            atexit(buffer_check);
    #endif
    #ifdef __clock__
            start_time = system_clock::now();
            atexit(print_elapsed_time);
    #endif
        }
    } __setupper; // struct setupper
} // namespace setting

#ifdef __clock__
    #include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\clock.hpp"
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

#ifdef LOCAL
    #include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\dump.hpp"
#else
    #define dump(...) ((void)0)
#endif

/* function utility start */
template <class T, class... types> T read(types... args) noexcept { typename std::remove_const<T>::type obj(args...); std::cin >> obj; return obj; }
#define input(type, var, ...) type var{read<type>(__VA_ARGS__)}
// substitute y for x if x > y.
template <class T> inline bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
// substitute y for x if x < y.
template <class T> inline bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
// binary search on discrete range.
template <class iter_type, class pred_type>
iter_type binary(iter_type __ok, iter_type __ng, pred_type pred)
{
    std::ptrdiff_t dist(__ng - __ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(__ok + dist / 2);
        if(pred(mid)) __ok = mid, dist -= dist / 2;
        else __ng = mid, dist /= 2;
    }
    return __ok;
}
// binary search on real numbers.
template <class pred_type>
long double binary(long double __ok, long double __ng, const long double eps, pred_type pred)
{
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}
// size of array.
template <class A, size_t N> size_t size(A (&array)[N]) { return N; }
// be careful that val is type-sensitive.
template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
/* functon utility end */

/* using alias start */
using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;
using namespace __gnu_cxx;
/* using alias end */

/* library start */

#ifndef modint_hpp
#define modint_hpp
#include <cassert>
#include <iostream>

template <int mod>
class modint
{
    int val;
public:
    constexpr modint() noexcept : val{0} {}
    constexpr modint(long long x) noexcept : val((x %= mod) < 0 ? mod + x : x) {}
    constexpr long long value() const noexcept { return val; }
    constexpr modint operator++(int) noexcept { modint t = *this; return ++val, t; }
    constexpr modint operator--(int) noexcept { modint t = *this; return --val, t; }
    constexpr modint &operator++() noexcept { return ++val, *this; }
    constexpr modint &operator--() noexcept { return --val, *this; }
    constexpr modint operator-() const noexcept { return modint(-val); }
    constexpr modint &operator+=(const modint &other) noexcept { return (val += other.val) < mod ? 0 : val -= mod, *this; }
    constexpr modint &operator-=(const modint &other) noexcept { return (val += mod - other.val) < mod ? 0 : val -= mod, *this; }
    constexpr modint &operator*=(const modint &other) noexcept { return val = (long long)val * other.val % mod, *this; }
    constexpr modint &operator/=(const modint &other) noexcept { return *this *= inverse(other); }
    constexpr modint operator+(const modint &other) const noexcept { return modint(*this) += other; }
    constexpr modint operator-(const modint &other) const noexcept { return modint(*this) -= other; }
    constexpr modint operator*(const modint &other) const noexcept { return modint(*this) *= other; }
    constexpr modint operator/(const modint &other) const noexcept { return modint(*this) /= other; }
    constexpr bool operator==(const modint &other) const noexcept { return val == other.val; }
    constexpr bool operator!=(const modint &other) const noexcept { return val != other.val; }
    constexpr bool operator!() const noexcept { return !val; }
    friend constexpr modint operator+(long long x, modint y) noexcept { return modint(x) + y; }
    friend constexpr modint operator-(long long x, modint y) noexcept { return modint(x) - y; }
    friend constexpr modint operator*(long long x, modint y) noexcept { return modint(x) * y; }
    friend constexpr modint operator/(long long x, modint y) noexcept { return modint(x) / y; }
    static constexpr modint inverse(const modint &other) noexcept
    {
        assert(other != 0);
        int a{mod}, b{other.val}, u{}, v{1}, t{};
        while(b) t = a / b, a ^= b ^= (a -= t * b) ^= b, u ^= v ^= (u -= t * v) ^= v;
        return {u};
    }
    static constexpr modint pow(modint other, long long e) noexcept
    {
        if(e < 0) e = e % (mod - 1) + mod - 1;
        modint res{1};
        while(e) { if(e & 1) res *= other; other *= other, e >>= 1; }
        return res;
    }
    friend std::ostream &operator<<(std::ostream &os, const modint &other) noexcept { return os << other.val; }
    friend std::istream &operator>>(std::istream &is, modint &other) noexcept { long long val; other = {(is >> val, val)}; return is; }
}; // class modint

#endif // modint_hpp

#ifndef binomial_hpp
#define binomial_hpp

namespace binomial
{
    constexpr int mod = 998244353;
    using mint = modint<mod>;
    namespace
    {
        namespace internal_helper
        {
            constexpr int N = 1 << 20;
            constexpr int loop_limit = 1 << 17;
            struct fact_impl
            {
                int _fact[N], _inv[N], _invfact[N];
                constexpr fact_impl() : _fact{1}, _inv{0, 1}, _invfact{1}
                {
                    int itr = 1; while(itr < N) for(int j = 0; j < loop_limit && itr < N; ++itr, ++j) _fact[itr] = (long long)_fact[itr - 1] * itr % mod;
                    itr = 2; while(itr < N) for(int j = 0; j < loop_limit && itr < N; ++itr, ++j) _inv[itr] = mod - (long long)_inv[mod % itr] * (mod / itr) % mod;
                    itr = 1; while(itr < N) for(int j = 0; j < loop_limit && itr < N; ++itr, ++j) _invfact[itr] = (long long)_invfact[itr - 1] * _inv[itr] % mod;
                }
            }; // struct fact_impl
            constexpr fact_impl fact_impl_inst;
            constexpr int fact_helper(int x) noexcept { assert(x < (int)N); return x < 0 ? 0 : fact_impl_inst._fact[x]; }
            constexpr int invfact_helper(int x) noexcept { assert(x < (int)N); return x < 0 ? 0 : fact_impl_inst._invfact[x]; }
            constexpr int inv_helper(int x) noexcept { assert(x < (int)N); return x < 0 ? 0 : fact_impl_inst._inv[x]; }
        } // namespace internal_helper
        constexpr mint fact(int x) noexcept { return internal_helper::fact_helper(x); }
        constexpr mint invfact(int x) noexcept { return internal_helper::invfact_helper(x); }
    } // unnamed namespace
    constexpr mint binom(int n, int k) noexcept { return fact(n) * invfact(k) * invfact(n - k); }
    constexpr mint fallfact(int n, int k) noexcept { return fact(n) * invfact(n - k); }
    constexpr mint risefact(int n, int k) noexcept { return fallfact(n + k - 1, k); }
    // time complexity: O(min(n, k) * log(n))
    constexpr mint stirling_2nd(int n, int k) noexcept
    {
        if(n < k) return 0;
        mint res{};
        for(int i{}, j{k}; j >= 0; ++i, --j)
            if(i & 1) res -= mint::pow(j, n) * invfact(j) * invfact(i);
            else res += mint::pow(j, n) * invfact(j) * invfact(i);
        return res;
    };
    // time complexity: O(min(n, k) * log(n))
    constexpr mint bell(int n, int k) noexcept
    {
        if(n < k) k = n;
        mint res{}, alt{};
        for(int i{}, j{k}; j >= 0; ++i, --j)
        {
            if(i & 1) alt -= invfact(i);
            else alt += invfact(i);
            res += alt * mint::pow(j, n) * invfact(j);
        }
        return res;
    }
    namespace internal_helper {} // namespace internal_helper
} // namespace binomial

#endif // binomial_hpp


/* library end */

/* The main code follows. */

template <class T> void _main();
struct solver;
int main() { _main<solver>(); }

template <class solver>
void _main()
{
    unsigned t;
#ifdef LOCAL
    t = 1;
#else
    t = 1; // single test case
#endif
    // t = -1; // infinite loop
    // cin >> t; // case number given

    while(t--) solver();
}

using namespace binomial;

struct solver
{

    solver()
    {
        int n; cin>>n;
        i64 k; cin>>k;
        if(n<=k) cout << 0 << "\n";
        else
        {
            mint ans;
            for(int x=1; x<=n-k; ++x)
            {
                mint tmp=binom(n-k,x)*mint::pow(x,n);
                if((n-k-x)&1)
                {
                    ans-=tmp;
                }
                else
                {
                    ans+=tmp;
                }
            }
            ans*=binom(n,n-k);
            if(k) ans*=2;
            cout << ans << "\n";
        }
    }
};