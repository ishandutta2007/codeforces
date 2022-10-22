#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n, m;
vi g[1000005];
vi rg[1000005];
int cc, c[1000005];
int vec[1000005], tme;
bool vis[1000005];
int out[1000005];

void dfs(int u) {
	vis[u] = 1;
	rep(i, g[u].size()) {
		int v = g[u][i];
		if (!vis[v]) dfs(v);
	}
	vec[-- tme] = u;
}

void rdfs(int u) {
	c[u] = cc;
	rep(i, rg[u].size()) {
		int v = rg[u][i];
		if (!~c[v]) rdfs(v);
	}
}

void scc() {
	rep(i, n) vis[i] = 0; tme = n;
	rep(i, n) if (!vis[i]) dfs(i);
	rep(i, n) c[i] = -1; cc = 0;
	rep(i, n) if (!~c[vec[i]]) {rdfs(vec[i]); cc ++;}
}

void Main() {
	n = read(), m = read();
	rep(i, n) g[i].clear(), rg[i].clear();
	rep(i, m) {
		int u = read() - 1, v = read() - 1;
		if (u != v) g[u].pb(v), rg[v].pb(u);
	}
	scc();
	if (cc == 1) {
		puts("No"); return;
	}
	rep(i, cc) out[i] = 0;
	rep(i, n) rep(j, g[i].size()) {
		if (c[g[i][j]] != c[i]) out[c[i]] ++;
	}
	rep(i, cc) if (!out[i]) {
		vi a, b;
		rep(j, n) if (c[j] == i) a.pb(j);
		rep(j, n) if (c[j] != i) b.pb(j);
		puts("Yes");
		printf("%d %d\n", (int) a.size(), (int) b.size());
		rep(i, a.size()) printf("%d%c", a[i] + 1, " \n"[i + 1 == (int) a.size()]);
		rep(i, b.size()) printf("%d%c", b[i] + 1, " \n"[i + 1 == (int) b.size()]);
		return;
	}
}

int main() {
	int T = read(); while (T --) Main();
	return 0;
}