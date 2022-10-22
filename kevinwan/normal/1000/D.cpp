#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[1001][1001], dp[1001],a[1001];
ll mod = 998244353;
int main() {
	int i, j;
	for(i=0;i<=1000;i++)c[i][0] = 1;
	for (i = 1; i <= 1000; i++)for (j = 1; j <= i; j++)c[i][j] = (c[i-1][j - 1] + c[i-1][j]) % mod;
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%lld", a + i);
	dp[0] = 1;
	for (i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (j = 0; j < i ; j++) {
			if (a[j + 1] <= 0 || a[j + 1] >= i - j)continue;
			dp[i] += dp[j] * (c[i - j - 2][a[j + 1]-1]),dp[i]%=mod;
		}
	}
	ll ans = 0;
	printf("%lld", (dp[n]+mod-1)%mod );
	getchar(); getchar();
}