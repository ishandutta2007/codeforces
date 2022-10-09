// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll buff[56000000]; int used;

ll* nu(int sz) {
	ll* r = buff + used;
	used += sz;
	return r;
}

ll* d[1 << 14][14];
int a[14][14], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// ucitaj
	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<n; j++)
			a[i][j] = s[j] == '1';
	}

	// inicijalizuj
	for (int mask=1; mask<(1<<n); mask++) {
		for (int j=0; j<n; j++) {
			if (mask & (1 << j)) {
				d[mask][j] = nu(1 << (__builtin_popcount(mask) - 1));
			}
		}
	}

	for (int i=0; i<n; i++) {
		d[1 << i][i][0] = 1;
	}

	// odradi sve
	for (int mask=1; mask<(1<<n)-1; mask++) {
		int m = __builtin_popcount(mask) - 1;
		for (int i=0; i<n; i++) {
			if (!(mask & (1<<i)))
				continue;
			for (int j=0; j<n; j++) {
				if (mask & (1 << j))
					continue;

				for (int u=0; u<(1<<m); u++) {
					d[mask | (1 << j)][j][2*u + a[i][j]] += d[mask][i][u];
				}
			}
		}
	}

	// ocitaj sa kraja
	for (int u=0; u<(1<<(n-1)); u++) {
		ll t = 0;
		for (int k=0; k<n; k++) {
			t += d[(1<<n)-1][k][u];
		}
		cout << t << ' ';
	}
	cout << '\n';
}

// I will still practice daily...