#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int a[55][55];
int n, k, h;

int p[1 << 20];
int q[1 << 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}

	h = n/2;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int mask=1; mask<(1<<h); mask++) {
		int c = 0, any = 0;
		for (int i=0; i<h; i++) {
			if (mask & (1<<i)) {
				p[mask] = max(p[mask], p[mask - (1<<i)]);
				c++;
				any = i;
			}
		}

		// ispitaj da li je sve klika
		bool ok = true;
		for (int i=0; i<h; i++) {
			if (mask & (1<<i)) {
				if (i != any) {
					ok = ok && a[i][any];
				}
			}
		}

		if (ok && p[mask - (1<<any)] == c-1) {
			p[mask] = c;
		}
	}

	// isto to samo za drugi

	for (int mask=1; mask<(1<<(n-h)); mask++) {
		int c = 0, any = 0;
		for (int i=0; i<(n-h); i++) {
			if (mask & (1<<i)) {
				q[mask] = max(q[mask], q[mask - (1<<i)]);
				c++;
				any = i;
			}
		}

		// ispitaj da li je sve klika
		bool ok = true;
		for (int i=0; i<(n-h); i++) {
			if (mask & (1<<i)) {
				if (i != any) {
					ok = ok && a[i+h][any+h];
				}
			}
		}

		if (ok && q[mask - (1<<any)] == c-1) {
			q[mask] = c;
		}
	}

	int sol = 0;

	for (int mask=0; mask<(1<<h); mask++) {
		if (p[mask] == __builtin_popcount(mask)) {
			int maks = 0;
			// pogledaj koji sve cvorovi su zakaceni
			for (int j=0; j<(n-h); j++) {
				// da li je?
				int c = 0;
				for (int i=0; i<h; i++) {
					if (mask & (1 << i)) {
						c += a[i][j+h];
					}
				}

				if (c == p[mask]) {
					maks |= 1 << j;
				}
			}

			// cerr << mask << ' ' << maks << ' ' << p[mask] << ' ' << q[maks] << '\n';

			sol = max(sol, p[mask] + q[maks]);
		}
	}

	double x = k * 1.0 / sol;
	double izlaz = x * x * sol * (sol-1) / 2;

	cerr << sol << '\n';

	cout.precision(20);
	cout << fixed << izlaz;
}