// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

map<pair<ll, ll>, ll> sol;

ll f(ll x) {
	ll z = 0;
	while (x > 0) {
		z += x % 10;
		x /= 10;
	}
	return z;
}

void uradi(ll x) {
	ll z = 0;
	for (ll k=0; k<=9; k++) {
		z += f(x + k);
		if (!sol.count({z, k})) {
			sol[{z, k}] = x;
		} else {
			sol[{z, k}] = min(sol[{z, k}], x);
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	for (ll v=0; v<=10000; v++) {
		uradi(v);
	}

	for (ll x0 = 1; x0 <= 9; x0++) {
		for (ll c9 = 0; c9 <= 15; c9++) {
			for (ll s0 = 0; s0 < 10; s0++) {
				for (ll s1 = 0; s1 < 10; s1++) {
					ll v = x0;
					for (ll i=0; i<c9; i++) {
						v = 10*v + 9;
					}
					v = 10*v + s0;
					v = 10*v + s1;
					uradi(v);
				}
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		if (!sol.count({n, k})) {
			cout << "-1\n";
		} else {
			cout << sol[{n, k}] << '\n';
		}
	}
}