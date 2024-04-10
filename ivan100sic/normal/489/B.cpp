#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[105], b[105];
int dp[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	cin >> m;
	for (int i=1; i<=m; i++)
		cin >> b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if (abs(a[i] - b[j]) <= 1) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
			}
		}
	}
	cout << dp[n][m] << '\n';
}