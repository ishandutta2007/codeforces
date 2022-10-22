#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

struct treap {
	static const int maxn = 1e6 + 5;
	int key[maxn], add_key[maxn];
	int val[maxn], add_val[maxn];
	int fix[maxn], siz[maxn];
	int lson[maxn], rson[maxn];
	int tot;
	treap() {
		tot = 0;
		key[0] = 0; val[0] = 0;
		add_key[0] = add_val[0] = 0;
		fix[0] = 0; siz[0] = 0;
		lson[0] = rson[0] = 0;
	}
	int new_node(int i, int v) {
		int x = ++ tot;
		key[x] = i; val[x] = v;
		add_key[x] = add_val[x] = 0;
		fix[x] = rand(); siz[x] = 1;
		lson[x] = rson[x] = 0;
		return x;
	}
	void push_key(int x, int v) {
		key[x] += v;
		add_key[x] += v;
	}
	void push_val(int x, int v) {
		val[x] += v;
		add_val[x] += v;
	}
	void pushdown(int x) {
		if (add_key[x]) {
			if (lson[x]) push_key(lson[x], add_key[x]);
			if (rson[x]) push_key(rson[x], add_key[x]);
			add_key[x] = 0;
		}
		if (add_val[x]) {
			if (lson[x]) push_val(lson[x], add_val[x]);
			if (rson[x]) push_val(rson[x], add_val[x]);
			add_val[x] = 0;
		}
	}
	void pushup(int x) {
		siz[x] = siz[lson[x]] + 1 + siz[rson[x]];
	}
	void split(int x, int v, int &a, int &b) {
		if (!x) {a = b = 0; return ;}
		pushdown(x);
		if (val[x] <= v) {
			a = x;
			split(rson[x], v, rson[a], b);
			pushup(a);
		} else {
			b = x;
			split(lson[x], v, a, lson[b]);
			pushup(b);
		}
	}
	void splitk(int x, int v, int &a, int &b) {
		if (!x) {a = b = 0; return ;}
		pushdown(x);
		if (siz[lson[x]] + 1 <= v) {
			a = x;
			splitk(rson[x], v - siz[lson[x]] - 1, rson[a], b);
			pushup(a);
		} else {
			b = x;
			splitk(lson[x], v, a, lson[b]);
			pushup(b);
		}
	}
	int merge(int a, int b) {
		if (!a || !b) return a | b;
		if (fix[a] < fix[b]) {
			pushdown(a);
			rson[a] = merge(rson[a], b);
			pushup(a);
			return a;
		} else {
			pushdown(b);
			lson[b] = merge(a, lson[b]);
			pushup(b);
			return b;
		}
	}
	int rt;
	void upd(int l, int r) {
		int a, b, c, al, ar, cl, cr;
		split(rt, r - 1, b, c);
		split(b, l - 2, a, b);
		if (b) {
			int bl, br;
			splitk(b, 1, bl, br);
			int nbl = new_node(key[bl], val[bl]);
			b = merge(bl, br);
			push_key(b, 1), push_val(b, 1);
			b = merge(nbl, b);
			splitk(c, 1, cl, cr); c = cr;
		}
		rt = merge(merge(a, b), c);
		split(rt, l - 1, a, b);
		if (b) {
			splitk(b, 1, b, c);
			val[b] = l;
			b = merge(b, c);
		}
		rt = merge(a, b);
//		prt(rt); puts("");
	}
	int mxk(int x) {
		if (!x) return -1e9;
		pushdown(x);
		int ans = max(mxk(lson[x]), mxk(rson[x]));
		if (val[x] <= 1e9) ans = max(ans, key[x]);
		return ans;
	}
	void prt(int x) {
		if (!x) return ;
		pushdown(x);
		prt(lson[x]);
		printf("(%d,%d)", key[x], val[x]);
		prt(rson[x]);
	}
} tr;

const int maxn = 3e5 + 5;

int n;

int main() {
	scanf("%d", &n);
	tr.rt = tr.new_node(0, 0);
	for (int i = 1; i <= n; ++ i)
		tr.rt = tr.merge(tr.rt, tr.new_node(i, 1e9 + i));
	for (int i = 0; i < n; ++ i) {
		int l, r;
		scanf("%d %d", &l, &r);
		tr.upd(l, r);
	}
	printf("%d\n", tr.mxk(tr.rt));
	return 0;
}