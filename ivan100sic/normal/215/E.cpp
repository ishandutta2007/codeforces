// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int mo[66];

int cif(ll x) {
	int q = 0;
	while (x)
		x >>= 1, q++;
	return q;
}

ll resi(ll h) {
	int c = cif(h);
	ll z = 0;
	for (int d=1; d<c; d++) {
		for (int m=2; m<=d; m++) {
			if (d % m == 0) {
				z += -1 * mo[m] * (1ll << (d / m - 1));
			}
		}
	}

	for (int m=2; m<=c; m++) {
		if (c % m == 0) {
			int p = c / m;
			ll q = 0;
			ll u = h >> (c-p);
			q += u - (1ll << (p - 1));
			ll t = 0;
			for (int i=0; i<c/p; i++) {
				t = (t << p) | u;
			}
			if (t <= h)
				q++;
			z += q * -mo[m];
		}
	}

	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	mo[1] = 1;
	for (int i=1; i<66; i++)
		for (int j=2*i; j<66; j+=i)
			mo[j] -= mo[i];

	ll a, b;
	cin >> a >> b;
	cout << resi(b) - resi(a-1) << '\n';
}

// I will still practice daily...