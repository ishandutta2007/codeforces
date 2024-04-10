#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define MOD 998244353
using namespace std;
int N;
int T;
int com[300100];
int mo(int n, int m = MOD - 2)
{
	if (m % 2)
		return n * mo(n, m - 1) % MOD;
	else if (m == 0)
		return 1;
	int a = mo(n, m / 2);
	return a * a % MOD;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int K;
	cin >> N>>K;
	vector<pair<int, int>>t;
	int i;
	for (i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		t.push_back({ a,0 });
		t.push_back({ b,1 });
	}
	sort(t.begin(), t.end());
	K--;
	com[K] = 1;
	for (i = K + 1; i <= N; i++)
	{
		com[i] = com[i - 1] * i;
		com[i] %= MOD;
		com[i] = com[i] * mo(i - K) % MOD;
	}
	int su = 0;
	int ans = 0;
	for (i = 0; i < 2 * N; i++)
	{
		if (t[i].second)
		{
			su--;
		}
		else
		{
			ans += com[su];
			su++;
		}
	}
	cout << ans % MOD;
}