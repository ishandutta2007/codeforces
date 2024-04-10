#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[101];
int arr[101];
int cnt[101];
int va[101][101];
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
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for (i = 0; i < N; i++)
		{
			memset(cnt, 0, sizeof(cnt));
			int j;
			int v = 0;
			for (j = i; j < N; j++)
			{
				if (arr[j] <= N)
					cnt[arr[j]]++;
				while (cnt[v])
					v++;
				va[i][j] = v;
			}
		}
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			memset(dp, 0, sizeof(dp));
			int j;
			for (j = i; j < N; j++)
			{
				int k;
				for (k = i; k <= j; k++)
				{
					dp[j + 1] = max(dp[k] + va[k][j]+1,dp[j+1]);
				}
				ans += dp[j + 1];
			}
		}
		cout << ans << '\n';
	}
}