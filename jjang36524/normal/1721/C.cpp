#include <bits/stdc++.h>
using namespace std;
#define int long long
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
		vector<int>a,b;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			b.push_back(x);
			
		}
		for (i = 0; i < N; i++)
		{
			auto t = lower_bound(b.begin(), b.end(), a[i]);
			cout << (*t) - a[i] << ' ';
		}
		cout << '\n';
		vector<int>c;
		for (i = 1; i < N; i++)
		{
			if (a[i] > b[i - 1])
			{
				c.push_back(i - 1);
			}
		}
		c.push_back(N - 1);
		int x = 0;
		for (i = 0; i < N; i++)
		{
			while (c[x] < i)
				x++;
			cout << b[c[x]] - a[i] << ' ';
		}
		cout << '\n';
	}
}