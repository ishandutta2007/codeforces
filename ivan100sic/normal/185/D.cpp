#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
LCM(...) = proizvod za k parno
= proizvod / (2^(r-l+1 - 1)) za k neparno

Proizvod (a+1)(a^2+1) = 1,1,1,1
% * (a^4+1) = 1,1,1,1,1,1,1,1

*/

// m >= 1, x >= 0, y >= 0 (0^0 = 1)
ll modpow(ll x, ll y, ll m) {
	if (x >= m)
		x %= m;
	if (y == 0)
		return 1%m;
	ll z = modpow(x, y>>1, m);
	z = z*z%m;
	if (y & 1)
		z = z*x%m;
	return z;
}

// x^(2^y)
// m prime, y >= 0, x >= 0
ll tower(ll x, ll y, ll m) {
	if (x >= m)
		x %= m;
	if (!x)
		return 0;
	ll z = modpow(2, y, m-1);
	return modpow(x, z, m);
}

// y factors (x+1)(x^2+1)(x^4+1)...
// m prime, x >= 0, y >= 1
ll squares(ll x, ll y, ll m) {
	if (x >= m)
		x %= m;
	if (x == 0)
		return 1;
	if (x == 1)
		return modpow(2, y, m);
	ll z = (tower(x, y, m)+m-1)%m;
	z = z*modpow(x-1, m-2, m)%m;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll k, l, r, p;
		cin >> k >> l >> r >> p;
		if (p == 2) {
			// specijalan slucaj
			cout << 1-k%2 << '\n';
		} else {
			ll q = tower(k, l, p);
			q = squares(q, r-l+1, p);
			if (k % 2)
				q = q*modpow(modpow(2, r-l, p), p-2, p)%p;
			cout << q << '\n';
		}
	}
}