#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}	
}

const int N = 205;

int n, k, a[N], dp[N][N], tmp[N], h[N];
vector<int> adj[N];

void solve(int u, int p) {
	dp[u][0] = a[u];
	h[u] = 1;

	for (int v : adj[u]) if (v != p) {
		solve(v, u);
		
		for (int i = h[v]; i; i--)
			dp[v][i] = dp[v][i - 1];
		dp[v][0] = 0;

		h[u] = max(h[u], ++ h[v]);

		for (int j = 0; j < h[v]; j++) {
			for (int i = 0; i < h[u]; i++) {
				if (i + j > k)
					tmp[min(i, j)] = max(tmp[min(i, j)], dp[u][i] + dp[v][j]);
			}
			tmp[j] = max(tmp[j], dp[v][j]);
		}
		for (int i = 0; i < h[u]; i++)
			dp[u][i] = max(dp[u][i], tmp[i]), tmp[i] = 0;
	}

}

void solve_case() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	solve(1, 0);

	cout << *max_element(dp[1], dp[1] + n);
}