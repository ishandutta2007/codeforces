#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5, mul = 233, mod = 1e9 + 7;
int n;
char str[mxn];
int head[mxn], nex[mxn * 2], to[mxn * 2], tot;
int fa[mxn], dep[mxn], sz[mxn], son[mxn];
int top[mxn], dfn[mxn], ed[mxn], on[mxn], tim;
char s[mxn * 2];
int A[mxn * 2], pw[mxn * 2];
int alle[mxn * 2];

inline void adde(int u, int v) {
	to[++ tot] = v;
	nex[tot] = head[u];
	head[u] = tot;
}

inline void dfs(int u, int p) {
	sz[u] = 1, son[u] = -1;
	for (int e = head[u]; e; e = nex[e]) {
		int v = to[e];
		if (v == p) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
		if (!~son[u] || sz[v] > sz[son[u]]) son[u] = v;
	}
}

inline void hld(int u, int p) {
	top[u] = ~p && u == son[p] ? top[p] : u;
	on[tim] = u, dfn[u] = tim ++;
	if (~son[u]) {
		hld(son[u], u);
	}
	for (int e = head[u]; e; e = nex[e]) {
		int v = to[e];
		if (v == p || v == son[u]) continue;
		hld(v, u);
	}
	ed[u] = tim;
}

struct range {
	int l, r;
};

inline void getpath(int u, int v, range vec[], int &sz) {
	sz = 0;
	static range VEC[40];
	int SZ = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]])
			vec[sz ++] = {n * 2 - 1 - dfn[u], n * 2 - 1 - dfn[top[u]]}, u = fa[top[u]];
		else
			VEC[SZ ++] = {dfn[top[v]], dfn[v]}, v = fa[top[v]];
	}
	if (dep[u] > dep[v]) vec[sz ++] = {n * 2 - 1 - dfn[u], n * 2 - 1 - dfn[v]};
	else vec[sz ++] = {dfn[u], dfn[v]};
	while (SZ --) vec[sz ++] = VEC[SZ];
}

inline bool eq(int x, int y, int l) {
	if (s[x] != s[y]) return 0;
	if (std::min(alle[x], l) != std::min(alle[y], l)) return 0;
	return (1LL * (A[x] - A[y]) * pw[l] + mod - A[x + l] + A[y + l]) % mod == 0;
}

inline int getlcp(int x, int y, int l) {
	if (s[x] != s[y]) return 0;
	int e = 1, le = 0;
	while (e < l && eq(x, y, e)) le = e, e <<= 1;
	int lb = le, rb = std::min(e, l);
	while (lb + 1 < rb) {
		int md = (lb + rb) >> 1;
		if (eq(x, y, md)) lb = md;
		else rb = md;
	}
	return lb;
}

namespace IO {
	const int mxsz = 1 << 23;
	char ibuf[mxsz], *iend = ibuf + mxsz, *ipos = iend, obuf[mxsz], *oend = obuf + mxsz, *opos = obuf;
	inline char get_char() { if (ipos == iend) iend = (ipos = ibuf) + fread(ibuf, 1, mxsz, stdin); return *ipos ++; }
	inline void put_char(char c) { if (opos == oend) fwrite(opos = obuf, 1, mxsz, stdout); *opos ++ = c; }
}
inline void read(int &x) {
	x = 0; char c = IO::get_char();
	while (c <= 32) c = IO::get_char();
	while (c > 32) x = x * 10 + c - 48, c = IO::get_char();
}
inline void write(int x) { if (x >= 10) write(x / 10); IO::put_char(x % 10 + 48); }
inline void writeln(int x) { write(x); IO::put_char(10); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif
	read(n);
	rep(i, n) {
		str[i] = IO::get_char();
		while (isspace(str[i])) str[i] = IO::get_char();
	}
	rep(i, n - 1) {
		int u, v;
		read(u), read(v);
		-- u, -- v;
		adde(u, v); adde(v, u);
	}
	dfs(0, -1);
	hld(0, -1);
	rep(i, n) s[dfn[i]] = str[i], s[2 * n - 1 - dfn[i]] = str[i];
	for (int i = 2 * n - 1; ~i; -- i) alle[i] = s[i] == s[i + 1] ? alle[i + 1] : 1;
	rep(i, 2 * n + 1) pw[i] = i ? 1LL * mul * pw[i - 1] % mod : 1;
	rep(i, 2 * n) A[i + 1] = (1LL * mul * A[i] + s[i]) % mod;
	int q;
	read(q);
	while (q --) {
		int u, v, x, y;
		read(u), read(v), read(x), read(y);
		-- u, -- v, -- x, -- y;
		if (str[u] != str[x]) {
			writeln(0);
			continue;
		}
		static range vec1[40], vec2[40];
		int sz1, sz2;
		getpath(u, v, vec1, sz1);
		getpath(x, y, vec2, sz2);
		int l = 0;
		for (int i = 0, p = vec1[i].l, j = 0, q = vec2[j].l; i < sz1 && j < sz2; ) {
			int nl = std::min(vec1[i].r - p + 1, vec2[j].r - q + 1);
			if (eq(p, q, nl)) {
				l += nl;
				if (nl == vec1[i].r - p + 1) ++ i, p = vec1[i].l; else p += nl;
				if (nl == vec2[j].r - q + 1) ++ j, q = vec2[j].l; else q += nl;
				continue;
			}
			nl = getlcp(p, q, nl);
			l += nl, p += nl, q += nl;
			break;
		}
		writeln(l);
	}
	fwrite(IO::obuf, 1, IO::opos - IO::obuf, stdout);
	return 0;
}