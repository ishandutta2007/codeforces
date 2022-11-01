#include <bits/stdc++.h>
using namespace std;

int dp[1000005];
int n, x[1000005];
bool exist[1000005];

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", x+i), exist[x[i]] = true;
	for (int i = 0;i < n;i++)
		dp[x[i]] = 1;
	for (int i = 0;i < n;i++) for (int j = x[i]*2;j <= 1000000;j+=x[i]) if (exist[j])
		dp[j] = max(dp[j], dp[x[i]]+1);
	int ans = 0;
	for (int i = 0;i <= 1000000;i++) if (dp[i] > ans)
		ans = dp[i];
	printf("%d\n", ans);
	return 0;
}