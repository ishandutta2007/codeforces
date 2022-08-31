#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int mod = 998244353;

#define maxN 223456

int n;
i64 dp[maxN][3];
vector<int> s[maxN];

void dfs(int u) {
	if (s[u].empty()) {
		dp[u][2] = 1;
		return;
	}
	dp[u][0] = 1;
	dp[u][1] = 0;
	dp[u][2] = 1;
	i64 tmp = 1;
	for (auto v : s[u]) {
		dfs(v);
		dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][2]) % mod;
		dp[u][1] = (tmp * (dp[v][1] + dp[v][2]) + dp[u][1] * (dp[v][0] + dp[v][2])) % mod;
		tmp = tmp * (dp[v][0] + dp[v][2]) % mod;
		dp[u][2] = dp[u][2] * (dp[v][0] + dp[v][1] + dp[v][2] * 2) % mod;
	}
	dp[u][2] = (dp[u][2] - tmp - dp[u][1]) % mod;
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		s[p].push_back(i);
	}
	dfs(1);
	i64 ans = (dp[1][0] + dp[1][2]) % mod;
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
}