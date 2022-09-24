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

const int MAXK = 19;
const int MAXN = 1 << MAXK;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n;
vector<int> e[MAXN];
int vis[MAXN], tmr;
int sz[MAXN];
int can[MAXN];

void dfs1(int v) {
	vis[v] = tmr;
	sz[v] = 1;
	for (int to : e[v]) {
		if (vis[to] == tmr) continue;
		dfs1(to);
		sz[v] += sz[to];
	}
}

multiset<int> st;

void dfs2(int v, bool f) {
	vis[v] = tmr;
	if (f == 0) {
		st.erase(st.lower_bound(sz[v]));
	}
	else {
		st.insert(sz[v]);
	}
	for (int to : e[v]) {
		if (vis[to] == tmr) continue;
		dfs2(to, f);
	}
}

void dfs3(int v, int csz) {
	bool ok = 1;
	vis[v] = tmr;
	for (int to : e[v]) {
		if (vis[to] == tmr) continue;
		ok &= sz[to] * 2 <= n;
	}
	ok &= csz * 2 <= n;
	can[v] |= ok;

	// csz - x <= n / 2
	// x >= csz - n / 2
	auto it = st.lower_bound(csz - n / 2);
	if (it != st.end() && *it <= n / 2) {
		can[v] |= 1;
	}

	for (int to : e[v]) {
		if (vis[to] == tmr) continue;
		dfs3(to, csz + sz[v] - sz[to]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			e[i].clear();
			can[i] = 0;
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}

		tmr++;
		dfs1(0);
		int root = 0;
		int pr = -1;
		while (1) {
			bool f = 0;
			for (int to : e[root]) {
				if (to != pr && sz[to] * 2 >= n) {
					pr = root;
					root = to;
					f = 1;
					break;
				}
			}
			if (!f) break;
		}
		tmr++;
		dfs1(root);

		can[root] = 1;
		st.clear();
		for (int i = 0; i < n; i++) {
			if (i != root) {
				st.insert(sz[i]);
			}
		}

		for (int to : e[root]) {
			tmr++;
			vis[root] = tmr;
			dfs2(to, 0);

			st.insert(n - sz[to]);
			tmr++;
			vis[root] = tmr;
			dfs3(to, n - sz[to]);
			st.erase(st.lower_bound(n - sz[to]));

			tmr++;
			vis[root] = tmr;
			dfs2(to, 1);
		}

		for (int i = 0; i < n; i++) printf("%d%c", (int)can[i], " \n"[i + 1 == n]);
	}

	return 0;
}