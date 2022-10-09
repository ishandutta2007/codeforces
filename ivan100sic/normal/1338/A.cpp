// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll y = 0, z = 0;
		while (n--) {
			ll x;
			cin >> x;
			x += 332233223322ll;
			z = max(z, y-x);
			y = max(y, x);
		}
		cout << (z ? 64 - __builtin_clzll(z) : 0) << '\n';
	}
}