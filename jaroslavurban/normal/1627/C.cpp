#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 100100;
vector<vector<pair<int, int>>> g;
vector<int> deg, res;

void dfs(int u, int p, int par) {
	for (auto [i, v] : g[u]) if (v != p) {
		res[i] = par;
		dfs(v, u, !par);
	}
}

void ProGamerMove() {
	int n;
	cin >> n;
	res.resize(n - 1);
	deg.assign(n, 0);
	g.assign(n, {});
	bool pos = true;
	for (int u, v, i = 0; i < n - 1; ++i) {
		cin >> u >> v, --u, --v;
		g[u].push_back({i, v});
		g[v].push_back({i, u});
		++deg[u], ++deg[v];
		if (deg[u] > 2 || deg[v] > 2) pos = false;
	}
	if (!pos) {
		cout << "-1\n";
		return;
	}
	for (int i = 0; i < n; ++i) if (deg[i] == 1) {
		dfs(i, i, 0);
		break;
	}
	for (int r : res) cout << (r ? 2 : 3) << " ";
	cout << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}