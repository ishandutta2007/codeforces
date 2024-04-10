#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num(ll x) {
	int ans = 0;
	for (; x; x >>= 1)ans += x & 1;
	return ans;
}
const int mn = 3e5 + 10;
int k[mn],dp[mn][2];
int main() {
	int n,i,j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		k[i] = num(x);
	}
	ll ans = 0;
	for (i = 1; i <= n; i++) {
		dp[i][k[i] & 1] = dp[i - 1][0]+1;
		dp[i][k[i] & 1 ^ 1] = dp[i - 1][1];
		int sum=k[i], big=k[i];
		for (j = 1; j <= 60 && i - j > 0; j++) {
			sum += k[i - j];
			big = max(big, k[i - j]);
			if (big * 2 <= sum&&!(sum&1))ans++;
		}
		ans += dp[i - j][sum & 1];
	}
	printf("%lld", ans);
}