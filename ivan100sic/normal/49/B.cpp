// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll e(string a, ll k) {
	ll v = 0;
	for (char c : a) {
		if (c - '0' >= k) return -1e18;
		v = k*v + c - '0';
	}
	return v;
}

ll l(ll x, ll k) {
	ll z = 0;
	while (x) {
		z++;
		x /= k;
	}
	return z;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string a, b;
	cin >> a >> b;
	ll sol = 0;
	for (int k=2; k<=3000; k++) {
		ll val = e(a, k) + e(b, k);
		if (val >= 0) {
			sol = max(sol, l(val, k));
		}
	}

	cout << sol << '\n';
}