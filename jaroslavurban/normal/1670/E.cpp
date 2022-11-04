#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;


void ProGamerMove() {
	int p, n; cin >> p; n = 1 << p;
	vector<vector<pair<int, int>>> g(n);
	for (int u, v, i = 0; i < n - 1; ++i) {
		cin >> u >> v, --u, --v;
		g[u].push_back({i, v});
		g[v].push_back({i, u});
	}
	vector<int> res(n), res2(n - 1);
	int x = 0;
	function<void(int, int, int)> dfs = [&] (int u, int par, int d) {
		res[u] = x | d << p;
		for (auto [i, v] : g[u]) if (v != par) {
			res2[i] = ++x | d << p;
			dfs(v, u, d ^ 1);
		}
	};
	dfs(0, 0, 1);
	cout << "1\n";
	for (auto v : res) cout << v << ' '; cout << '\n';
	for (auto v : res2) cout << v << ' '; cout << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}