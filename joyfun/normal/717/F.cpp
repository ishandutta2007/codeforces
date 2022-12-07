#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
const long long INF = (1LL<<40);
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)

int n, m, a[N], aa[N];

struct Node {
	int l, r;
	long long m[3], a[3];
} node[N * 4];

void pushup(int x) {
	for (int i = 0; i < 3; i++)
		node[x].m[i] = min(node[lson(x)].m[i], node[rson(x)].m[i]);
}

void pushdown(int x) {
	for (int i = 0; i < 3; i++) {
		if (node[x].a[i]) {
			node[lson(x)].a[i] += node[x].a[i];
			node[lson(x)].m[i] += node[x].a[i];
			node[rson(x)].a[i] += node[x].a[i];
			node[rson(x)].m[i] += node[x].a[i];
			node[x].a[i] = 0;
		}
	}
}

void build(int L, int R, int x = 1) {
	node[x].l = L; node[x].r = R;
	for (int i = 0; i < 3; i++) {
		node[x].m[i] = INF;
		node[x].a[i] = 0;
	}
	if (L == R) {
		node[x].m[2] = a[L];
		node[x].m[L % 2] = aa[L];
		return;
	}
	int mid = (L + R)>>1;
	build(L, mid, lson(x));
	build(mid + 1, R, rson(x));
	pushup(x);
}

void add(int l, int r, int w, int tp, int x = 1) {
	if (l > r) return;
	if (node[x].l >= l && node[x].r <= r) {
		node[x].a[tp] += w;
		node[x].m[tp] += w;
		return;
	}
	pushdown(x);
	int mid = (node[x].l + node[x].r)>>1;
	if (l <= mid) add(l, r, w, tp, lson(x));
	if (r > mid) add(l, r, w, tp, rson(x));
	pushup(x);
}

long long query(int l, int r, int tp, int x = 1) {
	if (l == 0) return 0LL;
	if (node[x].l >= l && node[x].r <= r)
		return node[x].m[tp];
	int mid = (node[x].l + node[x].r)>>1;
	long long ans = INF;
	pushdown(x);
	if (l <= mid) ans = min(ans, query(l, r, tp, lson(x)));
	if (r > mid) ans = min(ans, query(l, r, tp, rson(x)));
	pushup(x);
	return ans;
}

bool judge(int l, int r) {
	if (query(l, r, 2) < 0) return false;
	if (r % 2 == (l - 1) % 2) {
		if (query(r, r, r % 2) - query(l - 1, l - 1, (l - 1) % 2)) return false;
	} else {
		if (query(r, r, r % 2) + query(l - 1, l - 1, (l - 1) % 2)) return false;
	}
	int f1 = 1, f2 = 1;
	int tmp = query(l - 1, l - 1, (l - 1) % 2);
	add(l, r, tmp, l % 2);
	if (query(l, r, l % 2) < 0) f1 = 0;
	add(l, r, -tmp, l % 2);
	add(l, r, -tmp, !(l % 2));
	if (query(l, r, !(l % 2)) < 0) f2 = 0;
	add(l, r, tmp, !(l % 2));
	return (f1 && f2);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); a[i]--;
		aa[i] = a[i];
		aa[i] -= aa[i - 1];
	}
	build(1, n);
	int tp, a, b, k;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d%d", &tp, &a, &b);
		a++; b++;
		if (tp == 1) {
			scanf("%d", &k);
			add(a, b, k, 2);
			add(a, b, k, a % 2);
			if ((b - a + 1) % 2) {
				add(b + 1, n, -k, (b + 1) % 2);
				add(b + 1, n, k, !((b + 1) % 2));
			}
		} else {
			printf("%d\n", judge(a, b));
		}
		//for (int i = 1; i <= n; i++) printf("%lld ", query(i, i, i % 2)); printf("\n");
	}
	return 0;
}