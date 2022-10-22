#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> g[300001];
ll dp[300001][3],mod= 998244353;
ll inv(ll x) {
	ll ans = 1;
	for (ll i = mod-2; i; i >>= 1, x = x * x%mod)if (i & 1)ans = ans * x%mod;
	return ans;
}
void dfs(int x, int p) {
	ll pr = 1,pr0=1,pr1=1;
	for (int y : g[x]) {
		if (y == p)continue;
		dfs(y, x);
		pr = pr * (2 * dp[y][0] + dp[y][2]) % mod;
		pr0 = pr0 * (dp[y][0]+dp[y][2]) % mod;
	}
	dp[x][2] = pr0;
	dp[x][1] = pr;
	for (int y : g[x]) {
		if (y == p)continue;
		dp[x][0] += dp[y][1] * pr%mod*inv(dp[y][0] * 2 + dp[y][2])%mod;
		dp[x][0] %= mod;
	}
}
int main() {
	scanf("%d", &n);
	int a, b,i;
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b), g[a].push_back(b), g[b].push_back(a);
	dfs(1,0);
	printf("%lld",( dp[1][0] + dp[1][2])%mod);
}