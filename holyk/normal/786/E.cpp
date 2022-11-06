#include <bits/stdc++.h>
#define REP(i, a, b) for (int i(a); i <= (b); ++i)
#define pb push_back
#define gc getchar()
struct Reader {
	template <class T> inline operator T() {
		char c, p = 0; T w;
		while (!isdigit(c = gc)) if (c == '-') p = 1;
		for (w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
		return p ? -w : w;
	}
} rd;

template <class T> inline bool smin(T&x, const T&y) { return y < x ? x = y, 1 : 0; }
template <class T> inline bool smax(T&x, const T&y) { return x < y ? x = y, 1 : 0; }

typedef long long ll;

const int N(2e4 + 5), M(1e6 + 5);
int n, m, cnt, id[20][N], up[20][N], dep[N];
int head[N], to[N << 1], ne[N << 1], tot;
inline void add(int x, int y) { to[++tot] = y, ne[tot] = head[x], head[x] = tot; }

namespace MaxFlow {

struct Edge {
	int v, w, ne;
} e[10000005];
int head[M], tot = 1;
inline void add(int x, int y, int z) {
	e[++tot] = {y, z, head[x]}, head[x] = tot;
	e[++tot] = {x, 0, head[y]}, head[y] = tot;
}
int s, t, d[M], gap[M];
int dfs(int x, int flow) {
	if (x == t || !flow) return flow;
	int used = 0;
	for (int i = head[x]; i; i = e[i].ne)
		if (e[i].w && d[x] == d[e[i].v] + 1) {
			int f = dfs(e[i].v, std::min(e[i].w, flow - used));
			used += f, e[i].w -= f, e[i ^ 1].w += f;
			if (used == flow) return flow;
		}
	if (!--gap[d[x]]) d[s] = t + 1;
	++gap[++d[x]];
	return used;
}

bool vis[M];
void dfs(int x) {
	vis[x] = 1;
	for (int i = head[x]; i; i = e[i].ne)
		if (e[i].w && !vis[e[i].v])
			dfs(e[i].v);
}
void solve() {
	std::vector<int> ans1, ans2;
	int r = 0;
	while (d[s] <= t) r += dfs(s, 1e9);
	dfs(s);
	REP(i, 1, m) if (!vis[i]) ans1.pb(i);
	REP(i, 2, n) if (vis[id[0][i]]) ans2.pb(id[0][i] - m);
	printf("%d\n%d", r, (int)ans1.size());
	for (int i : ans1) printf(" %d", i);
	printf("\n%d", (int)ans2.size());
	for (int i : ans2) printf(" %d", i);
}
}

void go(int x) {
	for (int i = head[x]; i; i = ne[i])
		if (to[i] != up[0][x]) {
			up[0][to[i]] = x;
			id[0][to[i]] = (i + 1 >> 1) + m;
			dep[to[i]] = dep[x] + 1;
			go(to[i]);
		}
}
void init() {
	n = rd, m = rd;
	REP(i, 2, n) {
		int x = rd, y = rd;
		add(x, y), add(y, x);
	}
	using MaxFlow::add;
	REP(i, 1, m) add(0, i, 1);
	cnt = m + n - 1;
	go(1);
	REP(i, 1, 16) REP(x, 1, n) {
		up[i][x] = up[i - 1][up[i - 1][x]];
		if (up[i][x]) {
			id[i][x] = ++cnt;
			add(cnt, id[i - 1][x], 1e9), add(cnt, id[i - 1][up[i - 1][x]], 1e9);
		}
	}
	MaxFlow::t = ++cnt;
	REP(i, 1, n - 1) add(m + i, cnt, 1);
	REP(o, 1, m) {
		int x = rd, y = rd;
		
		if (dep[x] != dep[y]) {
			if (dep[x] < dep[y]) std::swap(x, y);
			for (int i = 0; dep[x] ^ dep[y]; ++i)
				if (dep[x] - dep[y] >> i & 1)
					add(o, id[i][x], 1e9), x = up[i][x];
		}
		if (x == y) continue;
		for (int i = std::__lg(dep[x]); ~i; --i)
			if (up[i][x] != up[i][y]) {
				add(o, id[i][x], 1e9), add(o, id[i][y], 1e9);
				x = up[i][x], y = up[i][y];
			}
		add(o, id[0][x], 1e9), add(o, id[0][y], 1e9);	
	}
}
int main() {
	init();
	MaxFlow::solve();
	return 0;
}