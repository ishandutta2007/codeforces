#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pr;
const int maxn = 3e5 + 10;
int n, m, head[maxn], nxt[maxn << 1], to[maxn << 1]; ll c[maxn], ans[maxn]; vector <pr> q[maxn];

inline void addline(int u, int v) {
	static int cnt;
	nxt[++cnt] = head[u], head[u] = cnt, to[cnt] = v;
}

inline void add(int pos, int x) {
	for (; pos <= n; pos += pos & -pos) {
		c[pos] += x;
	}
}

inline ll query(int pos) {
	ll res = 0;
	for (; pos; pos &= pos - 1) {
		res += c[pos];
	}
	return res;
}

inline void upd(int l, int r, int x) {
	add(l, x), add(r + 1, -x);
}

void dfs(int u, int f, int d) {
	for (int i = 0; i < (int)q[u].size(); i++) {
		upd(d, d + q[u][i].first, q[u][i].second);
	}
	ans[u] = query(d);
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != f) dfs(v, u, d + 1);
	}
	for (int i = 0; i < (int)q[u].size(); i++) {
		upd(d, d + q[u][i].first, -q[u][i].second);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		addline(u, v), addline(v, u);
	}
	scanf("%d", &m);
	for (int i = 1, v, d, x; i <= m; i++) {
		scanf("%d %d %d", &v, &d, &x);
		q[v].push_back(pr(d, x));
	}
	dfs(1, 0, 1);
	for (int i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}
	return 0;
}