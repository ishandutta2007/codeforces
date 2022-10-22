#pragma GCC optimize(3)
#if 0
date



 ax + b  (a, b) 
 k  -k 
 (a, b) 

 (a, b) 
 A, B  A 
 A, B 
 A, B 

#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<ll, ll> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 300005;

int head[maxn], nxt[maxn << 1], to[maxn << 1], va[maxn << 1], vb[maxn << 1], hp = 1;
inline void add(int u, int v, int a, int b) {
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
	va[hp] = a;
	vb[hp] = b;
}

int last[maxn], np;
inline void expand(int u) {
	if(last[u]) {
		++ np;
		add(np, last[u], 0, 0);
		add(last[u], np, 0, 0);
		last[u] = np;
	} else
		last[u] = u;
}

int cen, censize;
bool vis[maxn];
int size[maxn];
void find_cen(int u, int from, int n) {
	size[u] = 1;
	for(int i = head[u]; i; i = nxt[i])
		if(!vis[i >> 1]) {
			vis[i >> 1] = 1;
			find_cen(to[i], i >> 1, n);
			size[u] += size[to[i]];
			vis[i >> 1] = 0;
		}
	int now = std::max(size[u], n - size[u]);
	if(now < censize) {
		cen = from;
		censize = now;
	}
}

inline par minus(par a, par b) {
	return par(a.first - b.first, a.second - b.second);
}

typedef long double ld;
inline bool cmp(par a, par b) {
	return ld(a.second) / a.first > ld(b.second) / b.first;
}

struct Hull {
	std::vector<par> dot;
	std::vector<par> vector;
	par last;
	inline void add(par p) { dot.push_back(p); }
	void make() {
		std::sort(dot.begin(), dot.end());
		/* debug("making\n"); */
		/* for(par d : dot) */
		/* 	debug("%lld %lld\n", d.first, d.second); */
		last = par(0, 0);
		for(par d : dot)
			if(d != last) {
				while(vector.size()) {
					par v = minus(d, last);
					if(cmp(v, vector.back())) {
						last = minus(last, vector.back());
						vector.pop_back();
					} else
						break;
				}
				vector.push_back(minus(d, last));
				last = d;
			}
		dot.clear();
		/* debug("made\n"); */
		/* for(par v : vector) */
		/* 	debug(" +%lld %lld\n", v.first, v.second); */
	}
};

Hull operator + (Hull &a, Hull &b) {
	Hull c;
	auto p1 = a.vector.begin(), p2 = b.vector.begin();
	while(p1 != a.vector.end() and p2 != b.vector.end())
		if(cmp(*p1, *p2))
			c.vector.push_back(*(p1 ++));
		else
			c.vector.push_back(*(p2 ++));
	while(p1 != a.vector.end())
		c.vector.push_back(*(p1 ++));
	while(p2 != b.vector.end())
		c.vector.push_back(*(p2 ++));
	c.last = par(0, 0);
	c.dot.push_back(c.last);
	for(par v : c.vector) {
		c.last.first += v.first;
		c.last.second += v.second;
		c.dot.push_back(c.last);
	}
	return c;
}

int tp;
void dfs(int u, ll a, ll b, Hull &h) {
	h.add(par(a, b));
	for(int i = head[u]; i; i = nxt[i])
		if(!vis[i >> 1]) {
			vis[i >> 1] = 1;
			dfs(to[i], a + va[i], b + vb[i], h);
			vis[i >> 1] = 0;
		}
}

Hull shit;
void divi(int u, int n) {
	if(n == 1) return;

	cen = 0;
	censize = maxn;
	find_cen(u, 0, n);
	if(size[u] != n) exit(1);
	vis[cen] = 1;
	int x = to[cen << 1], y = to[cen << 1 | 1];

/* 	debug("div %d %d\n", u, n); */

	Hull ha, hb;
	ha.add(par(0, 0));
	dfs(x, va[cen << 1], vb[cen << 1], ha);
	dfs(y, 0, 0, hb);
	ha.make();
	hb.make();

	for(par d : (ha + hb).dot)
		shit.add(d);

	if(size[x] > size[y]) {
		int bak = size[y];
		divi(x, n - size[y]);
		divi(y, bak);
	} else {
		int bak = n - size[x];
		divi(x, size[x]);
		divi(y, bak);
	}
}

int main() {
	int n = read, m = read;
	np = n;
	for(int i = 1; i < n; i ++) {
		int u = read, v = read, a = read, b = read;
		expand(u);
		expand(v);
		add(last[u], last[v], a, b);
		add(last[v], last[u], a, b);
	}

	divi(1, np);
	shit.make();

	shit.vector.push_back(par(0, 0));
	auto it = shit.vector.begin();
	par now = par(0, 0), nowto = *it;
	for(int k = 0; k < m; k ++) {
		while(it != shit.vector.end() and
				nowto.first * k + nowto.second >= now.first * k + now.second) {
			now = nowto;
			++ it;
			nowto.first += it -> first;
			nowto.second += it -> second;
		}
		printf("%lld ", now.first * k + now.second);
	}
	puts("");
}