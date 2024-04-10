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
const int MAXN = 1 << 17;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n;
vector<int> e[MAXN];
int c[MAXN];

int dfs(int v, int pr) {
	int cur = -2;
	for (int to : e[v]) {
		if (to == pr) continue;
		int x = dfs(to, v);
		if (pr == -1) {
			if (x == -1) cur = -1;
		}
		else {
			if (cur == -2 || cur == x) cur = x;
			else cur = -1;
		}
	}
	if (pr != -1) {
		if (cur == -2) cur = c[v];
		else if (cur != c[v]) cur = -1;
	}
	return cur;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) e[i].clear();

		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int i = 0; i < n; i++) scanf("%d", &c[i]);

		vector<int> vct;
		for (int i = 0; i < n; i++) {
			for (int to : e[i]) {
				if (c[i] != c[to]) {
					vct.push_back(i);
					vct.push_back(to);
					break;
				}
			}
			if (!vct.empty()) break;
		}
		if (vct.empty()) {
			printf("YES\n%d\n", 1);
			continue;
		}
		int ans = -1;
		for (int i = 0; i < (int)vct.size(); i++) {
			int x = dfs(vct[i], -1);
			if (x != -1) {
				ans = vct[i] + 1;
			}
		}
		if (ans == -1) {
			printf("NO\n");
		}
		else {
			printf("YES\n%d\n", ans);
		}
	}

	return 0;
}