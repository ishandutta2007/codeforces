#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<pair<ll, ll>, ll> c;

ll r(ll x, ll s) {
	if (s < x || (x^s) % 2)
		return 0;
	if (x + s == 0)
		return 1;
	if (c.count({x, s}))
		return c[{x, s}];
	ll& z = c[{x, s}];
	if (x & 1) {
		z = 2 * r(x>>1, s>>1);
	} else {
		z = r(x>>1, (s>>1)) + r(x>>1, (s>>1) - 1);
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x, s;
	cin >> s >> x;

	ll z = r(x, s);
	if (x == s)
		z -= 2;

	cout << z << '\n';
}