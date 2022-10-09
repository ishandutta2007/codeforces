#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[18][18], n, m, k;
int a[18];
ll dp[1 << 18][18];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	while (k--) {
		int x, y, z;
		cin >> x >> y >> z;
		c[x-1][y-1] = z;
	}

	// init
	for (int i=0; i<n; i++)
		dp[1 << i][i] = a[i];

	for (int mask=1; mask<(1<<n); mask++) {
		for (int i=0; i<n; i++) {
			if (mask & (1 << i)) {
				for (int j=0; j<n; j++) {
					if (!(mask & (1 << j))) {
						dp[mask | (1 << j)][j] = max(
							dp[mask | (1 << j)][j],
							dp[mask][i] + a[j] + c[i][j]);
					}
				}
			}
		}
	}

	ll z = 0;

	for (int mask=0; mask<(1 << n); mask++) {
		if (__builtin_popcount(mask) != m)
			continue;
		for (int i=0; i<n; i++)
			z = max(z, dp[mask][i]);
	}
	cout << z << '\n';
}