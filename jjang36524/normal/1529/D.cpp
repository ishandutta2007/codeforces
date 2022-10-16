#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
#define MOD 998244353
int D[1000100];
int dp[1000100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++)
	{
		int j;
		for (j = i; j <= N; j += i)
			D[j]++;
	}
	int sum = 0;
	for (i = 1; i <= N; i++)
	{
		dp[i] = D[i]+sum;
		dp[i] %= 998244353;
		sum += dp[i];
	}
	cout << dp[N];
}