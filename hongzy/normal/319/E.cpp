#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
struct node {
	int op, l, r;
} a[N];
int q, n, b[N * 2], f[N], L[N], R[N];
inline bool bel(int u, int l, int r) {
	return l < u && u < r;
}
int find(int u) {
	return u == f[u] ? u : f[u] = find(f[u]);
}
vector<int> vec[N << 2];
void solve(int u, int l, int r, int p, int cur) {
	if(vec[u].size()) {
		for(int i = 0; i < (int) vec[u].size(); i ++) {
			int v = vec[u][i]; v = find(v); f[v] = cur;
			L[cur] = min(L[cur], L[v]); R[cur] = max(R[cur], R[v]);
		}
		vec[u].clear();
		vec[u].push_back(cur);
	}
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(p <= mid) solve(u << 1, l, mid, p, cur);
	else solve(u << 1 | 1, mid + 1, r, p, cur);
}
void pushe(int u, int l, int r, int ql, int qr, int cur) {
	if(l == ql && r == qr) {
		vec[u].push_back(cur);
		return ;
	}
	int mid = (l + r) >> 1;
	if(qr <= mid) pushe(u << 1, l, mid, ql, qr, cur);
	else if(ql > mid) pushe(u << 1 | 1, mid + 1, r, ql, qr, cur);
	else {
		pushe(u << 1, l, mid, ql, mid, cur);
		pushe(u << 1 | 1, mid + 1, r, mid + 1, qr, cur);
	}
}
int main() {
	scanf("%d", &q);
	for(int i = 1; i <= q; i ++) {
		scanf("%d%d%d", &a[i].op, &a[i].l, &a[i].r);
		if(a[i].op == 1) {
			b[++ n] = a[i].l; b[++ n] = a[i].r;
		}
	}
	sort(b + 1, b + n + 1);
	n = unique(b + 1, b + n + 1) - b - 1;
	int c = 0;
	for(int i = 1; i <= q; i ++) {
		if(a[i].op == 1) {
			a[i].l = lower_bound(b + 1, b + n + 1, a[i].l) - b;
			a[i].r = lower_bound(b + 1, b + n + 1, a[i].r) - b;
			c ++; f[c] = c; L[c] = a[i].l; R[c] = a[i].r;
			solve(1, 1, n, a[i].l, c);
			solve(1, 1, n, a[i].r, c);
			if(a[i].l < a[i].r - 1) {
				pushe(1, 1, n, a[i].l + 1, a[i].r - 1, c);
			}
		}
		if(a[i].op == 2) {
			int u = find(a[i].l), v = find(a[i].r);
			bool tag = u == v || bel(L[u], L[v], R[v]) || bel(R[u], L[v], R[v]);
			puts(tag ? "YES" : "NO");
		}
	}
	return 0;
}