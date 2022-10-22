#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

const int N = 5e5 + 5;

int n, m, q, h[N], ok[N];
vector<pair<int, int>> adj[N];

int par[19][N];
int bnd[19][N];

void pre_dfs(int u, int p) {
	h[u] = h[par[0][u] = p] + 1;
	for (int i = 1; i < 19; i++)
		par[i][u] = par[i - 1][par[i - 1][u]];

	for (auto [v, w] : adj[u]) if (v != p) {
		if (!w) ok[v] = 1; pre_dfs(v, u);
	}
}

inline int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);

	for (int i = 19; i --; )
		if (h[v] - h[u] >> i & 1)
			v = par[i][v];

	if (u == v) return u;

	for (int i = 19; i --; )
		if (par[i][u] ^ par[i][v])
			u = par[i][u], v = par[i][v];

	return par[0][u];
}

inline void update(int u, int d, int w) {
	for (int i = 19; i --; )
		if (d >> i & 1) {
			bnd[i][u] = min(bnd[i][u], w);
			u = par[i][u];
		}
}

int dsu[N];

inline int find(int u) {
	return dsu[u] == u ? u : dsu[u] = find(dsu[u]);
}

inline bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	return dsu[u] = v, 1;
}

void solve_case() {
	cin >> n >> m >> q;

	vector<tuple<int, int, int>> edges, query;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		edges.emplace_back(0, u, v);
	}
	
	memset(bnd, 0x3f, sizeof bnd);

	for (int u, v, w; q --; ) {
		cin >> u >> v >> w;
		edges.emplace_back(w, u, v);
	}

	sort(edges.begin(), edges.end());

	iota(dsu + 1, dsu + n + 1, 1);
	for (auto [w, u, v] : edges) {
		if (merge(u, v)) {
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
		} else {
			query.emplace_back(w, u, v);
		}
	}
	
	pre_dfs(1, 0);

	for (auto [w, u, v] : query) {
		int l = lca(u, v);
		update(u, h[u] - h[l], w);
		update(v, h[v] - h[l], w);
	}
	
	long long res = 0;

	for (int i = 19; i --; ) {
		for (int j = 1; j <= n; j++) {
			if (i == 0 && ok[j]) {
				if (bnd[0][j] > 1e9 + 99)
					return cout << "-1\n", (void) 0;
				res += bnd[0][j];
			}
			if (i > 0) {
				bnd[i - 1][j] = min(bnd[i - 1][j], bnd[i][j]);
				bnd[i - 1][par[i - 1][j]] = min(bnd[i - 1][par[i - 1][j]], bnd[i][j]);
			}
		}
	}

	cout << res;
}