#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back

const int N = 5e5 + 10;

int n, idx, q, f[N], dl[N], dr[N];
vector<int> G[N];
bool emp[N << 2], col[N << 2];
void pd(int u) {
	if(col[u]) {
		col[u << 1] = col[u << 1 | 1] = 1;
		emp[u << 1] = emp[u << 1 | 1] = 0;
		col[u] = 0;
	}
}
void pu(int u) {
	emp[u] = emp[u << 1] || emp[u << 1 | 1];
}
void build(int u, int l, int r) {
	emp[u] = 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}
void clr(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) { col[u] = 1; emp[u] = 0; return ; }
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) clr(u << 1, l, mid, ql, qr);
	else if(ql > mid) clr(u << 1 | 1, mid + 1, r, ql, qr);
	else {
		clr(u << 1, l, mid, ql, mid);
		clr(u << 1 | 1, mid + 1, r, mid + 1, qr);
	}
	pu(u);
}
void tag(int u, int l, int r, int p) {
	if(l == r) { emp[u] = 1; return ; }
	int mid = (l + r) >> 1; pd(u); 
	if(p <= mid) tag(u << 1, l, mid, p);
	else tag(u << 1 | 1, mid + 1, r, p);
	pu(u);
}
bool qry(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) return emp[u];
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) return qry(u << 1, l, mid, ql, qr);
	if(ql > mid) return qry(u << 1 | 1, mid + 1, r, ql, qr);
	return qry(u << 1, l, mid, ql, mid) || qry(u << 1 | 1, mid + 1, r, mid + 1, qr);
}
void dfs(int u, int fa = 0) {
	dl[u] = ++ idx; f[u] = fa;
	for(int v : G[u]) if(v != fa) dfs(v, u);
	dr[u] = idx;
}

int main() {
	scanf("%d", &n);
	int u, v;
	for(int i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u);
	}
	dfs(1); build(1, 1, n);
	scanf("%d", &q);
	while(q --) {
		scanf("%d%d", &u, &v);
		if(u == 1) {
			if(f[v] && qry(1, 1, n, dl[v], dr[v])) tag(1, 1, n, dl[f[v]]);
			clr(1, 1, n, dl[v], dr[v]);
		}
		if(u == 2) tag(1, 1, n, dl[v]);
		if(u == 3) printf("%d\n", !qry(1, 1, n, dl[v], dr[v]));
	}
	return 0;
}