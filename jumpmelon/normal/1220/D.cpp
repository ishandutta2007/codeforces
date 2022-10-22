#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	typedef pair<int, int> pii;

	int n;
	map<ll, vector<ll> > v;
#define lowbit(x) (x & (-x))

	void work()
	{
		scanf("%d", &n);
		ll x;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &x);
			v[lowbit(x)].push_back(x);
		}
		int ans = 0;
		ll id = -1;
		for (ll i = 1; i <= 1e18; i <<= 1)
			if (ans < int(v[i].size()))
				ans = v[i].size(), id = i;
		printf("%d\n", n - ans);
		for (ll i = 1; i <= 1e18; i <<= 1)
			if (i != id)
				for (ll j : v[i])
					printf("%lld ", j);
	}
}

int main()
{
	TYC::work();
	return 0;
}