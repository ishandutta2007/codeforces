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

const int N = 2e5 + 5;

int n, m, q, tin[N], low[N], timer;

int st[N], top, comp_cnt, comp[N];
vector<int> nadj[N];
vector<pair<int, int>> adj[N];

void tarjan(int u, int pid) {
	tin[u] = low[u] = ++ timer;
	st[++ top] = u;

	for (auto e : adj[u]) {
		int v = e.first, id = e.second;
		if (id == pid) continue ;

		if (tin[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			tarjan(v, id);
			low[u] = min(low[u], low[v]);
		}

	}

	if (tin[u] <= low[u]) {
		++ comp_cnt;
		while (top) {
			int v = st[top --];
			comp[v] = comp_cnt;
			if (v == u) break ;
		}
	}
}

bool vis[N];
set<int> sg[N];

bool dfs(int u, int p) {
	vis[u] = 1;
	for (int v : nadj[u]) if (v != p) {
		if (!dfs(v, u))
			return 0;
		
		if (sg[u].size() < sg[v].size())
			swap(sg[u], sg[v]);

		for (int x : sg[v]) {
			if (sg[u].count(-x)) {
				sg[u].erase(-x);
			}
			else {
				sg[u].insert(x);
			}
		}

	}

	return sg[u].empty() ? 1 : *sg[u].begin() > 0 || *sg[u].rbegin() < 0;
}

void solve_case() {
	cin >> n >> m >> q;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	for (int i = 1; i <= n; i++)
		if (!tin[i]) tarjan(i, 0);

	for (int i = 1; i <= n; i++)
		for (auto e : adj[i]) {
			int j = e.first;
			if (comp[i] != comp[j])
				nadj[comp[i]].push_back(comp[j]);
		}

	for (int i = 1, s, t; i <= q; i++) {
		cin >> s >> t;
		if (comp[s] != comp[t]) {
			sg[comp[s]].insert( i);
			sg[comp[t]].insert(-i);
		}
	}

	for (int i = 1; i <= comp_cnt; i++) 
		if (!vis[i]) {
			if (!dfs(i, 0) || sg[i].size())
				return cout << "No", (void) 0;
		}

	cout << "Yes";
}