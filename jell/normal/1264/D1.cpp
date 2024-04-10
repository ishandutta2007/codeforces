#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define __clock__
#else
    #pragma GCC optimize("Ofast")
    // #define NDEBUG
#endif
#define buffer_check
#define __precision__ 10
#define iostream_untie true
#define debug_stream std::cerr

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
#define odd(n) ((n) & 1)
#define even(n) (not __odd(n))
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)

using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>;
template <class T> using heap = std::priority_queue<T>;
template <class T> using rheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T> using hashset = std::unordered_set<T>;
template <class Key, class Value> using hashmap = std::unordered_map<Key, Value>;

namespace setting
{
    using namespace std::chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { debug_stream << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n"; }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
            std::cout << std::fixed << std::setprecision(__precision__);
    #ifdef stderr_path
            if(freopen(stderr_path, "a", stderr))
            {
                std::cerr << std::fixed << std::setprecision(__precision__);
            }
    #endif
    #ifdef stdout_path
            if(not freopen(stdout_path, "w", stdout))
            {
                freopen("CON", "w", stdout);
                debug_stream << "\n\033[1;35mwarning\033[0m: failed to open stdout file.\n";
            }
            std::cout << "";
    #endif
    #ifdef stdin_path
            if(not freopen(stdin_path, "r", stdin))
            {
                freopen("CON", "r", stdin);
                debug_stream << "\n\033[1;35mwarning\033[0m: failed to open stdin file.\n";
            }
    #endif
    #ifdef LOCAL
            debug_stream << "----- stderr at LOCAL -----\n\n";
            atexit(print_elapsed_time);
    #endif
    #if defined(__clock__) || defined(LOCAL)
            start_time = system_clock::now();
    #endif
        }
    } __setupper; // struct setupper
} // namespace setting
#ifdef __clock__
class
{
    std::chrono::system_clock::time_point built_pt, last_pt; int built_ln, last_ln;
    std::string built_func, last_func; bool is_built = false;
  public:
    void build(int crt_ln, const std::string &crt_func)
    {
        is_built = true, last_pt = built_pt = std::chrono::system_clock::now(),  last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(is_built) last_pt = std::chrono::system_clock::now(), last_ln = crt_ln, last_func = crt_func;
        else debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::set failed (yet to be built!)\n";
    }
    void get(int crt_ln, const std::string &crt_func)
    {
        if(is_built)
        {
            std::chrono::system_clock::time_point crt_pt(std::chrono::system_clock::now());
            long long diff = std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt - last_pt).count();
            debug_stream << diff << " ms elapsed from" << " [ " << last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) debug_stream << " (when built)";
            debug_stream << " to" << " [ " << crt_ln << " : " << crt_func << " ]" << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::get failed (yet to be built!)\n";
        }
    }
} myclock; // unnamed class
    #define build_clock() myclock.build(__LINE__, __func__)
    #define set_clock() myclock.set(__LINE__, __func__)
    #define get_clock() myclock.get(__LINE__, __func__)
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

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
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t)  { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} // namespace std

#ifdef LOCAL
    #define dump(...)                                                              \
        debug_stream << "[ " << __LINE__ << " : " << __FUNCTION__ << " ]\n",       \
            dump_func(#__VA_ARGS__, __VA_ARGS__)
    template <class T> void dump_func(const char *ptr, const T &x)
    {
        debug_stream << '\t';
        for(char c = *ptr; c != '\0'; c = *++ptr) if(c != ' ') debug_stream << c;
        debug_stream << " : " << x << '\n';
    }
    template <class T, class... rest_t> void dump_func(const char *ptr, const T &x, rest_t... rest)
    {
        debug_stream << '\t';
        for(char c = *ptr; c != ','; c = *++ptr) if(c != ' ') debug_stream << c;
        debug_stream << " : " << x << ",\n"; dump_func(++ptr, rest...);
    }
#else
    #define dump(...) ((void)0)
#endif
template <class P> void read_range(P __first, P __second) { for(P i = __first; i != __second; ++i) std::cin >> *i; }
template <class P> void write_range(P __first, P __second) { for(P i = __first; i != __second; std::cout << (++i == __second ? '\n' : ' ')) std::cout << *i; }

// substitue y for x if x > y.
template <class T> inline bool sbmin(T &x, const T &y) { return x > y ? x = y, true : false; }
// substitue y for x if x < y.
template <class T> inline bool sbmax(T &x, const T &y) { return x < y ? x = y, true : false; }
// binary search.
i64 bin(const std::function<bool(i64)> &pred, i64 ok, i64 ng)
{
    while(std::abs(ok - ng) > 1) { i64 mid = (ok + ng) / 2; (pred(mid) ? ok : ng) = mid; }
    return ok;
}
double bin(const std::function<bool(double)> &pred, double ok, double ng, const double eps)
{
    while(std::abs(ok - ng) > eps) { double mid = (ok + ng) / 2; (pred(mid) ? ok : ng) = mid; }
    return ok;
}
// be careful that val is type-sensitive.
template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T *)array, (T *)(array + N), val); }
// reset all bits.
template <class A> void reset(A &array) { memset(array, 0, sizeof(array)); }


/* The main code follows. */

