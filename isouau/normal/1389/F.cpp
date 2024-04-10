#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

struct SegmentTree {
	int mx[N << 2], tag[N << 2];

	void update(int u) { mx[u] = max(mx[u << 1], mx[u << 1 | 1]); }

	void add_tag(int u, int x) {
		mx[u] += x;
		tag[u] += x;
	}

	void pushdown(int u) {
		if (tag[u]) {
			add_tag(u << 1, tag[u]);
			add_tag(u << 1 | 1, tag[u]);
			tag[u] = 0;
		}
	}

	void change(int u, int l, int r, int x, int y) {
		if (l == r) {
			mx[u] = max(mx[u], y);
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		if (mid >= x) change(u << 1, l, mid, x, y);
		else change(u << 1 | 1, mid + 1, r, x, y);
		update(u);
	}

	void add(int u, int L, int R, int l, int r, int x) {
		if (l <= L && R <= r) {
			add_tag(u, x);
			return;
		}
		pushdown(u);
		int mid = (L + R) >> 1;
		if (mid >= l) add(u << 1, L, mid, l, r, x);
		if (mid + 1 <= r) add(u << 1 | 1, mid + 1, R, l, r, x);
		update(u);
	}

	int query(int u, int L, int R, int l, int r) {
		if (l <= L && R <= r) return mx[u];
		pushdown(u);
		int mid = (L + R) >> 1, ans = 0;
		if (mid >= l) ans = max(ans, query(u << 1, L, mid, l, r));
		if (mid + 1 <= r) ans = max(ans, query(u << 1 | 1, mid + 1, R, l, r));
		return ans;
	}
} tr[2];

struct ele {
	int l, r, t;
	ele (int a = 0, int b = 0, int c = 0) : l(a), r(b), t(c) {}
	bool operator < (const ele A) const { return l < A.l; }
} a[N];

int b[N];
int n, len;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
		--a[i].t; b[++len] = a[i].l; b[++len] = a[i].r;
	}
	sort(b + 1, b + len + 1); len = unique(b + 1, b + len + 1) - b - 1;
	for (int i = 1; i <= n; i++) {
		a[i].l = lower_bound(b + 1, b + len + 1, a[i].l) - b;
		a[i].r = lower_bound(b + 1, b + len + 1, a[i].r) - b;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		tr[a[i].t].change(1, 0, len, a[i].r, max(tr[a[i].t ^ 1].query(1, 0, len, 0, a[i].l - 1), tr[a[i].t].query(1, 0, len, 0, a[i].r)) + 1);
		if (a[i].r < len) tr[a[i].t].add(1, 0, len, a[i].r + 1, len, 1);
	}
	printf("%d\n", max(tr[0].query(1, 0, len, 0, len), tr[1].query(1, 0, len, 0, len)));
	return 0;
}