#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	const int offset = 3 * m;
	vector<int> c(m), t(m);
	vector<vector<int>> e(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v >> c[i] >> t[i];
		--u;
		--v;
		e[u].push_back(i);
		e[v].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		sort(e[i].begin(), e[i].end(), [&](int i, int j) {return c[i] < c[j];});
	for (int i = 0; i < n; ++i) {
		int col = -1, cnt = 0;
		for (int j : e[i]) {
			if (c[j] == col) {
				++cnt;
				if (cnt > 2) {
					cout << "No\n";
					return 0;
				}
			} else {
				col = c[j];
				cnt = 1;
			}
		}
	}
	vector<vector<int>> g(6 * m);
	vector<int> dfn(6 * m), low(6 * m), be(6 * m), stk;
	int dfs_now, cc;
	function<void(int)> tarjan = [&](int u) {
		dfn[u] = low[u] = dfs_now++;
		stk.push_back(u);
		for (int v : g[u]) {
			if (dfn[v] == -1) {
				tarjan(v);
				low[u] = min(low[u], low[v]);
			} else if (be[v] == -1) {
				low[u] = min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			int v;
			do {
				v = stk.back();
				stk.pop_back();
				be[v] = cc;
			} while (v != u);
			++cc;
		}
	};
	auto check = [&](int cost) {
		fill(dfn.begin(), dfn.end(), -1);
		fill(be.begin(), be.end(), -1);
		for (int i = 0; i < 6 * m; ++i)
			g[i].clear();
		int cnt = m;
		for (int i = 0; i < n; ++i) {
			int col = -1, id = -1;
			for (int j : e[i]) {
				if (t[j] > cost)
					g[j].push_back(j + offset);
				if (c[j] == col) {
					g[j + offset].push_back(id);
					g[id + offset].push_back(j);
				}
				int p = cnt++;
				if (id != -1) {
					g[p - 1].push_back(p);
					g[p + offset].push_back(p - 1 + offset);
					g[p - 1].push_back(j + offset);
					g[j].push_back(p - 1 + offset);
				}
				g[j].push_back(p);
				g[p + offset].push_back(j + offset);
				col = c[j];
				id = j;
			}
		}
		dfs_now = cc = 0;
		for (int i = 0; i < 6 * m; ++i)
			if (dfn[i] == -1)
				tarjan(i);
		for (int i = 0; i < 3 * m; ++i)
			if (be[i] == be[i + offset])
				return false;
		return true;
	};
	int l = 0, r = 1000000001;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	if (l == 1000000001) {
		cout << "No\n";
		return 0;
	}
	check(l);
	cout << "Yes\n";
	vector<int> sol;
	for (int i = 0; i < m; ++i)
		if (be[i] < be[i + offset])
			sol.push_back(i);
	cout << l << " " << sol.size() << "\n";
	for (int i : sol)
		cout << i + 1 << " \n"[i == sol.back()];
	return 0;
}