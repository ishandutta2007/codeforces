#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll mul(ll x, ll y) {
	if (x * 1.0 * y > 4e18)
		return 4e18;
	return x * y;
}

ll pw(ll x, ll y) {
	if (y == 1)
		return x;

	ll p = pw(x, y >> 1);
	p = mul(p, p);
	if (y & 1)
		p = mul(p, x);
	return p;
}

ll root(ll x, ll y) {
	ll z = pow(x, 1.0 / y);
	while (pw(z+1, y) <= x)
		z++;
	while (pw(z, y) > x)
		z--;
	return z;
}

int mobius[66];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	fill(mobius+1, mobius+66, 1);
	for (int i=2; i<66; i++)
		for (int j=2*i; j<66; j+=i)
			mobius[j] -= mobius[i];

	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;

		ll sol = x;
		for (int i=2; i<=66; i++)
			sol -= mobius[i] * root(x, i);
		cout << sol << '\n';
	}
}