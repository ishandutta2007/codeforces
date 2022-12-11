#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
const int mod1 = 1e9 + 9, mod2 = 19260817, base = 2333;
int n, q1, q2;
char str[N];
int qpow(int a, int b, int mod) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
		if(b & 1) ans = 1ll * ans * a % mod;
	return ans;
}
struct ha {
	int h1, h2;
	ha() {}
	ha(int x) : h1(x % mod1), h2(x % mod2) {}
	ha(int x, int y) : h1(x % mod1), h2(y % mod2) {}
	void operator = (int x) { h1 = x % mod1; h2 = x % mod2; }
	ha operator * (int x) { return ha(1ll * h1 * x % mod1, 1ll * h2 * x % mod2); }
	ha operator - (int x) { return ha((h1 - x + mod1) % mod1, (h2 - x + mod2) % mod2); }
	ha operator + (int x) { return ha((h1 + x) % mod1, (h2 + x) % mod2); }
	ha operator * (ha x) { return ha(1ll * h1 * x.h1 % mod1, 1ll * h2 * x.h2 % mod2); }
	ha operator - (const ha &x) { return ha((h1 - x.h1 + mod1) % mod1, (h2 - x.h2 + mod2) % mod2); }
	ha operator + (const ha &x) { return ha((h1 + x.h1) % mod1, (h2 + x.h2) % mod2); }
	ha operator / (const ha &x) {
		return ha(1ll * qpow(x.h1, mod1 - 2, mod1) * h1 % mod1, 1ll * qpow(x.h2, mod2 - 2, mod2) * h2 % mod2);
	}
	bool operator != (const ha &x) {
		return h1 != x.h1 || h2 != x.h2;
	}
	friend ha qpow(ha a, int b) {
		ha ans = 1;
		for(; b >= 1; b >>= 1, a = a * a)
			if(b & 1) ans = ans * a;
		return ans;
	}
} pw[N], pwc[10][N], h[N << 2];
int tag[N << 2];
void init() {
	pw[0] = 1;
	for(int i = 1; i <= n; i ++) {
		pw[i] = pw[i - 1] * base;
	}
	for(int i = 0; i < 10; i ++) {
		pwc[i][0] = 0;
		for(int j = 1; j <= n; j ++) {
			pwc[i][j] = pwc[i][j - 1] * base + i;
		}
	}
}
void build(int u, int l, int r) {
	tag[u] = -1;
	if(l == r) { h[u] = (int) (str[l] - '0'); return ; }
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	h[u] = h[u << 1] * pw[r - mid] + h[u << 1 | 1];
}
ha repha(ha v, int l, int k) {
	ha p = pw[l];
	return (qpow(p, k) - 1) / (p - 1) * v;
}
void pushd(int u, int l, int r) {
	if(tag[u] == -1) return ;
	int mid = (l + r) >> 1;
	tag[u << 1] = tag[u << 1 | 1] = tag[u];
	h[u << 1] = pwc[tag[u]][mid - l + 1];
	h[u << 1 | 1] = pwc[tag[u]][r - mid];
	tag[u] = -1;
}
int pl;
ha cur;
void query(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) {
		cur = cur + h[u] * pw[pl];
		pl += r - l + 1;
		return ;
	}
	int mid = (l + r) >> 1; pushd(u, l, r);
	if(qr <= mid) query(u << 1, l, mid, ql, qr);
	else if(ql > mid) query(u << 1 | 1, mid + 1, r, ql, qr);
	else {
		query(u << 1 | 1, mid + 1, r, mid + 1, qr);
		query(u << 1, l, mid, ql, mid);
	}
}
void modify(int u, int l, int r, int ql, int qr, int c) {
	if(l == ql && r == qr) {
		h[u] = pwc[c][r - l + 1];
		tag[u] = c;
		return ;
	}
	int mid = (l + r) >> 1; pushd(u, l, r);
	if(qr <= mid) modify(u << 1, l, mid, ql, qr, c);
	else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, c);
	else {
		modify(u << 1 | 1, mid + 1, r, mid + 1, qr, c);
		modify(u << 1, l, mid, ql, mid, c);
	}
	h[u] = h[u << 1] * pw[r - mid] + h[u << 1 | 1];
}
ha query(int l, int r) {
	pl = 0; cur = 0; query(1, 1, n, l, r);
	return cur;
}
int main() {
	scanf("%d%d%d%s", &n, &q1, &q2, str + 1); init();
	build(1, 1, n);
	for(int op, l, r, c, i = 1; i <= q1 + q2; i ++) {
		scanf("%d%d%d%d", &op, &l, &r, &c);
		if(op == 1) modify(1, 1, n, l, r, c);
		if(op == 2) {
			bool tag = 1;
			if(c < r - l + 1) {
				ha t = query(l, l + c - 1);
				int y = (r - l + 1) % c;
				t = repha(t, c, (r - l + 1) / c);
				if(t != query(l, r - y)) tag = 0;
				if(tag && y) {
					if(query(l, l + y - 1) != query(r - y + 1, r)) tag = 0;
				}
			}
			puts(tag ? "YES" : "NO");
		}
	}
	return 0;
}