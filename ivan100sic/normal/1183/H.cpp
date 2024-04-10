#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void ad(ll& x, ll y) {
	x = min(x+y, ll(1e13));
}

int n;
string s;
ll t, dp[105][105][27];
ll z[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t >> s;
	s = string(" ") + s;

	dp[0][0][26] = 1;
	for (int i=1; i<=n; i++) {
		dp[i][0][26] = 1;
		for (int j=1; j<=i; j++) {
			ll suma = 0;
			for (int k=0; k<27; k++) {
				suma += dp[i-1][j-1][k];
			}
			for (int k=0; k<27; k++) {
				ad(dp[i][j][k], dp[i-1][j][k]);
				if (k == s[i] - 'a') {
					ad(dp[i][j][k], suma - dp[i-1][j][k]);
				}
			}
		}
	}

	for (int j=1; j<=n; j++)
		for (int k=0; k<27; k++)
			ad(z[j], dp[n][j][k]);
	z[0] = 1;

	// for (int j=0; j<=n; j++)
	// 	cerr << j << ": " << z[j] << '\n';

	ll cost = 0;
	for (int j=n; j>=0; j--) {
		ll delta = min(t, z[j]);
		cost += (n-j) * delta;
		t -= delta;
	}

	if (t)
		cost = -1;
	cout << cost << '\n';
}