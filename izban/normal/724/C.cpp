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



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	bool first = 1;
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		if (first) first = 0;
		else printf("\n");

		vector<pair<int, int> > a(k);
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}

		// diag1: 0<=x+y<=n+m
		// diag2: -m<=x-y<=n

		vector<ll> ans(k, -1);

		vector<vector<int> > radars1(n + m + 1);
		vector<vector<int> > radars2(n + m + 1);

		for (int i = 0; i < k; i++) {
			int x = a[i].first, y = a[i].second;
			radars1[x + y].push_back(i);
			radars2[x - y + m].push_back(i);
		}

		int x = 0, y = 0;
		int curDiag = 2;
		ll cdist = 0;
		while (1) {
			if (curDiag == 1) {
				for (int id : radars1[x + y]) {
					ll dist = cdist + (abs(x - a[id].first) + abs(y - a[id].second)) / 2;
					if (ans[id] == -1 || ans[id] > dist) ans[id] = dist;
				}
			}
			else {
				for (int id : radars2[x - y + m]) {
					ll dist = cdist + (abs(x - a[id].first) + abs(y - a[id].second)) / 2;
					if (ans[id] == -1 || ans[id] > dist) ans[id] = dist;
				}
			}

			int nx, ny;
			if (curDiag == 1) {
				if (y == 0 || x == n) {
					int t = min(x, m - y);
					nx = x - t;
					ny = y + t;
				}
				else {
					int t = min(y, n - x);
					nx = x + t;
					ny = y - t;
				}
			}
			else {
				if (x == 0 || y == 0) {
					int t = min(n - x, m - y);
					nx = x + t;
					ny = y + t;
				}
				else {
					int t = min(x, y);
					nx = x - t;
					ny = y - t;
				}
			}
			
			cdist += (abs(x - nx) + abs(y - ny)) / 2;
			x = nx;
			y = ny;
			curDiag = 3 - curDiag;
			if (x == 0 && y == 0 || x == 0 && y == m || x == n && y == 0 || x == n && y == m) break;
		}

		for (int i = 0; i < k; i++) printf("%I64d\n", ans[i]);
	}

	return 0;
}