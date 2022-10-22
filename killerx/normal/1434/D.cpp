#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void read(int &x) {
	x = 0;
	bool f = true;
	int c = getchar();
	while (c <= 32) c = getchar();
	if (c == 45) f = false, c = getchar();
	while (c > 32) x = x * 10 + c - 48, c = getchar();
	if (!f) x *= -1;
}

inline void write(int x) {
	if (x < 0) {
		putchar(45);
		write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

inline void writeln(int x) {
	write(x);
	putchar(10);
}

struct SEG {
	static const int mxn = 1 << 22;
	struct S {
		int mn, mx[2], mx2l[2], mx2r[2], ans;
		S operator+ (const S &o) const {
			S a;
			a.mn = min(mn, o.mn);
			a.ans = max(ans, o.ans);
			rep(p, 2) {
				a.mx[p] = max(mx[p], o.mx[p]);
				a.mx2l[p] = max(max(mx2l[p], o.mx2l[p]), mx[p] - 2 * o.mn);
				a.mx2r[p] = max(max(mx2r[p], o.mx2r[p]), o.mx[p] - 2 * mn);
				a.ans = max(a.ans, max(mx2l[p] + o.mx[p], mx[p] + o.mx2r[p]));
			}
			return a;
		}
	} s[mxn << 1];
	bool tag[mxn << 1];

	void push(int x) {
		tag[x] ^= 1;
		swap(s[x].mx[0], s[x].mx[1]);
		swap(s[x].mx2l[0], s[x].mx2l[1]);
		swap(s[x].mx2r[0], s[x].mx2r[1]);
	}

	void pushdown(int x) {
		if (tag[x]) {
			push(x << 1);
			push(x << 1 | 1);
			tag[x] = 0;
		}
	}

	void pushup(int x) {
		s[x] = s[x << 1] + s[x << 1 | 1];
	}

	void build(int i, int a, int b, int *vec, int *dep, int *xsum) {
		if (a + 1 == b) {
			int u = vec[a];
			s[i].mn = dep[u];
			memset(s[i].mx, -0x3f, sizeof(s[i].mx));
			memset(s[i].mx2l, -0x3f, sizeof(s[i].mx2l));
			memset(s[i].mx2r, -0x3f, sizeof(s[i].mx2r));
			s[i].mx[xsum[u]] = dep[u];
			s[i].mx2l[xsum[u]] = -dep[u];
			s[i].mx2r[xsum[u]] = -dep[u];
			s[i].ans = 0;
			return ;
		}
		int m = (a + b) >> 1;
		build(i << 1, a, m, vec, dep, xsum);
		build(i << 1 | 1, m, b, vec, dep, xsum);
		pushup(i);
	}

	void upd(int i, int a, int b, int l, int r) {
		if (r <= a || b <= l) return ;
		if (l <= a && b <= r) return push(i);
		pushdown(i);
		int m = (a + b) >> 1;
		upd(i << 1, a, m, l, r);
		upd(i << 1 | 1, m, b, l, r);
		pushup(i);
	}
} seg;

const int mxn = 1 << 22;

int n;
vector <int> g[mxn], c[mxn];
int dfn[mxn], ed[mxn], tme, vec[mxn];
int dep[mxn], xsum[mxn];
vector <pair <int, int> > E;

void dfs(int u, int p) {
	vec[tme] = u, dfn[u] = ed[u] = tme ++;
	rep(i, g[u].size()) {
		int v = g[u][i];
		int w = c[u][i];
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		xsum[v] = xsum[u] ^ w;
		dfs(v, u);
		vec[tme] = u, ed[u] = tme ++;
	}
}

int main() {
	read(n);
	rep(i, n - 1) {
		int u, v, w;
		read(u), read(v), read(w);
		-- u, -- v;
		g[u].pb(v), c[u].pb(w);
		g[v].pb(u), c[v].pb(w);
		E.pb(mp(u, v));
	}
	dfs(0, -1);
	seg.build(1, 0, tme, vec, dep, xsum);
	rep(i, E.size()) {
		if (dep[E[i].first] > dep[E[i].second]) {
			swap(E[i].first, E[i].second);
		}
	}
	int q;
	read(q);
	while (q --) {
		int id;
		read(id);
		-- id;
		int u = E[id].second;
		seg.upd(1, 0, tme, dfn[u], ed[u] + 1);
		writeln(seg.s[1].ans);
	}
	return 0;
}