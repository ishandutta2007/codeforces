#include <cmath>
#include <cassert>
#include <ctime>
#include <memory.h>
#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;
 
typedef long long ll;
 
const int MAXK = 17;
const int MAXN = 1 << MAXK;
const int INF = 1e9;
int n, m;
vector<int> e[MAXN];
int p[MAXN][MAXK];
int h[MAXN];
int pr[MAXN];
bool used[MAXN];
int cnt[MAXN];
int ans[MAXN];

void dfs1(int v, int pr, int ch) {
	h[v] = ch;
	p[v][0] = pr;
	for (int i = 1; i < MAXK; i++) p[v][i] = p[p[v][i - 1]][i - 1];
	for (int i = 0; i < (int)e[v].size(); i++) if (e[v][i] != pr) dfs1(e[v][i], v, ch + 1);
}

int dfs2(int v, int pr) {
	cnt[v] = 1;
	for (int i = 0; i < (int)e[v].size(); i++) if (e[v][i] != pr && !used[e[v][i]]) cnt[v] += dfs2(e[v][i], v);
	return cnt[v];
}

void split(int v, int p) {
	int sz = dfs2(v, v);
	int last = v;
	while (1) {
		bool end = 1;
		for (int i = 0; i < (int)e[v].size(); i++) {
			if (!used[e[v][i]] && cnt[e[v][i]] * 2 >= sz && e[v][i] != last) {
				last = v;
				v = e[v][i];
				end = 0;
				break;
			}
		}
		if (end) break;
	}
	pr[v] = p;
	used[v] = 1;
	for (int i = 0; i < (int)e[v].size(); i++) if (!used[e[v][i]]) split(e[v][i], v);
}

int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	for (int i = 0; i < MAXK; i++) if ((h[u] - h[v]) & (1 << i)) u = p[u][i];
	if (u == v) return u;
	for (int i = MAXK - 1; i >= 0; i--) {
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}

int dist(int u, int v) {
	int w = lca(u, v);
	return h[u] + h[v] - 2 * h[w];
}

void upd(int v) {
	int u = v;
	while (u != -1) {
		ans[u] = min(ans[u], dist(u, v));
		u = pr[u];
	}
}

int get(int v) {
	int u = v;
	int res = INF;
	while (u != -1) {
		res = min(res, ans[u] + dist(u, v));
		u = pr[u];
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
	memset(ans, 63, sizeof(ans));
    scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 1, 0);
	split(1, -1);

	upd(1);
	for (int i = 0; i < m; i++) {
		int t, v;
		scanf("%d%d", &t, &v);
		if (t == 1) {
			upd(v);
		}
		if (t == 2) {
			printf("%d\n", get(v));
		}
	}
 
    return 0;
}