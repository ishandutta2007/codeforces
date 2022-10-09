// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[205];
int dp[605][205];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a, a+n);
		memset(dp, 63, sizeof dp);
		dp[0][0] = 0;
		for (int i=0; i<604; i++) {
			for (int j=0; j<=n; j++) {
				mn(dp[i+1][j], dp[i][j]);
				if (j < n) {
					mn(dp[i+1][j+1], dp[i][j] + abs(i+1-a[j]));
				}
			}
		}

		cout << dp[604][n] << '\n';
	}
}