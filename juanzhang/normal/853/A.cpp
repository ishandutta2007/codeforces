#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 10;
ll sum;
bool vis[maxn];
int n, k, ans[maxn];

struct plane {
	int t;
	ll val;
	inline bool operator < (const plane& p) const {
		return p.val ^ val ? val > p.val : t < p.t;
	}
} a[maxn];

struct segment_tree {
	int l, r;
	bool flag;
} tree[maxn << 2];

void maintain(int k) {
	tree[k].flag = tree[k << 1].flag && tree[k << 1 | 1].flag;
}

void build(int k, int l, int r) {
	tree[k].l = l, tree[k].r = r;
	if (l == r) {
		return;
	}
	int mid = l + r >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
}

void update(int k, int x) {
	if (tree[k].l == tree[k].r) {
		tree[k].flag = 1;
		return;
	}
	int mid = tree[k].l + tree[k].r >> 1;
	if (x <= mid) {
		update(k << 1, x);
	} else {
		update(k << 1 | 1, x);
	}
	maintain(k);
}

int query(int k, int x) {
	if (tree[k].l == tree[k].r) {
		return tree[k].l;
	}
	int mid = tree[k].l + tree[k].r >> 1;
	if (!tree[k << 1].flag && x <= mid) {
		return query(k << 1, x);
	} else {
		return query(k << 1 | 1, x);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i].val), a[i].t = i;
	}
	sort(a + 1, a + n + 1);
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int t = query(1, max(a[i].t - k, 1));
		vis[t] = 1;
		update(1, t);
		ans[a[i].t] = t + k;
		sum += (t + k - a[i].t) * a[i].val;
	}
	printf("%lld\n", sum);
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}