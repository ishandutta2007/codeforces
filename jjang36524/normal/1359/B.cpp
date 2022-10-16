#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define int long long
int N, M,T, a, b, c, d;
int dp[1005];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M>>a>> b;
		string s;
		int i;
		dp[1] = a;
		for (i = 2; i <= M; i++)
		{
			dp[i] = min(dp[i - 2] + b, dp[i - 1] + a);
		}
		int ans = 0;
		while (N--)
		{
			cin >> s;
			int bef = 0;
			for (i = 0; i < M; i++)
			{
				if (s[i] == '*')
				{
					ans += dp[i - bef];
					bef = i + 1;
				}
			}
			ans += dp[i - bef];
		}
		cout << ans << '\n';
	}
}