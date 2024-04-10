#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
ll a[55], z[55];

bool dp[55][55];

bool moze(ll x) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			for (int l=0; l<i; l++) {
				dp[i][j] |= dp[l][j-1] && (((z[i] - z[l]) & x) == x);
			}
		}
	}
	return dp[n][k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}

	ll sol = 0;
	for (int i=60; i>=0; i--) {
		if (moze(sol | (1ll << i))) {
			sol |= 1ll << i;
		}
	}
	cout << sol << '\n';
}