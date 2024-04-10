#ifdef stderr_path
    #define LOCAL
    #define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("Ofast")
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>
#include <chrono>

#define debug_stream std::cerr
#define iostream_untie true
#define __precision__ 10

#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define __odd(n) ((n) & 1)
#define __even(n) (__odd(n) ^ 1)
#define __popcount(n) __builtin_popcountll(n)

using i64 = int_fast64_t;
using pii = std::pair<int, int>;
using pll = std::pair<int_fast64_t, int_fast64_t>;
template <class T> using heap = std::priority_queue<T>;
template <class T> using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T> constexpr T inf = std::numeric_limits<T>::max() / (T)2 - (T)1123456;

namespace execution
{
    std::chrono::system_clock::time_point start_time, end_time;
    void print_elapsed_time()
    {
        end_time = std::chrono::system_clock::now();
        std::cerr << "\n----- Exec time : ";
        std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cerr << " ms -----\n\n";
    }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie)
            {
                std::ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
            }
            std::cout << std::fixed << std::setprecision(__precision__);
#ifdef stderr_path
            if(freopen(stderr_path, "a", stderr))
            {
                std::cerr << std::fixed << std::setprecision(__precision__);
            }
            else fclose(stderr);
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
            atexit(print_elapsed_time);
            start_time = std::chrono::system_clock::now();
#endif
        }
    } __setupper;
}

struct myclock_t
{
    std::chrono::system_clock::time_point built_pt, last_pt;
    int built_ln, last_ln;
    std::string built_func, last_func;
    bool is_built;
    myclock_t() : is_built(false) {}
    void build(int crt_ln, const std::string &crt_func)
    {
        is_built = true;
        last_pt = built_pt = std::chrono::system_clock::now();
        last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(is_built)
        {
            last_pt = std::chrono::system_clock::now();
            last_ln = crt_ln, last_func = crt_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::set failed (yet to be built clock!)\n";
        }
    }
    void get(int crt_ln, const std::string &crt_func) {
        if(is_built) 
        {
            std::chrono::system_clock::time_point crt_pt(std::chrono::system_clock::now());
            int64_t diff = std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt - last_pt).count();
            debug_stream << diff << " ms elapsed from" << " [ " <<  last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) debug_stream << " (when built)";
            debug_stream << " to" << " [ " << crt_ln << " : " << crt_func << " ]" << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::get failed (yet to be built clock!)\n";
        }
    }
};
#ifdef LOCAL
    myclock_t myclock;
    #define build_clock() myclock.build(__LINE__, __func__)
    #define set_clock() myclock.set(__LINE__, __func__)
    #define get_clock() myclock.get(__LINE__, __func__)
#else
    #define build_clock() 42
    #define set_clock() 42
    #define get_clock() 42
#endif

namespace std
{
    template <class RAitr> void rsort(RAitr __first, RAitr __last) { sort(__first, __last, greater<>()); }
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T,U>> { size_t operator()(pair<T,U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class ...T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    template <class T, class U> istream &operator>> (std::istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
    template <class T, class U> ostream &operator<< (std::ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
    template <class T> istream &operator>> (istream &s, vector<T> &v) { for(T &e : v) { s >> e; } return s; }
    template <class T> ostream &operator<< (ostream &s, const vector<T> &v) { for(size_t i = 0; i < v.size(); ++i) { s << (i ? " " : "") << v[i]; } return s; }
    template <class tuple_t, size_t index>
    struct tupleos
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            tupleos<tuple_t,index - 1>::apply(s,t);
            return s << " " << get<index>(t);
        }
    };
    template <class tuple_t>
    struct tupleos<tuple_t, 0>
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            return s << get<0>(t);
        }
    };
    template <class ...T> ostream &operator<< (ostream &s, const tuple<T...> &t)
    {
        return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(s,t);
    }
    template <> ostream &operator<< (ostream &s, const tuple<> &t) { return s; }
}


#ifdef LOCAL
    #define dump(...) debug_stream << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ", dump_func(__VA_ARGS__)
#else
    #define dump(...) 42
