#include <bits/stdc++.h>
using namespace std;

int dp[4005], cac[4005];
int v[4005][4005];
int n, k;
char tmp;

void slv(int lo, int hi, int lft, int rgt)
{
	if (lo == hi) return;
	int mid = (lo+hi) / 2;
	int bst = -1;
	for (int i = max(mid+1, lft);i <= rgt;i++)
	{
		int alt = cac[i]+v[i-1][i-1]-v[mid-1][i-1]-v[i-1][mid-1]+v[mid-1][mid-1];
		if (alt < dp[mid])
		{
			dp[mid] = alt;
			bst = i;
		}
	}
	slv(lo, mid, lft, bst);
	slv(mid+1, hi, bst, rgt);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++)
	{
		scanf(" %c", &tmp);
		v[i][j] = tmp+v[i][j-1]+v[i-1][j]-v[i-1][j-1]-'0';
	}
	for (int i = 1;i <= n;i++) dp[i] = 1000000000;
	for (int i = 1;i <= k;i++)
	{
		swap(dp, cac);
		for (int j = 1;j <= n;j++) dp[j] = 1000000000;
		slv(1, n+1, 1, n+1);
	}
	printf("%d\n", dp[1]/2);
	return 0;
}