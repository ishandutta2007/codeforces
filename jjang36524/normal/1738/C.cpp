#include <bits/stdc++.h>
using namespace std;
#define int long long
int vis[100100];
int dp[101][101][2][2];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	dp[0][0][0][0] = 1;
	dp[0][0][1][1] = 1;
	int i;
	for (i = 0; i <= 100; i++)
	{
		int j;
		for (j = 0; j <= 100; j++)
		{
			if (i)
			{
				dp[i][j][0][0] |= !dp[i-1][j][0][1];
				dp[i][j][0][1] |= !dp[i - 1][j][0][0];
				dp[i][j][1][0] |= !dp[i - 1][j][1][1];
				dp[i][j][1][1] |= !dp[i - 1][j][1][0];
			}
			if (j)
			{
				dp[i][j][0][0] |= !dp[i][j-1][1][1];
				dp[i][j][0][1] |= !dp[i][j-1][0][0];
				dp[i][j][1][0] |= !dp[i][j-1][0][1];
				dp[i][j][1][1] |= !dp[i][j-1][1][0];
			}
		}
	}
	while (T--)
	{
		int N;
		cin >> N;
		int a = 0;
		int b = 0;
		int i;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			if ((x + (1LL << 30)) % 2)
				b++;
			else
				a++;
		}
		if (dp[a][b][0][0])
			cout << "Alice" << '\n';
		else
			cout << "Bob" << '\n';
	}
}