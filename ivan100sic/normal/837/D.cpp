#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
#include <cstring>
using namespace std;

int n, k;
int a[205], b[205];

int dp[2][205][6005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		long long x;
		cin >> x;

		while (x % 5 == 0) {
			x /= 5;
			a[i]++;
		}

		while (x % 2 == 0) {
			x /= 2;
			b[i]++;
		}

		// cerr << a[i] << ' ' << b[i] << '\n';
	}

	memset(dp, 128, sizeof(dp));
	dp[0][0][0] = 0;

	for (int i=1; i<=n; i++) {
		auto nu = dp[i%2];
		auto old = dp[1 - i%2];

		memcpy(nu, old, sizeof(dp[0]));

		// uzimamo
		for (int j=1; j<=k; j++) {
			for (int u=a[i]; u<=30*n; u++) {
				nu[j][u] = max(nu[j][u], b[i] + old[j-1][u - a[i]]);
			}
		}
	}

	int sol = 0;
	for (int u=0; u<=30*n; u++) {
		// cerr << u << ' ' << dp[n%2][k][u] << '\n';
		if (dp[k][u] < 0) {
			continue;
		}
		sol = max(sol, min(u, dp[n%2][k][u]));
	}

	cout << sol;



}