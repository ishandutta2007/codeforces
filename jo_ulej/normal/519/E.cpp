#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << "[DBG] " << #X << "=" << (X) << '\n';
	#define SAY(X) cout << "[SAY] " << (X) << '\n';
#else
	#define DBG(X)
	#define SAY(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = (int)1e5 + 77;
const int LOG  = 20;
vector<int> G[MAXN];
int n, q, root;
int depth[MAXN], p[LOG][MAXN], subtree[MAXN];
void dfs_init(int v, int pa) {
	depth[v] = (pa == NIL ? 0 : depth[pa] + 1);
	p[0][v] = (pa == NIL ? v : pa);
	subtree[v] = 1;
	for(auto& u: G[v]) if(u != pa) {
		dfs_init(u, v);
		subtree[v] += subtree[u];
	}
}
int up(int v, int k) {
	assert(k <= depth[v]);
	for(int i = 0; i < LOG; ++i) if((k>>i)&1) {
		v = p[i][v];
	}
	return v;
}
int LCA(int v, int u) {
	if(depth[v] < depth[u]) swap(v, u);
	v = up(v, depth[v] - depth[u]);
	if(v == u) return v;
	for(int i = LOG - 1; i >= 0; --i) {
		int v2 = p[i][v], u2 = p[i][u];
		if(v2 != u2) {
			v = v2;
			u = u2;
		}
	}
	return p[0][v];
}
int go(int v, int u, int w, int dist, int k) {
	DBG(v + 1); DBG(u + 1); DBG(k);
	assert(k >= 0 && k <= dist);
	if(k > depth[v] - depth[w]) {
		swap(u, v);
		k = dist - k;
	}
	return up(v, k);
}
int getsz(int v, int child) {
	if(child != p[0][v]) {
		return subtree[child];
	} else {
		return n - subtree[v];
	}
}
int query(int v, int u) {
	if(v == u) return n;
	int w = LCA(v, u); DBG(w + 1);
	int dist = depth[v] + depth[u] - 2 * depth[w];
	if(dist&1) return 0;
	DBG(dist);
	int upper  = go(v, u, w, dist, dist/2-1); DBG(upper + 1);
	int center = go(v, u, w, dist, dist/2); DBG(center + 1);
	int lower  = go(v, u, w, dist, dist/2+1); DBG(lower + 1);
	return n - getsz(center, upper) - getsz(center, lower);
}
void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	root = 0;
	dfs_init(root, NIL);
	for(int log = 1; log < LOG; ++log) for(int v = 0; v < n; ++v) {
		p[log][v] = p[log - 1][p[log - 1][v]];
	}
	for(cin >> q; q > 0; --q) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		cout << query(v, u) << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}