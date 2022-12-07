#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int N = 1000005;

int n, m;
char str[N];

struct Tree {
	int l, r, lv, rv, sum;
	Tree operator + (const Tree &a) {
		Tree h;
		h.sum = sum + a.sum; h.lv = lv + a.lv; h.rv = rv + a.rv;
		int num1 = min(lv, a.rv); 
		h.sum += num1 * 2; h.lv -= num1; h.rv -= num1;
		return h;
	}
}st[3 * N];

Tree build(int l, int r, int id) {
	if (l == r) {
		if (str[l] == '(') {
			st[id].lv = 1; st[id].rv = 0; st[id].sum = 0;
		}
		else {
			st[id].lv = 0; st[id].rv = 1; st[id].sum = 0;
		}
		st[id].l = l; st[id].r = r;
	}
	else {
		int mid = (l + r) / 2;
		st[id] = build(l, mid, id * 2) + build(mid + 1, r, id * 2 + 1);
		st[id].l = l; st[id].r = r;
	}
	return st[id];
}

Tree Query(int l, int r, int id) {
	if (l == st[id].l && r == st[id].r)
		return st[id];
	int mid = (st[id].l + st[id].r) / 2;
	if (l <= mid && r > mid)
		return Query(l, mid, 2 * id) + Query(mid + 1, r, 2 * id + 1);
	else if (l <= mid && r <= mid) {return Query(l, r, 2 * id);}
	else {return Query(l, r, 2 * id + 1);}
}

void init() {
	scanf("%s%d", str + 1, &m);
	n = strlen(str + 1);
	build(1, n, 1);
	int l, r;
	while (m--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", Query(l, r, 1).sum);
	}
}

int main() {
	init();
	return 0;
}