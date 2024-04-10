#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[2][101][10001],ch[101][101];
int a[101],nums[101];
int main() {
	int n,i,j,k;
	for(i=0;i<=100;i++)ch[i][0] = 1;
	for (i = 1; i <= 100; i++)for (j = 1; j <= i; j++)ch[i][j] = ch[i - 1][j - 1] + ch[i - 1][j];
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", a + i);
		nums[a[i]]++;
	}
	dp[0][0][0] = 1;
	for (i = 1; i <= n; i++) {
		memcpy(dp[i & 1], dp[i & 1 ^ 1], sizeof(dp[i & 1]));
		for (j = a[i]; j <= 10000; j++) {
			for (k = 1; k <= i; k++) {
				dp[i & 1][k][j] += dp[i & 1 ^ 1][k - 1][j - a[i]];
			}
		}
	}
	int ans = 0,types=0;
	bool comp = 0;
	for (i = 1; i <= 100; i++) {
		if (nums[i])types++;
		for (j = 1; j <= nums[i]; j++) {
			int tar = i * j;
			int num = 0;
			if (dp[n&1][j][tar] == ch[nums[i]][j])ans = max(ans, j),comp=(j==nums[i]);
		}
	}
	if (comp&&types == 2)ans = n;
	printf("%d", ans);
}