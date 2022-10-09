#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, b, mod;
int a[505];
int d[2][505][505];

// d[i][j][k] <- sum_x d[i-1][j-x][k - a[i]*x]
// d[i][j][k] = d[i-1][j][k] + sum_x d[i-1][j-1-x][k - a[i] - a[i]*x]

void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> b >> mod;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	d[0][0][0] = 1;
	for (int i=1; i<=n; i++) {
		auto ol = d[(i+1) % 2];
		auto nu = d[i % 2];
		memset(nu, 0, sizeof(d[0]));
		for (int j=0; j<=m; j++) {
			for (int k=0; k<=b; k++) {
				ad(nu[j][k], ol[j][k]);
				if (j-1 >= 0 && k - a[i] >= 0)
					ad(nu[j][k], nu[j-1][k - a[i]]);
			}
		}
	}
	int sol = 0;
	for (int i=0; i<=b; i++)
		ad(sol, d[n%2][m][i]);

	cout << sol << '\n';
}