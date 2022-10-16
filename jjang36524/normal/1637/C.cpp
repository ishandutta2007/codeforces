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
		int ans = 0;
		int comm = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (i == 0 || i == N - 1)
				continue;
			if (N == 3 && a % 2)
				ans = -2;
			if (a >= 2)
				comm = 1;
			if (ans >= 0)
			{
				ans += a;
				ans += a % 2;
			}
		}
		if (comm == 0)
			cout << -1 << '\n';
		else
			cout << ans / 2 << '\n';
	}
}