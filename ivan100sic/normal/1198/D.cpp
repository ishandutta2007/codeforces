#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s[55];
int z[55][55];
int dp[55][55][55][55];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			z[i+1][j+1] = s[i][j] == '#';
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			z[i][j] += z[i-1][j];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			z[i][j] += z[i][j-1];

	for (int p=n-1; p>=0; p--) {
		for (int q=p+1; q<=n; q++) {
			for (int r=n-1; r>=0; r--) {
				for (int s=r+1; s<=n; s++) {
					if (z[p][r] + z[q][s] - z[p][s] - z[q][r] == 0) {
						dp[p][q][r][s] = 0;
					} else if (q-p == 1 && s-r == 1) {
						dp[p][q][r][s] = 1;
					} else {
						dp[p][q][r][s] = max(q-p, s-r);
						for (int i=p+1; i<q; i++)
							mn(dp[p][q][r][s], dp[p][i][r][s] + dp[i][q][r][s]);
						for (int j=r+1; j<s; j++)
							mn(dp[p][q][r][s], dp[p][q][r][j] + dp[p][q][j][s]);
					}
				}
			}
		}
	}
	cout << dp[0][n][0][n] << '\n';
}