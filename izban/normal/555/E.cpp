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

const int MAXN = 1 << 18;

int n, m, q;
int u[MAXN], v[MAXN];
int s[MAXN], d[MAXN];
vector<int> e[MAXN];
vector<int> g[MAXN];
int tmr, in[MAXN], out[MAXN];
int c[MAXN], cc;
int used[MAXN];
bool ok = 1;
vector<pair<int, int> > events[MAXN];
char was[MAXN];

int go(int id, int x) {
	return x ^ u[id] ^ v[id];
}

void dfs1(int v, int pr) {
	in[v] = out[v] = tmr++;
	for (int i = 0; i < (int)e[v].size(); i++) {
		if (e[v][i] == pr) continue;
		int to = go(e[v][i], v);
		if (in[to] != -1) {
			out[v] = min(out[v], in[to]);
		} else {
			dfs1(to, e[v][i]);
			out[v] = min(out[v], out[to]);
		}
	}
}

void dfs2(int v, int cur) {
	c[v] = cur;
	for (int i = 0; i < (int)e[v].size(); i++) {
		int to = go(e[v][i], v);
		if (c[to] != -1) continue;

		int ncur = cur;
		if (out[to] > in[v]) {
			ncur = cc++;
			g[cur].push_back(ncur);
			g[ncur].push_back(cur);
		}
		dfs2(to, ncur);
	}
}

pair<int, int> dfs3(int v) {
	used[v] = 1;
	pair<int, int> o = make_pair(0, 0);
	for (int i = 0; i < (int)g[v].size(); i++) {
		if (!used[g[v][i]]) {
			pair<int, int> oo = dfs3(g[v][i]);
			o.first += oo.first;
			o.second += oo.second;
		}
	}

	for (int i = 0; i < (int)events[v].size(); i++) {
		if (was[events[v][i].second]) {
			if (events[v][i].first == 0) o.second--;
			else o.first--;
		} else {
			was[events[v][i].second] = 1;
			if (events[v][i].first == 0) o.first++;
			else o.second++;
		}
	}

	if (o.first > 0 && o.second > 0) ok = 0;
	return o;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d%d", &n, &m, &q) == 3) {
		for (int i = 0; i < n; i++) e[i].clear();
		for (int i = 0; i < n; i++) g[i].clear();
		for (int i = 0; i < n; i++) events[i].clear();
		memset(in, -1, sizeof(in));
		memset(out, -1, sizeof(out));
		memset(c, -1, sizeof(c));
		memset(used, 0, sizeof(used));
		memset(was, 0, sizeof(was));
		tmr = 0;
		ok = 1;
		cc = 0;

		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u[i], &v[i]);
			--u[i]; --v[i];
			e[u[i]].push_back(i);
			e[v[i]].push_back(i);
		}
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &s[i], &d[i]);
			--s[i]; --d[i];
		}

		for (int i = 0; i < n; i++) {
			if (in[i] != -1) continue;
			dfs1(i, -1);
		}
		for (int i = 0; i < n; i++) {
			if (c[i] != -1) continue;
			dfs2(i, cc++);
		}
		for (int i = 0; i < q; i++) {
			events[c[s[i]]].push_back(make_pair(0, i));
			events[c[d[i]]].push_back(make_pair(1, i));
		}
		for (int i = 0; i < cc; i++) {
			if (used[i]) continue;
			pair<int, int> o = dfs3(i);
			if (o.first > 0 || o.second > 0) ok = 0;
		}
		if (ok) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}