#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int n, m, a[maxn];
struct seg {
	int val[maxn << 2]; ll sum[maxn << 2];
	void maintain(int k) {
		sum[k] = sum[k << 1] + sum[k << 1 | 1];
		val[k] = max(val[k << 1], val[k << 1 | 1]);
	}
	void build(int k, int l, int r) {
		if (l == r) {
			sum[k] = val[k] = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(k << 1, l, mid);
		build(k << 1 | 1, mid + 1, r);
		maintain(k);
	}
	void upd(int k, int l, int r, int x, int y) {
		if (l == r) {
			sum[k] = val[k] = y;
			return;
		}
		int mid = l + r >> 1;
		if (x <= mid) {
			upd(k << 1, l, mid, x, y);
		} else {
			upd(k << 1 | 1, mid + 1, r, x, y);
		}
		maintain(k);
	}
	void mdf(int k, int s, int t, int l, int r, int x) {
		if (val[k] < x) return;
		if (s == t) {
			sum[k] %= x, val[k] %= x;
			return;
		}
		int mid = s + t >> 1;
		if (r <= mid) {
			mdf(k << 1, s, mid, l, r, x);
		} else if (l > mid) {
			mdf(k << 1 | 1, mid + 1, t, l, r, x);
		} else {
			mdf(k << 1, s, mid, l, mid, x), mdf(k << 1 | 1, mid + 1, t, mid + 1, r, x);
		}
		maintain(k);
	}
	ll query(int k, int s, int t, int l, int r) {
		if (s == l && t == r) {
			return sum[k];
		}
		int mid = s + t >> 1;
		if (r <= mid) {
			return query(k << 1, s, mid, l, r);
		} else if (l > mid) {
			return query(k << 1 | 1, mid + 1, t, l, r);
		} else {
			return query(k << 1, s, mid, l, mid) + query(k << 1 | 1, mid + 1, t, mid + 1, r);
		}
	}
} tree;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	tree.build(1, 1, n);
	int op, x, y, k;
	while (m--) {
		scanf("%d %d %d", &op, &x, &y);
		if (op == 1) {
			printf("%lld\n", tree.query(1, 1, n, x, y));
		} else if (op == 2) {
			scanf("%d", &k);
			tree.mdf(1, 1, n, x, y, k);
		} else {
			tree.upd(1, 1, n, x, y);
		}
	}
	return 0;
}