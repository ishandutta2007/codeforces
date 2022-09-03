#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MOD = int(1e9 + 7);

int n, m;
map<int, int> g[100000];
unsigned long long cntNg[1000001];
unsigned long long  memo[1000001];

unsigned long long fac(int n)
{
	if (n == 1)
		return 1;
	
	unsigned long long &ret = memo[n];
	if (ret)
		return ret;

	return (n*fac(n-1))%MOD;
}

hash<int> hf;

int main()
{
	cin.sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int gs;
		cin >> gs;
		for (int j = 0; j < gs; j++)
		{
			int x;
			cin >> x;
			g[i][x]++;
		}
		for (auto j : g[i])
		{
			const long long p = 100003;
			cntNg[j.first] *= p * p;
			cntNg[j.first] += (i + 1) * p + (j.second + 1);
		}
	}

	map<unsigned long long, int> tcscnt;
	for (int i = 1; i <= m; i++)
		tcscnt[cntNg[i]]++;

	unsigned long long ans = 1;
	for (auto i : tcscnt)
	{
		ans *= fac(i.second);
		ans %= MOD;
	}
	cout << ans << endl;

	return 0;
}