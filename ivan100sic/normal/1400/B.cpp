// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	// fuj

	int t;
	cin >> t;
	while (t--) {
		ll p, f, sol=0;
		cin >> p >> f;

		ll cs, cw;
		cin >> cs >> cw;

		ll s, w;
		cin >> s >> w;

		if (s > w) {
			swap(s, w);
			swap(cs, cw);
		}

		for (ll ts=0; ts<=cs; ts++) {
			if (ts * s > p) {
				break;
			}

			ll d = (p - ts*s) / w;
			ll z = ts + d;

			// drugom ostavljam
			ll rs = cs - ts;
			ll rw = cw - d;

			ll frem = f;
			// uzmi prvo s
			ll t = min(frem / s, rs);
			z += t;
			frem -= t * s;
			// pa w
			z += min(frem / w, rw);
			sol = max(sol, z);
		}

		cout << sol << '\n';
	}
}