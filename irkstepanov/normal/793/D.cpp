#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9;
const int nmax = 85;

int dp[nmax][nmax][nmax][2];
vector<pii> g[nmax];

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	for (int i = 0; i < nmax; ++i) {
		for (int j = 0; j < nmax; ++j) {
			for (int k = 0; k < nmax; ++k) {
				dp[i][j][k][0] = dp[i][j][k][1] = inf;
			}
		}
	}

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n + 1; ++i) {
		for (int j = i; j <= n + 1; ++j) {
			dp[i][j][0][0] = dp[i][j][0][1] = 0;
		}
	}

	int m;
	cin >> m;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].pb({v, c});
	}
	for (int j = 1; j <= n; ++j) {
		g[0].pb({j, 0});
	}
	for (int i = 1; i <= n; ++i) {
		g[n + 1].pb({i, 0});
	}

	for (int t = 1; t <= k; ++t) {
		for (int i = 0; i <= n + 1; ++i) {
			for (int j = i + 1; j <= n + 1; ++j) {
				for (pii& p : g[i]) {
					if (p.first > i && p.first < j) {
						dp[i][j][t][0] = min(dp[i][j][t][0], min(dp[i][p.first][t - 1][1], dp[p.first][j][t - 1][0]) + p.second);
					}
				}
				for (pii& p : g[j]) {
					if (p.first < j && p.first > i) {
						dp[i][j][t][1] = min(dp[i][j][t][1], min(dp[p.first][j][t - 1][0], dp[i][p.first][t - 1][1]) + p.second);
					}
				}
			}
		}
	}

	int ans = min(dp[0][n + 1][k][0], dp[0][n + 1][k][1]);
	if (ans == inf) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}

}