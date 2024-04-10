#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
const int N = 3e5 + 10;
const int mo = 1e9 + 9;
const int S = 383008016;
const int S_inv = 276601605; // 1 / S
const int A = 691504013; // A = 1 / A - 1
const int B = 308495997; // B = 1 / B - 1
//F[n] = S_inv A ^ n - S_inv B ^ n
int n, m, v[N], pA[N], pB[N];

namespace cipolla {

const int mo = 1e9 + 9;
int a, t;
struct Node {
	int x, y;
	Node operator * (const Node &b) const {
		return (Node) {
			(int) ((1ll * x * b.x % mo + 1ll * y * b.y % mo * t % mo) % mo),
			(int) ((1ll * x * b.y % mo + 1ll * y * b.x % mo) % mo)
		};
	}
};
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}
Node nqpow(Node a, int b) {
	Node ans = (Node) {1, 0};
	for(; b >= 1; b >>= 1, a = a * a)
		if(b & 1) ans = ans * a;
	return ans;
}
int sqrt(int n) {
	a = 1; srand(time(0));
	while(qpow(((t = (1ll * a * a % mo - n) % mo + mo) % mo), (mo - 1) / 2) != mo - 1)
		a = 1ll * rand() * rand() % mo;
	return nqpow((Node) {a, 1}, (mo + 1) / 2).x;
}

}

namespace seg1 {

int s[N << 2], fir[N << 2], nl, nr;
void add(int u, int p, int l, int r) { //[l, r] += p, pA, pA^2, ...
	(s[u] += p == 0 ? 0 : p * (pA[r - l + 1] - 1ll) % mo * A % mo) %= mo;
	(fir[u] += p) %= mo;
}
void pd(int u, int l, int r) {
	if(fir[u]) {
		int mid = (l + r) >> 1;
		add(u << 1, fir[u], l, mid);
		add(u << 1 | 1, 1ll * fir[u] * pA[mid - l + 1] % mo, mid + 1, r);
		fir[u] = 0;
	}
}
void modify(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) {
		add(u, 1ll * S_inv * pA[l - nl + 1] % mo, l, r); return ;
	}
	int mid = (l + r) >> 1; pd(u, l, r);
	if(qr <= mid) modify(u << 1, l, mid, ql, qr);
	else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr);
	else {
		modify(u << 1, l, mid, ql, mid);
		modify(u << 1 | 1, mid + 1, r, mid + 1, qr);
	}
	s[u] = (s[u << 1] + s[u << 1 | 1]) % mo;
}
int qry(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) return s[u];
	int mid = (l + r) >> 1; pd(u, l, r);
	if(qr <= mid) return qry(u << 1, l, mid, ql, qr);
	if(ql > mid) return qry(u << 1 | 1, mid + 1, r, ql, qr);
	return (qry(u << 1, l, mid, ql, mid) + qry(u << 1 | 1, mid + 1, r, mid + 1, qr)) % mo;
}

}

namespace seg2 {

int s[N << 2], fir[N << 2], nl, nr;
void add(int u, int p, int l, int r) { //[l, r] += p, pB, pB^2, ...
	(s[u] += p == 0 ? 0 : p * (pB[r - l + 1] - 1ll) % mo * B % mo) %= mo;
	(fir[u] += p) %= mo;
}
void pd(int u, int l, int r) {
	if(fir[u]) {
		int mid = (l + r) >> 1;
		add(u << 1, fir[u], l, mid);
		add(u << 1 | 1, 1ll * fir[u] * pB[mid - l + 1] % mo, mid + 1, r);
		fir[u] = 0;
	}
}
void modify(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) {
		add(u, 1ll * S_inv * pB[l - nl + 1] % mo, l, r); return ;
	}
	int mid = (l + r) >> 1; pd(u, l, r);
	if(qr <= mid) modify(u << 1, l, mid, ql, qr);
	else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr);
	else {
		modify(u << 1, l, mid, ql, mid);
		modify(u << 1 | 1, mid + 1, r, mid + 1, qr);
	}
	s[u] = (s[u << 1] + s[u << 1 | 1]) % mo;
}
int qry(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) return s[u];
	int mid = (l + r) >> 1; pd(u, l, r);
	if(qr <= mid) return qry(u << 1, l, mid, ql, qr);
	if(ql > mid) return qry(u << 1 | 1, mid + 1, r, ql, qr);
	return (qry(u << 1, l, mid, ql, mid) + qry(u << 1 | 1, mid + 1, r, mid + 1, qr)) % mo;
}

}

void solve(int l, int r) {
	seg1 :: nl = l; seg1 :: nr = r; seg1 :: modify(1, 1, n, l, r);
	seg2 :: nl = l; seg2 :: nr = r; seg2 :: modify(1, 1, n, l, r);
}
int query(int l, int r) {
	return (seg1 :: qry(1, 1, n, l, r) - seg2 :: qry(1, 1, n, l, r) + mo) % mo;
}
int main() {
	scanf("%d%d", &n, &m);
	pA[0] = pB[0] = 1;
	for(int i = 1; i <= n; i ++) {
		pA[i] = 1ll * pA[i - 1] * A % mo;
		pB[i] = 1ll * pB[i - 1] * B % mo;
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%d", v + i); (v[i] += v[i - 1]) %= mo;
	}
	for(int l, r, op, i = 1; i <= m; i ++) {
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) solve(l, r);
		if(op == 2) {
			int ans = (v[r] - v[l - 1] + mo) % mo;
			printf("%d\n", (ans + query(l, r)) % mo);
		}
	}
	return 0;
}