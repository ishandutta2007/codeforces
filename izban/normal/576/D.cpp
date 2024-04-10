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
#include <bitset>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = 192;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int K = 4;
const int INF = 1000 * 1000 * 1000 + 7;

struct edge {
	int u, v, d;

	bool operator< (const edge &e) const {
		return d < e.d;
	}
};

int n, m;
edge e[MAXN];
vector<int> g[MAXN];
bitset<MAXN> can[K * MAXN * MAXN];
bitset<MAXN> can2[K * MAXN * MAXN + 1];
bitset<MAXN> ee[MAXN];

bool stupid() {
	for (int i = 0; i < K * n * n; i++) can[i].reset();

	for (int i = 0; i < n; i++) {
		ee[i].reset();
	}

	can[0][0] = 1;
	int cur = 0;
	for (int i = 0; i < K * n * n; i++) {
		while (cur < m && e[cur].d == i) {
			ee[e[cur].u][e[cur].v] = 1;
			cur++;
		}

		for (int j = 0; j < n; j++) if (can[i][j]) {
			can[i + 1] |= ee[j];
		}
	}

	for (int j = 0; j <= K * n * n; j++) {
		if (can[j][n - 1]) {
			printf("%d\n", j);
			return 1;
		}
	}
	return 0;
}

int mn[MAXN][MAXN][MAXN];


bool bfs(int mx) {
	vector<char> vis(n, 0);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int cmn = INF;
		for (int j = 1; j <= n; j++) cmn = min(cmn, mn[i][j][i]);
		if (cmn == INF) continue;
		int mn2 = -INF;
		for (int j = 0; j <= K * n * n; j++) if (can[j][i]) {
			mn2 = j;
			//break;
		}
		if (mn2 < cmn) continue;
		q.push(i);
		vis[i] = 1;
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < (int)g[v].size(); i++) {
			if (e[g[v][i]].d <= mx && !vis[e[g[v][i]].v]) {
				vis[e[g[v][i]].v] = 1;
				q.push(e[g[v][i]].v);
			}
		}
	}
	return vis[n - 1];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 0; i < n; i++) g[i].clear();

		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].d);
			e[i].u--;
			e[i].v--;
		}
		sort(e, e + m);
		for (int i = 0; i < m; i++) {
			g[e[i].u].push_back(i);
		}

		if (stupid()) continue;
		
		for (int i = 0; i <= K * n * n; i++) can2[i].reset();

		for (int i = 0; i < n; i++) {
			memset(mn[i], 63, sizeof(mn[i]));
			mn[i][0][i] = 0;
			for (int len = 0; len < n; len++) {
				for (int j = 0; j < n; j++) {
					if (mn[i][len][j] > INF) continue;
					for (int k = 0; k < (int)g[j].size(); k++) {
						edge &cur = e[g[j][k]];
						mn[i][len + 1][cur.v] = min(mn[i][len + 1][cur.v], max(mn[i][len][j], cur.d - len));
					}
				}
			}
		}

		int l = 0, r = INF;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (bfs(m)) r = m;
			else l = m;
		}

		if (r == INF) {
			printf("Impossible\n");
			continue;
		}

		int maxans = r + n;


		for (int i = 0; i < n; i++) {
			for (int len = 1; len <= n; len++) {
				if (mn[i][len][i] < INF) {
					for (int j = 0; j < K * n * n; j++) {
						if (can[j][i]) {
							int s = maxans;
							while ((s - j) % len) s--;
							while (maxans - s <= K * n * n && s >= j) {
								can2[K * n * n - (maxans - s)][i] = 1;
								s -= len;
							}
							break;
						}
					}
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) ee[i].reset();
		int cur = 0;
		while (cur < m && e[cur].d < maxans - K * n * n) {
			ee[e[cur].u][e[cur].v] = 1;
			cur++;
		}

		for (int i = 0; i < K * n * n; i++) {
			while (cur < m && e[cur].d == maxans - K * n * n + i) {
				ee[e[cur].u][e[cur].v] = 1;
				cur++;
			}

			for (int j = 0; j < n; j++) {
				if (can2[i][j]) {
					can2[i + 1] |= ee[j];
				}
			}
		}

		bool ok = 0;
		for (int j = 0; j <= K * n * n; j++) {
			if (can2[j][n - 1]) {
				ok = 1;
				printf("%d\n", maxans - K * n * n + j);
				break;
			}
		}
		assert(ok);
	}

	return 0;
}