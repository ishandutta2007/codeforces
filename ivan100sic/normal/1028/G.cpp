#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ask(vector<ll> a) {
	cout << a.size();
	for (ll x : a)
		cout << ' ' << x;
	cout << '\n' << flush;

	int y;
	cin >> y;
	if (y == -2)
		exit(1);
	if (y == -1)
		exit(0);
	return y;
}

map<pair<ll, int>, ll> mp;

ll dokle_resivo(ll x, int q) { // vraca najveci broj y tako da moze da se resi x .. y sa q upita
	if (mp.count({x, q}))
		return mp[{x, q}];

	if (q == 1) {
		return mp[{x, q}] = x + min(x, 10000ll) - 1;
	}

	if (x > 10000) {
		ll d = x-10000;
		return mp[{x, q}] = d + dokle_resivo(10000, q);
	}

	// glup
	ll t = x;
	for (int i=0; i<=x; i++) {
		t = dokle_resivo(t, q-1) + 2;
	}
	return mp[{x, q}] = t-2;
}

vector<ll> range(ll x, ll amt, ll gap) {
	vector<ll> v(amt);
	for (ll i=0; i<amt; i++)
		v[i] = x + i*gap;
	return v;
}

void resi(ll x, int q) {
	if (q == 1) {
		// samo odstampaj sve brojeve
		ask(range(x, min(10000ll, x), 1));
	}

	// glup
	ll t = x;
	vector<ll> u, v = {t-1};
	for (int i=0; i<=min(x, 10000ll); i++) {
		t = dokle_resivo(t, q-1) + 1;
		if (i < min(x, 10000ll))
			u.push_back(t);
		v.push_back(t);
		t++;
	}

	int j = ask(u);
	resi(v[j]+1, q-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	resi(1, 5);
}