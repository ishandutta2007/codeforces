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
const int SIGMA = 27;

struct state {
	int len, link;
	int nxt[SIGMA];

	state() {
		len = link = 0;
		memset(nxt, -1, sizeof(nxt));
	}
};

state st[MAXN];
int pos[MAXN];
int p[MAXN][MAXK];
int e[MAXN][SIGMA];
int sz, last;
int tmr, L[MAXN], R[MAXN], len[MAXN];
int a[MAXN];
vector<int> t[MAXN];
int ans[MAXN];

void init(int n) {
	sz = 0;
	last = sz++;
	for (int i = 0; i < n * 2; i++) st[i] = state();
}

void add(char c) {
	int p = last;
	last = sz++;
	st[last].len = st[p].len + 1;
	pos[last] = st[last].len;
	for (; st[p].nxt[c] == -1; p = st[p].link) st[p].nxt[c] = last;
	if (st[p].nxt[c] == last) {
		st[last].link = 0;
		return;
	}
	int q = st[p].nxt[c];
	if (st[p].len + 1 == st[q].len) {
		st[last].link = q;
		return;
	}
	int clone = sz++;
	st[clone].link = st[q].link;
	st[clone].len = st[p].len + 1;
	memcpy(st[clone].nxt, st[q].nxt, sizeof(st[clone].nxt));
	pos[clone] = pos[q];
	st[last].link = clone;
	st[q].link = clone;
	for (; st[p].nxt[c] == q; p = st[p].link) st[p].nxt[c] = clone;
}

void dfs(int v, int h) {
	h += len[v];
	bool leaf = 1;
	L[v] = tmr;
	for (int i = 0; i < SIGMA; i++) {
		if (e[v][i] != -1) {
			dfs(e[v][i], h);
			leaf = 0;
		}
	}
	if (leaf) {
		R[v] = tmr;
		a[tmr++] = h;
	}
	else R[v] = tmr - 1;
}

void build(int v, int tl, int tr) {
	t[v].clear();
	if (tl == tr) {
		t[v].push_back(a[tl]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
	merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
}

int x, y;
bool get(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l == tl && r == tr) {
		int id = lower_bound(t[v].begin(), t[v].end(), x) - t[v].begin();
		return id ? t[v][id - 1] >= y : 0;
	}
	int tm = (tl + tr) >> 1;
	return get(v * 2, tl, tm, l, min(r, tm)) || get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int fastsolve(string s) {
	s.insert(s.begin(), 'a' + 26);
	int n = s.length();
	init(n);
	for (int i = 0; i < n; i++) add(s[i] - 'a');
	memset(e, -1, sizeof(e[0]) * sz);
	for (int i = 1; i < sz; i++) {
		int j = st[i].link;
		e[j][s[pos[i] - st[j].len - 1] - 'a'] = i;
		len[i] = st[i].len - st[j].len;
	}
	vector<int> pp(sz);
	for (int i = 0; i < sz; i++) pp[i] = i;
	sort(pp.begin(), pp.end(), [&](int i, int j) {
		return st[i].len < st[j].len;
	});
	for (int i = 0; i < sz; i++) {
		int v = pp[i];
		p[v][0] = st[v].link;
		for (int j = 1; j < MAXK; j++) p[v][j] = p[p[v][j - 1]][j - 1];
	}
	tmr = 0;
	dfs(0, 0);
	build(1, 0, tmr - 1);
	int res = 0;
	for (int i = 1; i < sz; i++) {
		int v = pp[i];
		if (st[v].len == pos[v] && st[st[v].link].len + 1 == st[v].len) continue;
		int cur = v;
		for (int j = MAXK - 1; j >= 0; j--) {
			int u = p[cur][j];
			x = pos[v];
			y = pos[v] - st[v].len + st[u].len;
			bool need = !get(1, 0, tmr - 1, L[u], R[u]);
			if (need) {
				cur = u;
			}
		}
		int u = p[cur][0];
		ans[v] = ans[u] + 1;
		res = max(res, ans[v]);
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("task.in", "r", stdin);
#endif

	int n;
	string s;
	while (cin >> n >> s) {
		cout << fastsolve(s) << endl;
	}

#ifndef ONLINE_JUDGE
	cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
	return 0;
}