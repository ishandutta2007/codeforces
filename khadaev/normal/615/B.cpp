#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<set<int> > edges(n);
	vector<int> deg(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		deg[u]++;
		deg[v]++;
		if (u > v)swap(u, v);
		edges[v].insert(u);
	}
	vector<int> dp(n);
	for (int i = 0; i < n; ++i) {
		int t = 0;
		for (int v : edges[i])
			t = max(t, dp[v]);
		dp[i] = t + 1;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, 1ll * dp[i] * deg[i]);
	cout << ans << '\n';
}