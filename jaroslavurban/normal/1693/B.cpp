#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<vector<int>> g(n);
	vector<int> l(n), r(n);
	for (int u, v = 1; v < n; ++v) cin >> u, g[--u].push_back(v);
	for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
	int res = 0;
	function<int(int)> dfs = [&] (int u) {
		ll sm = 0;
		for (int v : g[u]) sm += dfs(v);
		if (sm < l[u]) { ++res; return r[u]; }
		return (int)min(sm, (ll)r[u]);
	};
	dfs(0);
	cout << res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}