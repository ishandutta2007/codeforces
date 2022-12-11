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

const int N = 20005;
int h[N], ne[N<<1], to[N<<1], w[N<<1], dep[N], F[17][N], siz[N], dfn[N], cnt, tot, m, n;
inline void add(int x, int y, int z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
struct node { 
	int fi; char se; int th;
	node() {}
	node(int a, char b, int c) { fi = a, se = b, th = c; }
}f[N];

vector<node > vec[N];

void dfs(int x, int fa) {
	dep[dfn[x] = ++cnt] = dep[fa] + 1;
	F[0][cnt] = fa, siz[cnt] = 1;
	for (int i = 1; F[i - 1][cnt]; ++i)
		F[i][cnt] = F[i-1][F[i-1][cnt]];
	for (int i = h[x], y; i; i = ne[i]) {
		if (!dfn[y = to[i]]) {
			dfs(y, dfn[x]), siz[dfn[x]] += siz[dfn[y]];
			vec[dfn[x]].emplace_back(dfn[y], w[i], dfn[y] < dfn[x] ? n - siz[dfn[x]] : siz[dfn[y]]);
		}
		else f[dfn[x]].fi = dfn[y], f[dfn[x]].se = w[i], f[dfn[x]].th = n - siz[dfn[x]];
	}
	f[dfn[x]].th = n - siz[dfn[x]];
	if (fa) vec[dfn[x]].emplace_back(f[dfn[x]]);
}

inline int Lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 16; ~i; --i)
		if (dep[F[i][x]] >= dep[y]) x = F[i][x];
	if (x == y) return y;
	for (int i = 16; ~i; --i)
		if (F[i][x] != F[i][y]) x = F[i][x], y = F[i][y];
	return F[0][x];
}

int st[N], fr[N], d[N], c[N], tp;
void getC(int x, int y) {
	int t = Lca(x, y);
	while (x != t) c[++tp] = f[x].se, x = f[x].fi;
	tp += dep[y] - dep[t]; c[tp + 1] = 0;
	while (y != t) c[tp--] = f[y].se, y = f[y].fi;
}

int solve(void) {
	int res = -1;
	d[1] = 1, fr[1] = 0;
	while (tp) {
		int x = st[tp], ff = fr[tp], kd = d[tp] + 1, cc = c[kd - 1]; --tp; 
		res += cc ? 1 : 0;
		//printf ("x = %d, ff = %d, kd = %d, cc = %c\n", x, ff, kd, (char)cc);
		for (auto t: vec[x]) if (t.fi != ff) {
			//printf ("t.fi = %d, t.se = %c, t.th = %d\n", t.fi, t.se, t.th);
			if (t.se < cc) res += t.th;
			else if (t.se == cc) st[++tp] = t.fi, fr[tp] = x, d[tp] = kd;
		}
		//printf ("res = %d\n", res);
	}
	return res;
}

int main() {
	srand(time(0));
	read(n), read(m);
	for (int i = 1, x, y, c;i < n; ++i) {
		char ch[4]; 
		read(x), read(y);
		scanf ("%s", ch); c = ch[0];
		add(x, y, c), add(y, x, c);
	}
	int rt = rand() % n + 1;
	dfs(rt, 0);
	for (int i = 1, x, y;i <= m; ++i) {
		read(x), read(y), x = dfn[x], y = dfn[y], getC(x, y);
		st[tp = 1] = x, write(solve());
	}
	return 0;
}