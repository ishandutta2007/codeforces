#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

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
	#define DBG(X) cout << #X << "=" << (X) << '\n';
	#define SAY(X) cout << (X) << '\n';
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

const int MAXN = (int)1e5 + 7;
const int D    = 51;

struct Edge {
	int from, to;

	bool operator<(const Edge& other) const {
		if(from != other.from) return from < other.from;
		return to < other.to;
	}
};

Edge edges[D * MAXN];
int E = 0;

void add_edge(int v, int u) {
	edges[E++] = {v, u};
}

int n, m, d;
int good[D * MAXN];
int g[D * MAXN], ord[D * MAXN], head = 0;
int used[D * MAXN], mark = 13, last;
int scc[D * MAXN];
void build_ord(int v) {
	used[v] = mark;
	for(int i = g[v]; i < E && edges[i].from == v; ++i) {
		int u = edges[i].to;
		if(used[u] != mark) {
			build_ord(u);
		}
	}

	ord[head++] = v;
}

int ord2[D * MAXN], head2 = 0;
void paint(int v) {
	used[v] = mark;
	scc[v] = last;
	ord2[head2++] = v;
	for(int i = g[v]; i < E && edges[i].from == v; ++i) {
		int u = edges[i].to;
		if(used[u] != mark) {
			paint(u);
		}
	}
}

Edge edges2[D * MAXN];
int co[D * MAXN], ptr[D * MAXN];
void initG() {
	memset(co, 0, sizeof(co));
	for(int id = 0; id < E; ++id) {
		++co[edges[id].from];
	}

	ptr[0] = 0;
	for(int i = 1; i < D * MAXN; ++i) {
		ptr[i] = ptr[i - 1] + co[i - 1];
	}

	for(int id = 0; id < E; ++id) {
		int f = edges[id].from;
		edges2[ptr[f]++] = edges[id];
	}

	for(int id = 0; id < E; ++id) edges[id] = edges2[id];
	
	for(int v = 0; v < n * d; ++v) g[v] = E;
	for(int id = 0; id < E; ++id) {
		int v = edges[id].from;
		if(g[v] >= E) {
			g[v] = id;
		}

		//cout << "@@edge: " << edges[id].from << " -> " << edges[id].to << '\n';
	}

	//cout << '\n';
}

int cnt[D * MAXN], dp[D * MAXN];
int fnd[MAXN];

void dfs(int v) {
	used[v] = mark;
	dp[v] = cnt[v];

	for(int i = g[v]; i < E && edges[i].from == v; ++i) {
		int u = edges[i].to;
		if(u == v) continue;
		if(used[u] != mark) dfs(u);
		dp[v] = (dp[u] + cnt[v] > dp[v] ? dp[u] + cnt[v] : dp[v]);
	}
}

void solve() {
	cin >> n >> m >> d;
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		for(int t = 0; t < d; ++t) {
			add_edge(d * v + t, d * u + (t + 1 == d ? 0 : t + 1));
		}
	}

	for(int v = 0; v < n; ++v) {
		auto row = fetch<string>();
		for(int t = 0; t < d; ++t) {
			good[d * v + t] = row[t] - '0';
		}
	}

	initG();
	for(int v = 0; v < n * d; ++v) {
		if(used[v] != mark) {
			build_ord(v);
		}
	}

	for(int id = 0; id < E; ++id) {
		swap(edges[id].from, edges[id].to);
	}

	initG();
	++mark; last = 0;
	for(int j = head - 1; j >= 0; --j) {
		int v = ord[j];
		if(used[v] != mark) {
			paint(v);
			++last;
		}
	}

	for(int j = 0; j < head2;) {
		int l = j, r = j;
		while(r + 1 < head2 && scc[ord2[r + 1]] == scc[ord2[l]]) {
			++r;
		}

		int w = scc[ord2[l]];
		for(int i = l; i <= r; ++i) {
			if(good[ord2[i]]) {
				int c = ++fnd[ord2[i] / d];
				cnt[w] += c == 1;
			}
		}

		for(int i = l; i <= r; ++i) {
			fnd[ord2[i] / d] = 0;
		}

		j = r + 1;
	}

#ifdef __LOCAL
	for(int i = 0; i < last; ++i) {
		cout << "@" << i << ": " << cnt[i] << '\n';
	}
#endif

	for(int id = 0; id < E; ++id) {
		swap(edges[id].from, edges[id].to);
		edges[id].from = scc[edges[id].from];
		edges[id].to   = scc[edges[id].to];

	}

	initG(); ++mark;
	for(int v = 0; v < last; ++v) {
		if(used[v] != mark) {
			dfs(v);
		}
	}

	DBG(scc[0]);
	int answ = dp[scc[0 * d + 0]];
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}