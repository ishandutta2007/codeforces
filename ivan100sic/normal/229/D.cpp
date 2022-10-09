// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int z[5005];

int dp[5005][5005], ft[5005][5005];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		z[i+1] = z[i] + x;
	}

	memset(dp, 224, sizeof dp);
	memset(ft, 224, sizeof ft);
	dp[0][0] = 0;
	for (int i=1; i<=n; i++) {
		dp[0][i] = 1;
	}

	for (int r=1; r<=n; r++) {
		int d = r;

		for (int l=0; l<r; l++) {
			mx(ft[l][r], ft[l][r-1]);
			mx(dp[l][r], ft[l][r]);
		}

		for (int l=r-1; l>=0; l--) {
			while (d <= n && z[d] - z[r] < z[r] - z[l]) {
				d++;
			}

			if (d <= n) {
				mx(ft[r][d], dp[l][r] + 1);
			}
		}
	}

	int sol = 0;
	for (int l=0; l<n; l++) {
		mx(sol, dp[l][n]);
	}
	cout << n - sol << '\n';
}