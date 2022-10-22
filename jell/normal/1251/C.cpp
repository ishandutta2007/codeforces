#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define __clock__
#else
    #pragma GCC optimize("Ofast")
#endif
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

// #define NDEBUG
#define __precision__ 10
#define iostream_untie true
#define debug_stream std::cerr

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
#define __odd(n) ((n) & 1)
#define __even(n) (not __odd(n))
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)
#define uo_ unordered_

using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>;
template <class T> using heap = std::priority_queue<T>;
template <class T> using rheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class K, class T> using hashmap = std::unordered_map<K, T>;
template <class T> using hashset = std::unordered_set<T>;

namespace execution
{
    using namespace std::chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { std::cerr << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n\n"; }
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
                std::cerr << "Failed to open the stdout file\n\n";
            }
            std::cout << "";
    #endif
    #ifdef stdin_path
            if(not freopen(stdin_path, "r", stdin))
            {
                freopen("CON", "r", stdin);
                std::cerr << "Failed to open the stdin file\n\n";
            }
    #endif
    #ifdef LOCAL
            std::cerr << "----- stderr at LOCAL -----\n\n";
            atexit(print_elapsed_time);
    #else
            fclose(stderr);
    #endif
    #ifdef __clock__
            start_time = system_clock::now();
    #endif
        }
    } __setupper;

    class myclock_t
    {
        system_clock::time_point built_pt, last_pt; int built_ln, last_ln;
        std::string built_func, last_func; bool is_built;
    public:
        myclock_t() : is_built(false) {}
        void build(int crt_ln, const std::string &crt_func)
        {
            is_built = true, last_pt = built_pt = system_clock::now(),  last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
        }
        void set(int crt_ln, const std::string &crt_func)
        {
            if(is_built) last_pt = system_clock::now(), last_ln = crt_ln, last_func = crt_func;
            else debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::set failed (yet to be built!)\n";
        }
        void get(int crt_ln, const std::string &crt_func)
        {
            if(is_built)
            {
                system_clock::time_point crt_pt(system_clock::now());
                long long diff = duration_cast<milliseconds>(crt_pt - last_pt).count();
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
    };
} // namespace execution

#ifdef __clock__
    execution::myclock_t __myclock;
    #define build_clock() __myclock.build(__LINE__, __func__)
    #define set_clock() __myclock.set(__LINE__, __func__)
    #define get_clock() __myclock.get(__LINE__, __func__)
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

namespace std
{
    template <class P> void rsort(P __first, P __last) { sort(__first, __last, greater<>()); }
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T, U>> { size_t operator()(pair<T, U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1> struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class... T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    template <class T, class U> istream &operator>>(std::istream &s, pair<T, U> &p) { return s >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(std::ostream &s, const pair<T, U> &p) { return s << p.first << " " << p.second; }
    template <class T> istream &operator>>(istream &s, vector<T> &v) { for(T &e : v) s >> e; return s; }
    template <class T> ostream &operator<<(ostream &s, const vector<T> &v)  { bool is_front = true; for(const T &e : v) { if(not is_front) s << ' '; else is_front = false; s << e; } return s; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &s, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(s, t); return s << " " << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &s, const tuple_t &t) { return s << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &s, const tuple<T...> &t)  { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(s, t); }
    template <> ostream &operator<<(ostream &s, const tuple<> &t) { return s; }
    string revstr(string str) { reverse(str.begin(), str.end()); return str; }
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

using namespace std;


main()
{
    void __solve();

    u32 t = 1;

#ifdef LOCAL
    t = 1;
#endif

    // t = -1;
    cin >> t;

    while(t--)
    {
        __solve();
    }
}

void __solve()
{
    string s; cin>>s;
    const int n=s.size();
    queue<char> od,ev;
    for(char c : s)
    {
        if(__odd(c-'0'))
        {
            od.push(c);
        }
        else
        {
            ev.push(c);
        }
    }
    string ans;

    while(!od.empty() || !ev.empty())
    {
        if(ev.empty())
        {
            ans+=od.front(),od.pop();
        }
        else if(od.empty())
        {
            ans+=ev.front(),ev.pop();
        }
        else
        {
            if(ev.front()>od.front())
            {
                ans+=od.front(),od.pop();
            }
            else
            {
                ans+=ev.front(),ev.pop();
            }
        }
    }

    cout << ans << "\n";
}