#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct robot {
	int l, e;
};

int n, m, q;
ll d[505][505][2], c[505][505], g[505];
basic_string<robot> h[505][505], v[505][505];

bool ok(int x) {
	return x >= 0 && (x & 3) == 0;
}

void mn(ll& x, ll y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	while (q--) {
		int x, y, d, t, e;
		cin >> x >> y >> d >> t >> e;
		bool k1 = ok(x+y-t);
		bool k2 = ok(x+y-t-1);
		bool k3 = ok(x+y+d-t-2);
		bool k4 = ok(x+y+d-t-3);
		if (k1) c[x][y] += e;
		if (k2) c[x+d][y-d] += e;
		if (k3) c[x+d][y] += e;
		if (k4) c[x][y+d] += e;
		if (k1 && k4) h[x][y] += {y+d, e};
		if (k2 && k3) h[x+d][y-d] += {y, e};
		if (k1 && k3) v[x][y] += {x+d, e};
	}

	memset(d, 63, sizeof(d));
	d[0][0][0] = d[0][0][1] = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			ll w = d[i][j][0];
			fill(g, g+m, 0);
			for (int k=j; k<m; k++) {
				w += (k > j)*c[i][k] - g[k];
				for (auto [l, e] : h[i][k])
					g[l] += e;
				if (k > j)
					mn(d[i][k][1], w);
			}
			w = d[i][j][1];
			fill(g, g+n, 0);
			for (int k=i; k<n; k++) {
				w += (k > i)*c[k][j] - g[k];
				for (auto [l, e] : v[k][j])
					g[l] += e;
				if (k > i)
					mn(d[k][j][0], w);
			}
		}
	}

	cout << min(d[n-1][m-1][0], d[n-1][m-1][1]) << '\n';
}