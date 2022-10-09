#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	ll k, n, a, b;
	cin >> k >> n >> a >> b;

	ll l = 0, r = n, o = -1;
	while (l <= r) {
		ll m = (l+r) >> 1;
		ll k2 = k - m*a - (n-m)*b;
		if (k2 > 0) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	cout << o << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		solve();
	}
}