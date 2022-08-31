#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 823456

struct info {
	int a, b, l1, l2, r1, r2, ans;
} t[maxN];
int a[maxN];
int n, q;
char s[maxN];

void update(int k) {
	int l = k << 1, r = k << 1 | 1;
	t[k].a = t[l].a + max(0, t[r].a - t[l].b);
	t[k].b = t[r].b + max(0, t[l].b - t[r].a);
	t[k].l1 = max(t[l].l1, max(t[l].a - t[l].b + t[r].l1, t[l].a + t[l].b + t[r].l2));
	t[k].l2 = max(t[l].l2, t[l].b - t[l].a + t[r].l2);
	t[k].r1 = max(t[r].r1, max(t[r].b - t[r].a + t[l].r1, t[r].a + t[r].b + t[l].r2));
	t[k].r2 = max(t[r].r2, t[r].a - t[r].b + t[l].r2);
	t[k].ans = max(max(t[l].ans, t[r].ans), max(t[l].r1 + t[r].l2, t[l].r2 + t[r].l1));
}

info ileft{0, 1, 1, 1, 0, 0, 0}, iright{1, 0, 0, 0, 1, 1, 0};
void build(int p1, int p2, int p3) {
	if (p2 == p3) {
		if (a[p2] == 1) {
			t[p1] = ileft;
		} else {
			t[p1] = iright;
		}
	} else {
		int mid = (p2 + p3) >> 1;
		build(p1 << 1, p2, mid);
		build(p1 << 1 | 1, mid + 1, p3);
		update(p1);
	}
}
void modify(int p1, int p2, int p3, int p4) {
	if (p2 == p3) {
		if (a[p2] == 1) {
			t[p1] = ileft;
		} else {
			t[p1] = iright;
		}
	} else {
		int mid = (p2 + p3) >> 1;
		if (p4 <= mid) modify(p1 << 1, p2, mid, p4);
		else modify(p1 << 1 | 1, mid + 1, p3, p4);
		update(p1);
	}

}

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s + 2);
	s[1] = '(';
	s[2 * n] = ')';
	for (int i = 1; i <= 2 * n; i++) {
		if (s[i] == '(') a[i] = 1;
		else a[i] = -1;
	}
	build(1, 1, 2 * n);
	printf("%d\n", t[1].ans);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		++l; ++r;
		swap(a[l], a[r]);
		modify(1, 1, 2 * n, l);
		modify(1, 1, 2 * n, r);
		printf("%d\n", t[1].ans);
	}
}