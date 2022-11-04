#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int u, v, i = 0; i < n - 1; ++i) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool pos = true;
	vector<int> after(n, -1), par(n, -1);
	vector<pair<int, int>> res;
	function<void(int)> push = [&] (int u) {
		assert(~par[u]);
		res.push_back({u, par[u]});
		if (~after[u]) push(after[u]);
	};
	function<int(int, int)> solve = [&] (int u, int p) {
		par[u] = p;
		vector<int> c[2];
		for (int v : g[u]) if (v != p) c[solve(v, u)].push_back(v);
		int s = g[u].size() & 1, d = (int)c[s].size() - (int)c[!s].size(), my = s ^ (d > 0);
		pos &= d <= (1 + (u != p)) && d >= 0 - (u != p);
		if (!pos) return 0;
		if (u != p) {
			c[my].push_back(u);
			reverse(c[0].begin(), c[0].end());
			reverse(c[1].begin(), c[1].end());
		}
		while (c[s].size()) {
			assert(c[s].size());
			if (c[s].back() == u) {
				if (c[!s].size()) {
					assert(c[!s].size() == 1);
					after[u] = c[!s].back();
				}
				break;
			}
			push(c[s].back());
			c[s].pop_back();
			s ^= 1;
		}
		return my;
	};
	solve(0, 0);
	if (!pos) { cout << "NO\n"; return; }
	cout << "YES\n";
	assert(res.size() == n - 1);
	for (auto [u, v] : res) cout << u + 1 << ' ' << v + 1 << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}