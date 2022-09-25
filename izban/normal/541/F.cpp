#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cmath>
#include <set>


using namespace std;

typedef long long ll;

const int maxt = 128;
const int maxn = 1024;

int n, T;
pair<int, int> a[maxn];
int dp[2][maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("task.in", "r", stdin);
#endif

	while (scanf("%d%d", &n, &T) == 2) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		sort(a, a + n);
		reverse(a, a + n);

		memset(dp, -1, sizeof(dp));
		dp[0][0][1] = 0;
		int ans = 0;
		for (int t = 0; t < T; t++) {
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j < maxn; j++) {
					if (dp[0][i][j] == -1) continue;
					ans = max(ans, dp[0][i][j]);
					dp[1][i][min(maxn - 1, j * 2)] = max(dp[1][i][min(maxn - 1, j * 2)], dp[0][i][j]);
					if (i < n) dp[0][i + 1][j] = max(dp[0][i + 1][j], dp[0][i][j]);
					if (i < n && j > 0 && t + a[i].first <= T) dp[0][i + 1][j - 1] = max(dp[0][i + 1][j - 1], dp[0][i][j] + a[i].second);
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < maxn; j++) {
					dp[0][i][j] = dp[1][i][j];
					dp[1][i][j] = -1;
				}
			}
		}
		for (int i = 0; i <= n; i++) for (int j = 0; j < maxn; j++) ans = max(ans, dp[0][i][j]);
		cout << ans << endl;
	}

	return 0;
}