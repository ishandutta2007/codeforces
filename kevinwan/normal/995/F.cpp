#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[3001][3001],mod=1000000007;
vector<int> g[3001];
ll inv(ll x) {
	ll ans = 1, b = mod - 2;
	for (; b; b >>= 1) {
		if (b & 1)ans *= x, ans %= mod;
		x *= x, x %= mod;
	}
	return ans;
}
void dfs(int x) {
	int i;
	for (i = 0; i <= n; i++)dp[x][i] = 1;
	for (int y : g[x]) { dfs(y); for (i = 0; i <= n; i++) dp[x][i] = dp[x][i] * dp[y][i] % mod; }
	for (i = 1; i <= n; i++)dp[x][i] += dp[x][i - 1], dp[x][i] %= mod;
}
int main() {
	int x,i,j;
	ll d;
	scanf("%d%lld", &n, &d);
	for (i = 2; i <= n; i++)scanf("%d", &x), g[x].push_back(i);
	dfs(1);
	d--;
	ll ans = 0, cur = 1, div = 1;
	for (i = 0; i <= n; i++) {
		cur = div = 1;
		for (j = 0; j <= n; j++) {
			if (i == j)continue;
			cur *= d - j, cur %= mod;
			div *= i - j, div %= mod;
		}
		cur *= dp[1][i], cur %= mod;
		cur *= inv(div), cur %= mod;
		ans += cur+mod, ans %= mod;
	}
	printf("%lld",ans );
	getchar(); getchar();
}