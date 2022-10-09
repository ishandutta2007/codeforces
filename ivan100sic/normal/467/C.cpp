#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[5005], z[5005];
ll dp[5005][5005];
int n, k, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			if (i >= m)
				dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + z[i] - z[i-m]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][k] << '\n';
}