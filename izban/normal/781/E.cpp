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
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2.01e9;

int h, w, n;
int u[MAXN], l[MAXN], r[MAXN], s[MAXN];
int p[MAXN];

pair<int, int> t[MAXN * 2];
vector<pair<int, int> > st[MAXN];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		st[tl] = vector<pair<int, int> >(1, make_pair(INF, 0));
		st[tl].push_back(make_pair(h + 1, 1));
		t[v] = make_pair(st[tl].back().first, tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (l > r) return make_pair(INF, -1);
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	return min(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void push(int v, int tl, int tr, int x, pair<int, int> y) {
	if (tl == tr) {
		st[tl].push_back(y);
		t[v] = make_pair(st[tl].back().first, tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (x <= tm) push(v * 2, tl, tm, x, y);
	else push(v * 2 + 1, tm + 1, tr, x, y);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int pop(int v, int tl, int tr, int x) {
	if (tl == tr) {
		int res = st[tl].back().second;
		st[tl].pop_back();
		t[v] = make_pair(st[tl].back().first, tl);
		return res;
	}
	int tm = (tl + tr) >> 1;
	int res;
	if (x <= tm) res = pop(v * 2, tl, tm, x);
	else res = pop(v * 2 + 1, tm + 1, tr, x);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d%d", &h, &w, &n) == 3) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &u[i], &l[i], &r[i], &s[i]);
			l[i]--;
			r[i]--;
		}

		for (int i = 0; i < n; i++) p[i] = i;
		sort(p, p + n, [&](int i, int j) {
			return u[i] > u[j];
		});
		build(1, 0, w - 1);
		for (int ii = 0; ii < n; ii++) {
			int i = p[ii];
			int sum = 0;
			while (1) {
				auto o = get(1, 0, w - 1, l[i], r[i]);
				if (o.first > u[i] + s[i]) break;
				int cnt = pop(1, 0, w - 1, o.second);
				sum = (sum + cnt) % MOD;
			}
			if (l[i] == 0) {
				push(1, 0, w - 1, r[i] + 1, make_pair(u[i], 2LL * sum % MOD));
			}
			else if (r[i] == w - 1) {
				push(1, 0, w - 1, l[i] - 1, make_pair(u[i], 2LL * sum % MOD));
			}
			else {
				push(1, 0, w - 1, r[i] + 1, make_pair(u[i], sum));
				push(1, 0, w - 1, l[i] - 1, make_pair(u[i], sum));
			}
		}
		int ans = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < (int)st[i].size(); j++) {
				ans = (ans + st[i][j].second) % MOD;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}