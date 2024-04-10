#include <unordered_map>
#include <unordered_set>
#include <functional>
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

const int MAXK = -1;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

const int INF = (int)1e9;

const int costs[6] = { 500, 1000, 1500, 2000, 2500, 3000 };

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		const int m = 5;
		vector<vector<int> > a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		vector<int> cnt(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != -1) cnt[j]++;
			}
		}

		int ans = INF;
		vector<int> cost(5, -1);
		auto calcScore = [&](int id) {
			int score = 0;
			for (int i = 0; i < 5; i++) {
				if (a[id][i] != -1) {
					score += cost[i] - cost[i] / 250 * a[id][i];
				}
			}
			return score;
		};
		// 10000 > MAX_N * 32
		for (int nw = 0; nw <= 5000; nw++) {
			int sc0 = 0, sc1 = 0;
			function<void(int)> rec = [&](int cur) {
				if (cur == 5) {
					//int sc0 = calcScore(0);
					//int sc1 = calcScore(1);
					if (sc0 > sc1) {
						ans = min(ans, nw);
					}
					return;
				}
				int pw = 1;
				for (int i = 0; i < 6; i++) {
					cost[cur] = costs[i];
					bool ok = 1;
					int mn, mx;
					if (i == 5) {
						mx = (n + nw) / pw - cnt[cur];
						mn = -cnt[cur];
					}
					else {
						// (cnt[cur] + x) / (n + nw) <= 1 / pw
						// pw * (cnt[cur] + x) <= (n + nw)
						// cnt[cur] + x <= (n + nw) / pw
						// x <= (n + nw) / pw - cnt[cur]


						// (cnt[cur] + x) / (n + nw) > 1 / (pw * 2)
						// (pw * 2) * (cnt[cur] + x) > (n + nw)
						// cnt[cur] + x > (n + nw) / (pw * 2)
						// x = (n + nw) / (pw * 2) - cnt[cur]

						mn = (n + nw) / (pw * 2) + 1 - cnt[cur];
						mx = (n + nw) / pw - cnt[cur];
					}
					mn = max(mn, 0);
					mx = min(mx, nw);
					ok = mn <= mx;
					ok &= a[0][cur] != -1 || mn == 0;
					if (ok) {
						if (a[0][cur] != -1) sc0 += cost[cur] - cost[cur] / 250 * a[0][cur];
						if (a[1][cur] != -1) sc1 += cost[cur] - cost[cur] / 250 * a[1][cur];
						rec(cur + 1);
						if (a[0][cur] != -1) sc0 -= cost[cur] - cost[cur] / 250 * a[0][cur];
						if (a[1][cur] != -1) sc1 -= cost[cur] - cost[cur] / 250 * a[1][cur];
					}
					pw *= 2;
				}
			};
			rec(0);
		}
		if (ans == INF) ans = -1;
		cout << ans << endl;
	}

	return 0;
}