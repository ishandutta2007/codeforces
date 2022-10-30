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

const int MAXN = 3007;
vector<int> g[MAXN];
int subtree[MAXN], tin[MAXN], tout[MAXN], timer = 13;
int pa[MAXN], depth[MAXN];
int n;

void dfs(int v, int p) {
	tin[v] = timer++;
	subtree[v] = 1;
	pa[v] = p;
	depth[v] = (p == NIL ? 0 : depth[p] + 1);
	for(auto& u: g[v]) {
		if(u != p) {
			dfs(u, v);
			subtree[v] += subtree[u];
		}
	}

	tout[v] = timer++;
}

int isparent(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

ll calc(int v, int u) {
	if(isparent(v, u)) {
		for(auto& w: g[v]) {
			if(isparent(w, u) && w != pa[v]) {
				return subtree[u] * 1LL * (n - subtree[w]);
			}
		}

		assert(false);
	} else if(isparent(u, v)) {
		for(auto& w: g[u]) {
			if(isparent(w, v) && w != pa[u]) {
				return subtree[v] * 1LL * (n - subtree[w]);
			}
		}

		assert(false);
	}

	return subtree[v] * 1LL * subtree[u];
}

namespace LCA {
	bitset<MAXN> used[MAXN];
	int dp[MAXN][MAXN];

	int get(int v, int u) {
		if(used[v][u]) return dp[v][u];
		used[v][u] = 1;
		if(v == u) {
			dp[v][u] = v;
		} else {
			if(depth[v] == depth[u]) {
				dp[v][u] = get(pa[v], pa[u]);
			} else if(depth[v] < depth[u]) {
				dp[v][u] = get(v, pa[u]);
			} else {
				dp[v][u] = get(pa[v], u);
			}
		}

		return dp[v][u];
	}

	int dist(int v, int u) {
		int w = get(v, u);
		return depth[v] + depth[u] - 2 * depth[w];
	}
};

bitset<MAXN> used[MAXN];
ll dp[MAXN][MAXN];
ll zfs(int l, int r) {
	if(used[l][r]) return dp[l][r];
	used[l][r] = 1;
	if(l == r) {
		dp[l][r] = 0;
	} else {
		dp[l][r] = 0;
		int M = calc(l, r);
		for(auto& l2: g[l]) {
			if(LCA::dist(l2, r) < LCA::dist(l, r)) {
				dp[l][r] = max(dp[l][r], M + zfs(l2, r));
			}
		}
		for(auto& r2: g[r]) {
			if(LCA::dist(l, r2) < LCA::dist(l, r)) {
				dp[l][r] = max(dp[l][r], M + zfs(l, r2));
			}
		}
	}

	return dp[l][r];
}

void solve() {
	cin >> n;	
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, NIL);
	ll answ = 0;
	for(int v = 0; v < n; ++v) {
		for(int u = 0; u < n; ++u) {
			answ = max(answ, zfs(v, u));
		}
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}