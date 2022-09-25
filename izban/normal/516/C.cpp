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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxk = 17;
const int maxn = 1 << maxk;
const int inf = 1e9;

struct item {
	ll bestAns;
	ll bestLeft;
	ll bestRight;
	ll sum;

	bool isFake() {
		return sum == -1;
	}
};

item getFake() {
	item res;
	res.sum = -1;
	return res;
}

int n, m;
int d[maxn], h[maxn];

item t[2 * maxn];

item merge(item a, item b) {
	item res;
	if (a.isFake()) return b;
	if (b.isFake()) return a;
	res.sum = a.sum + b.sum;
	res.bestAns = a.bestLeft + b.bestRight;
	res.bestAns = max(res.bestAns, max(a.bestAns, b.bestAns));
	res.bestLeft = max(b.bestLeft, a.bestLeft + b.sum);
	res.bestRight = max(a.bestRight, b.bestRight + a.sum);
	return res;
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v].bestAns = 0;
		t[v].bestLeft = 2LL * h[tl] + d[tl];
		t[v].bestRight = 2LL * h[tl];
		t[v].sum = d[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

item get(int v, int tl, int tr, int l, int r) {
	if (l > r) return getFake();
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	return merge(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 0; i < n; i++) scanf("%d", &d[i]);
		for (int i = 0; i < n; i++) scanf("%d", &h[i]);

		build(1, 0, n - 1);
		for (int i = 0; i < m; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			l--; r--;
			item res = getFake();
			if (l <= r) {
				res = merge(res, get(1, 0, n - 1, r + 1, n - 1));
				res = merge(res, get(1, 0, n - 1, 0, l - 1));
			} else {
				res = get(1, 0, n - 1, r + 1, l - 1);
			}
			cout << res.bestAns << "\n";
		}
	}

	return 0;
}