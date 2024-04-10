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
		ll n, k;
		cin >> n >> k;
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		ll presek = min(b, d) - max(a, c);
		ll i0 = 0;
		if (presek > 0) {
			i0 = n * presek;
		}

		ll uni = max(b, d) - min(a, c);

		ll odgbdouni;
		if (presek > 0) {
			odgbdouni = 2*uni - (b-a) - (d-c);
		} else {
			odgbdouni = uni;
		}

		ll sol = 4e18;

		// deft.
		if (i0 >= k) {
			sol = 0;
		}

		// radimo sa c njih
		for (ll c=1; c<=n; c++) {
			ll fali = k - i0;
			ll trosak;
			if (presek > 0) {
				trosak = 0;
			} else {
				trosak = c * (-presek);
			}

			if (fali <= 0) {
				//
			} else if (fali <= c * odgbdouni) {
				trosak += fali;
			} else {
				ll d = c * odgbdouni;
				trosak += d;
				fali -= d;
				trosak += 2 * fali;
			}

			sol = min(sol, trosak);
		}

		cout << sol << '\n';
	}
}