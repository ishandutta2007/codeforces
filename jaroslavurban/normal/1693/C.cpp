#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<vector<int>> ig(n);
	vector<int> deg(n);
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v, --u, --v;
		ig[v].push_back(u);
		++deg[u];
	}
	set<pair<int, int>> price;
	price.insert({0, n - 1});
	vector<int> res(n, INT_MAX), vis(n), viseds(n);
	vector<set<int>> mynums(n);
	res[n - 1] = 0;
	while (price.size()) {
		auto [p, u] = *price.begin();
		price.erase(price.begin());
		if (p != res[u]) continue;
		vis[u] = true;
		for (int v : ig[u]) if (!vis[v]) {
			++viseds[v];
			if (res[v] > deg[v] - viseds[v] + 1 + res[u]) {
				res[v] = deg[v] - viseds[v] + 1 + res[u];
				price.insert({res[v], v});
			}
		}
	}
	cout << res[0] << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}