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
		ll x, c=0;
		cin >> x;
		for (ll s=1;; s=2*s+1) {
			ll z = s*(s+1)/2;
			if (z <= x) {
				c++;
				x -= z;
			} else {
				cout << c << '\n';
				break;
			}
		}
	}
}