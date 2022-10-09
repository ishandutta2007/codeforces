// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[205], b[205], c[205];
int d[205][205][205];
int p, q, r, s;

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> p >> q >> r;
	for (int i=0; i<p; i++) cin >> a[i];
	for (int i=0; i<q; i++) cin >> b[i];
	for (int i=0; i<r; i++) cin >> c[i];
	sort(a, a+p, greater<int>());
	sort(b, b+q, greater<int>());
	sort(c, c+r, greater<int>());
	memset(d, 224, sizeof d);
	d[0][0][0] = 0;
	for (int i=0; i<=p; i++) {
		for (int j=0; j<=q; j++) {
			for (int k=0; k<=r; k++) {
				int m = (i < p ? 1 :0) + (j < q ? 2 : 0) + (k < r ? 4 : 0);
				if (m & 3) mx(d[i+1][j+1][k], d[i][j][k] + a[i]*b[j]);
				if (m & 5) mx(d[i+1][j][k+1], d[i][j][k] + a[i]*c[k]);
				if (m & 6) mx(d[i][j+1][k+1], d[i][j][k] + b[j]*c[k]);
				mx(s, d[i][j][k]);
			}
		}
	}

	cout << s << '\n';
}