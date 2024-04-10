#include <bits/stdc++.h>
using namespace std;

int dp[100005], t[100005], n;

int main()
{
	t[0] = -10000;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d", t+i);
		dp[i] = dp[i-1] + 20;
		int p = upper_bound(t, t+i+1, t[i]-90)-t-1;
		dp[i] = min(dp[i], dp[p]+50);
		p = upper_bound(t, t+i+1, t[i]-1440)-t-1;
		dp[i] = min(dp[i], dp[p]+120);
		printf("%d\n", dp[i]-dp[i-1]);
	}
	return 0;
}