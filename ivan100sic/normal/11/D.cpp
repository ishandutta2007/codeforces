#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[19][19];

ull c, dp[524288][19];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		a[u][v] = a[v][u] = 1;
	}

	for (int k=n-1; k>=2; k--) {
		// pocinjem i zavrsavam u cvoru k
		for (int mask=0; mask<(1<<k); mask++)
			for (int j=0; j<=k; j++)
				dp[mask][j] = 0;

		dp[0][k] = 1;
		for (int mask=0; mask<(1<<k); mask++) {
			int pc = __builtin_popcount(mask);
			for (int j=0; j<=k; j++) {
				if (!dp[mask][j])
					continue;

				// backedge koji zatvara ciklus?
				if (pc > 1 && a[j][k])
					c += dp[mask][j];

				// nastavi produbljivanje
				for (int y=0; y<k; y++) {
					if (mask & (1 << y))
						continue;
					if (!a[j][y])
						continue;
					dp[mask | (1 << y)][y] += dp[mask][j];
				}
			}
		}
	}

	cout << c/2 << '\n';
}