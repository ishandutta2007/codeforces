#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<ll> x1, x2;
ll n, l, w;

bool pokriva(ll x, ll z) {
	if (z < x+l)
		return false;

	ll p = z+x+l;
	ll q = z-x+l;

	return -w*q < p && p < w*q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> w;
	for (int i=0; i<n; i++) {
		ll x, t;
		cin >> x >> t;
		if (t == 1) 
			x1.push_back(x);
		else
			x2.push_back(x);
	}

	sort(x2.begin(), x2.end());
	ll sol = 0;

	/*
	for (ll x : x1)
		for (ll z : x2)
			if (pokriva(x, z))
				sol++;

	cerr << sol << '\n';
	sol = 0;
	*/

	for (ll x : x1) {

		ll lo = 0, hi = (ll)x2.size()-1, o = x2.size();

		while (lo <= hi) {
			ll j = (lo + hi) / 2;

			if (pokriva(x, x2[j])) {
				o = j;
				hi = j-1;
			} else {
				lo = j+1;
			}
		}

		sol += (ll)x2.size() - o;
	}

	cout << sol << '\n';
}