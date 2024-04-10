#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 60;
int n;
char str[maxn];
ll ans, dp[maxn][10];

int main() {
	gets(str + 1);
	n = strlen(str + 1);
	if (n == 1) {
		return puts("9"), 0;
	}
	fill(dp[1], dp[1] + 10, 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			int t = (j << 1) - (str[i] ^ 48);
			for (int k = -1; k < 2; k++) {
				if (t + k >= 0 && t + k < 10) {
					dp[i][j] += dp[i - 1][t + k];
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}
	for (int i = 2; i <= n; i++) {
		if (abs(str[i] - str[i - 1]) > 1) {
			break;
		}
		if (i == n) {
			ans--;
		}
	}
	printf("%lld", ans);
	return 0;
}