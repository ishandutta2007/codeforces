#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000000007;

/*
	n / x = q
	n / y >= q+1
	n / (q+1) >= y
	n / n / (q+1)
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, m, sol = 0;
	cin >> n >> m;
	// idi po svim kolicnicima
	ll q = 0;
	while (1) {
		ll r = q ? n / q : m;

		if (q == n) {
			// ostatak je ionako 0, zavrsi
			break;
		} else {
			// cerr << q << ' ';
			
			q = n / (n / (q+1));
			ll l = n / q + 1;
			
			// cerr << l << ' ' << r << ' ';

			if (l > m)
				continue;
			if (r > m)
				r = m;

			ll r1 = n % l;
			ll r2 = n % r;
			
			// cerr << r1 << ' ' << r2 << '\n';

			sol = (sol + (r1 + r2) % MOD * ((r-l+1) % MOD)) % MOD;
		}
	}

	sol %= MOD;
	if (sol % 2)
		sol += MOD;
	sol >>= 1;
	sol %= MOD;
	cout << sol << '\n';
}