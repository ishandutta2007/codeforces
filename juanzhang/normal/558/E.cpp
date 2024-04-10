#include <bits/stdc++.h>
using namespace std;

#prag\
ma GCC optimize(3)
#define nc getchar
#define re register int
const int maxn = 1e5 + 10;
int n, m, sum[26]; 
struct node {
	int l, r, lazy, sum[26];
} tree[maxn << 2];

inline void maintain(int k) {
	for (re i = 0; i < 26; i++) {
		tree[k].sum[i] = tree[k << 1].sum[i] + tree[k << 1 | 1].sum[i];
	}
}

inline void pushlazy(int k, int x) {
	for (re i = 0; i < 26; i++) {
		tree[k].sum[i] = 0;
	}
	tree[k].sum[x] = tree[k].r - tree[k].l + 1, tree[k].lazy = x;
}

inline void pushdown(int k) {
	if (~tree[k].lazy) {
		pushlazy(k << 1, tree[k].lazy);
		pushlazy(k << 1 | 1, tree[k].lazy);
		tree[k].lazy = -1;
	}
}

void build(int k, int l, int r) {
	tree[k].l = l, tree[k].r = r, tree[k].lazy = -1;
	if (l == r) {
		static char c;
		for (c = nc(); c < 'a'; c = nc());
		tree[k].sum[c - 'a']++;
		return;
	}
	int mid = l + r >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	maintain(k);
}

void print(int k) {
	if (tree[k].l == tree[k].r) {
		static int pos;
		for (pos = 0; pos < 26; pos++) {
			if (tree[k].sum[pos]) {
				putchar('a' + pos);
				return;
			}
		}
	}
	pushdown(k);
	print(k << 1), print(k << 1 | 1);
}

void upd(int k, int l, int r, int x) {
	if (tree[k].l == l && tree[k].r == r) {
		pushlazy(k, x); return;
	}
	pushdown(k);
	int mid = tree[k].l + tree[k].r >> 1;
	if (r <= mid) {
		upd(k << 1, l, r, x);
	} else if (l > mid) {
		upd(k << 1 | 1, l, r, x);
	} else {
		upd(k << 1, l, mid, x), upd(k << 1 | 1, mid + 1, r, x);
	}
	maintain(k);
}

void query(int k, int l, int r) {
	if (tree[k].l == l && tree[k].r == r) {
		for (re i = 0; i < 26; i++) {
			sum[i] += tree[k].sum[i];
		}
		return;
	}
	pushdown(k);
	int mid = tree[k].l + tree[k].r >> 1;
	if (r <= mid) {
		query(k << 1, l, r);
	} else if (l > mid) {
		query(k << 1 | 1, l, r);
	} else {
		query(k << 1, l, mid), query(k << 1 | 1, mid + 1, r);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	build(1, 1, n);
	re op, l, r, pos;
	while (m--) {
		scanf("%d %d %d", &l, &r, &op);
		memset(sum, 0, sizeof sum);
		query(1, l, r), pos = l;
		if (!op) {
			for (int i = 25; ~i; i--) {
				if (sum[i]) upd(1, pos, pos + sum[i] - 1, i), pos += sum[i];
			}
		} else {
			for (int i = 0; i < 26; i++) {
				if (sum[i]) upd(1, pos, pos + sum[i] - 1, i), pos += sum[i];
			}
		}
	}
	print(1);
	return 0;
}