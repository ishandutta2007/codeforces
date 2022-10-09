// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int g[72];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	memset(g, 192, sizeof g);
	g[0] = 0;

	int n, m, k;
	cin >> n >> m >> k;

	for (int i=0; i<n; i++) {

		int dp[72][72];
		memset(dp, 192, sizeof dp);
		for (int r=0; r<k; r++) {
			dp[0][r] = g[r];
		}

		for (int j=0; j<m; j++) {
			int x;
			cin >> x;
			for (int u=j; u>=0; u--) {
				for (int r=0, rx=x%k; r<k; r++) {
					mx(dp[u+1][rx], dp[u][r] + x);
					rx++;
					rx -= (rx == k) * k;
				}
			}
		}

		memset(g, 192, sizeof g);

		for (int u=0; u<=m/2; u++) {
			for (int r=0; r<k; r++) {
				mx(g[r], dp[u][r]);
			}
		}
	}

	cout << g[0] << '\n';
}