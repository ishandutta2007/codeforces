#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool xortrie[75][524288];
int a[100005];

void dodaj(int x) {
	if (a[x])
		return;
	a[x] = 1;

	// dodaj u xortrie za svakog malog delioca

	for (int d=1; d<75; d++) {
		if (x % d != 0)
			continue;

		int nd = 1;

		xortrie[d][1] = 1;

		for (int i=16; i>=0; i--) {
			if (x & (1 << i))
				nd = 2*nd + 1;
			else
				nd = 2*nd;
			xortrie[d][nd] = 1;
		}
	}
}

int trie_seek(int d, int ub, int ksor, int i, int x, int xl, int xr) {

	// cerr << "II " << i << ' ' << x << ' ' << xl << ' ' << xr << '\n';

	if (xl > ub)
		// nothing for me here
		return -1;

	if (xortrie[d][x] == 0)
		return -1;

	if (i == 0) {
		return xl;
	}

	int xm = (xl + xr) >> 1;

	if (ksor & (1 << (i - 1))) {
		// prvo levo pa desno
		int rez = trie_seek(d, ub, ksor, i-1, 2*x, xl, xm);
		if (rez != -1)
			return rez;

		return trie_seek(d, ub, ksor, i-1, 2*x+1, xm+1, xr);
	} else {
		// kontra
		int rez = trie_seek(d, ub, ksor, i-1, 2*x+1, xm+1, xr);
		if (rez != -1)
			return rez;

		return trie_seek(d, ub, ksor, i-1, 2*x, xl, xm);
	}
}

int trie_seek(int d, int ub, int ksor) {
	return trie_seek(d, ub, ksor, 17, 1, 0, 131071);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			dodaj(x);
		} else {
			int x, k, s;
			cin >> x >> k >> s;

			if (x % k != 0) {
				cout << "-1\n";
				continue;
			}

			s -= x;

			int bestval = -1, bestnum = -1;

			if (k >= 75) { // ?
				for (int j=k; j<=s; j+=k) {
					if (a[j]) {
						if ((j ^ x) >= bestval) {
							bestval = j ^ x;
							bestnum = j;
						}
					}
				}
			} else {
				bestnum = trie_seek(k, s, x);
			}

			cout << bestnum << '\n';
		}
	}
}