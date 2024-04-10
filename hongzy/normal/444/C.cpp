#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m, col[N << 2], tag[N << 2], len[N << 2];
ll sum[N << 2], s[N << 2];

void pu(int u) {
	col[u] = col[u << 1] == col[u << 1 | 1] ? col[u << 1] : 0;
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

void pd(int u) {
	if(tag[u]) {
		s[u << 1] += s[u]; sum[u << 1] += len[u << 1] * s[u];
		s[u << 1 | 1] += s[u]; sum[u << 1 | 1] += len[u << 1 | 1] * s[u];
		tag[u << 1] = tag[u << 1 | 1] = tag[u];
		col[u << 1] = col[u << 1 | 1] = col[u];
		tag[u] = 0; s[u] = 0;
	}
}

void build(int u, int l, int r) {
	len[u] = r - l + 1;
	if(l == r) { col[u] = l; return ; }
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

void upd(int u, int l, int r, int ql, int qr, int c) {
	if(l == ql && r == qr && col[u]) {
		ll x = abs(col[u] - c);
		sum[u] += x * len[u]; s[u] += x;
		col[u] = tag[u] = c;
		return ;
	}
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) upd(u << 1, l, mid, ql, qr, c);
	else if(ql > mid) upd(u << 1 | 1, mid + 1, r, ql, qr, c);
	else {
		upd(u << 1, l, mid, ql, mid, c);
		upd(u << 1 | 1, mid + 1, r, mid + 1, qr, c);
	}
	pu(u);
}

ll qry(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) return sum[u];
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) return qry(u << 1, l, mid, ql, qr);
	if(ql > mid) return qry(u << 1 | 1, mid + 1, r, ql, qr);
	return qry(u << 1, l, mid, ql, mid) + qry(u << 1 | 1, mid + 1, r, mid + 1, qr);
}

int main() {
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for(int i = 1; i <= m; i ++) {
		int op, l, r, x;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) {
			scanf("%d", &x);
			upd(1, 1, n, l, r, x);
		}
		if(op == 2) {
			printf("%I64d\n", qry(1, 1, n, l, r));
		}
	}
	return 0;
}