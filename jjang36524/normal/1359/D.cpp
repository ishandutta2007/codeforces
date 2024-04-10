#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define int long long
int N, M,T, a, b, c, d;
int dp[200510];
int arr[200510];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> dp[i];
	}
	memset(arr, -10, sizeof(arr));
	int ans = 0;
	for (i = -30; i <= 30; i++)
	{
		int j;
		for (j = 0; j < N; j++)
		{
			if (dp[j] == i)
				arr[j] = i;
		}
		int p = 0;
		int tans = -(1LL<<60);
		for (j = 0; j < N; j++)
		{
			p += arr[j];
			if (p < 0)
				p = 0;
			else
				tans = max(p, tans);
		}
		ans = max(ans, tans - i);
	}
	cout << ans << '\n';
}