#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int adj[14][14];

bool imaput[14][14][1 << 14];
int  preput[14][14][1 << 14];
bool imacyc[1 << 14];

basic_string<int> cyc[1 << 14];
basic_string<pair<int, int>> sol;

bitset<256> dp[1 << 14];

void addcyc(int j) {
	for (int i=0; i<(int)cyc[j].size(); i++) {
		sol += {cyc[j][i], cyc[j][(i+1) % cyc[j].size()]};
	}
}

bitset<256> napravi(int j) {
	bitset<256> z;
	for (int i=0; i<(int)cyc[j].size(); i++) {
		int x = cyc[j][i];
		int y = cyc[j][(i+1) % cyc[j].size()];
		if (x > y)
			swap(x, y);
		z[(x<<4)|y] = 1;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u][v] = adj[v][u] = 1;
	}

	for (int i=0; i<n; i++) {
		imaput[i][i][1 << i] = 1;
		preput[i][i][1 << i] = -1;
		for (int mask=0; mask<(1<<n); mask++) {
			for (int j=0; j<n; j++) {
				if (!imaput[i][j][mask])
					continue;
				for (int k=0; k<n; k++) {
					if (mask & (1 << k))
						continue;
					if (adj[j][k]) {
						imaput[i][k][mask | (1 << k)] = 1;
						preput[i][k][mask | (1 << k)] = j;
					}
				}
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == j)
				continue;
			for (int mask=0; mask<(1<<n); mask++) {
				if (imaput[i][j][mask] && adj[i][j] && __builtin_popcount(mask) > 2
					&& !imacyc[mask])
				{
					imacyc[mask] = 1;
					int t = j;
					int uuu = mask;
					while (t != i) {
						int tt = t;
						cyc[mask] += t;
						t = preput[i][t][uuu];
						uuu -= 1 << tt;
					}
					cyc[mask] += i;
				}
			}
		}
	}

	if (imacyc[(1 << n) - 1]) {
		addcyc((1 << n) - 1);
	} else {

		for (int mask=0; mask<(1<<n); mask++) {
			dp[mask].set();
		}
		dp[0].reset();

		basic_string<pair<int, bitset<256>>> ajde;
		for (int mask=0; mask<(1<<n); mask++) {
			if (imacyc[mask]) {
				ajde += {mask, napravi(mask)};
			}
		}

		for (int mask=0; mask<(1<<n); mask++) {
			for (auto [c, d] : ajde) {
				if ((c & mask) == 0 && mask)
					continue;
				if (dp[mask | c].count() > (dp[mask] | d).count()) {
					dp[mask | c] = dp[mask] | d;
				}
			}
		}

		for (int i=0; i<256; i++) {
			if (dp[(1<<n)-1][i]) {
				int x = i >> 4;
				int y = i & 15;
				sol += {x, y};
			}
		}
	}

	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x+1 << ' ' << y+1 << '\n';
}