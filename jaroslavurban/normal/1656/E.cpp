#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 100100;
vector<int> g[N];
int res[N];

bool chck(int v) { return v && abs(v) <= int(1e5); }

bool solve(int u, int p, int t, int c) {
	int chld = g[u].size() - (u != p);
	if (!chld) return chck(res[u] = t);
	res[u] = t - c * chld;
	if (!chck(res[u])) return false;
	for (int v : g[u]) if (v != p)
		if (!solve(v, u, c, c * int(g[u].size() - 1) + res[u]))
			return false;
	return true;
}

void ProGamerMove() {
	int n; cin >> n;
	for (int u = 0; u < n; ++u) g[u].clear();
	pair<int, int> mx = {0, 0};
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
		mx = max(mx, {(int)g[u].size(), u});
		mx = max(mx, {(int)g[v].size(), v});
	}
	for (int i = -20; i <= 20; ++i)
		for (int j = -20; j <= 20; ++j)
			if (solve(mx.second, mx.second, i, j)) {
				for (int u = 0; u < n; ++u) cout << res[u] << " "; cout << "\n";
				return;
			}
	assert(0);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}