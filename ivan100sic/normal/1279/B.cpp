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

	ll t;
	cin >> t;
	while (t--) {
		ll n, s;
		cin >> n >> s;
		ll h = 0, z = 0, best = 0, hi = -1, sol = -1;
		for (ll i=0; i<n; i++) {
			ll x;
			cin >> x;
			if (x > h) {
				h = x;
				hi = i;
			}
			z += x;
			if (z - h <= s && i > best) {
				best = i;
				sol = hi;
			}
			if (z <= s && i+1 > best) {
				best = i+1;
				sol = -1;
			}
		}
		cout << sol + 1 << '\n';
	}	
}