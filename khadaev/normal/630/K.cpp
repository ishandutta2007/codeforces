#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<int> p = {2, 3, 5, 7};
	ll ans = 0;
	forn(i, 0, 16) {
		ll t = n, sgn = 1;
		forn(j, 0, 4) {
			if (i & (1 << j)) {
				sgn *= -1;
				t /= p[j];
			}
		}
		ans += t * sgn;
	}
	cout << ans << '\n';
	return 0;
}