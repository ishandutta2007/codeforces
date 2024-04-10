#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 25005;
const int mxq = 100005;
const int sq = 80;
const int nsq = mxn / sq + 5;

int n, q;
int perm[mxn], inv[mxn];

struct Range {
	int l, r;
} rng[mxq];

struct Edge {
	int u, v;

	Edge(): u(), v() { }

	Edge(int _u, int _v): u(_u), v(_v) { }
} cand[mxq * sq * 2];
int candsz;

int candlsz[mxn], *candl[mxn];
int candrsz[mxn], *candr[mxn];

void add_cand(int u, int v) {
	cand[candsz ++] = Edge(u, v);
}

int *ell[mxn], *elr[mxn], *erl[mxn], *err[mxn];

namespace CandGen {
int id[mxq];

bool comp(int a, int b) {
	return rng[a].l / sq == rng[b].l / sq ?
		rng[a].r < rng[b].r :
		rng[a].l / sq < rng[b].l / sq;
}

std::set <int> cur;

void insert(int p) {
	cur.insert(perm[p]);
	std::set <int>::iterator it = cur.find(perm[p]), nit;
	if (it != cur.begin()) {
		nit = it; -- nit;
		add_cand(inv[*nit], p);
	}
	nit = it; ++ nit;
	if (nit != cur.end()) {
		add_cand(p, inv[*nit]);
	}
}

void erase(int p) {
	std::set <int>::iterator it = cur.find(perm[p]), lit, rit;
	rit = it; ++ rit;
	if (it != cur.begin() && rit != cur.end()) {
		lit = it; -- lit;
		add_cand(inv[*lit], inv[*rit]);
	}
	cur.erase(perm[p]);
}

void solve() {
	rep(i, q) id[i] = i;
	std::sort(id, id + q, comp);
	int L = 0, R = 0;
	rep(i, q) {
		while (L > rng[id[i]].l) insert(-- L);
		while (R < rng[id[i]].r) insert(R ++);
		while (L < rng[id[i]].l) erase(L ++);
		while (R > rng[id[i]].r) erase(-- R);
	}
	// rep(i, candsz) eprintf("%d %d\n", cand[i].u + 1, cand[i].v + 1);
	rep(i, candsz) if (cand[i].u < cand[i].v) ++ candrsz[cand[i].u];
	else ++ candlsz[cand[i].u];
	rep(i, n) candl[i] = new int[candlsz[i]], candlsz[i] = 0;
	rep(i, n) candr[i] = new int[candrsz[i]], candrsz[i] = 0;
	rep(i, candsz) if (cand[i].u < cand[i].v)
		candr[cand[i].u][candrsz[cand[i].u] ++] = cand[i].v;
	else
		candl[cand[i].u][candlsz[cand[i].u] ++] = cand[i].v;
	rep(i, n) {
		std::sort(candl[i], candl[i] + candlsz[i]);
		std::sort(candr[i], candr[i] + candrsz[i]);
		std::reverse(candl[i], candl[i] + candlsz[i]);
		candlsz[i] = std::unique(candl[i], candl[i] + candlsz[i]) - candl[i];
		candrsz[i] = std::unique(candr[i], candr[i] + candrsz[i]) - candr[i];
	}
}
} // CandGen

namespace Q {
struct Event {
	int tp, x, y, i;

	Event(): tp(), x(), y(), i() { }

	Event(int _tp, int _x, int _y, int _i): tp(_tp), x(_x), y(_y), i(_i) { }

	bool operator < (const Event &oth) const {
		if (y != oth.y) return y > oth.y;
		if (tp != oth.tp) return tp > oth.tp;
		return 0;
	}
} evt[mxq * sq * 4 + mxq];
int evtsz;

int mn[mxn];
int o;

void update(int x, int v) {
	for (++ x; x < mxn; x += x & -x)
		mn[x] = std::min(mn[x], v);
}

int query(int x) {
	int ans = mxq;
	for (++ x; x; x -= x & -x)
		ans = std::min(ans, mn[x]);
	return ans;
}

inline void add_range(int l, int r, int i) {
	evt[evtsz ++] = Event(1, l, r, i);
}

inline int add_query(int l, int r) {
	evt[evtsz ++] = Event(0, l, r, o);
	return o ++;
}

int ans[mxq * sq * 8];

void solve() {
	rep(i, mxn) mn[i] = mxq;
	std::sort(evt, evt + evtsz);
	rep(i, evtsz) {
		if (evt[i].tp == 0) ans[evt[i].i] = query(evt[i].x);
		else update(evt[i].x, evt[i].i);
	}
}
} // Q

int ans[mxq];

inline void update(int l, int r, int v) { ans[l] += v; ans[r] -= v; }

int main() {
	// freopen("in", "r", stdin);
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &perm[i]), -- perm[i], inv[perm[i]] = i;
	rep(i, q) scanf("%d %d", &rng[i].l, &rng[i].r), -- rng[i].l;
	CandGen::solve();
	rep(i, q) Q::add_range(rng[i].l, rng[i].r, i);
	rep(i, n) {
		ell[i] = new int[candlsz[i]];
		elr[i] = new int[candlsz[i]];
		erl[i] = new int[candrsz[i]];
		err[i] = new int[candrsz[i]];
		for (int j = 0, k = 0; j < candlsz[i]; ++ j) {
			ell[i][j] = Q::add_query(candl[i][j], i + 1);
			while (k < candrsz[i] && perm[candr[i][k]] > perm[candl[i][j]]) ++ k;
			if (k < candrsz[i])
				elr[i][j] = Q::add_query(candl[i][j], candr[i][k] + 1);
			else
				elr[i][j] = -1;
		}
		for (int j = 0, k = 0; j < candrsz[i]; ++ j) {
			erl[i][j] = Q::add_query(i, candr[i][j] + 1);
			while (k < candlsz[i] && perm[candl[i][k]] > perm[candr[i][j]]) ++ k;
			if (k < candlsz[i])
				err[i][j] = Q::add_query(candl[i][k], candr[i][j] + 1);
			else
				err[i][j] = -1;
		}
	}
	Q::solve();
	rep(i, n) {
		rep(j, candlsz[i]) ell[i][j] = Q::ans[ell[i][j]];
		rep(j, candlsz[i]) elr[i][j] = elr[i][j] == -1 ? q : Q::ans[elr[i][j]];
		rep(j, candlsz[i] - 1) elr[i][j] = std::min(elr[i][j], ell[i][j + 1]);
		rep(j, candlsz[i]) update(ell[i][j], elr[i][j], +1);

		rep(j, candrsz[i]) erl[i][j] = Q::ans[erl[i][j]];
		rep(j, candrsz[i]) err[i][j] = err[i][j] == -1 ? q : Q::ans[err[i][j]];
		rep(j, candrsz[i] - 1) err[i][j] = std::min(err[i][j], erl[i][j + 1]);
		rep(j, candrsz[i]) update(erl[i][j], err[i][j], +1);
	}
	rep(i, q) if (i) ans[i] += ans[i - 1];
	rep(i, q) printf("%d\n", ans[i]);
	/*
	rep(i, n) {
		eprintf("--------------------\n");
		eprintf("%d:\n", i + 1);
		eprintf("L:\n");
		rep(j, candlsz[i])
			eprintf("%d [%d, %d)\n", candl[i][j] + 1, ell[i][j], elr[i][j]);
		eprintf("\n");
		eprintf("R:\n");
		rep(j, candrsz[i])
			eprintf("%d [%d, %d)\n", candr[i][j] + 1, erl[i][j], err[i][j]);
		eprintf("\n");
	}
	*/
	return 0;
}