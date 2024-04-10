#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 19;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, cnt;
int l[maxn], r[maxn];
vector<int> e[maxn];

void dfs(int v, int p = -1) {
	l[v] = cnt++;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) dfs(e[v][i], v);
	r[v] = cnt++;
}

int t[4 * maxn][2], p[4 * maxn][2];

void push(int v, int k, int tl, int tr) {
	if (p[v][k] != -1) {
		if (tl != tr) p[v * 2][k] = p[v][k];
		if (tl != tr) p[v * 2 + 1][k] = p[v][k];
		t[v][k] = p[v][k];
		p[v][k] = -1;
	}
}

void upd(int v, int k, int tl, int tr, int l, int r, int x) {
	push(v, k, tl, tr);
	if (l > r) return;
	if (tl == l && tr == r) {
		p[v][k] = x;
		push(v, k, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v * 2, k, tl, tm, l, min(r, tm), x);
	upd(v * 2 + 1, k, tm + 1, tr, max(l, tm + 1), r, x);
	t[v][k] = max(t[v * 2][k], t[v * 2 + 1][k]);
}

int get(int v, int k, int tl, int tr, int l, int r) {
	push(v, k, tl, tr);
	if (l > r) return -1;
	if (tl == l && tr == r) return t[v][k];
	int tm = (tl + tr) >> 1;
	int ans = max(get(v * 2, k, tl, tm, l, min(r, tm)), get(v * 2 + 1, k, tm + 1, tr, max(l, tm + 1), r));
	t[v][k] = max(t[v * 2][k], t[v * 2 + 1][k]);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		cnt = 0;
		memset(p, -1, sizeof(p));
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		cin >> m;
		upd(1, 0, 0, cnt - 1, 0, cnt - 1, 0);
		upd(1, 1, 0, cnt - 1, 0, cnt - 1, 0);
		for (int i = 1; i <= m; i++) {
			int t, v;
			scanf("%d%d", &t, &v);
			if (t == 1) {
				upd(1, 0, 0, cnt - 1, l[v], r[v], i);
			}
			if (t == 2) {
				upd(1, 1, 0, cnt - 1, l[v], l[v], i);
			}
			if (t == 3) {
				int a1 = get(1, 0, 0, cnt - 1, l[v], l[v]);
				int a2 = get(1, 1, 0, cnt - 1, l[v], r[v]);
				cout << (int)(a1 > a2) << endl;
			}
		}
	}

	return 0;
}