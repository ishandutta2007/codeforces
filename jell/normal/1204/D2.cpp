#ifdef DEBUG
    #define _GLIBCXX_DEBUG
#endif 
#if !defined(LOCAL) && !defined(DEBUG)
    #pragma GCC optimize("Ofast")
#endif
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

#define stdout_filepath "stdout.txt"
#define stderr_filepath "stderr.txt"
#define iostream_untie true
#define stdout_precision 10
#define stderr_precision 10
#define rep(i,n) for(int_fast64_t i = 0; i < (int_fast64_t)(n); ++i)
#define rrep(i,n) for(int_fast64_t i = (int_fast64_t)(n) - 1; i >= 0; --i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define fir first
#define sec second
#define u_map unordered_map
#define u_set unordered_set
#define l_bnd lower_bound
#define u_bnd upper_bound
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcountll

using namespace std;
using i64 = int_fast64_t;
using pii = pair<int, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)2 - (T)1234567;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832;
constexpr long double Golden = 1.61803398874989484820;

namespace setup {
    struct setupper {
        setupper() {
            if(iostream_untie) {
                ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
                // std::cout.tie(nullptr);
                // std::cerr.tie(nullptr);
            }
            std::cout << std::fixed << std::setprecision(stdout_precision);
            std::cerr << std::fixed << std::setprecision(stderr_precision);
    #ifdef LOCAL
            if(!freopen(stderr_filepath,"wt",stderr)) {
                freopen("CON","wt",stderr);
                std::cerr << "Failed to open the stderr file\n";
            }
            if(!freopen(stdout_filepath,"wt",stdout)) {
                freopen("CON","wt",stdout);
                std::cerr << "Failed to open the stdout file\n";
            }
            // auto print_atexit = []() {
            //     std::cerr << "Exec time : " << clock() / (double)CLOCKS_PER_SEC * 1000.0 << "ms\n";
            //     std::cerr << "------------\n";
            // };
            // atexit((void(*)())print_atexit);
    #endif
        }
    } __setupper;
}

