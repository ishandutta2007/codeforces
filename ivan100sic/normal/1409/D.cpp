// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll sd(ll x) {
	ll z = 0;
	while (x) {
		z += x % 10;
		x /= 10;
	}
	return z;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		ll p = 1;
		for (int i=0; i<=18; i++) {
			ll r = (p - x % p) % p;
			if (sd(x+r) <= y) {
				cout << r << '\n';
				break;
			}
			if (i < 18) {
				p *= 10;
			}
		}
	}
}