#ifndef MODULO_HPP
#define MODULO_HPP
#include <iostream>
namespace modulo
{
    template <int mod>
    class modint
    {
        int val;
      public:
        constexpr modint() : val{0} {}
        constexpr modint(long long x) : val((x %= mod) < 0 ? mod + x : x) {}
        constexpr long long get() const { return val; }
        constexpr modint &operator+=(const modint &other) { return (val += other.val) < mod ? 0 : val -= mod, *this; }
        constexpr modint &operator++() { return ++val, *this; }
        constexpr modint operator++(int) { modint t = *this; return ++val, t; }
        constexpr modint &operator-=(const modint &other) { return (val += mod - other.val) < mod ? 0 : val -= mod, *this; }
        constexpr modint &operator--() { return --val, *this; }
        constexpr modint operator--(int) { modint t = *this; return --val, t; }
        constexpr modint &operator*=(const modint &other) { return val = (long long)val * other.val % mod, *this; }
        constexpr modint &operator/=(const modint &other) { return *this *= inverse(other); }
        constexpr modint operator-() const { return modint(-val); }
        constexpr modint operator+(const modint &other) const { return modint(*this) += other; }
        constexpr modint operator-(const modint &other) const { return modint(*this) -= other; }
        constexpr modint operator*(const modint &other) const { return modint(*this) *= other; }
        constexpr modint operator/(const modint &other) const { return modint(*this) /= other; }
        constexpr bool operator==(const modint &other) const { return val == other.val; }
        constexpr bool operator!=(const modint &other) const { return val != other.val; }
        constexpr bool operator!() const { return !val; }
        friend constexpr modint inverse(const modint &other)
        {
            assert(other != 0);
            int a{mod}, b{other.val}, u{}, v{1}, t{};
            while(b) t = a / b, a ^= b ^= (a -= t * b) ^= b, u ^= v ^= (u -= t * v) ^= v;
            return modint{u};
        }
        friend constexpr modint pow(modint other, long long e)
        {
            if(e < 0) e = e % (mod - 1) + mod - 1;
            modint res{1};
            while(e) { if(e & 1) res *= other; other *= other, e >>= 1; }
            return res;
        }
        friend std::ostream &operator<<(std::ostream &s, const modint &other) { return s << other.val; }
        friend std::istream &operator>>(std::istream &s, modint &other) { long long val; other = modint{(s >> val, val)}; return s; }
    }; // class modint
    template <>
    class modint<2>
    {
        bool val;
      public:
        constexpr modint(bool x = false) : val{x} {}
        constexpr modint(int x) : val(x & 1) {}
        constexpr modint(long long x) : val(x & 1) {}
        constexpr bool get() const { return val; }
        constexpr modint &operator+=(const modint &other) { return val ^= other.val, *this; }
        constexpr modint &operator++() { return val = !val, *this; }
        constexpr modint operator++(int) { modint t = *this; return val = !val, t; }
        constexpr modint &operator-=(const modint &other) { return val ^= other.val, *this; }
        constexpr modint &operator--() { return val = !val, *this; }
        constexpr modint operator--(int) { modint t = *this; return val = !val, t; }
        constexpr modint &operator*=(const modint &other) { return val &= other.val, *this; }
        constexpr modint &operator/=(const modint &other) { return *this; }
        constexpr modint operator-() const { return *this; }
        constexpr modint operator+(const modint &other) const { return val != other.val; }
        constexpr modint operator-(const modint &other) const { return val != other.val; }
        constexpr modint operator*(const modint &other) const { return val && other.val; }
        constexpr modint operator/(const modint &other) const { return *this; }
        constexpr bool operator==(const modint &other) const { return val == other.val; }
        constexpr bool operator!=(const modint &other) const { return val != other.val; }
        constexpr bool operator!() const { return !val; }
        operator bool() const { return val; }
        friend constexpr modint inverse(const modint &other) { return other; }
        friend constexpr modint pow(const modint &other, long long exp) { return other; }
        friend std::ostream &operator<<(std::ostream &os, const modint &other) { return os << other.val; }
        friend std::istream &operator>>(std::istream &is, modint &other) { long long val; other.val = (is >> val, val & 1); return is; }
    }; // class modint specialization
} // namespace modulo
#endif

const int mod=998244353;
using mint=modulo::modint<mod>;

using namespace std;

main()
{
    void __solve();
    u32 t = 1;
    // t = -1; // infinite loop
    // cin >> t; // case number given
    while(t--) __solve();
#ifdef buffer_check
    char bufc;
    if(cin >> bufc)
    {
        debug_stream << "\n\033[1;35mwarning\033[0m: buffer not empty.\n";
        // return EXIT_FAILURE;
    }
#endif
}

mint dp[2020][2020];

void __solve()
{
    string s; cin>>s;
    int n=s.size();
    vector<int> t(s.size()+1);
    vector<mint> p2(n+1,1);
    for(int i=0; i<n; i++)
    {
        p2[i+1]=p2[i]*2;
        t[i+1]=t[i]+(s[i]=='?');
    }
    for(int i=0; i<=n; ++i)
    {
        dp[i][i]=0;
    }
    for(int k=1; k<=n; ++k)
    {
        for(int i=0; i+k<=n; ++i)
        {
            int j=i+k;
            if(s[i]==')') dp[i][j]=dp[i+1][j];
            else if(s[j-1]=='(') dp[i][j]=dp[i][j-1];
            else if(s[i]=='(')
            {
                if(s[j-1]==')')
                {
                    dp[i][j]=dp[i+1][j-1]+p2[t[j-1]-t[i+1]];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    dp[i][j]+=dp[i+1][j-1]+p2[t[j-1]-t[i+1]];
                }
            }
            else
            {
                dp[i][j]=dp[i+1][j];
                if(s[j-1]==')')
                {
                    dp[i][j]+=dp[i+1][j-1]+p2[t[j-1]-t[i+1]];
                }
                else if(j-i>1)
                {
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]+=p2[t[j-1]-t[i+1]];
                }
            }
        }
    }
    cout << dp[0][n] << "\n";
}