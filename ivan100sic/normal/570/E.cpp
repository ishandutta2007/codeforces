#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1'000'000'007;

int n, m;
string s[505];
int dp[2][505][505];

void ad(int& x, int y) {
	x += y;
	if (x >= M)
		x -= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	n--;
	m--;
	for (int i=0; i<=n; i++)
		cin >> s[i];

	if ((n+m)%2 == 0) {
		for (int i=0; i<=n; i++) {
			int j = (n+m)/2 - i;
			if (j < 0 || j > m)
				continue;
			ad(dp[0][i][i], 1);
		}
	} else {
		for (int i=0; i<=n; i++) {
			int j = (n+m)/2 - i;
			if (j < 0 || j > m)
				continue;
			for (int u=0; u<=n; u++) {
				int v = (n+m)/2 + 1 - u;
				if (v < 0 || v > m)
					continue;
				if (i>u || j>v)
					continue;
				if (s[i][j] == s[u][v]) {
					ad(dp[0][i][u], 1);
				}				
			}
		}
	}

	auto ol = dp[0];
	auto nu = dp[1];

	for (int diag=(n+m)/2; diag>=1; diag--) {
		memset(nu, 0, sizeof(dp[0]));
		for (int i=0; i<=n; i++) {
			int j = diag - i;
			if (j < 0 || j > m)
				continue;
			for (int u=0; u<=n; u++) {
				int v = (n+m-diag) - u;
				if (v < 0 || v > m)
					continue;

				if (ol[i][u] == 0)
					continue;
				
				while (1) {
					int di = -1, dj = 0, du = +1, dv = 0;
					int ii = i + di;
					int jj = j + dj;
					int uu = u + du;
					int vv = v + dv;
					if (ii < 0 || ii > n) break;
					if (jj < 0 || jj > m) break;
					if (uu < 0 || uu > n) break;
					if (vv < 0 || vv > m) break;
					if (s[ii][jj] != s[uu][vv]) break;
					ad(nu[ii][uu], ol[i][u]);
					break;
				}

				while (1) {
					int di = 0, dj = -1, du = +1, dv = 0;
					int ii = i + di;
					int jj = j + dj;
					int uu = u + du;
					int vv = v + dv;
					if (ii < 0 || ii > n) break;
					if (jj < 0 || jj > m) break;
					if (uu < 0 || uu > n) break;
					if (vv < 0 || vv > m) break;
					if (s[ii][jj] != s[uu][vv]) break;
					ad(nu[ii][uu], ol[i][u]);
					break;
				}

				while (1) {
					int di = -1, dj = 0, du = 0, dv = +1;
					int ii = i + di;
					int jj = j + dj;
					int uu = u + du;
					int vv = v + dv;
					if (ii < 0 || ii > n) break;
					if (jj < 0 || jj > m) break;
					if (uu < 0 || uu > n) break;
					if (vv < 0 || vv > m) break;
					if (s[ii][jj] != s[uu][vv]) break;
					ad(nu[ii][uu], ol[i][u]);
					break;
				}

				while (1) {
					int di = 0, dj = -1, du = 0, dv = +1;
					int ii = i + di;
					int jj = j + dj;
					int uu = u + du;
					int vv = v + dv;
					if (ii < 0 || ii > n) break;
					if (jj < 0 || jj > m) break;
					if (uu < 0 || uu > n) break;
					if (vv < 0 || vv > m) break;
					if (s[ii][jj] != s[uu][vv]) break;
					ad(nu[ii][uu], ol[i][u]);
					break;
				}
			}
		}

		swap(nu, ol);
	}

	cout << ol[0][n] << '\n';
}