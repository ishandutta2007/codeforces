#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[5017][5017][2];
int N;
int arr[5010];
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i + 1];
	}
	int j;
	memset(dp, 100, sizeof(dp));
	dp[0][0][0] = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j <= (N + 1) / 2; j++)
		{
			dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
			if (j)
			{
				if (i == 1)
				{
					dp[i][j][1] = dp[i - 1][j - 1][0]+ max(0, arr[i + 1] - arr[i] + 1);
				}
				else
				{
					int righ = max(0, arr[i + 1] - arr[i] + 1);
					int lef = max(0, arr[i - 1] - arr[i] + 1);
					int newlef = max(0, min(arr[i - 2] - 1, arr[i - 1]) - arr[i] + 1);
					dp[i][j][1] = dp[i - 2][j - 1][0] + righ + lef;
					dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][1] + righ + newlef);
				}
				
			}
		}
	}
	for (i = 1; i <= (N + 1) / 2; i++)
	{
		cout << min(dp[N][i][0], dp[N][i][1])<<' ';
	}
}