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

struct segtree {
	int n, nn;
	vector<int> a;
	vector<int> t;

	segtree(vector<int> _a) {
		a = _a;
		sort(a.begin(), a.end());
		a.resize(unique(a.begin(), a.end()) - a.begin());
		n = a.size();
		nn = 1;
		while (nn < n) nn <<= 1;
		nn <<= 1;
		t.assign(2 * nn, 0);
	}

	void push(int v, int tl, int tr) {
		if (tl != tr) {
			t[2 * v] = max(t[2 * v], t[v]);
			t[2 * v + 1] = max(t[2 * v + 1], t[v]);
			t[v] = 0;
		}
	}

	void upd(int v, int tl, int tr, int l, int r, int x) {
		push(v, tl, tr);
		if (l > r) return;
		if (l == tl && r == tr) {
			t[v] = max(t[v], x);
			push(v, tl, tr);
			return;
		}
		int tm = (tl + tr) >> 1;
		upd(v * 2, tl, tm, l, min(r, tm), x);
		upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
	}

	void upd(int l, int r, int x) {
		int _l = lower_bound(a.begin(), a.end(), l) - a.begin();
		int _r = lower_bound(a.begin(), a.end(), r + 1) - a.begin() - 1;
		upd(1, 0, n - 1, _l, _r, x);
	}

	int get(int v, int tl, int tr, int x) {
		push(v, tl, tr);
		if (tl == tr) return t[v];
		int tm = (tl + tr) >> 1;
		if (x <= tm) return get(v * 2, tl, tm, x);
		return get(v * 2 + 1, tm + 1, tr, x);
	}

	int get(int x) {
		int _x = lower_bound(a.begin(), a.end(), x) - a.begin();
		return get(1, 0, n - 1, _x);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, q;
	while (scanf("%d%d\n", &n, &q) == 2) {
		vector<int> x(q), y(q);
		vector<char> c(q);
		for (int i = 0; i < q; i++) {
			scanf("%d%d %c\n", &x[i], &y[i], &c[i]);
		}

		segtree xx(x), yy(y);
		for (int i = 0; i < q; i++) {
			if (c[i] == 'U') {
				int o = xx.get(x[i]);
				printf("%d\n", y[i] - o);
				xx.upd(x[i], x[i], y[i]);
				yy.upd(o, y[i], x[i]);
			} else {
				int o = yy.get(y[i]);
				printf("%d\n", x[i] - o);
				yy.upd(y[i], y[i], x[i]);
				xx.upd(o, x[i], y[i]);
			}
		}
	}

	return 0;
}