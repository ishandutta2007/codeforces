#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 510;

int n, dp[N][N], f[N][N];
char s[N];

int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; i ++) dp[i][i] = 1;
	for(int i = n - 1; i >= 1; i --) {
		for(int j = i + 1; j <= n; j ++) {
			dp[i][j] = dp[i + 1][j] + 1;
			for(int k = i + 1; k <= j; k ++) if(s[i] == s[k]) {
				dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
			}
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}