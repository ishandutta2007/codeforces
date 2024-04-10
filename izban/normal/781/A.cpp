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
const int MAXN = 1 << 18;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

int n, k;
vector<int> e[MAXN];
int c[MAXN];
int last[MAXN], tmr;

void dfs(int v, int pr) {
	tmr++;
	if (pr != -1) last[c[pr]] = tmr;
	last[c[v]] = tmr;
	int cc = 0;

	for (int to : e[v]) {
		if (to == pr) continue;
		while (last[cc] == tmr) cc++;
		c[to] = cc;
		last[cc] = tmr;
	}
	
	for (int to : e[v]) {
		if (to == pr) continue;
		dfs(to, v);
	}
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
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int v = 0;
		for (int i = 0; i < n; i++) if (e[i].size() > e[v].size()) v = i;

		k = e[v].size() + 1;

		c[v] = 0;
		dfs(v, -1);
		printf("%d\n", k);
		for (int i = 0; i < n; i++) printf("%d%c", c[i] + 1, " \n"[i + 1 == n]);
	}

	return 0;
}