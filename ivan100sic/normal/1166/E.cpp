#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bitset<10016> a[50], full;
int m, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> n;
	for (int i=0; i<n; i++)
		full[i] = 1;
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		while (x--) {
			int y;
			cin >> y;
			y--;
			a[i][y] = 1;
		}
	}

	// pravilo koje dovodi do kontradikcije?
	for (int i=0; i<m; i++) {
		auto w = ~a[i];
		// ako napravim da w sadrzi a[i] to puca
		for (int j=0; j<m; j++) {
			for (int k=0; k<m; k++) {
				if ((w & a[k]) == a[k]) {
					w = (w ^ a[k]) | (full ^ a[k]);
				}
			}
		}
		if ((w & a[i]) == a[i]) {
			cout << "impossible\n";
			return 0;
		}
	}
	cout << "possible\n";
}