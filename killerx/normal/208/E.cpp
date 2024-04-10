#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
#define pb push_back
#define mp make_pair
using ll = long long;
using vi = vector <int>;
using pii = pair <int, int>;
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (auto it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == 45) f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

const int N = 100005;
int n;
map <int, int> cnt[N];
int ind[N];
vi qry[N];
pii Q[N];
vi g[N];
int ans[N];
bool r[N];

void dfs(int u, int p, int dep) {
	ind[u] = u;
	rep(i, g[u].size()) {
		int v = g[u][i];
		dfs(v, u, dep + 1);
		if (cnt[ind[v]].size() > cnt[ind[u]].size()) ind[u] = ind[v];
	}
	cnt[ind[u]][dep] ++;
	rep(i, g[u].size()) {
		int v = g[u][i]; if (ind[v] != ind[u])
		foreach(it, cnt[ind[v]]) cnt[ind[u]][it -> first] += it -> second;
	}
	rep(i, qry[u].size()) ans[qry[u][i]] = cnt[ind[u]][dep + Q[qry[u][i]].second] - 1;
}

int fa[N][20];

void init() {
	rep(j, 20) if (j) rep(i, n) {
		fa[i][j] = (!~fa[i][j - 1] ? -1 : fa[fa[i][j - 1]][j - 1]);
	}
}

int getfa(int u, int t) {
	rep(i, 20) if (t >> i & 1) {
		if (~u) u = fa[u][i];
	}
	return u;
}

int main() {
	n = read();
	rep(i, n) {
		int p = read() - 1;
		if (~p) g[p].pb(i);
		else r[i] = 1;
		fa[i][0] = p;
	}
	init();
	int q = read();
	rep(i, q) {
		Q[i].first = read() - 1;
		Q[i].second = read();
		int fa = getfa(Q[i].first, Q[i].second);
		qry[fa].pb(i);
	}
	rep(u, n) if (r[u]) dfs(u, -1, 0);
	rep(i, q) {
		printf("%d", ans[i]);
		putchar(i + 1 == q ? 10 : 32);
	}
	return 0;
}