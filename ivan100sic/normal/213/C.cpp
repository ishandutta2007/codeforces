// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[305][305];

// dist, rowi, rowj
int dp[2][305][305];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}

	memset(dp, 192, sizeof dp);
	dp[0][0][0] = a[0][0];

	for (int i=0; i<2*n-2; i++) {

		auto ol = dp[i%2];
		auto nu = dp[1-i%2];

		memset(nu, 192, sizeof dp[0]);

		for (int j=0; j<n && j<=i; j++) {
			for (int k=0; k<n && k<=i; k++) {

				int w = ol[j][k];

				for (int u=0; u<2; u++) {
					for (int v=0; v<2; v++) {
						int j2 = j+u;
						int k2 = k+v;
						if (j2 >= n || k2 >= n) continue;

						int p2 = i+1-j2;
						int q2 = i+1-k2;
						if (p2 >= n || q2 >= n) continue;

						if (tie(j2, p2) == tie(k2, q2)) {
							mx(nu[j2][k2], w + a[j2][p2]);
						} else {
							mx(nu[j2][k2], w + a[j2][p2] + a[k2][q2]);
						}
					}
				}

			}
		}
	}

	cout << dp[0][n-1][n-1] << '\n';
}