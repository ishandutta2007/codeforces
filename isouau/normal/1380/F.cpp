#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5, md = 998244353;

inline int add(int x, int y) {
	x += y;
	if (x >= md) x -= md;
	return x;
}

inline void addx(int &x, int y) {
	x += y;
	if (x >= md) x -= md;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += md;
	return x;
}

inline void subx(int &x, int y) {
	x -= y;
	if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

struct mat { int a[2][2], l, r; };

inline int getv(int x) {
	if (x >= 19) return 0;
	if (x <= 9) return x + 1;
	return 19 - x;
}

mat merge(mat a, mat b) {
	mat ans; ans.l = a.l; ans.r = b.r;
	memset(ans.a, 0, sizeof(ans.a));
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 1; k++) {
				for (int t = 0; t <= 1; t++) {
					if (j != k) continue;
					int now = 0;
					if (j && k) {
						if (a.r != 1) continue;
						now = a.r * 10 + b.l;
					}
					// if (!i && !t) fprintf(stderr, "%d %d %d %d\n", a.a[i][j], b.a[k][t], now, getv(now));
					addx(ans.a[i][t], mul(mul(a.a[i][j], b.a[k][t]), getv(now)));
				}
			}
		}
	}
	return ans;
}

struct node_t {
	int l, r;
	mat val;
} p[N << 2];

char c[N];
int n, m;

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r;
	if (l == r) {
		p[u].val.l = p[u].val.r = c[l] - '0';
		p[u].val.a[0][0] = getv(c[l] - '0');
		p[u].val.a[0][1] = p[u].val.a[1][0] = 1;
		p[u].val.a[1][1] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

void change(int u, int x, int y) {
	if (p[u].l == p[u].r) {
		p[u].val.l = p[u].val.r = y;
		p[u].val.a[0][0] = getv(y);
		return;
	}
	int mid = (p[u].l + p[u].r) >> 1;
	if (mid >= x) change(u << 1, x, y);
	else change(u << 1 | 1, x, y);
	p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

int main() {
	scanf("%d%d%s", &n, &m, c + 1);
	build(1, 1, n);
	// printf("%d\n", p[1].val.a[0][0]);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		change(1, x, y);
		printf("%d\n", p[1].val.a[0][0]);
	}
	return 0;
}