#endif
template <class T> void dump_func(const T &x) { debug_stream << x << '\n'; }
template <class T,class ...Rest> void dump_func(const T &x, Rest ... rest) { debug_stream << x << ", "; dump_func(rest...); }
template <class T> void write(const T &x) { std::cout << x << '\n'; }
template <class T, class ...Rest> void write(const T &x, Rest ... rest) { std::cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(const T &x, Rest ... rest) { std::cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
template <class P> void read_range(P __first, P __second) { for(P i = __first; i != __second; ++i) std::cin >> *i; }

template <class T> bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
template <class T> bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
template <class T> constexpr T minf(const T &x, const T &y) { return std::min(x,y); }
template <class T> constexpr T maxf(const T &x, const T &y) { return std::max(x,y); }
template <class int_t, class F>
int_t bin(int_t ok, int_t ng, const F &f)
{
    while (std::abs(ok - ng) > 1)
    {
        int_t mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
template <class A, size_t N> void init(A (&array)[N]) { memset(array, 0, sizeof(array)); }
void for_subset(int_fast64_t s, const std::function<void(int_fast64_t)> &fn) { int_fast64_t t = s; do { fn(t); } while((--t &= s) != s); }

namespace math
{
    template <class int_t>
    constexpr int_t gcd(int_t x, int_t y)
    {
        x = x > 0 ? x : -x, y = y > 0 ? y : -y;
        while(y) y ^= x ^= y ^= x %= y;
        return x;
    }
    template <class int_t>
    constexpr int_t lcm(int_t x, int_t y)
    {
        return x ? x / gcd(x, y) * y : 0;
    }
    template <class int_t>
    constexpr std::tuple<int_t, int_t, int_t> ext_gcd(int_t a, int_t b)
    {
        int_t sgn_a = a >= 0 ? 1 : (a = -a, 0), sgn_b = b >= 0 ? 1 : (b = -b, 0);
        int_t p = 1, q = 0, r = 0, s = 1;
        while(b)
        {
            int_t t = a / b;
            r ^= p ^= r ^= p -= t * r;
            s ^= q ^= s ^= q -= t * s;
            b ^= a ^= b ^= a %= b;
        }
        return std::tuple<int_t, int_t, int_t>(a, sgn_a ? p : -p, sgn_b ? q : -q);
    }
    template <class int_t>
    constexpr std::pair<int_t, int_t> mod_comp(int_t k, int_t m, int_t l, int_t n)
    {
        assert(m > 0 and n > 0);
        int_t g, x, y; std::tie(g, x, y) = ext_gcd(m, n);
        k += ((k %= m) < 0) * m, l += ((l %= n) < 0) * n;
        int_t s = k / g, t = l / g, r = k % g;
        if(r != l % g) return std::pair<int_t, int_t>(-1, -1);
        int_t lcm = m / g * n;
        return std::pair<int_t, int_t>((m * x % lcm * t % lcm + n * y % lcm * s % lcm + r + lcm * 2) % lcm, lcm);
    }
}

/* The main code follows. */

signed main()
{
    void solve();
    void input();
    void init();

    int t = 1;

    // cin >> t;

    while(t--)
    {
        init();
        input();
        solve();
    }
}


using namespace std;
using namespace math;

int n,m;
int a[1<<18];

pll __opr(pll x,pll y)
{
    // i64 ar[]={x.first,x.second,y.first,y.second};
    if(x.first<y.first)
    {
        return pll(x.first,min(y.first,x.second));
    }
    else
    {
        return pll(y.first,min(x.first,y.second));
    }
    // sort(ar,ar+4);
    // return pll(ar[0],ar[1]);
}

void upd(pll &x, i64 y)
{
    x.first=y;
}

template <class Monoid, class act_t>
class Segtree
{
    std::vector<Monoid> data;

public:
    const std::size_t n, N;

    using opr_t = std::function<Monoid(const Monoid &, const Monoid &)>;
    using update_opr_t = std::function<void(Monoid &, const act_t &)>;
    const opr_t opr;
    const update_opr_t update_opr;
    const Monoid identity;

    Segtree(std::size_t _n=1LL<<18, const Monoid &_identity=pll(inf<i64>,inf<i64>), const opr_t &_opr = __opr, const update_opr_t &_update_opr = upd)
        : n(_n), N(adjust_size(_n)), opr(_opr), update_opr(_update_opr), identity(_identity)
    {
        data.assign(N << 1, identity);
    }

    Monoid operator[](std::size_t i) { return data[i + N]; }

    template <class P>
    void copy(P s, P t)
    {
        for (std::size_t i = N; s != t; ++s, ++i)
            data[i] = *s;
        for (std::size_t i = N - 1; i; --i)
            data[i] = opr(data[left(i)], data[right(i)]);
    }

    template <class A>
    void copy(const A &v) { copy(begin(v), end(v)); }

    void init(const Monoid &x)
    {
        for (std::size_t i = 0; i < N; ++i)
            data[i + N] = x;
        for (std::size_t i = N - 1; i; --i)
            data[i] = opr(data[left(i)], data[right(i)]);
    }

    void update(std::size_t idx, const act_t &actor)
    {
        update_opr(data[idx += N], actor);
        while (idx >>= 1)
            data[idx] = opr(data[idx * 2], data[idx * 2 + 1]);
    }

    // operation result of range [a, b).
    Monoid query(std::size_t a, std::size_t b) const
    {
        Monoid lft = identity, rgt = identity;
        a += N, b += N;
        while (a < b)
        {
            if (a & 1)
                lft = opr(lft, data[a++]);
            if (b & 1)
                rgt = opr(data[--b], rgt);
            a >>= 1, b >>= 1;
        }
        return opr(lft, rgt);
    }

    // maximum r where range [idx, r) meets the condition.
    std::size_t right_bound(std::size_t idx, const std::function<bool(const Monoid &)> &f)
    {
        assert(idx < n);
        std::size_t ret = idx;
        Monoid now = identity;
        right_bound(idx, f, 1, 0, N, now, ret);
        return std::min(ret, n);
    }

    // minimum l where range [l, idx) meets the condition.
    std::size_t left_bound(std::size_t idx, const std::function<bool(const Monoid &)> &f)
    {
        assert(idx <= n);
        std::size_t ret = idx;
        Monoid now = identity;
        left_bound(idx, f, 1, 0, N, now, ret);
        return ret;
    }

private:
    constexpr std::size_t adjust_size(const std::size_t n)
    {
        std::size_t d = 0;
        for (std::size_t i = 0; i < 30; ++i)
            if (n >> i & 1)
                d = i;
        return 1 << (d + 1);
    }

    constexpr std::size_t left(const std::size_t k) { return k * 2; }

    constexpr std::size_t right(const std::size_t k) { return left(k) ^ 1; }

    constexpr std::size_t parent(const std::size_t k) { return k >> 1; }

    constexpr std::size_t sibling(const std::size_t k) { return k ^ 1; }

    void right_bound(std::size_t idx, const std::function<bool(const Monoid &)> &f, std::size_t k, std::size_t l, std::size_t r, Monoid &now, std::size_t &pos)
    {
        if (idx >= r || l > pos)
            return;
        const std::size_t mid = (l + r) / 2;
        if (l >= idx)
        {
            Monoid nxt = opr(now, data[k]);
            if (f(nxt))
            {
                pos = r;
                now = nxt;
                return;
            }
        }
        if (r - l > 1)
        {
            right_bound(idx, f, left(k), l, mid, now, pos);
            right_bound(idx, f, right(k), mid, r, now, pos);
        }
    }

    void left_bound(std::size_t idx, const std::function<bool(const Monoid &)> &f, std::size_t k, std::size_t l, std::size_t r, Monoid &now, std::size_t &pos)
    {
        if (idx <= l || r < pos)
            return;
        const std::size_t mid = (l + r) / 2;
        if (r <= idx)
        {
            Monoid nxt = opr(data[k], now);
            if (f(nxt))
            {
                pos = l;
                now = nxt;
                return;
            }
        }
        if (r - l > 1)
        {
            left_bound(idx, f, right(k), mid, r, now, pos);
            left_bound(idx, f, left(k), l, mid, now, pos);
        }
    }
};



void init()
{}

void input()
{
    std::cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        std::cin >> a[i];
    }
}

const int ten[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

int dig(int x, int e)
{
    return x/ten[e]%10;
}

void solve()
{
    Segtree<pll,i64> sgt[9];

    for(int k=0;k<9;++k)
    {
        vector<pll> init(n);
        for(int i=0; i<n; i++)
        {
            pll p{inf<i64>,inf<i64>};
            if(dig(a[i],k))
            {
                p.first=a[i];
            }
            init[i]=p;
        }
        sgt[k].copy(init);
    }


    while(m--)
    {
        int t; std::cin >> t;
        if(t==1)
        {
            int i,x; std::cin >> i>>x;
            i--;
            a[i]=x;
            for(int k=0; k<9; k++)
            {
                i64 nex=inf<i64>;
                if(dig(x,k))
                {
                    nex=x;
                }
                sgt[k].update(i,nex);
            }
        }
        else
        {
            int l,r; std::cin >> l>>r;
            l--,r--;

            i64 ans=inf<i64>;

            for(int k=0; k<9; k++)
            {
                auto p=sgt[k].query(l,r+1);
                dump(k,p);
                chmin(ans,p.first+p.second);
            }

            if(ans==inf<i64>)
            {
                std::cout << -1 << "\n";
            }
            else
            {
                std::cout << ans << "\n";
            }
        }
    }

}