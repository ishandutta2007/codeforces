#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int N;
int dp[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int n, p, k;
		cin >> n >> p>>k;
		vector<int>prize;
		int i;
		prize.push_back(0);
		for (i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			prize.push_back(a);
		}
		sort(prize.begin(), prize.end());
		int ans = 0;
		for (i = 1; i <= n; i++)
		{
			dp[i] = dp[i - 1] + prize[i];
			if (i >= k)
				dp[i] = min(dp[i], dp[i - k] + prize[i]);
			if (dp[i] <= p)
				ans = i;
		}
		cout <<ans << '\n';
	}
}