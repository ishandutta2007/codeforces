#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int T;
int a, b, c, d;
string s;
int dp[401][201];
vector<int>arr;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		arr.clear();
		memset(dp, 1, sizeof(dp));
		int N;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
		for (i = 0; i <= 2 * N; i++)
		{
			dp[i][0] = 0;
		}
		for (i = 1; i <= 2*N; i++)
		{
			int j;
			for (j = 1; j <= N; j++)
			{
				dp[i][j] = min(dp[i - 1][j - 1] + abs(arr[j - 1] - i), dp[i - 1][j]);
			}
		}
		cout << dp[2 * N][N]<<'\n';
	}
}