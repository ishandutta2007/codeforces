#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 105;

int n, T, a[N], b[N], cnt[N], dp[N][N][N], ma[N][N];

int main() {
	scanf("%d%d", &n, &T);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i); b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i ++) {
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b; cnt[a[i]] ++;
	}
	for(int i = 1; i <= n; i ++) {
		ma[i][i] = cnt[i];
		for(int j = i + 1; j <= n; j ++) {
			ma[i][j] = max(ma[i][j - 1], cnt[j]);
		}
	}
	memset(dp, -1, sizeof dp);
	int ans = 0; dp[0][0][0] = 0; a[0] = 1;
	for(int i = 0; i <= n && i <= T; i ++) {
		for(int j = 0; j <= n; j ++) { //pos
			for(int k = 0; k <= n; k ++) if(~ dp[i][j][k]) {
//				printf("dp{%d, %d, %d} = {%d}\n", i, j, k, dp[i][j][k]);
				ans = max(ans, (T - i) * k + dp[i][j][k]);
				if(i) {
					for(int l = j + 1; l <= n; l ++) if(a[j] <= a[l]) {
						int &f = dp[i][l][k];
						f = max(f, dp[i][j][k] + 1);
					}
				}
				for(int l = 1; l <= n; l ++) if(a[j] <= a[l]) {
					int &f = dp[i + 1][l][max(k, ma[a[j]][a[l]])];
					f = max(f, dp[i][j][k] + 1);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}