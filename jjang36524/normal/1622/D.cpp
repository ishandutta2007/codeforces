#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define int long long
int dp[5010][5010];
#define MOD 998244353
vector<int>t;
signed main()
{
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	t.push_back(0);
	int i;
	for (i = 0; i < N; i++)
	{
		if (s[i] == '1')
			t.push_back(i + 1);
	}
	t.push_back(N + 1);
	if (t.size() <= K + 1 || K == 0)
	{
		cout << 1;
	}
	else
	{
		dp[0][0] = 1;
		for (i = 1; i <= N; i++)
		{
			int j;
			for (j = 0; j <= i; j++)
			{
				dp[i][j] += dp[i-1][j];
				dp[i][j + 1] += dp[i - 1][j];
			}
			for (j = 0; j <= i; j++)
			{
				dp[i][j] %= MOD;
			}
		}
		int ans = 0;
		for (i = 0; i + K + 1 < t.size(); i++)
		{
			if (i == 0)
			{
				ans += dp[t[i + K + 1] - t[i] - 1][K];
			}
			else
			{
				ans += dp[t[i + K + 1] - t[i] - 1][K];
				ans -= dp[t[i + K] - t[i]-1][K - 1];
				ans += MOD;
			}
		}
		cout << ans%MOD;
	}
}