#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int dp[20001000];
int cur[20001000];
bool isp[20010000];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		int j;
		for (j = 1; j * j <= a; j++)
		{
			if (a % j == 0)
			{
				cur[j]++;
				if(j*j<a)
					cur[a / j]++;
			}
		}
	}
	int ans = 0;
	for (i = 1; i <= 5000000; i++)
	{
		dp[i] += cur[i]*i;
		ans = max(ans, dp[i]);
		int j;
		for (j = i * 2; j <= 5000000; j+=i)
		{
			dp[j] = max(dp[j], dp[i]-cur[j]*i);
		}
	}
	cout << ans;
}