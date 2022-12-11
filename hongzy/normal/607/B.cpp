#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 520;

int n, dp[N][N], c[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", c + i); dp[i][i] = 1;
	}
	for(int i = n; i >= 1; i --) {
		for(int j = i + 1; j <= n; j ++) {
			dp[i][j] = 2e9;
			if(c[i] == c[j]) {
				dp[i][j] = min(dp[i][j], i + 1 == j ? 1 : dp[i + 1][j - 1]);
			}
			for(int k = i; k < j; k ++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}