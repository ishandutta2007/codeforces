#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 705;
const int mod = 1e9 + 7;
int dg, n, pw[N], dp[N][2][N];
char s[N];
int work() {
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= n; j ++)
			dp[i][0][j] = dp[i][1][j] = 0;
	dp[0][1][0] = 1;
	for(int i = 0; i < n; i ++) {
		for(int lim = 0; lim < 2; lim ++) {
			for(int k = 0; k <= i; k ++) if(dp[i][lim][k]) {
				int r = lim ? s[i + 1] - '0' : 9;
				for(int j = 0; j <= r; j ++) {
					(dp[i + 1][lim && (j == r)][k + (j >= dg)] += dp[i][lim][k]) %= mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		(ans += 1ll * pw[i - 1] * (dp[n][0][i] + dp[n][1][i]) % mod) %= mod;
	}
	return ans;
}
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	pw[0] = 1; int cur = 1;
	for(int i = 1; i <= n; i ++) {
		cur = cur * 10ll % mod;
		pw[i] = (pw[i - 1] + cur) % mod;
	}
	int ans = 0;
	for(dg = 1; dg <= 9; dg ++) {
		(ans += work()) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}