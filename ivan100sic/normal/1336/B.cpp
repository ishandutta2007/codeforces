// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll sq(ll x) { return x*x; }

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		vector<int> a[3];
		for (int i=0, x; i<3; i++)
			cin >> x, a[i].resize(x);
		for (int i=0; i<3; i++) {
			for (int& x : a[i])
				cin >> x;
			sort(begin(a[i]), end(a[i]));
		}
		sort(a, a+3);
		ll sol = 8e18;
		do {
			for (int x : a[0]) {
				auto u = upper_bound(begin(a[1]), end(a[1]), x);
				auto v = lower_bound(begin(a[2]), end(a[2]), x);
				if (u != begin(a[1])) {
					--u;
					if (v != end(a[2]))
						sol = min(sol, sq(x-*u) + sq(x-*v) + sq(*u-*v));
				}
			}
		} while (next_permutation(a, a+3));
		cout << sol << '\n';
	}
}