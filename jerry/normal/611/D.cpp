#include <bits/stdc++.h>
using namespace std;

#define MOD  1000000007

bool yes[5005][5005];
int dp[5005][5005];
int cu[5005][5005];
char buf[5005];
int n;

int main()
{
	scanf("%d%s", &n, buf);
	for (int i = 1;i < n;i++)
	{
		int sf = 0, j = 0;
		for (;j+i+i <= n;j++)
		{
			if (j-sf == i) sf++;
			if (buf[j] != buf[i+j])
			{
				if (buf[j] < buf[i+j]) for (;sf <= j;sf++)
					yes[sf][i+sf] = true;
				sf = j+1;
			}
		}
		for (;j+i < n;j++) if (buf[j] != buf[i+j])
		{
			if (buf[j] < buf[i+j]) for (;sf+i+i <= n;sf++) yes[sf][i+sf] = true;
			break;
		}
	}
	for (int i = n-1;i >= 0;i--) if (buf[i] != '0')
	{
		cu[i][n] = dp[i][n] = 1;
		for (int j = n-1;j > i;j--) cu[i][j] = (dp[i][j]+cu[i][j+1])%MOD;
		for (int j = max(0, i+i-n);j < i;j++)
		{
			int d = i-j;
			dp[j][i] = cu[i][i+d+1];
			if (yes[j][i]) dp[j][i] = cu[i][i+d];
		}
	}
	int ans = 0;
	for (int i = 0;i <= n;i++) ans = (ans + dp[0][i]) % MOD;
	printf("%d\n", ans);
	return 0;
}