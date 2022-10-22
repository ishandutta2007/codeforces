#include <bits/stdc++.h>
using namespace std;
int dp[101][2001],back[101][2001];
struct item {
	int d,t,  p,ind;
};
bool comp(const item&a, const item&b) { return a.d < b.d; }
item a[101];
int main() {
	int n,i,j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d%d%d", &a[i].t,&a[i].d,&a[i].p),a[i].ind=i;
	sort(a+1, a + n+1,comp);
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= 2000; j++) {
			if(dp[i-1][j]>dp[i][j])dp[i][j] =dp[i-1][j],back[i][j]=0;
			if (j + a[i].t < a[i].d&&dp[i - 1][j] + a[i].p>dp[i][j + a[i].t])dp[i][j + a[i].t] = dp[i - 1][j] + a[i].p,back[i][j+a[i].t]=1;
		}
	}
	int ans = -0x3f3f3f3f,t;
	for (i = 0; i <= 2000; i++)if (dp[n][i] > ans)ans = dp[n][i], t = i;
	vector<int> nums;
	for (i = n; i; i--) {
		if (back[i][t])nums.push_back(i),t-=a[i].t;
	}
	printf("%d\n%d\n", ans, nums.size());
	for (i = nums.size()-1; i >= 0;i--)printf("%d ", a[nums[i]].ind);
	getchar(); getchar();
}