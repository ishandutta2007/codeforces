#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = 1 << 18;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const double INF = 1e20;

int n, k;
int t[MAXN];
double g[MAXN], st[MAXN], srt[MAXN];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &k) == 2) {
		vector<int> t(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &t[i]);
		}
		g[0] = st[0] = srt[0] = 0;
		for (int i = 1; i <= n; i++) {
			st[i] = st[i - 1] + t[i - 1];
			srt[i] = srt[i - 1] + 1.0 / t[i - 1];
			g[i] = g[i - 1] + st[i - 1] / t[i - 1];
		}

		vector<vector<pair<double, double> > > dp(k + 1);
		vector<vector<pair<double, double> > > line(k + 1);
		dp[0].push_back(make_pair(-INF, 0));
		line[0].push_back(make_pair(0, 0));
		/*for (int i = 1; i <= k; i++) {
			dp[i].push_back(make_pair(0, INF));
			line[i].push_back(make_pair(0, INF));
		}*/

		vector<vector<double> > valdp(n + 1, vector<double>(k + 1, -1));
		for (int i = 0; i <= n; i++) {
			for (int j = min(k, i); j >= (i ? 1 : 0); j--) {
				double cx = srt[i];
				int id = upper_bound(dp[j].begin(), dp[j].end(), make_pair(cx, -INF)) - dp[j].begin();
				//valdp[i][j] = dp[j][id - 1].second + (cx - dp[j][id - 1].first) / (dp[j][id].first - dp[j][id - 1].first) * (dp[j][id].second - dp[j][id - 1].second);
				valdp[i][j] = line[j][id - 1].first * cx + line[j][id - 1].second;
				valdp[i][j] += g[i];

				if (i == n || j == k) continue;

				double k = -st[i];
				double b = valdp[i][j] + -g[i] + k * -srt[i];
				while (!dp[j + 1].empty()) {
					double tx = dp[j + 1][(int)dp[j + 1].size() - 1].first;
					double ty = dp[j + 1][(int)dp[j + 1].size() - 1].second;
					double cy = k * tx + b;
					if (ty >= cy) {
						dp[j + 1].pop_back();
						line[j + 1].pop_back();
						continue;
					}
					else {
						double nx = (b - line[j + 1].back().second) / (line[j + 1].back().first - k);
						double ny = k * nx + b;
						dp[j + 1].push_back(make_pair(nx, ny));
						line[j + 1].push_back(make_pair(k, b));
						break;
					}
				}
				if (dp[j + 1].empty()) {
					double nx = -INF;
					double ny = k * nx + b;
					dp[j + 1].push_back(make_pair(nx, ny));
					line[j + 1].push_back(make_pair(k, b));
				}
			}
		}
		printf("%.15f\n", valdp[n][k] + n);
	}

	return 0;
}