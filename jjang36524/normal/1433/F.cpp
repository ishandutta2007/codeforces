#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[71][71][36][71];
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	memset(dp, -10, sizeof(dp));
	dp[0][0][0][0] = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			int k, l;
			for (k = 0; k <= M / 2; k++)
			{
				for (l = 0; l < K; l++)
				{
					if (j == M - 1)
					{
						dp[i + 1][0][0][l] = max(dp[i][j][k][l], dp[i + 1][0][0][l]);
						if (k != M / 2)
						{
							dp[i + 1][0][0][(l+a)%K] = max(dp[i][j][k][l]+a, dp[i + 1][0][0][(l+a)%K]);
						}
					}
					else
					{
						dp[i][j+1][k][l] = max(dp[i][j][k][l], dp[i][j+1][k][l]);
						if (k != M / 2)
						{
							dp[i][j+1][k+1][(l + a) % K] = max(dp[i][j][k][l]+a, dp[i][j+1][k+1][(l + a) % K]);
						}
					}
				}
			}
		}
	}
	cout << dp[N][0][0][0];
}