namespace std {
    template <class RAitr> void rsort(RAitr __first, RAitr __last) {
        sort(__first, __last, greater<>());
    }
    template <class T> void hash_combine(size_t &seed, T const &key) {
        seed ^= hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    template <class T, class U> struct hash<pair<T,U>> {
        size_t operator()(pair<T,U> const &pr) const
        {
            size_t seed = 0;
            hash_combine(seed,pr.first);
            hash_combine(seed,pr.second);
            return seed;
        }
    };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct hashval_calc {
        static void apply(size_t& seed, tuple_t const& t) {
            hashval_calc<tuple_t, index - 1>::apply(seed, t);
            hash_combine(seed,get<index>(t));
        }
    };
    template <class tuple_t>
    struct hashval_calc<tuple_t, 0> {
        static void apply(size_t& seed, tuple_t const& t) {
            hash_combine(seed,get<0>(t));
        }
    };
    template <class ...T> struct hash<tuple<T...>> {
        size_t operator()(tuple<T...> const& t) const
        {
            size_t seed = 0;
            hashval_calc<tuple<T...>>::apply(seed,t);
            return seed;
        }
    };
}

template <class T, class U> istream &operator>> (istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
template <class T, class U> ostream &operator<< (ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
template <class T> istream &operator>> (istream &s, vector<T> &v) { for(T &e : v) { s >> e; }   return s; }
template <class T> ostream &operator<< (ostream &s, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); ++i) { s << (i ? " " : "") << v[i]; }   return s;
}
template <class tuple_t, size_t index>
struct tupleos {
    static ostream &apply(ostream &s, const tuple_t &t) {
        tupleos<tuple_t,index - 1>::apply(s,t);
        return s << " " << get<index>(t);
    }
}; 
template <class tuple_t>
struct tupleos<tuple_t, 0> {
    static ostream &apply(ostream &s, const tuple_t &t) {
        return s << get<0>(t);
    }
};
template <class ...T> ostream &operator<< (ostream &s, const tuple<T...> &t) {
    return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(s,t);
}
template <> ostream &operator<< (ostream &s, const tuple<> &t) { return s; }
#ifdef DEBUG
    #define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ", dump_func(__VA_ARGS__)
#else
    #define dump(...) 
#endif
template <class T> void dump_func(const T &x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(const T &x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T> void write(const T &x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(const T &x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(const T &x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
template <class P> void read(P __first, P __second) { for(P i = __first; i != __second; ++i) cin >> *i; }

namespace updater {
    template <class T> static void add(T &x, const T &y) { x += y; }
    template <class T> static void ext_add(T &x, const T &y, size_t w) { x += y * w; }
    template <class T> static void mul(T &x, const T &y) { x *= y; }
    template <class T> static void ext_mul(T &x, const T &y, size_t w) { x *= (T)pow(y,w); }
    template <class T> static bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
    template <class T> static bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
};
using updater::add;
using updater::mul;
using updater::chmax;
using updater::chmin;
template <class T> constexpr T minf(const T &x, const T &y) { return min(x,y); }
template <class T> constexpr T maxf(const T &x, const T &y) { return max(x,y); }
constexpr bool odd(int_fast64_t n) { return n & 1; }
constexpr bool even(int_fast64_t n) { return (int)odd(n) ^ 1; }
constexpr bool bit(int_fast64_t n, int e) { return (n >> e) & 1; }
constexpr int_fast64_t mask(int_fast64_t n, int e) { return n & ((1 << e) - 1); }
constexpr int_fast64_t ilog(int_fast64_t x, int_fast64_t b = 2) { return x ? 1 + ilog(x / b, b) : -1; }
constexpr int_fast64_t gcd(int_fast64_t x, int_fast64_t y) { return x = max(x, -x), y = max(y, -y) ? gcd(y, x % y) : x; }
constexpr int_fast64_t lcm(int_fast64_t x, int_fast64_t y) { return x ? x / gcd(x, y) * y : 0; }
int_fast64_t binry(int_fast64_t ok, int_fast64_t ng, const function<bool(int_fast64_t)> &fn) {
    while (abs(ok - ng) > 1) {
        int_fast64_t mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array, (T*)(array + N), val); }
template <class T> vector<int> cmprs(const vector<T> &v) {
    vector<T> tmp = v; vector<int> ret;
    sort(begin(tmp),end(tmp));
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(T i : v) ret.emplace_back(lower_bound(begin(tmp),end(tmp),i) - begin(tmp));
    return ret;
}
template <class T> vector<int> cmprs(const T *__first, const T *__last) {
    return cmprs(vector<T>(__first, __last));
}
void for_subset(int_fast64_t s, const function<void(int_fast64_t)> &fn) {
    int_fast64_t tmp = s;
    do { fn(tmp); } while((--tmp &= s) != s);
}


/* The main code follows. */


signed main() {
    void solve();
    void input();
    void init();

    int t = 1;

    #ifdef LOCAL
        // cin >> t;
    #endif

    // cin >> t;
    
    while(t--) {
        init();
        input();
        solve();
    }
}


template <class Monoid, class act_t>
struct Segtree {
    vector<Monoid> data;
    const size_t n, N;

    using opr_t = function<Monoid(const Monoid&, const Monoid&)>;
    using update_opr_t = function<void(Monoid&, const act_t&)>;
    const opr_t opr;
    const update_opr_t update_opr;
    const Monoid identity;

    constexpr size_t adjust_size(const int32_t n) {
        size_t d = 0; 
        for(size_t i = 0; i < 30; ++i) if(n >> i & 1) d = i; 
        return 1 << (d + 1);
    }

    constexpr size_t left(const size_t k) { return k * 2; }

    constexpr size_t right(const size_t k) { return left(k) ^ 1; }

    constexpr size_t parent(const size_t k) { return k >> 1; }

    constexpr size_t sibling(const size_t k) { return k ^ 1; }

    Segtree(size_t _n, const Monoid &_identity, const opr_t &_opr, const update_opr_t &_update_opr)
        : n(_n), N(adjust_size(_n)), opr(_opr), update_opr(_update_opr), identity(_identity)
    {
        data.assign(N << 1, identity);
    }

    const Monoid& operator[](size_t i) { return data[i + N]; }

    template <class P> void copy(P s, P t) {
        for(size_t i = N; s != t; ++s, ++i) data[i] = *s;
        for(size_t i = N - 1; i; --i) data[i] = opr(data[left(i)], data[right(i)]);
    }

    template <class A> void copy(const A &v) { copy(begin(v), end(v)); }

    void init(const Monoid &x) {
        for(size_t i = 0; i < N; ++i) data[i + N] = x;
        for(size_t i = N - 1; i; --i) data[i] = opr(data[left(i)], data[right(i)]);
    }

    void update(size_t idx, act_t val) {
        update_opr(data[idx += N], val);
        while(idx >>= 1) data[idx] = opr(data[idx * 2], data[idx * 2 + 1]);
    }

    Monoid query(size_t a, size_t b, bool is_first = true) const {
        if(a >= b) return identity;
        if(is_first) a += N, b += N;
        Monoid left = a & 1 ? data[a++] : identity;
        Monoid right = b & 1 ? data[--b] : identity;
        return opr(opr(left, query(a >> 1, b >> 1, false)), right);
    }

    size_t rightbound(size_t idx, const function<bool(const Monoid&)> &judge) {
        assert(idx < n);
        size_t ret = idx;
        Monoid now = identity;
        rightbound(idx, judge, 1, 0, N, now, ret);
        return min(ret, n);
    }

    void rightbound(size_t idx, const function<bool(const Monoid&)> &judge, size_t k, size_t l, size_t r, Monoid &now, size_t &pos) {
        if(idx >= r || l > pos) return;
        const size_t mid = (l + r) / 2;
        if(l >= idx) {
            Monoid nxt = opr(now, data[k]);
            if(judge(nxt)) {
                pos = r; now = nxt;
                return;
            }
        }
        if(r - l > 1) {
            rightbound(idx, judge, left(k), l, mid, now, pos);
            rightbound(idx, judge, right(k), mid, r, now, pos);
        }
    }

    size_t leftbound(size_t idx, const function<bool(const Monoid&)> &judge) {
        assert(idx <= n);
        size_t ret = idx;
        Monoid now = identity;
        leftbound(idx, judge, 1, 0, N, now, ret);
        return ret;
    }

    void leftbound(size_t idx, const function<bool(const Monoid&)> &judge, size_t k, size_t l, size_t r, Monoid &now, size_t &pos) {
        if(idx <= l || r < pos) return;
        const size_t mid = (l + r) / 2;
        if(r <= idx) {
            Monoid nxt = opr(data[k], now);
            if(judge(nxt)) {
                pos = l; now = nxt;
                return;
            }
        }
        if(r - l > 1) {
            leftbound(idx, judge, right(k), mid, r, now, pos);
            leftbound(idx, judge, left(k), l, mid, now, pos);
        }
    }
};


template <class Monoid, class act_t>
struct LazySegtree {
    const size_t n, N;
    vector<Monoid> data;
    vector<act_t> lazy;
    vector<bool> lazyflag;

    using opr_t = function<Monoid(const Monoid&, const Monoid&)>;
    using lazy_opr_t = function<void(act_t&, const act_t&, size_t)>;
    using update_opr_t = function<void(Monoid&, const act_t&, size_t)>;
    const opr_t opr;
    const lazy_opr_t lazy_opr;
    const update_opr_t update_opr;
    const Monoid identity, lazy_identity;

    constexpr size_t adjust_size(const size_t n) {
        size_t d = 0; 
        for(size_t i = 0; i < 30; ++i) if(n >> i & 1) d = i; 
        return 1 << (d + 1);
    }

    constexpr size_t left(const size_t k) { return k * 2; }

    constexpr size_t right(const size_t k) { return left(k) ^ 1; }

    constexpr size_t parent(const size_t k) { return k >> 1; }

    constexpr size_t sibling(const size_t k) { return k ^ 1; }

    LazySegtree(size_t _n, const Monoid &_identity, const Monoid &_lazy_identity, const opr_t &_opr, const lazy_opr_t &_lazy_opr, const update_opr_t &_update_opr)
        : n(_n), N(adjust_size(_n)), opr(_opr), lazy_opr(_lazy_opr), update_opr(_update_opr), identity(_identity), lazy_identity(_lazy_identity)
    {
        data.assign(N << 1, identity);
        lazy.assign(N << 1, lazy_identity);
        lazyflag.assign(N << 1, false);
    }

    const Monoid& operator[](size_t i) { return query(i, i + 1); }

    template <class P> void copy(P s, P t) {
        for(size_t i = N; s != t; ++s, ++i) data[i] = *s;
        for(size_t i = N - 1; i; --i) data[i] = opr(data[left(i)], data[right(i)]);
    }

    template <class A> void copy(A &v) { copy(begin(v), end(v)); }

    void init(const Monoid &x) {
        for(size_t i = 0; i < N; ++i) data[i + N] = x;
        for(size_t i = N - 1; i; --i) data[i] = opr(data[left(i)], data[right(i)]);
    }

    void eval(size_t k, size_t l, size_t r) {
        if(!lazyflag[k]) return;
        update_opr(data[k], lazy[k], r - l);
        if(r - l > 1) {
            lazy_opr(lazy[left(k)], lazy[k], (r - l) / 2);
            lazy_opr(lazy[right(k)], lazy[k], (r - l) / 2);
            lazyflag[left(k)] = lazyflag[right(k)] = true;
        }
        lazy[k] = lazy_identity;
        lazyflag[k] = false;
    }

    void update(size_t a, size_t b, const act_t &actor) { update(a, b, actor, 1, 0, N); }

    void update(size_t a, size_t b, const act_t &actor, size_t k, size_t l, size_t r) {
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy_opr(lazy[k], actor, r - l);
            lazyflag[k] = true;
            eval(k, l, r);
        } else {
            update(a, b, actor, left(k), l, (l + r) / 2);
            update(a, b, actor, right(k), (l + r) / 2, r);
            data[k] = opr(data[left(k)], data[right(k)]);
        }
    }

    Monoid query(size_t a, size_t b) { return query(a, b, 1, 0, N); }

    Monoid query(size_t a, size_t b, size_t k, size_t l, size_t r) {
        if(b <= l || r <= a) return identity;
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        return opr(query(a, b, left(k), l, (l + r) / 2), query(a, b, right(k), (l + r) / 2, r));
    }

    size_t rightbound(size_t idx, const function<bool(const Monoid&)> &judge) {
        assert(idx < n);
        size_t ret = idx;
        Monoid now = identity;
        rightbound(idx, judge, 1, 0, N, now, ret);
        return min(ret, n);
    }

    void rightbound(size_t idx, const function<bool(const Monoid&)> &judge, size_t k, size_t l, size_t r, Monoid &now, size_t &pos) {
        if(idx >= r || l > pos) return;
        eval(k, l, r);
        const size_t mid = (l + r) / 2;
        if(l >= idx) {
            Monoid nxt = opr(now, data[k]);
            if(judge(nxt)) {
                pos = r; now = nxt;
                return;
            }
        }
        if(r - l > 1) {
            rightbound(idx, judge, left(k), l, mid, now, pos);
            rightbound(idx, judge, right(k), mid, r, now, pos);
        }
    }

    size_t leftbound(size_t idx, const function<bool(const Monoid&)> &judge) {
        assert(idx <= n);
        size_t ret = idx;
        Monoid now = identity;
        leftbound(idx, judge, 1, 0, N, now, ret);
        return ret;
    }

    void leftbound(size_t idx, const function<bool(const Monoid&)> &judge, size_t k, size_t l, size_t r, Monoid &now, size_t &pos) {
        if(idx <= l || r < pos) return;
        eval(k, l, r);
        const size_t mid = (l + r) / 2;
        if(r <= idx) {
            Monoid nxt = opr(data[k], now);
            if(judge(nxt)) {
                pos = l; now = nxt;
                return;
            }
        }
        if(r - l > 1) {
            leftbound(idx, judge, right(k), mid, r, now, pos);
            leftbound(idx, judge, left(k), l, mid, now, pos);
        }
    }
};


int n;
string s;


void init() {}

void input() {
    cin>>s;
    n=s.size();
}

void solve() {
    LazySegtree<int,int> sg(n+1,inf<int>,0,minf<int>,[&](int &x,int y,int w){x+=y;},[&](int &x,int y,int w){x+=y;});
    LazySegtree<int,int> sg2(n+1,inf<int>,0,minf<int>,[&](int &x,int y,int w){x+=y;},[&](int &x,int y,int w){x+=y;});
    
    sg.init(0);
    sg2.init(0);

    for(int i=n-1; i>=0; --i) {
        int now=-1;
        if(s[i]=='1') now=1;
        sg2.update(i,n,now);
    }

    
    for(int i=0; i<n; ++i) {
        bool lft=true;
        if(i) {
            lft=sg.query(0,i)<=0;
        }
        bool rgt=true;
        sg2.update(i,n,s[i]=='1'?-1:1);
        if(i<n-1) {
            rgt=sg2.query(i+1,n)>=0;
        }
        if(s[i]=='1' and lft and rgt) {
            s[i]='0';
        }
        sg.update(0,i+1,s[i]=='1'?1:-1);
    }
    
    write(s);
}