#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll pw(ll x, ll y) {
	if (y == 0)
		return 1;
	ll z = pw(x, y >> 1);
	z = z * z;
	if (y & 1)
		z = z * x;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll k, z = 0;
	cin >> k;
	for (int n=1; n<15; n++) {
		ll lo = z+1;
		ll hi = z+n*pw(10, n-1)*9;
		if (lo <= k && k <= hi) {
			ll p = (k-lo) / n;
			ll q = (k-lo) % n;
			cerr << n << ' ' << p << ' ' << q << '\n';
			cout << to_string(pw(10, n-1) + p)[q] << '\n';
			return 0;
		} else {
			z = hi;
		}
	}
}