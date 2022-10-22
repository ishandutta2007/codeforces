#ifdef stderr_path
#define LOCAL
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("Ofast")
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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#define debug_stream std::cerr
#define iostream_untie true
#define __precision__ 10

#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define __odd(n) ((n) & 1)
#define __even(n) (__odd(n) ^ 1)
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(int32_t(n))
#define __clz64(n) __builtin_clzll(int64_t(n))
#define __ctz32(n) __builtin_ctz(int32_t(n))
#define __ctz64(n) __builtin_ctzll(int64_t(n))

using i64 = int_fast64_t;
using pii = std::pair<int, int>;
using pll = std::pair<int_fast64_t, int_fast64_t>;
template <class T>
using heap = std::priority_queue<T>;
template <class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
constexpr T inf = std::numeric_limits<T>::max() / T(2) - T(1123456);

namespace execution
{
    std::chrono::system_clock::time_point start_time, end_time;
    void print_elapsed_time()
    {
        end_time = std::chrono::system_clock::now();
        std::cerr << "\n----- Exec time : ";
        std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end_time - start_time)
                         .count();
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
            else
                fclose(stderr);
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
} // namespace execution

struct myclock_t
{
    std::chrono::system_clock::time_point built_pt, last_pt;
    int built_ln, last_ln;
    std::string built_func, last_func;
    bool is_built;
    myclock_t() : is_built(false)
    {}
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
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] "
                         << "myclock_t::set failed (yet to be built!)\n";
        }
    }
    void get(int crt_ln, const std::string &crt_func)
    {
        if(is_built)
        {
            std::chrono::system_clock::time_point crt_pt(
                std::chrono::system_clock::now());
            int64_t diff =
                std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt -
                                                                      last_pt)
                    .count();
            debug_stream << diff << " ms elapsed from"
                         << " [ " << last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) debug_stream << " (when built)";
            debug_stream << " to"
                         << " [ " << crt_ln << " : " << crt_func << " ]"
                         << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] "
                         << "myclock_t::get failed (yet to be built!)\n";
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
    template <class RAitr>
    void rsort(RAitr __first, RAitr __last)
    {
        sort(__first, __last, greater<>());
    }
    template <class T>
    size_t hash_combine(size_t seed, T const &key)
    {
        return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
    }
    template <class T, class U>
    struct hash<pair<T, U>>
    {
        size_t operator()(pair<T, U> const &pr) const
        {
            return hash_combine(hash_combine(0, pr.first), pr.second);
        }
    };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct tuple_hash_calc
    {
        static size_t apply(size_t seed, tuple_t const &t)
        {
            return hash_combine(
                tuple_hash_calc<tuple_t, index - 1>::apply(seed, t),
                get<index>(t));
        }
    };
    template <class tuple_t>
    struct tuple_hash_calc<tuple_t, 0>
    {
        static size_t apply(size_t seed, tuple_t const &t)
        {
            return hash_combine(seed, get<0>(t));
        }
    };
    template <class... T>
    struct hash<tuple<T...>>
    {
        size_t operator()(tuple<T...> const &t) const
        {
            return tuple_hash_calc<tuple<T...>>::apply(0, t);
        }
    };
    template <class T, class U>
    istream &operator>>(std::istream &s, pair<T, U> &p)
    {
        return s >> p.first >> p.second;
    }
    template <class T, class U>
    ostream &operator<<(std::ostream &s, const pair<T, U> p)
    {
        return s << p.first << " " << p.second;
    }
    template <class T>
    istream &operator>>(istream &s, vector<T> &v)
    {
        for(T &e : v)
        {
            s >> e;
        }
        return s;
    }
    template <class T>
    ostream &operator<<(ostream &s, const vector<T> &v)
    {
        for(size_t i = 0; i < v.size(); ++i)
        {
            s << (i ? " " : "") << v[i];
        }
        return s;
    }
    template <class tuple_t, size_t index>
    struct tupleos
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            tupleos<tuple_t, index - 1>::apply(s, t);
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
    template <class... T>
    ostream &operator<<(ostream &s, const tuple<T...> &t)
    {
        return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(
            s, t);
    }
    template <>
    ostream &operator<<(ostream &s, const tuple<> &t)
    {
        return s;
    }
} // namespace std

