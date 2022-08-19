#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 2010

int n, mod;
vector<int> adj[maxN];
i64 dp[maxN][maxN], ps[maxN][maxN], other[maxN][maxN], comb[maxN][maxN];
i64 pm[maxN], sm[maxN];

void dfs(int u, int f) {
	vector<int> son;
	for (auto v : adj[u]) if (v != f) {
		dfs(v, u);
		son.push_back(v);
	}
	for (auto v : son) {
		for (int i = 1; i <= n; i++) {
			ps[v][i] = (dp[v][i] + ps[v][i - 1]) % mod;
		}
	}
	for (int i = 1; i <= n; i++) {
		i64 w = 1;
		for (auto v : son) w = w * ps[v][i] % mod;
		dp[u][i] = (dp[u][i] + w) % mod;
	}
	int m = son.size();
	if (m && u != 1) {
		for (int j = 1; j <= n; j++) {
			pm[0] = 1;
			for (int k = 1; k <= m; k++) {
				int v = son[k - 1];
				pm[k] = pm[k - 1] * ps[v][j] % mod;
			}
			sm[m + 1] = 1;
			for (int k = m; k >= 1; k--) {
				int v = son[k - 1];
				sm[k] = sm[k + 1] * ps[v][j] % mod;
			}
			for (int k = 1; k <= m; k++) {
				int v = son[k - 1];
				other[v][j] = pm[k - 1] * sm[k + 1] % mod;
			}
		}
		for (auto v : son) {
			for (int k = 1; k <= n; k++) {
				other[v][k] = (other[v][k] + other[v][k - 1]) % mod;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (auto v : son)
				dp[u][i] = (dp[u][i] + dp[v][i] * other[v][i - 1]) % mod;
		}
	}
}

int main() {
	scanf("%d%d", &n, &mod);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d",&u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < i; j++) {
			dp[1][i] = (dp[1][i] - dp[1][j] * comb[i][j]) % mod;
		}
		if (dp[1][i] < 0) dp[1][i] += mod;
		printf("%lld\n", dp[1][i]);
	}

}