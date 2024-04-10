#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;
const int S = N << 2;

struct node {
	ll l, r; int lx, rx, lans, rans, ans, len;
	void init(int x) {
		l = r = x; lx = rx = ans = lans = rans = len = 1;
	}
} t[S];
int n, q, a[N];
ll tag[S];

node merge(const node &ls, const node &rs) {
	node u; u.l = ls.l; u.r = rs.r;
	u.lx = ls.lx == ls.len && ls.r > rs.l ? ls.len + rs.lx : ls.lx;
	u.rx = rs.rx == rs.len && ls.r < rs.l ? rs.len + ls.rx : rs.rx;
	u.ans = max(ls.ans, rs.ans);
	if(ls.r < rs.l) u.ans = max(u.ans, ls.rx + rs.lans);
	if(ls.r > rs.l) u.ans = max(u.ans, ls.rans + rs.lx);
	u.lans = ls.lans == ls.len && ls.r > rs.l ? ls.len + rs.lx : ls.lans;
	if(ls.rx == ls.len && ls.r < rs.l) u.lans = max(u.lans, ls.len + rs.lans);
	u.rans = rs.rans == rs.len && ls.r < rs.l ? rs.len + ls.rx : rs.rans;
	if(rs.lx == rs.len && ls.r > rs.l) u.rans = max(u.rans, rs.len + ls.rans);
	u.len = ls.len + rs.len;
	return u;
}

void pd(int u) {
	if(tag[u]) {
		tag[u << 1] += tag[u]; tag[u << 1 | 1] += tag[u];
		t[u << 1].l += tag[u]; t[u << 1].r += tag[u];
		t[u << 1 | 1].l += tag[u]; t[u << 1 | 1].r += tag[u];
		tag[u] = 0;
	}
}

void build(int u, int l, int r) {
	if(l == r) {
		t[u].init(a[l]); return ;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

void upd(int u, int l, int r, int ql, int qr, int d) {
	if(l == ql && r == qr) {
		tag[u] += d; t[u].l += d; t[u].r += d; return ;
	}
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) upd(u << 1, l, mid, ql, qr, d);
	else if(ql > mid) upd(u << 1 | 1, mid + 1, r, ql, qr, d);
	else {
		upd(u << 1, l, mid, ql, mid, d);
		upd(u << 1 | 1, mid + 1, r, mid + 1, qr, d);
	}
	t[u] = merge(t[u << 1], t[u << 1 | 1]);
//	printf("[%d, %d] : lans = %d, lx = %d, ans = %d\n", l, r, t[u].lans, t[u].lx, t[u].ans);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	build(1, 1, n);
	scanf("%d", &q);
	for(int i = 1; i <= q; i ++) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		upd(1, 1, n, l, r, d);
		printf("%d\n", t[1].ans);
	}
	return 0;
}