#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
int dp[100001][5];
int num[100001],ans[100001];
int main() {
	int n,i,j,k;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	int x;
	memset(dp[1], 0, sizeof(dp[1]));
	for (i = 1; i <= n; i++)scanf("%d", num + i);
	for (i = 2; i <= n; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				if (j == k)continue;
				if (dp[i-1][k] == -1)continue;
				if (j > k && num[i] >= num[i-1])dp[i][j] = k;
				if (j < k && num[i] <= num[i-1])dp[i][j] = k;
			}
		}
	}
	for (i = 0; i < 5; i++) {
		if (dp[n][i] == -1)continue;
		int cur = i;
		for (j = n; j; j--) {
			ans[j] = cur;
			cur = dp[j][cur];
		}
		for (j = 1; j <= n; j++)printf("%d ", ans[j] + 1);
		return 0;
	}
	printf("-1");
}