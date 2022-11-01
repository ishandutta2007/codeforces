#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, ll> hv;
ll x;
int n;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (ll i = 0;i < n;i++)
	{
		ll a; cin >> a;
		hv[a]++;
	}
	for (ll i = 2;i < (1ll<<34);i<<=1)
	{
		for (auto it = hv.begin();it != hv.end();it++)
			if (it->first*2 < i)
			{
				auto it2 = hv.find(i-it->first);
				if (it2 != hv.end()) x += it->second*it2->second;
			} else if (it->first*2 == i)
				x += it->second*(it->second-1)/2;
			else break;
	}
	cout << x << endl;
	return 0;
}