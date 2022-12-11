#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int N = 200500;
int ne[N<<1], to[N<<1], w[N<<1], h[N], tot;
inline void add(int x, int y, int z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
int dfn[N], low[N], st[N], vis[N], col[N], scc, tp, cnt, m, n;
ll dis[N], G[N];
void tarjan(int x) {
	dfn[x] = low[x] = ++cnt;
	st[++tp] = x, vis[x] = 1;
	for (int i = h[x], y; i; i = ne[i]) {
		if (!dfn[y = to[i]]) tarjan(y), low[x] = min(low[x], low[y]);
		else if (vis[y]) low[x] = min(low[x], low[y]);
	}
	if (dfn[x] == low[x]) {
		++scc; int z;
		while (z = st[tp--]) {
			col[z] = scc, vis[z] = 0;
			if (x == z) break;
		}
	}
}

void dfs(int x) {
	vis[x] = 1; int c = col[x];
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (col[y] != col[x]) continue;
		if (vis[y]) G[c] = __gcd(G[c], dis[x] - dis[y] + w[i]);
		else dis[y] = dis[x] + w[i], dfs(y);
	}
}

int main() {
	read(n), read(m);
	for (int i = 1, x, y, z;i <= m; ++i)
		read(x), read(y), read(z), add(x, y, z);
	for (int i = 1;i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	//for (int i = 1;i <= n; ++i)
		//printf ("dfn[%d] = %d\n", i, dfn[i]);
	for (int i = 1;i <= n; ++i) 
		if (!vis[i]) dfs(i);
	int T; ll s, t, v;
	for (read(T); T; --T) {
		read(v), read(s), read(t);
		v = col[v];
		if (s % __gcd(t, G[v]) == 0) puts("YES");
		else puts("NO");
	}

	return 0;
}