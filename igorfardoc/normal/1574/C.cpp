#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif

	ll sum = 0;
	int n;
	cin >> n;
	set<ll> s;
	for(int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		sum += a;
		s.insert(a);
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;
		auto it = s.lower_bound(x);
		ll res = 4000000000000000000ll;
		if(it != s.end())
		{
			res = min(res, max(0ll, y - (sum - *it)));
		}
		if(it != s.begin())
		{
			--it;
			ll res1 = x - *it;
			res1 += max(0ll, y - (sum - *it));
			res = min(res1, res);
		}
		cout << res << '\n';
	}
}