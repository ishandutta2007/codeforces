#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void calc(vector<vector<int>> g) {
	int n = g.size();
	vector<int> in(n);
	for (int u = 0; u < n; ++u)
		for (int v : g[u])
			++in[v];
	queue<int> q;
	vector<int> res;
	for (int u = 0; u < n; ++u) if (!in[u]) q.push(u);
	while (q.size()) {
		int u = q.front(); q.pop();
		res.push_back(u);
		for (auto v : g[u]) if (!--in[v]) q.push(v);
	}
	reverse(res.begin(), res.end());
	for (int u : res) cout << u + 1 << ' '; cout << '\n';
}

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<int> p(n), o(n), vis(n);
	for (int& v : p) cin >> v, --v;
	vector<vector<pair<int, int>>> g(n);
	vector<vector<int>> ng(m);
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v, --u, --v;
		g[u].push_back({i, v});
		g[v].push_back({i, u});
	}
	for (int i = 0; i < n; ++i) if (!vis[i]) {
		int u = i, cnt = 0;
		do {
			o[u] = cnt++;
			vis[u] = true;
			u = p[u];
		} while (u != i);
	}
	for (int u = 0; u < n; ++u) {
		sort(g[u].begin(), g[u].end(), [&] (pair<int, int> a, pair<int, int> b) {
			return make_pair(o[a.second] > o[u], -o[a.second]) < make_pair(o[b.second] > o[u], -o[b.second]);
		});
		for (int i = 1; i < g[u].size(); ++i) ng[g[u][i - 1].first].push_back(g[u][i].first);
	}
	calc(ng);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}