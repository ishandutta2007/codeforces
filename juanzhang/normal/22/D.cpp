#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, tot, ans[maxn];
struct pr {
	int l, r;
	bool operator < (const pr& o) const {
		return r < o.r;
	}
} a[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].l, &a[i].r);
		if (a[i].l > a[i].r) swap(a[i].l, a[i].r);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1, pos = -(1 << 30); i <= n; i++) {
		if (pos < a[i].l) {
			ans[++tot] = pos = a[i].r;
		}
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}