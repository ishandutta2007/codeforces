#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>

using namespace std;

vector< vector< pair<int, int> > > g;
const int MX = 81;
int dp[MX][MX][MX][MX];
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int m;
	cin >> m;
	g.resize(n);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c; a--;
		b--;
		g[a].push_back({ b, c });
	}
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			for (int a = 0; a < MX; a++)
				for (int b = 0; b < MX; b++)
					dp[i][j][a][b] = INF;
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) 
			for (int pos = l; pos <= r; pos++)
			dp[l][r][0][pos] = 0;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i + len <= n; i++) {
			int l = i;
			int r = l + len - 1;
			for (int numb = 1; numb <= k; numb++) {
				for (int pos = l; pos <= r; pos++) {
					for (int i = 0; i < g[pos].size(); i++) {
						if (g[pos][i].first >= l && g[pos][i].first <= r) {
							if (pos > g[pos][i].first)
								dp[l][r][numb][pos] = min(dp[l][r][numb][pos], dp[l][pos - 1][numb - 1][g[pos][i].first] + g[pos][i].second);
							else 
								dp[l][r][numb][pos] = min(dp[l][r][numb][pos], dp[pos + 1][r][numb - 1][g[pos][i].first] + g[pos][i].second);
						}
					}
				}
			}
		}
	}
	

	int mn = INF;
	for (int j = 0; j < n; j++)
		mn = min(mn, dp[0][n - 1][k - 1][j]);
	if (mn == INF)
		cout << -1;
	else
		cout << mn;
	return 0;
}