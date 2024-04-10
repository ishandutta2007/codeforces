#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007ll;

map<ll, ll> occ;
ll ans = 1;
int m;

ll power(ll base, ll exponent)
{
	if (exponent == 0) return 1;
	ll res = power(base, exponent>>1);
	res = res*res; res %= MOD;
	if (exponent&1) res = (res * base) % MOD;
	return res;
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> m;
	while (m--)
	{
		ll x; cin >> x;
		occ[x]++;
	}
	ll prod = 1;
	for (auto u: occ)
	{
		prod *= (u.second+1);
		prod %= (2ll*(MOD-1ll));
	}
	for (auto u: occ)
	{
		ans *= power(u.first, ((u.second*prod)%(2ll*(MOD-1ll))/2ll)%(MOD-1ll));
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}