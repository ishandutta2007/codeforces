#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#define int long long
#define MOD 1000000007
using namespace std;
int T, N;
int mul[61];
int co[61];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	int i;
	mul[0] = 1;
	for (i = 1; i < 60; i++)
	{
		mul[i] = mul[i - 1] * 2;
		mul[i] %= MOD;
	}
	while (T--)
	{
		memset(co, 0, sizeof(co));
		vector<int>x;
		cin >> N;
		int i;
		for (i = 1; i <= N; i++)
		{	
			int a;
			cin >> a;
			x.push_back(a);
			int j;
			for (j = 0; j < 60; j++)
			{
				if (a & (1LL << j))
					co[j]++;
			}
		}
		long long ans = 0;
		for (i = 0; i < N; i++)
		{
			int andv = 0;
			int orv = 0;
			int j;
			for (j = 0; j < 60; j++)
			{
				if (x[i] & (1LL << j))
				{
					andv += co[j] * mul[j];
					andv %= MOD;
					orv += N * mul[j];
					orv %= MOD;
				}
				else
				{
					orv += co[j] * mul[j];
					orv %= MOD;
				}
			}
			ans += andv * orv % MOD;
		}
		cout << ans % MOD << '\n';
	}
}