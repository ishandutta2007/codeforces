/* preprocessor start */
#ifdef LOCAL
/*
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
#include <cstring>
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
    void print_elapsed_time() { cerr << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n"; }
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
            cerr << "\n----- stderr at LOCAL -----\n\n";
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
#include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\Clock.hpp"
#else
#define build_clock() ((void)0)
#define set_clock() ((void)0)
#define get_clock() ((void)0)
#endif

#ifdef LOCAL
#include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\Dump.hpp"
#else
#define dump(...) ((void)0)
#endif

/* function utility start */
template <class T, class... types> T read(types... args) noexcept { T obj(args...); std::cin >> obj; return obj; }
#define input(type, var, ...) type var{read<type>(__VA_ARGS__)}
// substitute y for x if x > y.
template <class T> inline bool sbmin(T &x, const T &y) { return x > y ? x = y, true : false; }
// substitute y for x if x < y.
template <class T> inline bool sbmax(T &x, const T &y) { return x < y ? x = y, true : false; }
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
// reset all bits.
template <class A> void reset(A &array) { memset(array, 0, sizeof(array)); }
// be careful that val is type-sensitive.
template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
/* functon utility end */

/* using alias start */
using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using pii = pair<i32, i32>; using pll = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;
/* using alias end */

/* library start */



/* library end */

/* The main code follows. */


struct solver
{
    int n;
    vector<vector<int>> tre;
    vector<vector<i64>> dp;
    vector<vector<int>> dist;
    
    solver() : n(read<int>()),tre(n),dp(n,vector<i64>(n)),dist(n,vector<int>(n,n))
    {
        for(int i=1; i<n; ++i)
        {
            int u,v; cin>>u>>v; --u; --v;
            tre[u].emplace_back(v);
            tre[v].emplace_back(u);
        }
        
        vector<vector<pii>> path(n);
        
        for(int i=0; i<n; ++i)
        {
            queue<int> que;
            que.push(i);
            dist[i][i]=0;
            while(!que.empty())
            {
                int f=que.front(); que.pop();
                for(int v:tre[f])
                {
                    if(sbmin(dist[i][v],dist[i][f]+1))
                    {
                        que.push(v);
                    }
                }
            }
            for(int j=0; j<n; ++j)
            {
                path[dist[i][j]].emplace_back(i,j);
            }
        }
        
        vector<vector<int>> sz(n,vector<int>(n)),par(n,vector<int>(n));
        for(int i=0; i<n; ++i)
        {
            dfs(i,-1,sz[i],par[i]);
//            cerr<<sz[i]<<endl;
        }
        
        for(int i=0; i<n; ++i)
        {
            for(auto &uv:path[i])
            {
                int u,v; tie(u,v)=uv;
//                cerr<<u<<" "<<v<<endl;
                for(int w:tre[u])
                {
                    if(dist[w][v]>i)
                    {
//                        cerr<<'\t'<<w<<" "<<v<<endl;
                        sbmax(dp[w][v],dp[u][v]+sz[w][v]*sz[v][w]);
                    }
                }
                for(int w:tre[v])
                {
                    if(dist[u][w]>i)
                    {
//                        cerr<<'\t'<<u<<" "<<w<<endl;
                        sbmax(dp[u][w],dp[u][v]+sz[u][w]*sz[w][u]);
                    }
                }
            }
        }
        
        i64 ans{};
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                sbmax(ans,dp[i][j]);
            }
        }
        
        cout << ans << "\n";
        return;
    }
    
    void dfs(int f, int p, vector<int> &sz, vector<int> &par)
    {
        sz[f]=1;
        par[f]=p;
        for(int v:tre[f])
        {
            if(v!=p)
            {
                dfs(v,f,sz,par);
                sz[f]+=sz[v];
            }
        }
    }
    
}; // struct solver

int main(int argc, char *argv[])
{
    u32 t; // loop count
#ifdef LOCAL
    t = 1;
#else
    t = 1; // single test case
#endif
    // t = -1; // infinite loop
    // cin >> t; // case number given
    
    while(t--)
    {
        solver();
    }
}