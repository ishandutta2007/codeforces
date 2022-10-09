#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll fsf(ll x) {
	for (ll y=2; y*y <= x; y++) {
		if (x % y == 0) {
			return y;
		}
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll p, y;
	cin >> p >> y;

	for (ll t = y; t >= max(2ll, y - 1000); t--) {
		ll q = fsf(t);
		if (q > p) {
			cout << t << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}