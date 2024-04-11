#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, w[1005], b[1005], dp[2][1005][1005];
char c;
//0w1b
int f(bool c, int pos, int ln) {
	if (pos >= m)
		return 1000000000 * (ln < x);
	if (dp[c][pos][ln] != -1)
		return dp[c][pos][ln];
	dp[c][pos][ln] = 1000000000;
	if (c) {
		if (ln < x) {
			dp[c][pos][ln] = w[pos] + f(c, pos + 1, ln + 1);
			return dp[c][pos][ln];
		}
		if (ln < y) {
			dp[c][pos][ln] = min(w[pos] + f(c, pos + 1, ln + 1),
					b[pos] + f(!c, pos + 1, 1));
			return dp[c][pos][ln];
		}
		dp[c][pos][ln] = b[pos] + f(!c, pos + 1, 1);
		return dp[c][pos][ln];
	}
	if (ln < x) {
		dp[c][pos][ln] = b[pos] + f(c, pos + 1, ln + 1);
		return dp[c][pos][ln];
	}
	if (ln < y) {
		dp[c][pos][ln] = min(b[pos] + f(c, pos + 1, ln + 1),
				w[pos] + f(!c, pos + 1, 1));
		return dp[c][pos][ln];
	}
	dp[c][pos][ln] = w[pos] + f(!c, pos + 1, 1);
	return dp[c][pos][ln];

}

int main() {
	memset(w, 0, sizeof w);
	memset(b, 0, sizeof b);
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> x >> y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '.')
				w[j]++;
			else
				b[j]++;
		}
	}

	cout << min(f(0, 0, 0), f(1, 0, 0));

	return 0;
}