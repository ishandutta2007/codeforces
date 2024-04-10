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
		int n, x, m;
		cin >> n >> x >> m;

		int xl = x, xr = x;

		while (m--) {
			int l, r;
			cin >> l >> r;
			if (r < xl || xr < l) {
				continue;
			}

			xl = min(l, xl);
			xr = max(r, xr);
		}

		cout << xr-xl+1 << '\n';
	}
}