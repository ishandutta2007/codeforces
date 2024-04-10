#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, h;
int a[44][44];
int c[44];

void dfs(int x, bool& ok) {
	for (int y=0; y<n; y++) {
		if (a[x][y]) {
			if (c[y] == 0) {
				c[y] = 3 - c[x];
				dfs(y, ok);
			} else if (c[x] != 3 - c[y]) {
				ok = false;
			}
		}
	}
}

pair<bool, int> graf() {
	bool ok = true;
	memset(c, 0, sizeof(c));
	int cc = 0;
	for (int i=0; i<n; i++) {
		if (!c[i]) {
			cerr << "komp " << i+1 << '\n';
			cc++;
			c[i] = 1;
			dfs(i, ok);
		}
	}
	return {ok, cc};
}

int nbrs[22];
int d[1 << 20];

ll indsets() {
	memset(nbrs, 0, sizeof(nbrs));
	memset(d, 0, sizeof(d));
	for (int mask=0; mask<(1<<(n-h)); mask++) {
		bool ok = 1;
		for (int i=0; i<n-h; i++) {
			for (int j=0; j<n-h; j++) {
				if ((mask & (1 << i)) && (mask & (1 << j)) && a[i+h][j+h])
					ok = 0;
			}
		}
		d[mask] = ok;
	}

	for (int i=0; i<n-h; i++) {
		for (int mask=0; mask<(1<<(n-h)); mask++) {
			if (mask & (1 << i)) {
				d[mask] += d[mask - (1 << i)];
			}
		}
	}

	for (int i=0; i<h; i++) {
		for (int j=0; j<n-h; j++) {
			if (a[i][j+h]) {
				nbrs[i] |= 1 << j;
			}
		}
	}

	ll sol = 0;

	for (int mask=0; mask<(1<<h); mask++) {
		bool ok = 1;
		int ban = 0;
		for (int i=0; i<h; i++) {
			if (mask & (1 << i)) {
				for (int j=0; j<h; j++) {
					if ((mask & (1 << j)) && a[i][j])
						ok = 0;
				}
				ban |= nbrs[i];
			}
		}
		if (ok) {
			sol += d[(1<<(n-h))-1-ban];			
		}
	}

	cerr << "indset " << sol << '\n';
	return sol;
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
		x--, y--;
		a[x][y] = a[y][x] = 1;
	}

	h = n / 2;

	auto [bip, cc] = graf();
	int ls = 0;	
	for (int i=0; i<n; i++)
		if (count(a[i], a[i]+n, 1) == 0)
			ls++;

	cerr << "bip cc ls " << bip << ' ' << cc << ' ' << ls << '\n';

	ll sol = 0;
	sol += 2 * indsets();
	sol += 1ll << cc;

	sol -= 2ll << ls;
	if (bip) sol -= 1ll << cc;

	if (m == 0) sol += 1ll << n;

	cout << ((1ll << n) - sol) << '\n';
}