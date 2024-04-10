#ifndef LOCAL
    #pragma GCC optimize("Ofast")
#endif
#include <cassert>
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
using dbl = double;
using ldbl = long double;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
using pdi = pair<double, int>;
using pdd = pair<double, double>;
template <class T> using vct = vector<T>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)16;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832795028;
constexpr long double Golden = 1.61803398874989484820;
constexpr long double eps = 1e-15;

#define iostream_untie true
#define mod 1000000007LL
#define stdout_precision 10
#define stderr_precision 10
#define itrep(i,v) for(auto i = begin(v); i != end(v); ++i)
#define ritrep(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n) - 1; i >= 0; --i)
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
namespace trie_prep {
    constexpr size_t nodecnt_max = 5e5 * 20;
    
    struct node {
        node *par, *lft, *rgt;
        size_t cnt;
        node(node *_par = nullptr) : par(_par), lft(), rgt(), cnt() {}
    };

    size_t nodecnt = 0;
    node stock[nodecnt_max];

    struct trie {
        const size_t dep;
        node *root;
        
        trie(size_t _dep) : dep(_dep), root(alloc(nullptr)) {}

        node *alloc(node *_par) const {
            node *ret = stock + nodecnt++;
            ret->par = _par;
            return ret;
        }

        size_t size() const {
            return root->cnt;
        }

        bool insert(int_fast64_t x) {
            node *p = root;
            p->cnt++;
            bool ret = false;
            bool bit[dep];
            for(int_fast64_t d = dep - 1, t = x; d >= 0; --d, t >>= 1) {
                bit[d] = t & 1;
            }
            for(size_t d = 0; d < dep; ++d) {
                if(bit[d]) {
                    if(!p->rgt) p->rgt = alloc(p), ret = true;
                    p = p->rgt;
                } else {
                    if(!p->lft) p->lft = alloc(p), ret = true;
                    p = p->lft;
                }
                p->cnt++;
            }
            return ret;
        }

        size_t erase(int_fast64_t x, size_t y = 1) {
            node *list[dep + 1];
            node *p = root;
            list[0] = p;
            bool bit[dep];
            for(int_fast64_t d = dep - 1, t = x; d >= 0; --d, t >>= 1) {
                bit[d] = t & 1;
            }
            for(size_t d = 0; d < dep; list[++d] = p) {
                if(bit[d]) {
                    if(!p->rgt) return 0;
                    p = p->rgt;
                } else {
                    if(!p->lft) return 0;
                    p = p->lft;
                }
            }
            for(size_t i = 0; i <= dep; ++i) {
                p = list[i];
                y = min(y, p->cnt);
                p->cnt -= y;
            }
            return y;
        }

        int_fast64_t operator[](size_t idx) const {
            if(idx >= size()) return -1;
            node *p = root;
            int_fast64_t ret = 0;
            int_fast64_t power[dep];
            for(int_fast64_t d = dep - 1, t = 1; d >= 0; --d, t <<= 1) {
                power[d] = t;
            }
            for(size_t d = 0; d < dep; ++d) {
                size_t lsz = p->lft ? p->lft->cnt : 0;
                if(idx < lsz) {
                    p = p->lft;
                } else {
                    idx -= lsz;
                    p = p->rgt;
                    ret += power[d];
                }
            }
            return ret;
        }
    };
}
using trie_prep::trie;

int n,m,q;
int cnt[500010];
i64 dp[500010];
int ans[500010];

signed main() {
    cin>>n>>m>>q;
    rep(i,n) {
        int a; cin>>a;
        cnt[a]++;
    }

    vector<pll> cit(m);
    for(int i=1; i<=m; ++i) {
        cit[i-1]={cnt[i],i};
    }
    sort(all(cit));

    dp[0]=0;
    for(i64 i=1; i<m; ++i) {
        i64 las=cit[i-1].fir;
        dp[i]=dp[i-1]+i*(cit[i].fir-las);
    }

    trie tri(20);

    minheap<pll> qu;
    rep(i,q) {
        i64 k; cin>>k;
        k-=n;
        qu.emplace(k,i);
    } 

    dp[m]=2e18;
    for(int i=1; i<=m; ++i) {
        tri.insert(cit[i-1].sec);
        while(!qu.empty() && qu.top().fir<=dp[i]) {
            i64 k,qnum; tie(k,qnum)=qu.top();
            k-=dp[i-1];
            qu.pop();
            k%=i; if(!k) k=i;
            ans[qnum]=tri[k-1];
        }
    }

    for(int i=0; i<q; ++i) {
        cout<<ans[i]<<"\n";
    }
}