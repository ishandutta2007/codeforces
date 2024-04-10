#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
			for (char& x : a[i])
				x = x == 'A';
		}
		// nista?
		int c = 0;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				c += a[i][j];
		if (c == 0) {
			cout << "MORTAL\n";
			continue;
		}

		// 0?
		if (c == n*m) {
			cout << "0\n";
			continue;
		}

		// 1 (postoji puna vrsta ili kolona na pocetku)
		c = 0;
		for (int i=0; i<n; i++)
			c += a[i][0];
		if (c == n) {
			cout << "1\n";
			continue;
		}

		c = 0;
		for (int i=0; i<n; i++)
			c += a[i][m-1];
		if (c == n) {
			cout << "1\n";
			continue;
		}

		c = 0;
		for (int j=0; j<m; j++)
			c += a[0][j];
		if (c == m) {
			cout << "1\n";
			continue;
		}

		c = 0;
		for (int j=0; j<m; j++)
			c += a[n-1][j];
		if (c == m) {
			cout << "1\n";
			continue;
		}

		// 2 (postoji puna vrsta ili kolona negde, ili cose)
		if (a[0][0] || a[n-1][0] || a[0][m-1] || a[n-1][m-1]) {
			cout << "2\n";
			continue;
		}

		c = 0;
		for (int i=0; i<n; i++) {
			int d = 0;
			for (int j=0; j<m; j++)
				d += a[i][j];
			c += d == m;
		}
		for (int j=0; j<m; j++) {
			int d = 0;
			for (int i=0; i<n; i++)
				d += a[i][j];
			c += d == n;
		}

		if (c) {
			cout << "2\n";
			continue;
		}

		// 3 (postoji polje uz ivicu)

		c = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (i == 0 || i == n-1 || j == 0 || j == m-1)
					c += a[i][j];
			}
		}

		if (c) {
			cout << "3\n";
		} else {
			cout << "4\n";
		}
	}
}