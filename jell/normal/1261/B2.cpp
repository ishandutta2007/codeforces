#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define __clock__
#else
    #pragma GCC optimize("Ofast")
    // #define NDEBUG
#endif
#define __precision__ 10
#define buffer_check true
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
template <class K, class T> using hashmap = std::unordered_map<K, T>;
template <class T> using hashset = std::unordered_set<T>;

namespace execution
{
    using namespace std::chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { std::cerr << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n"; }
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
    // cin >> t;
    while(t--) __solve();

    char chec;
    if(buffer_check && cin >> chec)
    {
        cerr << "\n\033[1;35mwarning\033[0m: buffer not empty.\n";
        return EXIT_FAILURE;
    }
}

template <class Monoid, class act_t>
class Segment_tree
{
    const size_t n, N;
    std::vector<Monoid> data;
    using opr_t = std::function<Monoid(const Monoid &, const Monoid &)>;
    using update_opr_t = std::function<void(Monoid &, const act_t &)>;
    const opr_t opr;
    const update_opr_t update_opr;
    const Monoid identity;

  public:
    Segment_tree(size_t _n, const Monoid &_identity, const opr_t &_opr,
                          const update_opr_t &_update_opr)
        : n(_n), N(n > 1 ? 1 << (32 - __builtin_clz(n - 1)) : 1), data(N << 1, _identity),
          opr(_opr), update_opr(_update_opr), identity(_identity)
    {}

    Monoid operator[](size_t i) { return data[i + N]; }

    template <class P> void build(P s, P t)
    {
        for(size_t i = N; s != t; ++s, ++i) data[i] = *s;
        for(size_t i = N - 1; i; --i) data[i] = opr(data[left(i)], data[right(i)]);
    }

    template <template <class, class> class A> void build(A<Monoid, std::allocator<Monoid>> &v) { build(std::begin(v), std::end(v)); }

    void init(const Monoid &x)
    {
        for(size_t i = 0; i < N; ++i) data[i + N] = x;
        for(size_t i = N - 1; i; --i) data[i] = opr(data[left(i)], data[right(i)]);
    }

    void update(size_t idx, const act_t &actor)
    {
        update_opr(data[idx += N], actor);
        while(idx >>= 1) data[idx] = opr(data[idx * 2], data[idx * 2 + 1]);
    }

    // operation result of range [a, b).
    Monoid query(size_t a, size_t b) const
    {
        Monoid lft = identity, rgt = identity;
        a += N, b += N;
        while(a < b)
        {
            if(a & 1) lft = opr(lft, data[a++]);
            if(b & 1) rgt = opr(data[--b], rgt);
            a >>= 1, b >>= 1;
        }
        return opr(lft, rgt);
    }

    // maximum r where range [idx, r) meets the condition.
    size_t right_bound(size_t idx, const std::function<bool(const Monoid &)> &f)
    {
        assert(idx < n);
        size_t ret = idx;
        Monoid now = identity;
        right_bound(idx, f, 1, 0, N, now, ret);
        return std::min(ret, n);
    }

    // minimum l where range [l, idx) meets the condition.
    size_t left_bound(size_t idx, const std::function<bool(const Monoid &)> &f)
    {
        assert(idx <= n);
        size_t ret = idx;
        Monoid now = identity;
        left_bound(idx, f, 1, 0, N, now, ret);
        return ret;
    }

  private:
    size_t left(const size_t k) const { return k * 2; }
    size_t right(const size_t k) const { return left(k) ^ 1; }
    size_t parent(const size_t k) const { return k >> 1; }
    size_t sibling(const size_t k) const { return k ^ 1; }

    void right_bound(size_t idx, const std::function<bool(const Monoid &)> &f,
                     size_t k, size_t l, size_t r, Monoid &now, size_t &pos)
    {
        if(idx >= r || l > pos) return;
        const size_t mid = (l + r) / 2;
        if(l >= idx)
        {
            Monoid nxt = opr(now, data[k]);
            if(f(nxt))
            {
                pos = r;
                now = nxt;
                return;
            }
        }
        if(r - l > 1)
        {
            right_bound(idx, f, left(k), l, mid, now, pos);
            right_bound(idx, f, right(k), mid, r, now, pos);
        }
    }

    void left_bound(size_t idx, const std::function<bool(const Monoid &)> &f,
                    size_t k, size_t l, size_t r, Monoid &now, size_t &pos)
    {
        if(idx <= l || r < pos) return;
        const size_t mid = (l + r) / 2;
        if(r <= idx)
        {
            Monoid nxt = opr(data[k], now);
            if(f(nxt))
            {
                pos = l;
                now = nxt;
                return;
            }
        }
        if(r - l > 1)
        {
            left_bound(idx, f, right(k), mid, r, now, pos);
            left_bound(idx, f, left(k), l, mid, now, pos);
        }
    }
};

const bool naive=0;

void __solve()
{
    const int inf=1e9+7;

    int n; cin>>n;
    vector<i64> a(n);
    cin>>a;
    vector<i64> acc(1+n);
    for(int i=0; i<n; ++i)
    {
        acc[i+1]=acc[i]+a[i];
    }

    int m; cin>>m;
    vector<vector<pii>> qu(n+1);
    for(int i=0; i<m; ++i)
    {
        int p,k; cin>>k>>p; p;
        qu[k].emplace_back(p,i);
    }

    vector<i64> ans(m,-1);

    Segment_tree<int,int> seg(n,0,plus<int>(),[](int &x,int y){x+=y;});

    vector<pii> b(n);
    for(int i=0; i<n; ++i)
    {
        b[i]={a[i],i};
    }
    sort(all(b),[](pii p, pii q)
    {
        if(p.first!=q.first)
        {
            return p.first<q.first;
        }
        return p.second>q.second;
    });
    dump(b);

    int prv=inf;
    for(int k=1; k<=n; k++)
    {
        int v,ni; tie(v,ni)=b.back();
        b.pop_back();
        seg.update(ni,1);

        for(auto e : qu[k])
        {
            int ii;
            ii=seg.right_bound(0,[&](int x){return x<e.first;});
            dump(k,e.first,ii);
            ans[e.second]=a[ii];
        }
    }

    if(naive)
    {
        for(int k=1; k<=n; ++k)
        {
            int opt=-1;
            i64 maxs=0;
            for(int i=0; i+k<=n; ++i)
            {
                if(sbmax(maxs,acc[i+k]-acc[i]))
                {
                    opt=i;
                }
                else if(maxs==acc[i+k]-acc[i])
                {
                    // lexicographically compare
                    for(int l=0; l<k; ++l)
                    {
                        if(a[l+opt]!=a[l+i])
                        {
                            if(a[l+i]<a[l+opt])
                            {
                                opt=i;
                            }
                            break;
                        }
                    }
                }
            }
            assert(~opt);
            for(auto e : qu[k])
            {
                ans[e.second]=a[e.first+opt];
            }
            dump(k,opt,maxs);
        }
    }
    else
    {

    }

    for(auto x : ans)
    {
        assert(~x);
        cout << x << "\n";
    }
}