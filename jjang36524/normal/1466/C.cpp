#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string.h>
#include <string>
using namespace std;
int T, N;
int dp[100100][2][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		memset(dp, 1, sizeof(dp[0])*(s.size()+1));
		dp[0][0][0] = 0;
		s.push_back('.');
		s.push_back('.');
		int i;
		for (i = 0; i < s.size()-2; i++)
		{
			if (s[i] != s[i + 1])
			{
				if (s[i] != s[i + 2])
				{
					dp[i + 1][0][0] = min({ dp[i][0][0],dp[i][1][0]+1 });
					dp[i + 1][1][0] = min({ dp[i][0][1],dp[i][1][1] + 1 });
				}
				else
				{
					dp[i + 1][0][1] = min({ dp[i][0][0],dp[i][1][0] + 1 });
					dp[i + 1][1][1] = min({ dp[i][0][1],dp[i][1][1] + 1 });
					dp[i + 1][0][0] = min({ dp[i][0][0],dp[i][1][0] }) + 1;
					dp[i + 1][1][0] = min({ dp[i][0][1],dp[i][1][1] }) + 1;
				}
			}
			else
			{
				if (s[i] != s[i + 2])
				{
					dp[i + 1][1][0] = min({ dp[i][0][0],dp[i][1][0] + 1,dp[i][0][1],dp[i][1][1]+1 });
					dp[i + 1][0][0] = min({ dp[i][0][0],dp[i][1][0]})+1;
				}
				else
				{
					dp[i + 1][1][1] = min({ dp[i][0][0], dp[i][1][0] + 1, dp[i][0][1], dp[i][1][1] + 1 });
					dp[i + 1][0][0] = min({ dp[i][1][0],dp[i][0][0] }) + 1;
					dp[i + 1][1][0] = min({ dp[i][1][1],dp[i][0][1] }) + 1;
				}
			}
		}
		cout << dp[s.size()-2][0][0] << '\n';
	}
}