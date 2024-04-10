#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll sh[66];

int level(ll x) {
	int z = 0;
	while (x != 1) {
		x >>= 1;
		z++;
	}
	return z;
}

void pomeri(int z, ll amt) {
	if (amt < 0) {
		amt += 1ll << z;
	}
	sh[z] = (sh[z] + amt) & ((1ll << z) - 1);
}

ll get_plus(int z, ll x) {
	return (1ll << z) + ((x + sh[z]) & ((1ll << z) - 1));
}

ll get_minus(int z, ll x) {
	return (1ll << z) + ((x + (1ll << z) - sh[z]) & ((1ll << z) - 1));
}

void pomeri_vise(int z, ll amt) {
	if (z == 62)
		return;
	pomeri(z, amt);
	pomeri_vise(z+1, 2*amt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// valjda ce overflow magija da ucini svoje

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			ll x, k;
			cin >> x >> k;
			x = level(x);
			k = -k;
			pomeri(x, k);
		} else if (t == 2) {
			ll x, k;
			cin >> x >> k;
			x = level(x);
			k = -k;
			pomeri_vise(x, k);
		} else {
			ll x;
			cin >> x;
			cout << x << ' ';
			ll y = level(x);
			x = get_minus(y, x - (1ll << y));
			while (y != 0) {
				y--;
				x >>= 1;
				cout << get_plus(y, x) << ' ';
			}
			cout << '\n';
		}
	}
}