#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <stdlib.h>
#define int long long
using namespace std;
int uf[500100];
int f(int n)
{
	return uf[n] == n ? n : uf[n] = f(uf[n]);
}
int u(int n, int m)
{
	if (f(n) == f(m))
	{
		return 0;
	}
	uf[f(n)] = f(m);
	return 1;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N;
		int i;
		vector<pair<int, int>>t;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			t.push_back({ a,i });
			uf[i] = i;
		}
		sort(t.begin(), t.end());
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			if (i && t[i].first == t[i - 1].first)
			{
				cout << "YES" << '\n';
				goto T;
			}
			ans += u(t[i].second, i);
		}
		if (ans % 2)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	T:
		int d;
	}
}