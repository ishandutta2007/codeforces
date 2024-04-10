#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, f, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> f >> k;

	bool u_prvom = true;
	ll gorivo = b, sol = 0;

	for (ll i=1; i<=k; i++) {
		if (u_prvom) {
			if (i == k) {
				// da li mogu da stignem do kraja sa gorivom?
				if (gorivo >= a) {
					// ok nista
				} else if (gorivo >= f) {
					// mogu da stignem do pumpe
					sol++;
					if (b < (a - f)) {
						// ne mogu da stignem od pumpe do cilja
						cout << -1;
						return 0;
					}
				} else {
					// ne mogu ni do pumpe
					cout << -1;
					return 0;
				}
			} else {
				// da li mogu da stignem do sledeceg prolaza pored pumpe?
				if (gorivo >= a + (a - f)) {
					// ok nista
					gorivo -= a;
				} else if (gorivo >= f) {
					// mogu da stignem do pumpe, natankaj se i odi na drugu stranu
					sol++;
					gorivo = b - (a - f);
					if (gorivo < 0) {
						cout << -1;
						return 0;
					}
				} else {
					cout << -1;
					return 0;
				}
			}
		} else {
			if (i == k) {
				// da li mogu da stignem do kraja sa gorivom?
				if (gorivo >= a) {
					// ok nista

				} else if (gorivo >= a - f) {
					// mogu da stignem do pumpe
					sol++;
					if (b < f) {
						// ne mogu da stignem od pumpe do cilja
						cout << -1;
						return 0;
					}
				} else {
					// ne mogu ni do pumpe
					cout << -1;
					return 0;
				}
			} else {
				// da li mogu da stignem do sledeceg prolaza pored pumpe?
				if (gorivo >= a + f) {
					// ok nista
					gorivo -= a;
				} else if (gorivo >= a - f) {
					// mogu da stignem do pumpe, natankaj se i odi na drugu stranu
					sol++;
					gorivo = b - f;
					if (gorivo < 0) {
						cout << -1;
						return 0;
					}
				} else {
					cout << -1;
					return 0;
				}
			}
		}

		u_prvom = !u_prvom;
	}

	cout << sol;
}