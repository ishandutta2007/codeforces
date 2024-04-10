#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
typedef long long llong;

int n, q;
struct node {
	node *l, *r;
	int cnt;
} tree0;

node trees[200000][20];
void maketree(node * pre, node * now, int s, int e, int v) {
	if (s == e) {
		now->cnt = pre->cnt + 1;
		now->l = now->r = 0;
		return;
	}
	int m = (s + e) / 2;
	if (v <= m) {
		now->l = now + 1;
		now->r = pre->r;
		maketree(pre->l, now->l, s, m, v);
	}
	else {
		now->l = pre->l;
		now->r = now + 1;
		maketree(pre->r, now->r, m + 1, e, v);
	}
	now->cnt = now->l->cnt + now->r->cnt;
}

node * root[200001];

llong nc2(int x) {
	return (llong)((llong)x * (x - 1)) / 2;
}

int query(node * pre, node * now, int s, int e, int i, int j) {
	if (j < s || e < i) return 0;
	if (i <= s && e <= j) return now->cnt - pre->cnt;
	int m = (s + e) / 2;
	return query(pre->l, now->l, s, m, i, j) + query(pre->r, now->r, m + 1, e, i, j);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	int l, d, r, u;
	tree0.cnt = 0;
	root[0] = tree0.l = tree0.r = &tree0;
	for (int i = 1; i <= n; ++i) {
		cin >> d;
		root[i] = trees[i - 1];
		maketree(root[i - 1], root[i], 1, n, d);
	}
	while (q--) {
		cin >> l >> d >> r >> u;
		llong ans = nc2(n);
		ans -= nc2(l - 1);
		ans -= nc2(d - 1);
		ans -= nc2(n - r);
		ans -= nc2(n - u);
		ans += nc2(query(root[0], root[l - 1], 1, n, 1, d - 1));
		ans += nc2(query(root[0], root[l - 1], 1, n, u + 1, n));
		ans += nc2(query(root[r], root[n], 1, n, 1, d - 1));
		ans += nc2(query(root[r], root[n], 1, n, u + 1, n));
		printf("%lld\n", ans);
	}
	return 0;
}