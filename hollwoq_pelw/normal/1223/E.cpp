#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

const int N = 5e5 + 5;

#define int long long

int n, k, dp[N][2];
vector<pair<int, int>> adj[N];

void solve(int u, int p) {
	dp[u][0] = dp[u][1] = 0;

	vector<int> add;

	for (auto e : adj[u]) {
		int v = e.first, w = e.second;
		if (v == p) continue ;
		
		solve(v, u);

		dp[u][0] += dp[v][0];
		dp[u][1] += dp[v][0];

		add.push_back(dp[v][1] + w - dp[v][0]);
	}

	sort(add.rbegin(), add.rend());
	for (int i = 0; i < add.size() && add[i] > 0; i++) {
		if (i < k - 0)
			dp[u][0] += add[i];
		if (i < k - 1)
			dp[u][1] += add[i];
	}
}

void solve_case() {
	// system("tint -l 1");
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		adj[i].clear();
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	solve(1, 0);

	cout << dp[1][0] << '\n';
}