// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int d[2005][2005];
int n;
string a, b;
int za[2005][26], zb[2005][26];

bool valid() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<26; j++) {
			za[i+1][j] = za[i][j];
			zb[i+1][j] = zb[i][j];
		}
		za[i+1][a[i]-'a']++;
		zb[i+1][b[i]-'a']++;
	}

	for (int i=0; i<26; i++)
		if (za[n][i] != zb[n][i])
			return false;
	return true;
}

void mx(int& x, int y) {
	x = max(x, y);
}

bool excess(int i, int j) {
	for (int k=0; k<26; k++) {
		if (k == a[i] - 'a') {
			if (za[i][k] >= zb[j][k])
				return false;
		} else {
			if (za[i][k] > zb[j][k])
				return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				d[i][j] = -123123123;
		d[0][0] = 0;

		if (!valid()) {
			cout << "-1\n";
			continue;
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (a[i] == b[j]) {
					mx(d[i+1][j+1], d[i][j] + 1);
				}

				mx(d[i][j+1], d[i][j]);
				if (excess(i, j))
					mx(d[i+1][j], d[i][j]);
			}
		}

		int h = 0;
		for (int j=0; j<=n; j++)
			mx(h, d[j][n]);
		cout << n-h << '\n';
	}
}

// .XXX
//  abab
// baba

// ..X
//   abc
// cba
//

// xyaaaazt
// bbxyztbb