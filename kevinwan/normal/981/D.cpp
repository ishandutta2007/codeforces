#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[51];
int n, k;
bitset<51> dp[51];
bool bet(ll x) {
	int i, j;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < i; j++) {
			if (((a[i] - a[j])&x) == x)dp[i] |= (dp[j] << 1);
		}
	}
	return dp[n][k];
}
int main() {
	ll i;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++) scanf("%lld", a + i), a[i] += a[i - 1];
	ll ans = 0;
	for (i = 60; i >= 0; i--) {
		if (bet(ans + (1LL << i)))ans += 1LL << i;
	}
	printf("%lld", ans);
	getchar(); getchar();
}