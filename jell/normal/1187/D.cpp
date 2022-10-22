#ifndef LOCAL
    #pragma GCC optimize("Ofast")
#endif
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>
 
using namespace std;
using i64 = int_fast64_t;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)2 - (T)123456;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832795;
constexpr long double Golden = 1.61803398874989484820;
constexpr long double eps = 1e-15;
 
#define iostream_untie true
#define mod 1000000007LL
#define stdout_precision 10
#define stderr_precision 10
#define itrep(i,v) for(auto i = begin(v); i != end(v); ++i)
#define ritrep(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
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
#define popcnt __builtin_popcount
 
namespace setup {
    struct setupper {
        setupper() {
            if(iostream_untie) {
                ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
                std::cout.tie(nullptr);
                std::cerr.tie(nullptr);
            }
            std::cout << std::fixed << std::setprecision(stdout_precision);
            std::cerr << std::fixed << std::setprecision(stderr_precision);
    #ifdef LOCAL
            if(!freopen("stderr.txt","wt",stderr)) {
                std::cerr << "Failed to open the stderr file\n";
                freopen("CON","wt",stderr);
            }
            if(!freopen("stdout.txt","wt",stdout)) {
                std::cerr << "Failed to open the stdout file\n";
                freopen("CON","wt",stdout);
            }
            if(!freopen("stdin.txt","rt",stdin)) {
                std::cerr << "Failed to open the stdin file.\n";
                freopen("CON","rt",stdin);
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
#define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ";\
dump_func(__VA_ARGS__)
template <class T> void dump_func(T x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(T x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T = i64> T read() { T x; return cin >> x, x; }
template <class T> void write(T x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
 
namespace updater {
    template <class T> static void add(T &x, const T &y) { x += y; }
    template <class T> static void ext_add(T &x, const T &y, size_t w) { x += y * w; }
    template <class T> static void mul(T &x, const T &y) { x *= y; }
    template <class T> static void ext_mul(T &x, const T &y, size_t w) { x *= (T)pow(y,w); }
    template <class T> static bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
    template <class T> static bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
};
using updater::add;
using updater::chmax;
using updater::chmin;
 
template <class T> constexpr T minf(const T &x, const T &y) { return min(x,y); }
template <class T> constexpr T maxf(const T &x, const T &y) { return max(x,y); }
constexpr bool bit(i64 n, int e) { return (n >> e) & 1; }
constexpr int_fast64_t mask(int_fast64_t n, int e) { return n & ((1 << e) - 1); }
constexpr int ilog(int_fast64_t x, int_fast64_t b = 2) { return x ? 1 + ilog(x / b, b) : -1; }
int_fast64_t binry(int_fast64_t ok, int_fast64_t ng, const function<bool(int_fast64_t)> &fn) {
    while (abs(ok - ng) > 1) {
        int_fast64_t mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array,(T*)(array + N),val); }
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
 
 
template <class Monoid, class act_t>
struct Segtree {
    vector<Monoid> data;
    const int n;
    const size_t N;
 
    using opr_t = function<Monoid(const Monoid&, const Monoid&)>;
    using update_opr_t = function<void(Monoid&, const act_t&)>;
    const opr_t opr;
    const update_opr_t update_opr;
    const Monoid idel;
 
    constexpr size_t adjust_size(const int32_t n) {
        size_t d = 0; 
        for(size_t i = 0; i < 30; ++i) if(n >> i & 1) d = i; 
        return 1 << (d + 1);
    }
 
    constexpr size_t left(const size_t k) {
        return k * 2;
    }
 
    constexpr size_t right(const size_t k) {
        return left(k) + 1;
    }
 
    constexpr size_t parent(const size_t k) {
        return k >> 1;
    }
 
    constexpr size_t sibling(const size_t k) {
        return k ^ 1;
    }
 
    Segtree(size_t _n, const Monoid &_idel, const opr_t &_opr, const update_opr_t &_update_opr)
        : n(_n), N(adjust_size(_n)), opr(_opr), update_opr(_update_opr), idel(_idel)
    {
        data.assign(N << 1, idel);
    }
 
    const Monoid& operator[](size_t i) {
        return data[i + N];
    }
 
    template <class P> void copy(P s, P t) {
        for(size_t i = N; s != t; ++s, ++i) data[i] = *s;
        for(size_t i = N - 1; i; --i) data[i] = opr(data[left(i)], data[right(i)]);
    }
 
    template <class A> void copy(const A &v) {
        copy(begin(v), end(v));
    }
 
    void init(const Monoid &x) {
        for(size_t i = 0; i < N; ++i) data[i + N] = x;
        for(size_t i = N - 1; i; --i) data[i] = opr(data[left(i)], data[right(i)]);
    }
 
    void update(size_t idx, act_t val) {
        update_opr(data[idx += N], val);
        while(idx >>= 1) data[idx] = opr(data[idx * 2], data[idx * 2 + 1]);
    }
 
    Monoid query(size_t a, size_t b, bool is_first = true) const {
        if(a >= b) return idel;
        if(is_first) a += N, b += N;
        Monoid left = a & 1 ? data[a++] : idel;
        Monoid right = b & 1 ? data[--b] : idel;
        return opr(opr(left, query(a >> 1, b >> 1, false)), right);
    }
 
    int rightbound(size_t i, const function<bool(Monoid,size_t)> &judge) {
        if(i >= n) return n; 
        int w = 1, rig = i, j = N << 1;
        i += N;
        while(i != j) {
            if(i & 1) {
                rig += w;
                if(!judge(data[i],w)) break;
                ++i;
            }
            i >>= 1, j >>= 1, w <<= 1;
        }
        if(i == j) return n;
        while(w > 1) {
            if(judge(data[i <<= 1], w >>= 1)) ++i;
            else rig -= w;
        }
        return min(n,--rig);
    }
 
    int leftbound(size_t i, const function<bool(Monoid,size_t)> &judge) {
        if(i < 0) return -1;
        int w = 1, lef = i, j = N - 1;
        i += N;
        while(i != j) {
            if(i & 1 ^ 1) {
                lef -= w;
                if(!judge(data[i],w)) break;
                --i;
            } 
            i >>= 1, j >>= 1, w <<= 1;
        }
        if(i == j) return -1;
        while(w > 1) {
            if(judge(data[++(i <<= 1)], w >>= 1)) --i;
            else lef += w;
        }
        return ++lef;
    }
 
    struct sum_lower_bound_opr {
        Monoid x;
        sum_lower_bound_opr(Monoid _x) : x(_x) {}
        bool operator()(Monoid v, size_t w) {
            return v < x ? x -= v,true : false;
        }
    };
 
    int sum_lower_leftbound(size_t i, Monoid v) {
        return leftbound(i, sum_lower_bound_opr(v));
    }
 
    int sum_lower_rightbound(size_t i, Monoid v) {
        return rightbound(i, sum_lower_bound_opr(v));
    }
 
    struct sum_upper_bound_opr {
        Monoid x;
        sum_upper_bound_opr(Monoid _x) : x(_x) {}
        bool operator()(Monoid v, size_t w) {
            return v <= x ? x -= v,true : false;
        }
    };
 
    int sum_upper_leftbound(size_t i, Monoid v) {
        return leftbound(i, sum_upper_bound_opr(v));
    }
 
    int sum_upper_rightbound(size_t i, Monoid v) {
        return rightbound(i, sum_upper_bound_opr(v));
    }
};
 
int qry;
int n;
int a[300010];
int b[300010];
 
bool solve() {
    Segtree<int,int> seg(n+1,-1,maxf<int>,[&](int &a,int b){a=b;});
    vector<vector<int>> plac(n+1);
    for(int i=0; i<n; ++i) {
        plac[b[i]].emplace_back(i);
    }
    vector<size_t> itr(n+1);
    for(int i=0; i<n; ++i) {
        if(plac[a[i]].size()==itr[a[i]]) return false;
        int p=plac[a[i]][itr[a[i]]++];
        if(~p) {
            if(p<seg.query(0,a[i])) return false;
            seg.update(a[i],p);
        } else {
            return false;
        }
    }
    return true;
}
 
signed main() {
    cin>>qry;
    while(qry--) {
        cin>>n;
        rep(i,n) cin>>a[i];
        rep(i,n) cin>>b[i];
        if(solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}