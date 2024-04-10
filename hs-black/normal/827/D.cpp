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

const int N = 200050;
int dep[N], f[N], st[N], nb[N], F[19][N], mn[19][N], m, n;
int h[N], ne[N<<1], w[N<<1], to[N<<1], ans[N], tot, tp;
inline int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
inline void add(int x, int y, int z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		F[0][y] = x, mn[0][y] = w[i], nb[y] = st[(i + 1) >> 1];
		for (int j = 1; F[j - 1][y]; ++j) {
			F[j][y] = F[j-1][F[j-1][y]];
			mn[j][y] = max(mn[j-1][y], mn[j-1][F[j-1][y]]);
		}
		dfs(y, x);
	}
	//printf ("nb[%d] = %d\n", x, nb[x]);
	//for (int i = 4;i >= 0; --i)
		//printf ("mn[%d][%d] = %d\n", i, x, mn[i][x]);
}

pair<int, int> get(int x, int y) {
	int mmn = 0;
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 18; i >= 0; --i)
		if (dep[F[i][x]] >= dep[y]) mmn = max(mmn, mn[i][x]), x = F[i][x];
	if (x == y) return make_pair(x, mmn);
	for (int i = 18; i >= 0; --i)
		if (F[i][x] != F[i][y]) mmn = max(mmn, max(mn[i][x], mn[i][y])), x = F[i][x], y = F[i][y];
	mmn = max(mmn, max(mn[0][x], mn[0][y]));
	return make_pair(F[0][x], mmn);
}

struct edges { int x, y, z, id; }ed[N];

int main() {
	read(n), read(m);
	for (int i = 1;i <= m; ++i) 
		read(ed[i].x), read(ed[i].y), read(ed[i].z), ed[i].id = i;
	sort(ed + 1, ed + m + 1, [&](edges x, edges y) { return x.z < y.z; });
	for (int i = 1;i <= n; ++i) f[i] = i;
	for (int i = 1;i <= m; ++i) {
		int x = ed[i].x, y = ed[i].y;
		if (find(x) == find(y)) continue;
		//printf ("add(%d, %d, %d)\n", x, y, ed[i].z);
		ed[i].x = ed[i].y = -1, st[++tp] = ed[i].id;
		add(x, y, ed[i].z), add(y, x, ed[i].z);
		f[find(x)] = find(y);
	}
	dfs(1, 0);
	for (int i = 1;i <= n; ++i) f[i] = i;
	for (int i = 1;i <= m; ++i) ans[i] = -1;
	for (int i = 1;i <= m; ++i) if (ed[i].x > 0) {
		//printf ("ed[%d].z = %d\n", i, ed[i].z);
		int x = ed[i].x, y = ed[i].y;
		pair<int, int> t(get(x, y));
		ans[ed[i].id] = t.second - 1;
		while (dep[x = find(x)] > dep[t.first]) f[x] = F[0][x], ans[nb[x]] = ed[i].z - 1;
		while (dep[y = find(y)] > dep[t.first]) f[y] = F[0][y], ans[nb[y]] = ed[i].z - 1;
	}
	for (int i = 1;i <= m; ++i) write(ans[i], ' ');
	return 0;
}