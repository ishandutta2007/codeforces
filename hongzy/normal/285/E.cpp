#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1010;
const int mo = 1e9 + 7;
int n, k, dp[N][N][4], ans[N], fac[N], fav[N];
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}
int C(int x, int y) {
	return x < y ? 0 : 1ll * fac[x] * fav[y] % mo * fav[x - y] % mo;
}
int main() {
	scanf("%d%d", &n, &k);
	if(n == k) {
		printf("%d\n", n & 1 ^ 1);
		return 0;
	}
	fac[0] = 1;
	for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mo;
	fav[n] = qpow(fac[n], mo - 2);
	for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mo;
	dp[0][0][1] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < i; j ++) {
			for(int S = 0; S < 4; S ++) if(dp[i - 1][j][S]) {
				(dp[i][j][S >> 1] += dp[i - 1][j][S]) %= mo;
				if(i != n) (dp[i][j + 1][(S >> 1) | 2] += dp[i - 1][j][S]) %= mo;
				if(S & 1 ^ 1) (dp[i][j + 1][S >> 1] += dp[i - 1][j][S]) %= mo;
			}
		}
	}
	for(int i = n; i >= k; i --) {
		ans[i] = (dp[n][i][0] + dp[n][i][1]) % mo * 1ll * fac[n - i] % mo;
		for(int j = i + 1; j <= n; j ++) {
			ans[i] = (ans[i] - 1ll * ans[j] * C(j, i) % mo + mo) % mo;
		}
	}
	printf("%d\n", ans[k]);
	return 0;
}