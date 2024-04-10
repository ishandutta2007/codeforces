#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, q;
string a[2005];
int z[2005][2005];

ll resi(int x, int y) {
	int p = x % (2*n);
	int q = y % (2*m);
	ll s = z[p][q];
	if (__builtin_parity(x/(2*n) ^ y/(2*m)))
		s = p*q - s;
	return (x*1ll*y-p*q)/2 + s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i].resize(2*m);
		a[i+n].resize(2*m);
	}
	for (int i=0; i<2*n; i++) {
		for (int j=0; j<2*m; j++) {
			char b = a[i%n][j%m];
			int f = i/n^j/m;
			a[i][j] = b^f;
			z[i+1][j+1] = a[i][j] - '0';
		}
	}

	for (int i=1; i<=2*n; i++)
		for (int j=1; j<=2*m; j++)
			z[i][j] += z[i-1][j];
	for (int i=1; i<=2*n; i++)
		for (int j=1; j<=2*m; j++)
			z[i][j] += z[i][j-1];

	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		ll sol = 0;
		sol += resi(x1, y1);
		sol += resi(x2, y2);
		sol -= resi(x1, y2);
		sol -= resi(x2, y1);
		cout << sol << '\n';
	}
}