#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, k, m;
vector<pair<int, int>> e[2005];
int u[2005], v[2005], w[2005];

int dp[2][82][82][82];
int sol = 1e9;

bool outside(int x, int y, int z) {
	if (x > y) {
		swap(x, y);
	}
	return z < x || z > y;
}

void sugg(int& x, int y) {
	x = min(x, y);
}

void solve() {
	memset(dp, 63, sizeof(dp));

	for (int i=1; i<=n; i++) {
		dp[1][i][1][n] = 0;
	}

	for (int j=1; j<k; j++) {

		auto ol = dp[j%2];
		auto nu = dp[1-j%2];

		memset(nu, 63, sizeof(dp[0]));

		for (int x=1; x<=n; x++) {
			for (int l=1; l<=x; l++) {
				for (int r=x; r<=n; r++) {
					if (ol[x][l][r] > 1e8) {
						continue;
					}

					for (auto p : e[x]) {
						int z = p.first;
						int w = p.second + ol[x][l][r];

						int nl=l, nr=r;

						if (z < l || z > r) {
							continue;
						}

						if (z > x) {
							nl = x+1;
						} else if (z < x) {
							nr = x-1;
						} else {
							continue;
						}

						sugg(nu[z][nl][nr], w);
					}
				}
			}
		}
	}

	for (int x=1; x<=n; x++) {
		for (int l=1; l<=x; l++) {
			for (int r=x; r<=n; r++) {
				sol = min(sol, dp[k%2][x][l][r]);
			}
		}
	}

	if (sol > 1e8) {
		sol = -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		e[u[i]].push_back({v[i], w[i]});
	}
	
	solve();

	cout << sol;
}