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

	int q;
	cin >> q;
	while (q--) {
		ll a[3], sol = 0;
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		do {
			ll x = a[0];
			ll y = a[1];
			ll z = a[2];

			if (z >= abs(x-y))
				sol = max(sol, (x+y+z)/2);
			else
				sol = max(sol, z+min(x, y));
		} while (next_permutation(a, a+3));
		cout << sol << '\n';
	}
}