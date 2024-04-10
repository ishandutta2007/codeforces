#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxsz = 5 << 20;

struct Node {
	int dep;
	int tagx;
	int sz;
	int ch[2];
	int msk[2];
} t[mxsz];

int fre[mxsz], fl, fr;

inline int new_node(int d) {
	int x = fre[fl ++];
	if (fl == mxsz) fl = 0;
	t[x].dep = d;
	t[x].tagx = 0;
	t[x].sz = 0;
	t[x].ch[0] = t[x].ch[1] = 0;
	t[x].msk[0] = t[x].msk[1] = 0;
	return x;
}

inline void del_node(int x) {
	fre[fr ++] = x;
	if (fr == mxsz) fr = 0;
}

inline void push(int x, int tagx) {
	if (!x) return ;
	t[x].tagx ^= tagx;
	if (tagx >> t[x].dep & 1) std::swap(t[x].ch[0], t[x].ch[1]);
	int nmsk0 = (t[x].msk[0] & ~tagx) | (t[x].msk[1] & tagx);
	int nmsk1 = (t[x].msk[1] & ~tagx) | (t[x].msk[0] & tagx);
	t[x].msk[0] = nmsk0, t[x].msk[1] = nmsk1;
}

inline void pushdown(int x) {
	if (t[x].tagx) push(t[x].ch[0], t[x].tagx), push(t[x].ch[1], t[x].tagx), t[x].tagx = 0;
}

inline void pushup(int x) {
	if (t[x].dep >= 0) {
		t[x].sz = t[t[x].ch[0]].sz + t[t[x].ch[1]].sz;
		t[x].msk[0] = t[t[x].ch[0]].msk[0] | t[t[x].ch[1]].msk[0] | (!!t[t[x].ch[0]].sz) << t[x].dep;
		t[x].msk[1] = t[t[x].ch[0]].msk[1] | t[t[x].ch[1]].msk[1] | (!!t[t[x].ch[1]].sz) << t[x].dep;
	}
}

void insert(int &x, int v, int d) {
	if (!x) x = new_node(d);
	if (d < 0) { t[x].sz = 1; return ; }
	insert(t[x].ch[v >> d & 1], v, d - 1);
	pushup(x);
}

void split(int x, int v, int &a, int &b) {
	if (!x) { a = b = 0; return ; }
	pushdown(x);
	if (t[x].dep < 0) { a = x; b = 0; return ; }
	if (v >> t[x].dep & 1) {
		a = x; b = new_node(t[x].dep);
		split(t[x].ch[1], v, t[a].ch[1], t[b].ch[1]);
	} else {
		b = x; a = new_node(t[x].dep);
		split(t[x].ch[0], v, t[a].ch[0], t[b].ch[0]);
	}
	pushup(a); pushup(b);
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	pushdown(x); pushdown(y);
	if (t[x].dep >= 0) {
		t[x].ch[0] = merge(t[x].ch[0], t[y].ch[0]);
		t[x].ch[1] = merge(t[x].ch[1], t[y].ch[1]);
		pushup(x);
	}
	del_node(y);
	return x;
}

void print(int x, int cur = 0) {
	if (!x) return ;
	pushdown(x);
	if (t[x].dep < 0) { eprintf("%d ", cur); return ; }
	rep(c, 2) print(t[x].ch[c], cur | c << t[x].dep);
}

void op_xor(int &x, int v) {
	push(x, v);
}

void op_or(int &x, int v) {
	if (!x) return ;
	pushdown(x);
	if ((v & t[x].msk[0] & t[x].msk[1]) == 0) {
		push(x, v & t[x].msk[0]);
		return ;
	}
	if (t[x].dep < 0) return ;
	if (v >> t[x].dep & 1) t[x].ch[1] = merge(t[x].ch[0], t[x].ch[1]), t[x].ch[0] = 0;
	op_or(t[x].ch[0], v);
	op_or(t[x].ch[1], v);
	pushup(x);
}

const int mxn = 1 << 18;
const int mxlv = 20;
const int mxs = (1 << mxlv) - 1;

int n, q;
int a[mxn];
int rt;

std::mt19937 rng;

inline int rand(int l, int r) {
	return std::uniform_int_distribution <int> (l, r)(rng);
}

int main() {
	for (int i = 1; i < mxsz; ++ i) del_node(i);
	scanf("%d %d", &n, &q);
	// n = 2e5, q = 1e5;
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) insert(rt, a[i], mxlv - 1);
	while (q --) {
		int tp;
		scanf("%d", &tp);
		// tp = rand(3, 4);
		int l, r;
		scanf("%d %d", &l, &r);
		// l = rand(0, mxs); r = rand(0, mxs);
		// if (l > r) std::swap(l, r);
		int a, b, c;
		split(rt, r, b, c);
		if (l) split(b, l - 1, a, b); else a = 0;
		if (tp <= 3) {
			int x;
			scanf("%d", &x);
			// x = rand(0, mxs);
			if (tp == 1) op_xor(b, mxs), op_or(b, mxs ^ x), op_xor(b, mxs);
			else if (tp == 2) op_or(b, x);
			else if (tp == 3) op_xor(b, x);
		} else {
			printf("%d\n", t[b].sz);
		}
		rt = merge(merge(a, b), c);
	}
	return 0;
}