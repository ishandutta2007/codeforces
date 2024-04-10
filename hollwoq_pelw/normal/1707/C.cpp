#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 1e5 + 5;

int n, m, dp[N], fa[N], h[N], par[17][N];
vector<pair<int, int>> edges;
vector<int> adj[N];
char s[N];

inline int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void pre_dfs(int u, int p) {
	h[u] = h[par[0][u] = p] + 1;
	for (int i = 1; i < 17; i++)
		par[i][u] = par[i - 1][par[i - 1][u]];

	for (int v : adj[u]) if (v != p)
		pre_dfs(v, u);
}

inline int lift(int u, int d) {
	for (int i = 17; i --; )
		if (d >> i & 1)
			u = par[i][u];
	return u;
}

inline int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	v = lift(v, h[v] - h[u]);
	if (u == v)
		return u;
	for (int i = 17; i--; )
		if (par[i][u] ^ par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

void dfs_calc(int u, int p) {
	s[u] = dp[u] == 0 ? '1' : '0';
	for (int v : adj[u]) if (v != p) {
		dp[v] += dp[u];
		dfs_calc(v, u);
	}
}

void Hollwo_Pelw(){
	cin >> n >> m;
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		if (find(u) != find(v)) {
			fa[find(u)] = find(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		} else {
			edges.emplace_back(u, v);
		}
	}
	pre_dfs(1, 0);
	for (auto [u, v] : edges) {
		if (h[u] > h[v]) swap(u, v);
		if (u == lca(u, v)) {
			dp[lift(v, h[v] - h[u] - 1)] ++;
			dp[v] --;
		} else {
			dp[1] ++;
			dp[u] --;
			dp[v] --;
		}
	}
	dfs_calc(1, 0);

	for (int i = 1; i <= n; i++)
		cout << s[i];
}