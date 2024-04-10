#include <bits/stdc++.h>

using namespace std;

namespace program
{
	typedef long long big;
	
	const int MAXN = 100000, MAXA = 100000, MAXM = 100, INF = 0x3f3f3f3f;
	int a, b, h, w, n, m;
	int A[MAXN + 10], Dp[MAXM + 10][MAXN + 10];
	big Sum[MAXM + 10];
	
	int dp(int i, int j)
	{
		big x = (big)j * h;
		big y = Sum[i - 1] / j * w;
		if(x >= a && y >= b)
			return 0;
		else
		{
			int &ans = Dp[i][j];
			if(~ans)
				return ans;
			if(i > MAXM || i > n)
				return ans = INF;
			else if(x >= a)
				return ans = dp(i + 1, j) + 1;
			else if(y >= b)
				return ans = dp(i + 1, j * A[i]) + 1;
			else
				return ans = min(dp(i + 1, j), dp(i + 1, j * A[i])) + 1;
		}
	}
	
	void work()
	{
		int ans;
		scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		sort(A + 1, A + n + 1, greater<int>());
		Sum[0] = 1; 
		for(int i = 1; i <= MAXM && i <= n; i++)
			Sum[i] = Sum[i - 1] * A[i];
		memset(Dp, -1, sizeof(Dp));
		ans = dp(1, 1);
		swap(a, b);
		memset(Dp, -1, sizeof(Dp));
		ans = min(ans, dp(1, 1));
		printf("%d\n", ans >= INF ? -1 : ans);
	}
}

int main()
{
	program::work(); 
	return 0;
}