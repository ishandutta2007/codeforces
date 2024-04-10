#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a, b;
int n, m, k;
int dp[1005][1005][22];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> a >> b;
	a += '.';
	b += '@';
	memset(dp, 128, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			for (int s=0; s<=2*k; s++) {
				if (s & 1) {
					// nepar -> nepar ako su ista slova
					if (a[i] == b[j]) {
						mx(dp[i+1][j+1][s], dp[i][j][s] + 1);
					}
					// nepar -> par ako hoces da odustanes od zivota
					mx(dp[i][j][s+1], dp[i][j][s]);
				} else {
					// iz par u par, samo preskaci
					mx(dp[i+1][j][s], dp[i][j][s]);
					mx(dp[i][j+1][s], dp[i][j][s]);
					mx(dp[i+1][j+1][s], dp[i][j][s]);

					// iz par u nepar ako su ista slova
					if (a[i] == b[j] && s < 2*k) {
						mx(dp[i+1][j+1][s+1], dp[i][j][s] + 1);
					}
				}
			}
		}
	}
	cout << dp[n][m][2*k] << '\n';
}