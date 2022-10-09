#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, x, z;
ll a[400005];

ll dp[400005][5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	for (int i=0; i<n; i++) {
		dp[i+1][0] = max(dp[i+1][0], dp[i][0] + 0);
		dp[i+1][1] = max(dp[i+1][1], dp[i][0] + a[i]);
		dp[i+1][2] = max(dp[i+1][2], dp[i][0] + x*a[i]);
		dp[i+1][3] = max(dp[i+1][3], dp[i][0] + a[i]);
		dp[i+1][4] = max(dp[i+1][4], dp[i][0] + 0);

		dp[i+1][1] = max(dp[i+1][1], dp[i][1] + a[i]);
		dp[i+1][2] = max(dp[i+1][2], dp[i][1] + x*a[i]);
		dp[i+1][3] = max(dp[i+1][3], dp[i][1] + a[i]);
		dp[i+1][4] = max(dp[i+1][4], dp[i][1] + 0);

		dp[i+1][2] = max(dp[i+1][2], dp[i][2] + x*a[i]);
		dp[i+1][3] = max(dp[i+1][3], dp[i][2] + a[i]);
		dp[i+1][4] = max(dp[i+1][4], dp[i][2] + 0);

		dp[i+1][3] = max(dp[i+1][3], dp[i][3] + a[i]);
		dp[i+1][4] = max(dp[i+1][4], dp[i][3] + 0);

		dp[i+1][4] = max(dp[i+1][4], dp[i][4] + 0);
	}

	cout << *max_element(dp[n], dp[n]+5) << "\n";
}