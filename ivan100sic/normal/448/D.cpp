#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, m, k;
	cin >> n >> m >> k;
	ll l = 1, r = n*m, o = 0;
	while (l <= r) {
		ll x = (l + r) >> 1, y = 0;
		for (ll i=1; i<=n; i++) {
			y += min(m, x / i);
		}
		if (y < k) {
			l = x + 1;
			o = x;
		} else {
			r = x - 1;
		}
	}
	cout << o + 1 << '\n';
}