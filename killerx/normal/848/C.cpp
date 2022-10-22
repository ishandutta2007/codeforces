#include <bits/stdc++.h>
using namespace std;

#define ld double
#define ll long long
#define pii pair <int, int>
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define PI acos(-1)
#define MOD 1000000007
#define MUL 19260817
#define EPS 1e-10
#define INF 1e9
#define LINF 1e18

template <typename T> inline void chkmin(T &x, T y) {if (y < x) x = y;}
template <typename T> inline void chkmax(T &x, T y) {if (y > x) x = y;}
template <typename T> inline T add(T x, T y) {return (x + y) % MOD;}
template <typename T> inline T mul(T x, T y) {return 1LL * x * y % MOD;}
template <typename T> inline T qp(T x, T n) {
	T ans = 1;
	do {if (n & 1) ans = mul(ans, x); x = mul(x, x);} while (n >>= 1);
	return ans;
}

#ifndef DEBUG
const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)
#endif

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 1 << 17;
int n, q;
mt19937 rnd(200);

namespace Treap {
	struct T {
		ll sum;
		int l, r;
		int sz, fix, val, id;
		T() {fix = rnd();}
	} t[N << 5];
	queue <int> freenodes;

	void ini() {
		for (int i = 1; i < (N << 5); ++ i)
			freenodes.push(i);
	}

	int newNode(int _val, int _id) {
		int x = freenodes.front();
		freenodes.pop();
		t[x].sum = t[x].val = _val;
		t[x].id = _id;
		t[x].sz = 1;
		t[x].l = t[x].r = 0;
		return x;
	}

	void pushup(int x) {
		t[x].sum = t[t[x].l].sum + t[x].val + t[t[x].r].sum;
		t[x].sz = t[t[x].l].sz + 1 + t[t[x].r].sz;
	}

	void split(int x, int v, int &a, int &b) {
		if (!x) return void(a = b = 0);
		if (t[x].id <= v) {
			a = x;
			split(t[x].r, v, t[a].r, b);
			pushup(a);
		} else {
			b = x;
			split(t[x].l, v, a, t[b].l);
			pushup(b);
		}
	}

	int merge(int x, int y) {
		if (!x || !y) return x + y;
		if (t[x].fix < t[y].fix) {
			t[x].r = merge(t[x].r, y);
			pushup(x);
			return x;
		} else {
			t[y].l = merge(x, t[y].l);
			pushup(y);
			return y;
		}
	}

	ll query(int x, int l) {
		int a, b;
		split(x, l - 1, a, b);
		int res = 0;
		if (t[b].sz) res = t[b].sum;
		x = merge(a, b);
		return res;
	}

	void dbg(int x) {
		if (!x) return;
		dbg(t[x].l);
		printf(" (%d, %d)", t[x].val, t[x].id);
		dbg(t[x].r);
	}
}

namespace SegT {
	int node[N << 1];
	void ini() {memset(node, 0, sizeof node);}
	void update(int x, int val, int id) {
		for (x += N; x; x >>= 1) {
			int l, r;
			Treap :: split(node[x], id, l, r);
			int m = Treap :: newNode(val, id);
			node[x] = Treap :: merge(Treap :: merge(l, m), r);
		}
	}
	void erase(int x, int id) {
		for (x += N; x; x >>= 1) {
			int l, m, r;
			Treap :: split(node[x], id, m, r);
			Treap :: split(m, id - 1, l, m);
			Treap :: freenodes.push(m);
			node[x] = Treap :: merge(l, r);
		}
	}
	ll query(int l, int r, int lb) {
		ll ans = 0;
		for (l += N, r += N; l ^ r; l >>= 1, r >>= 1) {
			if (l & 1) {ans += Treap :: query(node[l], lb); ++ l;}
			if (r & 1) {-- r; ans += Treap :: query(node[r], lb);}
		}
		return ans;
	}
}

int a[N];
set <int> p[N];
int nw = -1;
int pre[N];

int main() {
	memset(pre, -1, sizeof pre);
	Treap :: ini();
	SegT :: ini();
	n = read(), q = read();
	rep(i, n) a[i] = read();
	rep(i, n) {
		if (p[a[i]].size()) {
			int prv = *p[a[i]].rbegin();
			pre[i] = prv;
			SegT :: update(i, i - prv, prv);
		} else SegT :: update(i, 0, pre[i] = nw --);
		p[a[i]].insert(i);
	}
	rep(i, q) {
		int qtp = read(), qa = read(), qb = read();
		if (qtp == 1) {
			-- qa;
			if (a[qa] == qb) continue;
			{ // delete
				auto it = p[a[qa]].find(qa);
				auto jt = p[a[qa]].erase(it);
				auto kt = jt; if (jt != p[a[qa]].begin()) -- kt;
				SegT :: erase(qa, pre[qa]);
				if (jt != p[a[qa]].end()) {
					int nxt = *jt;
					SegT :: erase(nxt, qa);
					if (kt != jt) {
						int prv = *kt;
						pre[nxt] = prv;
						SegT :: update(nxt, nxt - prv, prv);
					} else {
						SegT :: update(nxt, 0, pre[nxt] = nw --);
					}
				}
			}
			{ // insert
				p[a[qa] = qb].insert(qa);
				auto it = p[a[qa]].find(qa);
				auto jt = it; ++ jt;
				auto kt = it; if (kt != p[a[qa]].begin()) -- kt;
				if (jt != p[a[qa]].end()) {
					int nxt = *jt;
					if (kt != it) SegT :: erase(nxt, *kt);
					else SegT :: erase(nxt, pre[nxt]);
					pre[nxt] = qa;
					SegT :: update(nxt, nxt - qa, qa);
				}
				if (kt != it) {
					int prv = *kt;
					pre[qa] = prv;
					SegT :: update(qa, qa - prv, prv);
				} else SegT :: update(qa, 0, pre[qa] = nw --);
			}
		} else printf("%lld\n", SegT :: query(qa - 1, qb, qa - 1));
//		rep(i, n) Treap :: dbg(SegT :: node[i + N]), putchar(i + 1 == n ? '\n' : ',');
	}
	return 0;
}