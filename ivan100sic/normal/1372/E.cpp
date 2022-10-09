// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

/*
I peeked the editorial. Shame on me.

I was really pissed off today for some reason and I just didn't have the nerves
to play with this problem anymore.
*/

int n, m, sol;
int d[105][105]; // last x, used r
int z[105][105];

int sq(int x) { return x*x; }

void ad(int l, int r) {
	z[l][r]++;
}

int cnt(int l, int r, int u, int v) {
	l = max(l, 1);
	u = max(u, 1);
	r = min(r, n);
	v = min(v, n);
	if (l > r || u > v) return 0;
	l--;
	u--;
	return z[l][u] + z[r][v] - z[l][v] - z[r][u];
}

int cnt(int l, int r, int x) {
	return cnt(l, x, x, r);
}

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int l, r;
			cin >> l >> r;
			ad(l, r);
		}
	}

	n = m;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			z[i][j] += z[i-1][j] + z[i][j-1] - z[i-1][j-1];
		}
	}

	for (int l=n; l>=1; l--) {
		for (int r=l; r<=n; r++) {
			for (int x=l; x<=r; x++) {
				int v = cnt(l, r, x);
				v *= v;
				if (l < x) v += d[l][x-1];
				if (x < r) v += d[x+1][r];
				mx(d[l][r], v);
			}
		}
	}

	cout << d[1][n] << '\n';
}