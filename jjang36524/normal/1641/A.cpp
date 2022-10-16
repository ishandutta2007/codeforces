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
		multiset<int>c;
		int N, M;
		cin >> N >> M;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			c.insert(a);
		}
		int v = 0;
		while (c.size())
		{
			auto a = c.begin();
			if (c.count((*a) * M))
				c.erase(c.lower_bound((*a) * M));
			else
				v++;
			c.erase(c.lower_bound((*a)));
		}
		cout << v << '\n';
	}
}