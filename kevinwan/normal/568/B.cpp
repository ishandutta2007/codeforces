#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[4001][4001],m[4001],ch[4001][4001],inf[4001],f[4001];

int main() {
	int n,i,j;
	m[0]=dp[0][0] = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j]*j + dp[i - 1][j - 1]) % mod;
			m[i] = (m[i] + dp[i][j]) % mod;
		}
	}
	for (i = 0; i <= n; i++)ch[i][0] = 1;
	for (i = 1; i <= n; i++)for (j = 1; j <= i; j++)ch[i][j] = (ch[i - 1][j - 1] + ch[i - 1][j])%mod;
	ll ans=0;
	for (i = 0; i < n; i++) {
		ans += m[i] * ch[n][n - i],ans%=mod;
	}
	printf("%lld", ans);
	getchar(); getchar();
}