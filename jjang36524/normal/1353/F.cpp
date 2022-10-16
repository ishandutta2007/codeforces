#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <functional>
#define int long long
using namespace std;
int T, a, b, c, d, e, f;
int arr[101][101];
int fakarr[101][101];
int dp[101][101];
vector<pair<int, pair<int, int>>>t;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		t.clear();
		cin >> a>>b;
		int i, j;
		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
			{
				cin >> arr[i][j];
				arr[i][j] -= i + j;
				t.push_back({ -arr[i][j],{i,j} });
				fakarr[i][j] = 1LL << 50;
			}
		}
		int ans = 1LL << 62;
		memset(dp, 60, sizeof(dp));
		dp[0][1] = 0;
		sort(t.begin(), t.end());
		for (i = 0; i < a * b; i++)
		{
			t[i].first *= -1;
			fakarr[t[i].second.first][t[i].second.second] = t[i].first;
			int k;
			for (j = 1; j <= a; j++)
			{
				for (k = 1; k <= b; k++)
				{
					if (fakarr[j][k] < 1LL << 50)
					{
						dp[j][k] = min(dp[j - 1][k], dp[j][k - 1]) + fakarr[j][k];
					}
					else
					{
						dp[j][k] = 1LL << 62;
					}
				}
			}
			ans = min(ans, dp[a][b] - (a + b - 1) * t[i].first);
		}
		cout << ans << '\n';
	}
}