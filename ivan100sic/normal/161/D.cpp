#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dp[50005][505];
ll sol = 0;
basic_string<int> e[50005];
int n, k;

void dfs(int x, int p) {
	dp[x][0]++;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
		for (int i=0; i<k; i++)
			dp[x][i+1] += dp[y][i];

		for (int j=0; j<k-j; j++) {
			if (j == 0 || k-j == 0)
				continue;
			sol -= dp[y][j-1] * 1ll * dp[y][k-j-1];
		}
	}
	// sol
	for (int j=0; j<k-j; j++)
		sol += dp[x][j] * 1ll * dp[x][k-j];

	// jos
	if (k % 2 == 0) {
		ll extra = dp[x][k >> 1] * 1ll * dp[x][k >> 1];
		for (int y : e[x]) {
			if (y == p)
				continue;
			extra -= dp[y][(k >> 1) - 1] * 1ll * dp[y][(k >> 1) - 1];
		}
		extra >>= 1;
		sol += extra;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);
	cout << sol << '\n';
}