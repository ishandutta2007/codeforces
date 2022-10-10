#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, c0, d0;
int a[15], b[15], c[15], d[15];

int dp[15][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> c0 >> d0;
	for (int i=1; i<=m; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i=1; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			// kuvam x komada
			for (int x=0; x<=a[i]/b[i]; x++) {
				if (j + x*c[i] > n)
					break;
				dp[i][j] = max(dp[i][j], dp[i-1][j + x*c[i]] + d[i]*x);
			}
		}
	}

	int sol = 0;
	for (int i=0; i<=n; i++)
		sol = max(sol, dp[m][i] + i / c0 * d0);
	cout << sol << '\n';
}