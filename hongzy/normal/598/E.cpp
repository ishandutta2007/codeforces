#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 52;
const int INF = 1e9 + 10;

int dp[N][N][N], n, m, k;
//dp[i][j][k] -> i jk
 
int main() {
	for(n = 1; n <= 30; n ++)
		for(m = 1; m <= 30; m ++) {
			if(n == 1 && m == 1) dp[n][m][1] = 0;
			else if(n == 1 || m == 1) dp[n][m][1] = 1;
			else dp[n][m][1] = min(n, m) * min(n, m) + 1;
		}
	for(k = 2; k <= 50; k ++) {			
		for(n = 1; n <= 30; n ++) {
			for(m = 1; m <= 30; m ++)  {
				int &f = dp[n][m][k]; f = INF;
				if(k == n * m) {
					f = 0;	
				} else if(k < n * m) {
					for(int i = 1; i < n; i ++) {
						for(int j = 0; j <= k; j ++) {
							f = min(f, dp[i][m][j] + dp[n - i][m][k - j] + m * m);
						}
					}
					for(int i = 1; i < m; i ++) {
						for(int j = 0; j <= k; j ++) {
							f = min(f, dp[n][i][j] + dp[n][m - i][k - j] + n * n);
						}
					}
				}
			}
		}
	}
	for(scanf("%*d"); ~ scanf("%d%d%d", &n, &m, &k); printf("%d\n", dp[n][m][k])) ;
	return 0;
}