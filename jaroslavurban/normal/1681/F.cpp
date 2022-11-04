#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;


void ProGamerMove() {
	int n; cin >> n;
	vector<int> cnt(n), upper(n - 1), lower(n - 1), sz(n), sz0(n, n), color(n - 1);
	vector<vector<tuple<int, int, int>>> g(n);
	for (int u, v, w, i = 0; i < n - 1; ++i) {
		cin >> u >> v >> w, --u, --v, --w;
		g[u].push_back({i, w, v});
		g[v].push_back({i, w, u});
		color[i] = w;
	}
	function<void(int, int)> dfs = [&] (int u, int p) {
		cnt[u] = 1;
		for (auto [id, c, v] : g[u]) if (v != p) {
			dfs(v, u);
			cnt[u] += cnt[v];
		}
	};
	dfs(0, 0);
	sz = cnt;
	vector<int> last(n);
	function<void(int, int, int, int)> dfs2 = [&] (int u, int p, int c, int id) {
		int lstc = last[c];
		upper[id] = last[c];
		lower[id] = u;
		if (last[c]) sz[last[c]] -= cnt[u];
		else sz0[c] -= cnt[u];
		last[c] = u;
		for (auto [nid, nc, v] : g[u]) if (v != p) {
			dfs2(v, u, nc, nid);
		}
		last[c] = lstc;
	};
	for (auto [id, c, v] : g[0]) dfs2(v, 0, c, id);
	ll res = 0;
	for (int i = 0; i < n - 1; ++i) {
		res += (upper[i] ? sz[upper[i]] : sz0[color[i]]) * ll(sz[lower[i]]);
	}
	cout << res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}