#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[300100][10];
int arr[300100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		int ans = 1LL<<60;
		for (i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[i] = a;
			int j;
			for (j = 0; j < 10; j++)
			{
				
				dp[i+1][j] = 1LL << 60;
				int k;
				for (k = 0; k < 10; k++)
				{
					if (i && arr[i] + j == arr[i - 1] + k)
						continue;
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][k]+b*j);
				}
				if (i == N - 1)
				{
					ans = min(ans, dp[i + 1][j]);
				}
			}
		}
		cout << ans<<'\n';
	}
}