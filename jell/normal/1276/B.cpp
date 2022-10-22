#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define __clock__
#else
    #pragma GCC optimize("Ofast")
    // #define NDEBUG
#endif
// #define __buffer_check__
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
    void buffer_check()
    {
        char bufc;
        if(std::cin >> bufc) debug_stream << "\n\033[1;35mwarning\033[0m: buffer not empty.\n";
    }
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
    #ifdef __buffer_check__
            atexit(buffer_check);
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
    template <class tuple_t, size_t index> struct tupleis { static istream &apply(istream &is, tuple_t &t) { tupleis<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tupleis<tuple_t, ~0> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t)  { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
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

using namespace std;

class Union_Find
{
    std::vector<int> dat;
    std::vector<bool> cyc, clr, flip;
    size_t comp, isol;
    bool is_bip;

  public:
    Union_Find(int n)
    {
        init(n);
    }

    void init(int n)
    {
        dat.assign(n, -1);
        cyc.assign(n, false);
        clr.assign(n, false);
        flip.assign(n, false);
        comp = isol = n;
        is_bip = true;
    }

    int find(int x)
    {
        if(dat[x] < 0) return x;
        int r = find(dat[x]);
        if(flip[dat[x]])
        {
            clr[x] = not clr[x];
            flip[x] = not flip[x];
        }
        return dat[x] = r;
    }

    size_t count() const
    {
        return comp;
    }

    size_t size(int x)
    {
        return -dat[find(x)];
    }

    size_t isolated() const
    {
        return isol;
    }

    bool color(int x)
    {
        find(x);
        return clr[x];
    }

    bool is_cyclic(int x)
    {
        return cyc[find(x)];
    }

    bool is_same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool is_bipartite() const
    {
        return is_bip;
    }

    bool unite(int x, int y)
    {
        int _x = find(x);
        int _y = find(y);
        bool f = clr[x] == clr[y];
        x = _x, y = _y;
        if(x == y)
        {
            if(f)
            {
                is_bip = false;
            }
            cyc[x] = true;
            return false;
        }
        if(dat[x] > dat[y]) std::swap(x, y);
        if(dat[y] == -1)
        {
            --isol;
            if(dat[x] == -1)
            {
                --isol;
            }
        }
        dat[x] += dat[y];
        dat[y] = x;
        cyc[x] = cyc[x] || cyc[y];
        if(f)
        {
            clr[y] = not clr[y];
            flip[y] = not flip[y];
        }
        --comp;
        return true;
    }
}; // class Union_Find

struct solver
{

    solver()
    {
        i64 n; cin>>n;
        Union_Find uf(n);

        int m; cin>>m;
        int a,b; cin>>a>>b; --a,--b;
        if(a>b) swap(a,b);

        vector<int> ga,gb;
        for(int t=0; t<m; ++t)
        {
            int u,v; cin>>u>>v; --u,--v;
            if(u>v) swap(u,v);
            if(u==a || u==b || v==a || v==b)
            {
                if(u==a)
                {
                    if(v!=b) ga.emplace_back(v);
                }
                else if(u==b)
                {
                    gb.emplace_back(v);
                }
                else if(v==a)
                {
                    ga.emplace_back(u);
                }
                else if(v==b)
                {
                    gb.emplace_back(u);
                }
            }
            else
            {
                uf.unite(u,v);
            }
        }

        i64 ans=0;

        vector<int> che(n),che2(n);

        for(int i=0; i<n; ++i)
        {
            int r=uf.find(i);
            if(che[r])
            {
                continue;
            }
            che[r]=1;
            i64 sz=uf.size(r);
            ans+=sz*(sz-1)/2;
        }
        fill(all(che),0);

        i64 sum=0;
        i64 squ=0;
        for(int v:ga)
        {
            v=uf.find(v);
            if(che[v]) continue;
            che[v]=1;
            i64 sz=uf.size(v);
            sum+=sz;
            squ+=sz*sz;
        }
        ans+=(sum*sum-squ)/2;

        sum=0;
        squ=0;
        for(int v:gb)
        {
            v=uf.find(v);
            if(che2[v]) continue;
            che2[v]=1;
            i64 sz=uf.size(v);
            sum+=sz;
            squ+=sz*sz;
        }
        ans+=(sum*sum-squ)/2;


        sum=squ=0;
        for(int i=0; i<n; ++i)
        {
            che[i]&=che2[i];
            if(che[i])
            {
                i64 sz=uf.size(i);
                sum+=sz;
                squ+=sz*sz;
            }
        }
        ans-=(sum*sum-squ)/2;

        ans=(n-2)*(n-3)/2-ans;

        cout << ans << "\n";
    }
};

main()
{
    u32 t = 1;
#ifdef LOCAL

#endif
    // t = -1; // infinite loop
    cin >> t; // case number given
    while(t--) solver();
}