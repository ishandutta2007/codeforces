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

const double eps = 1e-9;

const int MAXN = 1 << 17;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, m;
vector<pair<int, int> > edges[2];
int p[MAXN];
vector<int> e[MAXN];
int c[MAXN];

int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}

bool dfs(int v, int cc) {
	if (c[v] != -1) {
		return cc == c[v];
	}
	c[v] = cc;
	bool ok = 1;
	for (int i = 0; i < (int)e[v].size(); i++) {
		ok &= dfs(e[v][i], cc ^ 1);
	}
	return ok;
}

int bin(int a, int n) {
	if (n == 0) return 1 % MOD;
	int res = bin(a, n / 2);
	res = 1LL * res * res % MOD;
	if (n % 2) res = 1LL * res * a % MOD;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &m) == 2) {
		edges[0].clear();
		edges[1].clear();
		for (int i = 0; i < n; i++) p[i] = i;
		for (int i = 0; i < n; i++) e[i].clear();
		for (int i = 0; i < n; i++) c[i] = -1;

		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			edges[w ^ 1].push_back(make_pair(--u, --v));
		}

		for (int i = 0; i < (int)edges[0].size(); i++) {
			p[get(edges[0][i].second)] = get(edges[0][i].first);
		}

		bool bad = 0;
		for (int i = 0; i < (int)edges[1].size(); i++) {
			if (get(edges[1][i].first) == get(edges[1][i].second)) {
				bad = 0;
			}
			e[get(edges[1][i].first)].push_back(get(edges[1][i].second));
			e[get(edges[1][i].second)].push_back(get(edges[1][i].first));
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (c[i] != -1 || get(i) != i) continue;
			bad |= !dfs(i, 0);
			cnt++;
		}

		int ans = bin(2, cnt - 1);
		if (bad) ans = 0;
		cout << ans << endl;
	}

	return 0;
}