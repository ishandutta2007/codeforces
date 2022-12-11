#include <bits/stdc++.h>
using namespace std;
inline void Mx(int &x, int y) { x < y && (x = y); }
const int N = 200005, Q = 5005, D = 5001;
struct node {
	int l, r; double p;
	bool operator < (const node &i) const {
		return l == i.l ? r > i.r : l < i.l; 
	}
}p[Q];
vector<int> v[N]; double f[Q][Q<<1];
int g[N], a[N], mx, q, n, L, R;
int find(int x) { return g[x] == x ? x : g[x] = find(g[x]); }
int dfs(int x, int l, int r) {
	int tp = 0;
	for (int t: v[x]) Mx(tp, dfs(t, p[t].l, p[t].r));
	for (int i = find(l);i <= r; i = find(i)) Mx(tp, a[i]), g[i] = i + 1;
	for (int i = L;i <= tp - mx + D; i++) f[x][i] = 1;
	for (int t: v[x]) for (int i = R;i >= L; i--) 
			f[x][i] = 1 - (1 - f[x][i]) * (1 - f[t][i]);
	for (int i = R;i >= 1; i--)
		f[x][i] = f[x][i] * (1 - p[x].p) + f[x][i-1] * p[x].p;
	return tp;
}

int main() {
	scanf ("%d%d", &n, &q), L = D - q, R = D + q; g[n+1] = n + 1;
	for (int i = 1;i <= n; i++) scanf ("%d", a + i), Mx(mx, a[g[i] = i]);
	for (int i = 1;i <= q; i++) scanf ("%d%d%lf", &p[i].l, &p[i].r, &p[i].p);
	p[++q] = (node) {1, n, 0.0}; sort(p + 1, p + q + 1);
	for (int i = 1;i <= q; i++) for (int j = i - 1;j >= 1; j--) 
			if (p[j].r >= p[i].r) { v[j].push_back(i);  break; }
	dfs(1, 1, n); double ans = 0;
	for (int i = D + 1;i <= R; i++) ans += f[1][i];
	printf ("%.8lf\n", ans + mx);
	return 0;
}