#ifdef LOCAL
#define dump(...)                                                              \
    debug_stream << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] "        \
                 << #__VA_ARGS__ << " : ",                                     \
        dump_func(__VA_ARGS__)
#else
#define dump(...) 42
#endif
template <class T>
void dump_func(const T &x)
{
    debug_stream << x << '\n';
}
template <class T, class... Rest>
void dump_func(const T &x, Rest... rest)
{
    debug_stream << x << ", ";
    dump_func(rest...);
}
template <class T>
void write(const T &x)
{
    std::cout << x << '\n';
}
template <class T, class... Rest>
void write(const T &x, Rest... rest)
{
    std::cout << x << ' ';
    write(rest...);
}
void writeln()
{}
template <class T, class... Rest>
void writeln(const T &x, Rest... rest)
{
    std::cout << x << '\n';
    writeln(rest...);
}
#define esc(...) writeln(__VA_ARGS__), exit(0)
template <class P>
void read_range(P __first, P __second)
{
    for(P i = __first; i != __second; ++i)
        std::cin >> *i;
}

template <class T>
bool chmin(T &x, const T &y)
{
    return x > y ? x = y, true : false;
}
template <class T>
bool chmax(T &x, const T &y)
{
    return x < y ? x = y, true : false;
}
template <class T>
constexpr T minf(const T &x, const T &y)
{
    return std::min(x, y);
}
template <class T>
constexpr T maxf(const T &x, const T &y)
{
    return std::max(x, y);
}
template <class int_t, class F>
int_t bin(int_t ok, int_t ng, const F &f)
{
    while(std::abs(ok - ng) > 1)
    {
        int_t mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T>
void init(A (&array)[N], const T &val)
{
    std::fill((T *)array, (T *)(array + N), val);
}
template <class A, size_t N>
void init(A (&array)[N])
{
    memset(array, 0, sizeof(array));
}
void for_subset(int_fast64_t s, const std::function<void(int_fast64_t)> &fn)
{
    int_fast64_t t = s;
    do
    {
        fn(t);
    } while((--t &= s) != s);
}

namespace math
{
    template <class int_t>
    constexpr int_t gcd(int_t x, int_t y)
    {
        x = x > 0 ? x : -x, y = y > 0 ? y : -y;
        while(y)
            y ^= x ^= y ^= x %= y;
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
        int_t sgn_a = a >= 0 ? 1 : (a = -a, 0),
              sgn_b = b >= 0 ? 1 : (b = -b, 0);
        int_t p = 1, q = 0, r = 0, s = 1;
        while(b)
        {
            int_t t = a / b;
            r ^= p ^= r ^= p -= t * r;
            s ^= q ^= s ^= q -= t * s;
            b ^= a ^= b ^= a %= b;
        }
        return std::tuple<int_t, int_t, int_t>(a, sgn_a ? p : -p,
                                               sgn_b ? q : -q);
    }
    template <class int_t>
    constexpr std::pair<int_t, int_t> mod_comp(int_t k, int_t m, int_t l,
                                               int_t n)
    {
        assert(m > 0 and n > 0);
        int_t g, x, y;
        std::tie(g, x, y) = ext_gcd(m, n);
        k += ((k %= m) < 0) * m, l += ((l %= n) < 0) * n;
        int_t s = k / g, t = l / g, r = k % g;
        if(r != l % g) return std::pair<int_t, int_t>(-1, -1);
        int_t lcm = m / g * n;
        return std::pair<int_t, int_t>(
            (m * x % lcm * t % lcm + n * y % lcm * s % lcm + r + lcm * 2) % lcm,
            lcm);
    }
} // namespace math

/* The main code follows. */

template <class K>
class Convex_hull_trick
{
    struct line
    {
        K slop, incp;
        line(K a, K b) : slop(a), incp(b)
        {}
        K get(K x) const
        {
            return slop * x + incp;
        }
    };

    struct node
    {
        line ln;
        node *left, *right;
        node(const line &l) : ln(l), left(nullptr), right(nullptr)
        {}
        ~node()
        {
            delete left;
            delete right;
        }
        K get(K x) const
        {
            return ln.get(x);
        }
    };

    using comp_t = std::function<bool(const K &, const K &)>;
    const comp_t comp;
    const K x_min, x_max, eps;
    std::size_t node_cnt;
    node *root;

    // insert a line or segment for the interval [l, r).
    node *insert(node *const p, const K l, const K r, line ln, const K s,
                 const K t)
    {
        if(t - eps < l or r - eps < s) return p;
        const K mid = (l + r) / 2;
        if(l < s or t < r)
        {
            p->left = insert(p->left, l, mid, ln, s, t);
            p->right = insert(p->right, mid, r, ln, s, t);
            return p;
        }
        if(not p) return ++node_cnt, new node(ln);
        bool lcmp = comp(ln.get(l), p->get(l));
        bool rcmp = comp(ln.get(r - eps), p->get(r - eps));
        if(lcmp == rcmp)
        {
            if(lcmp) p->ln = ln;
            return p;
        }
        if(r - l <= eps) return p;
        if(comp(ln.get(mid), p->get(mid)))
        {
            std::swap(p->ln, ln);
            lcmp = not lcmp;
        }
        if(lcmp)
            p->left = insert(p->left, l, mid, ln, s, t);
        else
            p->right = insert(p->right, mid, r, ln, s, t);
        return p;
    }

  public:
    static constexpr K inf = std::numeric_limits<K>::max() / K(2) - K(1123456);
    // domain set to be the interval [x_min, x_max).
    explicit Convex_hull_trick(const comp_t &_comp, const K _x_min, const K _x_max,
                      const K _eps = K(1))
        : comp(_comp), x_min(_x_min), x_max(_x_max), eps(_eps), root()
    {}

#ifdef LOCAL
    ~Convex_hull_trick()
    {
        delete root;
    }
#endif

    std::size_t size() const
    {
        return node_cnt;
    }

    bool empty() const
    {
        return !root;
    }

    // insert a line whose slope is p and inception is q.
    void insert(const K p, const K q)
    {
        insert(p, q, x_min, x_max);
    }

    // insert a line(segment) whose slope is p, inception is q,
    // and domain is the interval [s, t).
    void insert(const K p, const K q, const K s, const K t)
    {
        if(s < t) root = insert(root, x_min, x_max, line(p, q), s, t);
    }

    // get the value at x.
    K query(const K x) const
    {
        node *p = root;
        K l = x_min, r = x_max;
        K res = inf;
        while(p)
        {
            if(comp(p->get(x), res)) res = p->get(x);
            if(r - l <= eps) return res;
            K mid = (l + r) / 2;
            if(x < mid)
            {
                p = p->left;
                r = mid;
            }
            else
            {
                p = p->right;
                l = mid;
            }
        }
        return res;
    }
};

using namespace std;
using namespace math;


i64 a[1 << 18], s[1 << 18];

signed main()
{
    int n;
    cin >> n;
    i64 tmp = 0;
    rep(i, n) cin >> a[i];
    s[0] = 0;
    for(int i = 0; i < n; ++i)
        s[i + 1] = s[i] + a[i];
    for(int i = 1; i <= n; ++i)
        tmp += a[i - 1] * i;
    i64 ans = 0;
    {
        Convex_hull_trick<i64> cht(std::less<i64>(),-1000000, 1000001);
        for(int i = 0; i < n; ++i)
        {
            if(i)
            {
                i64 qry = cht.query(a[i]);
                chmax(ans, s[i] - a[i] * i - qry);
            }
            cht.insert(-i, s[i]);
        }
    }
    {
        Convex_hull_trick<i64> cht(std::less<i64>(),-1000000, 1000001);
        for(int i = n - 1; i >= 0; --i)
        {
            if(i < n - 1)
            {
                i64 qry = cht.query(a[i]);
                chmax(ans, s[i + 1] - a[i] * i - qry);
            }
            cht.insert(-i, s[i + 1]);
        }
    }
    std::cout << ans + tmp << "\n";;
}