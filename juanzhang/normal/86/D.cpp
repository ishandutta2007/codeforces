#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
int n, m, sz, a[maxn], bl[maxn], cnt[maxn * 5]; ll now, ans[maxn];
struct node {
	int l, r, tid;
	bool operator < (const node& o) const {
		return bl[l] != bl[o.l] ? l < o.l : r > o.r;
	}
} q[maxn];

void add(int x) { now += x * (2 * (cnt[x]++) + 1); }
void del(int x) { now -= x * (2 * (cnt[x]--) - 1); }

int main() {
	scanf("%d %d", &n, &m), sz = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i), bl[i] = (i - 1) / sz + 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &q[i].l, &q[i].r), q[i].tid = i;
	}
	sort(q + 1, q + m + 1);
	int l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		while (q[i].l < l) add(a[--l]);
		while (q[i].r > r) add(a[++r]);
		while (q[i].l > l) del(a[l++]);
		while (q[i].r < r) del(a[r--]);
		ans[q[i].tid] = now;
	}
	for (int i = 1; i <= m; i++) {
		printf("%I64d\n", ans[i]);
	}
	return 0;
}