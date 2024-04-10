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

const int MAXK = 20;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

int n, m;
vector<int> e[MAXN];
int deg[MAXN];
int vis[MAXN];
int need[MAXN];

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int to : e[v]) {
		dfs(to);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 0; i < n; i++) {
			e[i].clear();
			deg[i] = 0;
			vis[i] = 0;
			need[i] = 0;
		}
		int loop = 0, edges = 0;
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			need[u] = need[v] = 1;
			if (u == v) {
				loop++;
			}
			else {
				edges++;
				e[u].push_back(v);
				e[v].push_back(u);
			}
		}
		for (int i = 0; i < n; i++) {
			if (need[i]) {
				dfs(i);
				break;
			}
		}

		bool fail = 0;
		for (int i = 0; i < n; i++) {
			if (need[i] && !vis[i]) {
				fail = 1;
			}
		}

		ll ans = 0;
		ans += 1LL * loop * (loop - 1) / 2;
		ans += 1LL * loop * edges;
		for (int i = 0; i < n; i++) {
			ans += 1LL * (int)e[i].size() * ((int)e[i].size() - 1) / 2;
		}
		if (fail) ans = 0;
		cout << ans << endl;
	}

	return 0;
}