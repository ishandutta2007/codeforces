// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll pw(ll x, ll y) {
	ll z = 1;
	while (y--)
		z *= x;
	return z;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ld n;
	cin >> n;

	ll sol = 0;
	ll d = n;
	for (int i=0; i+d<=2*n-2; i++) {
		ll adj = (i > 0) + (i+d < 2*n-2);
		ll t = 4 * pw(3, adj) * pw(4, 2*n-2-d-adj);
		sol += t;
	}

	cout << sol << '\n';
}