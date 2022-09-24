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
const int MAXN = 1 << 19;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n, q;
int a[MAXN];
ll b[MAXN];

struct item {
	int pref;
	int suf;
	int best;

	item() : pref(0), suf(0), best(0) {}
	item(int _pref, int _suf, int _best) : pref(_pref), suf(_suf), best(_best) {}
};

item t[MAXN * 2];

int sign(ll x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

item merge(item x, item y, int tl, int tm, int tr) {
	item res(0, 0, 0);
	
	res.best = max(res.best, x.best);
	res.best = max(res.best, y.best);
	if (sign(b[tm]) <= sign(b[tm + 1])) {
		res.best = max(res.best, x.suf + y.pref);
	}

	res.pref = x.pref;
	if (x.pref == tm - tl + 1 && sign(b[tm]) <= sign(b[tm + 1])) {
		res.pref = max(res.pref, x.pref + y.pref);
	}

	res.suf = y.suf;
	if (y.suf == tr - tm && sign(b[tm]) <= sign(b[tm + 1])) {
		res.suf = max(res.suf, x.suf + y.suf);
	}

	return res;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		int o = b[tl] != 0;
		t[v] = item(o, o, o);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = merge(t[v * 2], t[v * 2 + 1], tl, tm, tr);
}

void upd(int v, int tl, int tr, int x, int y) {
	if (tl == tr) {
		b[tl] += y;
		int o = b[tl] != 0;
		t[v] = item(o, o, o);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (x <= tm) upd(v * 2, tl, tm, x, y);
	else upd(v * 2 + 1, tm + 1, tr, x, y);
	t[v] = merge(t[v * 2], t[v * 2 + 1], tl, tm, tr);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	bool first = 1;
	while (scanf("%d", &n) == 1) {
		if (first) first = 0;
		else printf("\n");
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		for (int i = 0; i < n - 1; i++) {
			b[i] = a[i] - a[i + 1];
		}

		if (n != 1) build(1, 0, n - 2);
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d);
			if (n == 1) {
				printf("%d\n", 1);
				continue;
			}
			--l; --r;
			if (l) upd(1, 0, n - 2, l - 1, -d);
			if (r < n - 1) upd(1, 0, n - 2, r, d);
			printf("%d\n", t[1].best + 1);
		}
	}

	return 0;
}