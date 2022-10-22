#include <stdlib.h>
#include <assert.h>
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
#include <cmath>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>

using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
using db = long double;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
using pdi = pair<double, int>;
template <class T> using vct = vector<T>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / 4 - 17;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double gold = 1.618033988;
constexpr long double eps = 1e-15;

#define mod 1000000007LL
#define stdout_precision 10
#define stderr_precision 2
#define itr(i,v) for(auto i = begin(v); i != end(v); ++i)
#define ritr(i,v) for(auto i = rbegin(v); i != rend(v); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define fir first
#define sec second
#define fro front
#define bac back
#define u_map unordered_map
#define u_set unordered_set
#define l_bnd lower_bound
#define u_bnd upper_bound
#define rsz resize
#define ers erase
#define emp emplace
#define emf emplace_front
#define emb emplace_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcount

struct setupper {
    setupper() {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        std::cerr.tie(nullptr);
        std::cout << fixed << setprecision(stdout_precision);
        std::cerr << fixed << setprecision(stderr_precision);
// #ifdef LOCAL
//         std::cerr << "\n---stderr---\n";
//         auto print_atexit = []() {
//             std::cerr << "Exec time : " << clock() / (double)CLOCKS_PER_SEC * 1000.0 << "ms\n";
//             std::cerr << "------------\n";
//         };
//         atexit((void(*)())print_atexit);
// #endif
    }
} setupper_;

namespace std {
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
    template <class Tup, size_t index = tuple_size<Tup>::value - 1> struct hashval_calc {
        static void apply(size_t& seed, Tup const& tup) {
            hashval_calc<Tup, index - 1>::apply(seed, tup);
            hash_combine(seed,get<index>(tup));
        }
    };
    template <class Tup> struct hashval_calc<Tup,0> {
        static void apply(size_t& seed, Tup const& tup) {
            hash_combine(seed,get<0>(tup));
        }
    };
    template <class ...T> struct hash<tuple<T...>> {
        size_t operator()(tuple<T...> const& tup) const
        {
            size_t seed = 0;
            hashval_calc<tuple<T...>>::apply(seed,tup);
            return seed;
        }
    };
}

template <class T, class U> istream &operator>> (istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
template <class T, class U> ostream &operator<< (ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
template <class T> ostream &operator<< (ostream &s, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); ++i) s << (i ? " " : "") << v[i];
    return s;
}
#define dump(...) cerr << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ";\
dump_func(__VA_ARGS__)
template <class T> void dump_func(T x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(T x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T = int> T read() { T x; return cin >> x, x; }
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
    template <class T> static bool chmax(T &x, const T &y) { return x < y ? x = y,true : false; }
    template <class T> static bool chmin(T &x, const T &y) { return x > y ? x = y,true : false; }
};
using updater::chmax;
using updater::chmin;

template <class T> T minf(const T &x, const T &y) { return min(x,y); }
template <class T> T mixf(const T &x, const T &y) { return max(x,y); }
bool bit(i64 n, uint8_t e) { return (n >> e) & 1; }
i64 mask(i64 n, uint8_t e) { return n & ((1 << e) - 1); }
int ilog(uint64_t x, uint64_t b = 2) { return x ? 1 + ilog(x / b,b) : -1; }
template <class F> i64 binry(i64 ok, i64 ng, const F &fn) {
    while (abs(ok - ng) > 1) {
        i64 mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array,(T*)(array + N),val); }
template <class A> void cmprs(A ary[], size_t n) {
    vector<A> tmp(ary,ary + n);
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(A *i = ary; i != ary + n; ++i) *i = l_bnd(all(tmp),*i) - begin(tmp);
}
template <class T> void cmprs(vector<T> &v) {
    vector<T> tmp = v; sort(begin(tmp),end(tmp));
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(auto i = begin(v); i != end(v); ++i) *i = l_bnd(all(tmp),*i) - begin(tmp);
}
template <class F> void for_subset(uint_fast64_t s, const F &fn) {
    uint_fast64_t tmp = s;
    do { fn(tmp); } while((--tmp &= s) != s);
}

/* The main code follows. */

struct UnionFind
{
	vector<int> par;
	vector<int> size;

	UnionFind(int n)
	{
		init(++n);
	}

	void init(int n)
	{
		par.resize(n);
		size.assign(n, 1);
		for (int i = 0; i < n; ++i)
			par[i] = i;
	}

	int find(int x)
	{
		if (par[x] == x)
		{
			return x;
		}
		else
		{
			int r = find(par[x]);
			return par[x] = r;
		}
	}

	int scale(int x) { return size[find(x)]; }

	bool is_same(int x, int y) { return find(x) == find(y); }

	bool unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (size[x] < size[y])
			swap(x, y);
		size[x] += size[y];
		par[y] = x;
		return true;
	}
};


int n,m,d;
vector<int> G[1<<18];
bool used_neigh[1<<18];
bool used_root[1<<18];
vector<pii> ans;
bool vis[1<<18];

signed main() {
    cin>>n>>m>>d;
    UnionFind uf(n);
    rep(i,m) {
        int u,v; cin>>u>>v;
        u--,v--;
        if(u && v) uf.unite(u,v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vis[0]=true;
    queue<int> qu;
    for(int e:G[0]) {
        int r=uf.find(e);
        if(used_root[r]) continue;
        used_neigh[e]=true;
        used_root[r]=true;
        vis[e]=true;
        d--;
        qu.emplace(e);
        ans.emplace_back(0,e);
    }
    if(d<0) esc("NO");
    for(int e:G[0]) {
        if(!d) break;
        if(!used_neigh[e]) {
            used_neigh[e]=true;
            ans.emplace_back(0,e);
            qu.emplace(e);
            vis[e]=true;
            d--;
        }
    }
    if(d>0) esc("NO");
    while(!qu.empty()) {
        int v=qu.front();
        qu.pop();
        for(int e:G[v]) {
            if(vis[e]) continue;
            ans.emplace_back(v,e);
            vis[e]=true;
            qu.emplace(e);
        }
    }
    assert(ans.size()==n-1);
    writeln("YES");
    for(auto &p:ans) {
        p.fir++;
        p.sec++;
        writeln(p);
    }
}