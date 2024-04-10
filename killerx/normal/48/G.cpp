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

#define N 200005

int n;
vi g[N], cost[N];
int siz[N];
ll dis[N], disall[N];
int used[N];
ll ans[N];
int stk[N], tp;
vi c;
int root[N];
ll sum[N + N];
int ccost[N];
ll sum1[N + N], sum2[N + N];
int sumsiz[N + N];
ll Dis[N];
ll sumdisall[N + N];

void dfs1(int u, int p) {
	stk[tp ++] = u;
	used[u] = -1;
	rep(i, g[u].size()) {
		int v = g[u][i];
		if (!~used[v] && v != p) {
			do {
				c.pb(stk[-- tp]);
			} while (stk[tp] != v) ;
		}
		if (used[v]) continue;
		dfs1(v, u);
	}
	used[u] = 1;
	if (tp && stk[tp - 1] == u) -- tp;
}

void dfs2(int u, int p) {
	siz[u] = 1;
	rep(i, g[u].size()) {
		int v = g[u][i], w = cost[u][i];
		if (used[v] || v == p) continue;
		dis[v] = dis[u] + w;
		root[v] = root[u];
		dfs2(v, u);
		siz[u] += siz[v];
		disall[u] += 1LL * w * siz[v] + disall[v];
	}
}

void dfs3(int u, int p, ll D) {
	ll disalll = 0;
	rep(i, g[u].size()) {
		int v = g[u][i], w = cost[u][i];
		if (used[v] || v == p) continue;
		disalll += disall[v] + 1LL * w * siz[v];
	}
	rep(i, g[u].size()) {
		int v = g[u][i], w = cost[u][i];
		if (used[v] || v == p) continue;
		dfs3(v, u, D + 1LL * (siz[c[root[u]]] - siz[v]) * w + disalll - disall[v] - 1LL * w * siz[v]);
	}
	Dis[u] = D + disall[u];
}

int Bin(int i) {
	int lb, rb;
	lb = i, rb = c.size();
	while (lb < rb) {
		int md = (lb + rb + 1) >> 1;
		if (sum[md] - sum[i] > sum[c.size()] - sum[md] + sum[i]) rb = md - 1;
		else lb = md;
	}
	if (lb == c.size()) {
		lb = 0, rb = i;
		while (lb < rb) {
			int md = (lb + rb + 1) >> 1;
			if (sum[i] - sum[md] < sum[c.size()] - sum[i] + sum[md]) rb = md - 1;
			else lb = md;
		}
	}
	return lb;
}

ll Sum1(int l, int r) {
	return sum1[r] - (l ? sum1[l - 1] : 0) - 1LL * (sumsiz[r + 1] - sumsiz[l]) * sum[l];
}

ll Sum2(int l, int r) {
	return sum2[l] - sum2[r + 1] - 1LL * (sumsiz[r + 1] - sumsiz[l]) * (sum[2 * c.size() - 1] - sum[r]);
}

int main() {
	n = read();
	rep(i, n) {
		int u = read() - 1, v = read() - 1, w = read();
		g[u].pb(v), g[v].pb(u);
		cost[u].pb(w), cost[v].pb(w);
	}
	dfs1(0, -1);
//	rep(i, c.size()) eprintf("%d ", c[i] + 1); eprintf("\n");
	memset(used, 0, sizeof used);
	rep(i, c.size()) {
		rep(j, g[c[i]].size()) {
			if (g[c[i]][j] == c[(i + 1) % (int) c.size()]) {
				ccost[i] = cost[c[i]][j];
			}
		}
	}
	rep(i, c.size() * 2) sum[i + 1] = sum[i] + ccost[i % c.size()];
	rep(i, c.size()) {
		used[c[i]] = 1;
		root[c[i]] = i;
	}
	rep(i, c.size()) dfs2(c[i], -1);
	rep(i, c.size()) dfs3(c[i], -1, 0);
	rep(i, c.size() * 2) sumsiz[i + 1] = sumsiz[i] + siz[c[i % c.size()]];
	rep(i, c.size() * 2) sumdisall[i + 1] = sumdisall[i] + disall[c[i % c.size()]];
	sum1[0] = disall[c[0]];
	rep(i, c.size() * 2) if (i) sum1[i] = sum1[i - 1] + 1LL * sum[i] * siz[c[i % c.size()]] + disall[c[i % c.size()]];
	sum2[c.size() * 2 - 1] = disall[c[c.size() - 1]];
	for (int i = c.size() * 2 - 2; ~i; -- i) sum2[i] = sum2[i + 1] + 1LL * (sum[c.size() * 2 - 1] - sum[i]) * siz[c[i % c.size()]] + disall[c[i % c.size()]];
	rep(i, c.size()) {
		int u = c[i], j = Bin(i);
		ans[c[i]] += Sum1(i, j < i ? j + c.size() : j);
		ans[c[i]] += Sum2(j + 1, i < j + 1 ? i + c.size() : i);
		ans[c[i]] -= disall[c[i]];
	}
	rep(i, n) if (!ans[i]) {
		ans[i] = ans[c[root[i]]] - disall[c[root[i]]] + 1LL * (n - siz[c[root[i]]]) * dis[i] + Dis[i];
	}
	rep(i, n) printf("%lld", ans[i]), putchar(i + 1 == n ? 10 : 32);
	return 0;
}