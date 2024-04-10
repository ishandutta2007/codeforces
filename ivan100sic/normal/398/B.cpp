#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld d[2005][2005];
int n, m;

int r[2005], c[2005];

void solve() {
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			ld p = (ld)(n-i)*(n-j)/n/n;
			ld r = (ld)i*(n-j)/n/n;
			ld q = (ld)(n-i)*j/n/n;
			ld s = (ld)i*j/n/n;

			// d = 1 + p*d + qrs.blablabla

			ld vr = 0;

			if (j) vr += q * d[i][j-1];
			if (i) vr += r * d[i-1][j];
			if (i && j) vr += s * d[i-1][j-1];

			d[i][j] = (vr + 1) / (1 - p);
			if (i == 0 && j == 0)
				d[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		r[x-1] = 1;
		c[y-1] = 1;
	}

	solve();

	cout.precision(20);
	cout << fixed;
	cout << d[count(r, r+n, 0)][count(c, c+n, 0)];
}