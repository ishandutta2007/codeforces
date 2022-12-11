#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

struct Edge {
	int v, w, nxt;
} e[N * 2];
int hd[N], p, n, M;
void clr() { fill(hd + 1, hd + n + 1, -1); p = 0; }
void add(int u, int v, int w) {
	e[p] = (Edge) {v, w, hd[u]}; hd[u] = p ++;
}
int rt, sz[N], f[N], size;
bool vis[N];
void findrt(int u, int fa = 0) {
	sz[u] = 1; f[u] = 0;
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		Edge &g = e[i];
		if(g.v != fa && !vis[g.v]) {
			findrt(g.v, u);
			f[u] = max(f[u], sz[g.v]);
			sz[u] += sz[g.v];
		}
	}
	f[u] = max(f[u], size - sz[u]);
	if(!rt || f[rt] > f[u]) rt = u;
}
ll ans;
int pw[N], ad[N], au[N], d[N], c;
void dfs(int u, int fa, int vd, int vu, int de) {
	c ++; ad[c] = vd; au[c] = vu; d[c] = de;
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		Edge &g = e[i];
		if(g.v != fa && !vis[g.v]) {
			dfs(g.v, u, (vd * 10ll + g.w) % M, (1ll * pw[de] * g.w + vu) % M, de + 1);
		}
	}
}
void exgcd(ll a, ll b, ll &x, ll &y, ll &g) {
	if(!b) x = 1ll, y = 0ll, g = a;
	else exgcd(b, a % b, y, x, g), y -= x * (a / b);
}
ll calc(int u, int vd, int vu, int de) {
	c = 0; dfs(u, 0, vd % M, vu % M, de);
	ll res = 0;
	if(c == 0) return 0;
	sort(au + 1, au + c + 1);
	for(int i = 1; i <= c; i ++) {
		ll x, y, g, v = (M - ad[i]) % M;
		exgcd(pw[d[i]], M, x, y, g);
		if(v % g == 0) {
			x = x * (v / g) % M;
			x = (x + M) % M;
			int L = lower_bound(au + 1, au + c + 1, x) - au;
			int R = upper_bound(au + 1, au + c + 1, x) - au;
			res += R - L;
		}
	}
	return res;
}
void solve(int u) {
	vis[u] = 1; ans += calc(u, 0, 0, 0);
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		Edge &g = e[i];
		if(!vis[g.v]) ans -= calc(g.v, g.w, g.w, 1);
	}
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		Edge &g = e[i];
		if(!vis[g.v]) {
			size = sz[g.v]; rt = 0; findrt(g.v); solve(rt);
		}
	}
}
int main() {
	scanf("%d%d", &n, &M); clr();
	pw[0] = 1 % M;
	for(int i = 1; i <= n; i ++) pw[i] = 10ll * pw[i - 1] % M;
	int u, v, w;
	for(int i = 1; i < n; i ++) {
		scanf("%d%d%d", &u, &v, &w);
		u ++; v ++; add(u, v, w); add(v, u, w);
	}
	rt = 0; size = n; findrt(1); solve(rt);
	printf("%I64d\n", ans - n);
	return 0;
}
/*
k bits, down val = x
10^k * up(y) = - val (mod M)
pw[k] * up + M y = -val
*/