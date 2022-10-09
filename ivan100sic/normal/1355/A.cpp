// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

pair<int, int> dg(ll x) {
	int lo = 9, hi = 0;
	while (x > 0) {
		int y = x % 10;
		x /= 10;
		lo = min(lo, y);
		hi = max(hi, y);
	}
	return {lo, hi};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll a1, k;
		cin >> a1 >> k;
		ll a = a1;
		k--;
		for (ll i=0; i<k; i++) {
			auto [l, h] = dg(a);
			if (l == 0) {
				i = k;
				break;
			}
			a += l*h;
		}

		cout << a << '\n';
	}
}