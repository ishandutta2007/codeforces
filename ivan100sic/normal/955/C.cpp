#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll ml(ll x, ll y) {
	if (x * 1.0 * y > 1.1e18)
		return 1.1e18;
	return x * y;
}

ll pw(ll x, ll y) {
	if (y == 0)
		return 1;
	if (y == 1)
		return x;

	ll z = pw(x, y >> 1);
	z = ml(z, z);
	if (y & 1) {
		z = ml(z, x);
	}
	return z;
}

ll root(ll x, ll y) {
	ll l = 1, r = x, o = 0;

	ld approx = pow(x, 1.0 / y);

	l = max(1ll, (ll)(approx - 2));
	r = approx + 2;

	while (l <= r) {
		ll m = (l+r) >> 1;
		if (pw(m, y) <= x) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return o;
}

ll pcpw[100][100];

ll small_root(ll x, ll y) {
	ll z = 1;
	while (pcpw[z+1][y] <= x)
		z++;
	return z;
}

int meb[100];

ll r(ll x) {
	if (x <= 1)
		return 0;
	ll z = 0;
	for (int i=2; i<21; i++)
		if (meb[i] != 0)
			z += meb[i] * (root(x, i) - 1);
	for (int i=21; i<=60; i++)
		if (meb[i] != 0)
			z += meb[i] * (small_root(x, i) - 1);
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	fill(meb+1, meb+100, 1);
	for (int i=2; i<100; i++)
		for (int j=2; i*j<100; j++)
			meb[i*j] -= meb[i];

	for (int i=1; i<100; i++)
		for (int j=1; j<100; j++)
			pcpw[i][j] = pw(i, j);

	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		cout << r(b) - r(a-1) + (a == 1) << '\n';
	}
}