#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a[5005];
int dp[5005][5005];
int p[5005][5005], q[5005][5005];

// k < j
// dp[i][j] <- dp[i-1][k] + (j-k) + (j < a[i])
// (dp[i-1][k] - k) + j + (j < a[i])

// k = j trivijalno

// k > j
// dp[i][j] <- dp[i-1][k] + (j < a[i])

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	memset(p, 1, sizeof(p));
	memset(q, 1, sizeof(q));
	memset(dp, 1, sizeof(dp));

	dp[0][0] = p[0][0] = q[0][0] = 0;
	for (int i=1; i<=n+1; i++)
		p[0][i] = 0;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=min(n, a[i]); j++) {
			dp[i][j] = min(dp[i][j], p[i-1][j] + j + (j < a[i]));
			dp[i][j] = min(dp[i][j], q[i-1][j+1] + (j < a[i]));
		}
		p[i][0] = dp[i][0];
		for (int j=1; j<=n+1; j++)
			p[i][j] = min(p[i][j-1], dp[i][j] - j);
		q[i][n+1] = dp[i][n+1];
		for (int j=n; j>=0; j--)
			q[i][j] = min(q[i][j+1], dp[i][j]);
	}
	int sol = n;
	for (int j=0; j<=n; j++)
		sol = min(sol, dp[n][j]);
	cout << sol << '\n';
}