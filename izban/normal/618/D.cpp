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
const double PHI = (sqrt(5.0) - 1) / 2.0;

int n, x, y;
vector<int> e[MAXN];
int cnt;

int dfs(int v, int p) {
	int sum = 0;
	for (int i = 0; i < (int)e[v].size(); i++) {
		int to = e[v][i];
		if (to == p) continue;
		sum += dfs(to, v);
	}
	if (sum == 0) sum = 1;
	if (sum == 1) return 1;
	cnt += sum - 1;
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d%d", &n, &x, &y) == 3) {
		for (int i = 0; i < n; i++) {
			e[i].clear();
		}

		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}

		if (x <= y) {
			cnt = 0;
			cnt += dfs(0, -1);
			int cntY = cnt - 1;
			int cntX = n - 1 - cntY;
			cout << 1LL * cntY * y + 1LL * cntX * x << endl;
		}
		else {
			if (n <= 9) {
				vector<int> p;
				for (int i = 0; i < n; i++) p.push_back(i);
				map<pair<int, int>, int> cost;
				for (int i = 0; i < n; i++) for (int j = 0; j < (int)e[i].size(); j++) cost[make_pair(i, e[i][j])] = x;
				for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j && !cost.count(make_pair(i, j))) cost[make_pair(i, j)] = y;
				ll ans = 8e18;
				do {
					ll curCost = 0;
					for (int i = 1; i < n; i++) curCost += cost[make_pair(p[i - 1], p[i])];
					ans = min(ans, curCost);
				} while (next_permutation(p.begin(), p.end()));
				cout << ans << endl;
			}
			else {
				bool hasBad = 0;
				for (int i = 0; i < n; i++) if (e[i].size() == n - 1) hasBad = 1;
				if (hasBad) cout << 1LL * y * (n - 2) + x << endl;
				else cout << 1LL * y * (n - 1) << endl;
			}
		}
	}

	return 0;
}