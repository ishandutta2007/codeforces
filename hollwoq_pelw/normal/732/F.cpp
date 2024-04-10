#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

#ifdef LOCAL // PROBLEM NAME ???
	freopen(".inp", "r", stdin);
	freopen(".out", "w", stdout);
#endif

	// int test;
	// for (cin >> test; test --; )
	{
		solve_case();
	}

}

const int N = 4e5 + 5;

struct edge_t {
	int u, v, id;
	inline void direct(int nu, int nv) {
		u = nu, v = nv;
	}
} edges[N];
vector<edge_t> adj[N];

int n, m, vis[N], tin[N], low[N], timer;

vector<int> comp[N];
int st[N], top, comp_cnt;

void tarjan(int u, int p) {
	tin[u] = low[u] = ++ timer;
	st[++ top] = u;

	for (auto e : adj[u]) if (e.v != p) {
		if (tin[e.v]) {
			low[u] = min(low[u], tin[e.v]);
		} else {
			tarjan(e.v, u);
			low[u] = min(low[u], low[e.v]);
		}
	}

	if (tin[u] <= low[u]) { // no back edge

		++ comp_cnt;
		while (top) {
			int v = st[top --];
			comp[comp_cnt].push_back(v);
			if (v == u) break ;
		};

	}
}

void dfs_dir(int u, int p) {
	vis[u] = 1;
	for (auto e : adj[u]) if (e.v != p) {
		if (vis[e.v]) {
			edges[e.id].direct(e.u, e.v);
		} else {
			edges[e.id].direct(e.v, e.u);
			dfs_dir(e.v, u);
		}
	}
}

void solve_case() {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		edges[i] = {u, v, 0};
		adj[u].push_back({u, v, i});
		adj[v].push_back({v, u, i});
	}

	tarjan(1, 0);

	int root = 0, best = 0;

	for (int i = 1; i <= comp_cnt; i++) {
		if (best < comp[i].size()) {
			root = comp[i][0];
			best = comp[i].size();
		}

	}

	dfs_dir(root, 0);

	cout << best << '\n';
	for (int i = 1; i <= m; i++) {
		cout << edges[i].u << ' ' << edges[i].v << '\n';
	}
}