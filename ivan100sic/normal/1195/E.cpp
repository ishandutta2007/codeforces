#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[3005][3005], n, m, u, v;

int p[3005][3005], q[3005][3005], r[3005][3005], s[3005][3005];

int g0, x, y, z;

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> u >> v;
	cin >> g0 >> x >> y >> z;
	int g = g0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			a[i][j] = g;
			g = (g*1ll*x + y) % z;
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			p[i][j] = a[i][j];
			if (i%u)
				mn(p[i][j], p[i-1][j]);
			if (j%v)
				mn(p[i][j], p[i][j-1]);
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=m-1; j>=0; j--) {
			q[i][j] = a[i][j];
			if (i%u)
				mn(q[i][j], q[i-1][j]);
			if (j != m-1 && j%v != v-1)
				mn(q[i][j], q[i][j+1]);
		}
	}

	for (int i=n-1; i>=0; i--) {
		for (int j=0; j<m; j++) {
			r[i][j] = a[i][j];
			if (i != n-1 && i%u != u-1)
				mn(r[i][j], r[i+1][j]);
			if (j%v)
				mn(r[i][j], r[i][j-1]);
		}
	}

	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			s[i][j] = a[i][j];
			if (i != n-1 && i%u != u-1)
				mn(s[i][j], s[i+1][j]);
			if (j != m-1 && j%v != v-1)
				mn(s[i][j], s[i][j+1]);
		}
	}

	ll sol = 0;
	for (int i=0; i+u<=n; i++) {
		for (int j=0; j+v<=m; j++) {
			int x = i+u-1;
			int y = j+v-1;
			int z = min({p[x][y], q[x][j], r[i][y], s[i][j]});
			sol += z;
		}
	}

	cout << sol << '\n';
}