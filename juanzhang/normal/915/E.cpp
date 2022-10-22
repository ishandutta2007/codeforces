#include <bits/stdc++.h>
using namespace std;

#define ls tree[k].l
#define rs tree[k].r
#define mid ((s + t) >> 1)
#define lson ls, s, mid, l, r, x
#define rson rs, mid + 1, t, l, r, x
const int maxn = 1.5e7 + 10;
int n, m, rt, tot;
struct node {
	int l, r, s, t;
} tree[maxn];

void pushdown(int k, int s, int t) {
	if (tree[k].t == -1) return;
	if (!ls) ls = ++tot;
	if (!rs) rs = ++tot;
	tree[rs].s = tree[k].t * (t - mid);
	tree[ls].s = tree[k].t * (mid - s + 1);
	tree[ls].t = tree[rs].t = tree[k].t, tree[k].t = -1;
}

void upd(int& k, int s, int t, int l, int r, int x) {
	if (!k) tree[k = ++tot].t = -1;
	if (l <= s && t <= r) {
		tree[k].s = (tree[k].t = x) * (t - s + 1); return;
	}
	pushdown(k, s, t);
	if (l <= mid) upd(lson);
	if (r > mid) upd(rson);
	tree[k].s = tree[ls].s + tree[rs].s;
}

int main() {
	scanf("%d %d", &n, &m);
	upd(rt, 1, n, 1, n, 0);
	while (m--) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		upd(rt, 1, n, l, r, 2 - k);
		printf("%d\n", n - tree[1].s);
	}
	return 0;
}