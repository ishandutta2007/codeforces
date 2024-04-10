#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[19][4],p[19];
ll f(ll x) {
	int i,rem=3;
	ll ans=0;
	for (i = 18; i >= 0; x%=p[i], i--) {
		if (x < p[i])continue;
		if (rem < 0)break;
		ll num = x / p[i] - 1;
		ans += dp[i][rem];
		if (rem != 0)ans += dp[i][rem - 1] * num;
		rem--;
	}
	return ans+(rem>=0);
}
int main() {
	int i, j;
	dp[0][0] = 1;
	for (i = 1; i <= 18; i++) {
		dp[i][0] = 1;
		for (j = 1; j <= 3; j++)dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * 9;
	}
	for (i = 0; i <= 18; i++)for (j = 1; j <= 3; j++)dp[i][j] += dp[i][j - 1];
	p[0] = 1;
	for (i = 1; i <= 18; i++)p[i] = p[i - 1] * 10;
	int n;
	scanf("%d", &n);
	while (n--) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", f(r) - f(l - 1));
	}
	getchar(); getchar();
}