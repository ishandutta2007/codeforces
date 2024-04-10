#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int skip[1005][130][8];
// skip[i][l][x] = pozicija odmah posle l-tog pojavljivanja
// broja x u podnizu [i, ...]
int n;
int a[1005];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i]--;
	}
	// prvi sledeci
	{

		int p[8] = {n+1, n+1, n+1, n+1, n+1, n+1, n+1, n+1};

		// l = 0, svima dodeli samog sebe, sto mora da se uradi i za n+1

		for (int i=1; i<=n+1; i++) {
			for (int j=0; j<8; j++) {
				skip[i][0][j] = i;
			}
		}

		// l = 1, n+1 moras da dodelis 0, ostalima po zasluzi
		
		for (int i=n+1; i>=1; i--) {
			if (i <= n) {
				p[a[i]] = i;
			}
			for (int j=0; j<8; j++) {
				if (p[j] == n+1) {
					skip[i][1][j] = 0;
				} else {
					skip[i][1][j] = p[j]+1;
				}
			}
		}

		// sve ostale duzine (do n/8 je ok)
		// za n+1 ne diramo jer ce ionako da bude 0

		for (int l=2; l<=n/8+1; l++) {
			for (int i=1; i<=n; i++) {
				for (int j=0; j<8; j++) {
					int x = skip[i][l-1][j];
					if (x > n || x == 0) {
						skip[i][l][j] = 0;
					} else {
						skip[i][l][j] = skip[x][1][j];
					}
				}
			}
		}

		/*
		for (int l=0; l<=3; l++) {
			for (int i=1; i<=n; i++) {
				cerr << skip[i][l][0] << ' ';
			}
			cerr << '\n';
		}
		*/
	}

	// permutacije
	{
		int sol = 0;

		vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7};
		int pc = 40320;

		while (pc--) {
			int l = n/8;

			while (1) {
				// probaj
				int x = 1;
				for (int u : p) {
					x = skip[x][l][u];
				}
				if (x > 0 && x <= n+1) {
					// ok
					break;
				} else {
					l--;
				}
			}

			for (int mask=0; mask<256; mask++) {
				int lu[8], lut=0;
				for (int j=0; j<8; j++) {
					lu[j] = l + ((mask & (1<<j)) ? 1 : 0);
					lut += lu[j];
				}

				int x = 1;
				int i = 0;
				for (int u : p) {
					x = skip[x][lu[i]][u];
					i++;
				}

				if (x <= n+1 && x > 0) {
					sol = max(sol, lut);
				}

			}

			next_permutation(p.begin(), p.end());
		}

		cout << sol;
	}
}