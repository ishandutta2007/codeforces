#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][20100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 10, sizeof(dp));
		int N;
		cin >> N;
		int i;
		vector<pair<int,int>>t;
		int v = 0;
		int s = 0;
		for (i = 0; i < 2 * N; i++)
		{
			int a;
			cin >> a;
			if (i < N)
				t.push_back({ a,0 });
			else
				t[i - N].second = a;
			v += (N-1) * a * a;
		}
		dp[1][0] = v;
		for (i = 0; i <N; i++)
		{
			int f = t[i].first;
			int se = t[i].second;
			int c = i % 2;
			int b = (i + 1) % 2;
			int j;
			memset(dp[c], 10, sizeof(dp[c]));
			int l;
			for (l = 0; l <= s; l++)
			{
				dp[c][l + f] = min(dp[c][l + f], dp[b][l] + l * f * 2 + (s-l) * se * 2);
				dp[c][l + se] = min(dp[c][l + se], dp[b][l] + l * se * 2 + (s - l) * f * 2);
			}
			s += t[i].first;
			s += t[i].second;
		}
		int ans = 1LL << 30;
		for (i = 0; i <= s; i++)
		{
			ans = min(ans, dp[(N-1)%2][i]);
		}
		cout << ans << '\n';
	}
}