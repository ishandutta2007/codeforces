// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll solve(ll x) {
	ll z = 0;
	while (x) {
		if (x == 4) return z + 3;
		if (x % 4 == 0) {
			z += 1;
			x -= 2;
		} else {
			z += x/2;
			x = x/2 - 1;
		}
	}
	return z;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		if (x % 2 == 1) {
			// jbg
			cout << x - solve(x-1) << '\n';
		} else {
			cout << solve(x) << '\n';
		}
	}
}