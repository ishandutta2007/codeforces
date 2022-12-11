// luogu-judger-enable-o2
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;

struct opt { int l, r, k, id; } q[N], qL[N], qR[N];
int n, m, h[N], ans[N];
struct node { int res, l, r, len; } t[N << 2];

node operator + (const node &a, const node &b) {
	node ans; ans.len = a.len + b.len;
	ans.l = a.l == a.len ? a.l + b.l : a.l;
	ans.r = b.r == b.len ? b.r + a.r : b.r;
	ans.res = max(max(a.res, b.res), a.r + b.l);
	return ans;
}

void build(int u, int l, int r) {
	if(l == r) { t[u] = (node) {0, 0, 0, 1}; return ; }
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	t[u] = t[u << 1] + t[u << 1 | 1];
}

void ins(int u, int l, int r, int x, int y) {
	if(l == r) { t[u] = (node) {y, y, y, 1}; return ; }
	int mid = (l + r) >> 1;
	if(x <= mid) ins(u << 1, l, mid, x, y);
	else ins(u << 1 | 1, mid + 1, r, x, y);
	t[u] = t[u << 1] + t[u << 1 | 1];
}

node qry(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) return t[u];
	int mid = (l + r) >> 1;
	if(qr <= mid) return qry(u << 1, l, mid, ql, qr);
	if(ql > mid) return qry(u << 1 | 1, mid + 1, r, ql, qr);
	return qry(u << 1, l, mid, ql, mid) + qry(u << 1 | 1, mid + 1, r, mid + 1, qr);
}

void solve(int ql, int qr, int l, int r) {
	if(ql > qr || l > r) return ;
	if(l == r) {
		for(int i = ql; i <= qr; i ++) ans[q[i].id] = l;
		return ;
	}
//	printf("[%d, %d] & [%d, %d]\n", ql, qr, l, r);
	int mid = (l + r + 1) >> 1, nl = 0, nr = 0;
	for(int i = ql; i <= qr; i ++) {
		if(!q[i].id) {
			if(q[i].k >= mid) ins(1, 1, n, q[i].l, 1), qR[nr ++] = q[i];
			else qL[nl ++] = q[i];
		} else {
			int res = qry(1, 1, n, q[i].l, q[i].r).res;
			if(res >= q[i].k) qR[nr ++] = q[i];
			else qL[nl ++] = q[i];
		}
	}
	for(int i = 0; i < nl; i ++) q[ql + i] = qL[i];
	for(int i = 0; i < nr; i ++) q[ql + nl + i] = qR[i];
	solve(ql, ql + nl - 1, l, mid - 1);
	for(int i = ql + nl; i <= qr; i ++) if(!q[i].id && q[i].k >= mid) ins(1, 1, n, q[i].l, 0);
	solve(ql + nl, qr, mid, r);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", h + i), q[i] = (opt) {i, 0, h[i], 0};
	int l = *min_element(h + 1, h + n + 1);
	int r = *max_element(h + 1, h + n + 1);
	scanf("%d", &m);
	for(int i = n + 1; i <= n + m; i ++) {
		scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k); q[i].id = i - n;
	}
	build(1, 1, n); solve(1, n + m, l, r);
	for(int i = 1; i <= m; i ++) printf("%d\n", ans[i]);
	return 0;
}