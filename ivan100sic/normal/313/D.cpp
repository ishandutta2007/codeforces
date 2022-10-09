#include <bits/stdc++.h>
using namespace std;

// take THAT! O(n^4)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
ll d[305][305], h[305];
int c[305][305];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(d, 63, sizeof d);
	memset(c, 63, sizeof c);

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		int l, r, v;
		cin >> l >> r >> v;
		c[l][r] = min(c[l][r], v);
	}

	d[0][0] = 0;

	for (int l=1; l<=n; l++) {

		memset(h, 63, sizeof h);
		for (int t=0; t<l; t++) {
			for (int f=0; f<=t; f++) {
				h[f] = min(h[f], d[t][f]);
			}
		}

		for (int r=l; r<=n; r++) {
			if (c[l][r] <= 1.01e9) {
				int v = c[l][r];

				for (int t=l; t<=r; t++) {
					for (int f=0; f<=t; f++) {
						int f2 = f + r-t;
						d[r][f2] = min(d[r][f2], d[t][f] + v);
					}
				}

				for (int f=0; f<=l; f++) {
					int f2 = f + (r-l+1);
					d[r][f2] = min(d[r][f2], h[f] + v);
				}
			}
		}
	}

	ll sol = 1e18;
	for (int r=0; r<=n; r++)
		for (int i=k; i<=n; i++)
			sol = min(sol, d[r][i]);
	if (sol > 1e17)
		sol = -1;
	cout << sol << '\n';
}