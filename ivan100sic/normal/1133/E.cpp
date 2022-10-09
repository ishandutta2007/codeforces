#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[5005], h[5005];
int dp[5005][5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);

	for (int i=1; i<=n; i++)
		h[i] = lower_bound(a+1, a+n+1, a[i]-5) - a;

	memset(dp, 254, sizeof(dp));
	dp[0][0] = 0;
	for (int i=1; i<=n; i++)
		dp[0][i] = 0;
	for (int i=1; i<=k; i++) {
		for (int j=1; j<=n; j++) {
			dp[i][j] = max(dp[i][j-1], dp[i-1][h[j]-1] + (j - (h[j]-1)));
		}
	}

	int z = 0;
	for (int i=1; i<=k; i++)
		z = max(z, dp[i][n]);

	cout << z << '\n';
}