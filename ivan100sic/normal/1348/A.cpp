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
		ll x=0, y=0, n;
		cin >> n;
		for (ll i=0; i<n; i++) {
			if (i < n/2-1 || i == n-1)
				x += 1ll << i;
			else
				y += 1ll << i;
		}
		cout << 2ll*abs(x-y) << '\n';
	}
}