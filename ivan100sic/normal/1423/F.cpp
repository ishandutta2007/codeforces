// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll f(ll x) {
	if (x % 2 == 0) return x/2;
	return 0;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll n, k;
	cin >> n >> k;
	ll s = 0, z = 0;
	while (k--) {
		ll x, y;
		cin >> x >> y;
		s += y;
		z = (z + x*y) % n;
	}

	cout << (s < n || (s == n && z == f(n)) ? 1 : -1) << '\n';
}