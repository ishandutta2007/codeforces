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
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int INF = (int)(2.01e9);

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k, s, t;
	while (scanf("%d%d%d%d", &n, &k, &s, &t) == 4) {
		vector<pair<int, int> > a(n);
		for (int i = 0; i < n; i++) scanf("%d%d", &a[i].second, &a[i].first);
		vector<int> g(k);
		for (int i = 0; i < k; i++) scanf("%d", &g[i]);

		sort(g.begin(), g.end());
		sort(a.begin(), a.end());

		g.insert(g.begin(), 0);
		g.push_back(s);

		int mn = -1;
		for (int i = 1; i < (int)g.size(); i++) {
			mn = max(mn, g[i] - g[i - 1]);
		}
	
		vector<int> e;
		int d = 0;

		int curTime = 0;
		for (int i = 1; i < (int)g.size(); i++) {
			int cur = g[i] - g[i - 1];
			curTime += cur * 2;
			curTime -= min(mn - cur, cur);
			if (cur * 2 > mn) {
				d++;
				e.push_back(cur * 2);
			}
		}
		sort(e.begin(), e.end());
		int j = 0;

		int ans = INF;
		int last = mn;
		for (int i = 0; i < n; i++) {
			if (a[i].first < mn) continue;
			while (j < (int)e.size() && a[i].first >= e[j]) {
				curTime -= (e[j] - last) * d;
				last = e[j];
				d--;
				j++;
			}
			curTime -= (a[i].first - last) * d;
			last = a[i].first;
			if (curTime <= t) ans = min(ans, a[i].second);
		}
		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}

	return 0;
}