#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

struct node {
	double L, R;
	void rd() {
		int x, y;
		scanf("%d%d", &x, &y);
		L = R = x * 1.0 / y;
	}
} a[N << 2];
int n, q;

node operator + (const node &ls, const node &rs) {
	node ans;
	ans.L = ls.L * rs.L / (1 - ls.R * (1 - rs.L));
	ans.R = rs.R + (1 - rs.R) * rs.L * ls.R / (1 - ls.R * (1 - rs.L));
	return ans;
}

void build(int rt, int l, int r) {
	if(l == r) {
		a[rt].rd();
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	a[rt] = a[rt << 1] + a[rt << 1 | 1];
}

void modify(int rt, int l, int r, int x, double p) {
	if(l == r) {
		a[rt].L = a[rt].R = p;
		return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(rt << 1, l, mid, x, p);
	else modify(rt << 1 | 1, mid + 1, r, x, p);
	a[rt] = a[rt << 1] + a[rt << 1 | 1];
}

node query(int rt, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) return a[rt];
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(rt << 1, l, mid, ql, qr);
	if(ql > mid) return query(rt << 1 | 1, mid + 1, r, ql, qr);
	return query(rt << 1, l, mid, ql, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, qr);
}

int main() {
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	int op, x, y, z;
	while(q --) {
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) {
			scanf("%d", &z);
			modify(1, 1, n, x, y * 1.0 / z);
		}
		if(op == 2) {
			printf("%.10f\n", query(1, 1, n, x, y).L);
		}
	}
	return 0;
}
/*
u.L = ls.L * rs.L / (1 - ls.R * (1 - rs.L))
u.R = rs.R + (1 - rs.R) * rs.L * ls.R / (1 - ls.R(1 - rs.L))
*/