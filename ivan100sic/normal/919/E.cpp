#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a, b, p, x;

ll f[1000011];
ll g[1000011];

pair<ll, ll> find_lr(ll i) {
	ll w = (x-i) / p;
	if (x - i < 0)
		w = -1;
	return {i, i+w};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> p >> x;

	f[0] = 1;
	for (int i=1; i<p-1; i++)
		f[i] = f[i-1] * a % p;
	g[1] = 1;
	for (int i=2; i<p; i++)
		g[i] = p - g[p % i] * (p/i) % p;
	for (int i=1; i<p; i++)
		g[i] = b * g[i] % p;

	map<int, ll> mp;
	{
		// inicijalizuj
		auto par = find_lr(1);
		if (par.second - par.first > 2*(p-1)) {
			ll celo = (par.second - par.first) / (p-1) - 1;
			for (int i=0; i<p-1; i++)
				mp[f[i]] += celo;
			par.second -= celo * (p-1);
		}
		for (ll i=par.first; i<=par.second; i++)
			mp[f[i % (p-1)]] += 1;
	}

	ll sol = 0;

	// resi
	for (int i=1; i<p; i++) {

		sol += mp[g[i]];

		// predji
		auto staro = find_lr(i);
		auto novo = find_lr(i+1);

		// cerr << i << ' ' << staro.first << ' ' << staro.second << ' ' << mp[g[i]] << '\n';
		
		// for (int i=1; i<p; i++)
		// 	cerr << mp[i] << ' ';
		// cerr << '\n';

		if (novo.second < novo.first)
			break;

		for (ll j=staro.first; j<novo.first; j++)
			mp[f[j % (p-1)]] -= 1;
		for (ll j=staro.second + 1; j<=novo.second; j++)
			mp[f[j % (p-1)]] += 1;
	}

	cout << sol << '\n';
}