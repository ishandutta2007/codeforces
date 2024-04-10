#include <algorithm>
#include <cstdio>
using namespace std;

//const int N = 510;

int n; //dp[N][N]

int main() {
	scanf("%d", &n);
//	for(int i = 1; i <= n; i ++) dp[i][i] = dp[i][i + 1] = 0;
//	for(int i = n; i >= 1; i --) {
//		for(int j = i + 2; j <= n; j ++) {
//			dp[i][j] = 1e9;
//			for(int k = i + 1; k < j; k ++) {
//				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + i * j * k);
//			}
//		}
//	}
	int ans = 0;
	for(int i = 3; i <= n; i ++)
		ans += i * (i - 1);
	printf("%d\n", ans);
	return 0;
}