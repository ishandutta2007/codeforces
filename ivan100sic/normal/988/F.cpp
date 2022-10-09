#include <bits/stdc++.h>
using namespace std;

bool rain[2005];
int a, n, m;
long long p[2005];

long long dp11[2005][2005];
long long* dp[2005];

void mn(long long& x, long long y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> n >> m;
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		for (int j=l; j<r; j++)
			rain[j] = true;
	}

	fill(p, p+a+1, 123123123123123ll);

	for (int i=0; i<m; i++) {
		int x;
		long long w;
		cin >> x >> w;
		p[x] = min(p[x], w);
	}

	memset(dp11, 63, sizeof(dp11));

	for (int i=0; i<2005; i++)
		dp[i] = dp11[i] + 1;

	dp[0][-1] = 0;

	for (int i=0; i<a; i++) {
		for (int j=-1; j<=a; j++) {
			// ocu dalje
			if (rain[i]) {
				if (j != -1)
					mn(dp[i+1][j], dp[i][j] + p[j]);
				mn(dp[i+1][i], dp[i][j] + p[i]);
			} else {
				mn(dp[i+1][j], dp[i][j] + p[j]);
				mn(dp[i+1][i], dp[i][j] + p[i]);
				mn(dp[i+1][-1], dp[i][j]);
			}
		}
	}

	long long sol = *min_element(dp[a]-1, dp[a]+a+1);

	if (sol > 1e10)
		sol = -1;
	
	cout << sol;
}