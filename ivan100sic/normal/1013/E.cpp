#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll dp[5005][5005][2];
int n;
int a[5005];

ll& mn(ll& x, ll y) {
	return x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	a[0] = a[n+1] = -123123123;

	memset(dp, 63, sizeof(dp));
	for (int i=0; i<=n+1; i++)
		dp[i][0][0] = 0;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			ll dpcost = i >= 3 ? dp[i-3][j-1][0] : (
				j == 1 ? 0 : 123123123123123123ll
			);

			mn(dp[i][j][1],
				max(0ll, a[i+1]-a[i]+1ll)
			  + max(0ll, a[i-1]-a[i]+1ll)
			  + dpcost
			);

			if (j == 1)
				mn(dp[i][j][1],
					max(0ll, a[i+1]-a[i]+1ll)
				  + max(0ll, a[i-1]-a[i]+1ll)
				);

			mn(dp[i][j][0], dp[i-1][j][0]);

			if (j > 1 && i >= 3) {
				ll ekstra = max(0,
					max(0, a[i-1]-a[i]+1) - max(0, a[i-1]-a[i-2]+1));
				mn(dp[i][j][1],
					max(0ll, a[i+1]-a[i]+1ll)
				  + ekstra
				  + dp[i-2][j-1][1]
				);
			}

			// eeee
			mn(dp[i][j][0], dp[i][j][1]);
		}
	}

	for (int i=1; i<=(n+1)/2; i++)
		cout << dp[n][i][0] << ' ';
	cout << '\n';
}