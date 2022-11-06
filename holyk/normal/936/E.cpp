#include <bits/stdc++.h>
#define REP(i, a, b) for (int i(a); i <= (b); ++i)

const int SIZE(1 << 20 | 666);
char buf[SIZE], *iS, *iT;
#define gc (iS == iT ? iT = buf + fread(iS = buf, 1, SIZE, stdin), iS == iT ? EOF : *iS++ : *iS++)
struct Reader {
	template <class T> inline operator T() {
		T w; char c, p = 0;
		for(; !isdigit(c = gc); c == '-' && (p = 1));
		for(w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
		return p ? -w : w;
	}
} rd;

template <class T> inline void print(T x) {
	if (!x) return puts("0"), void();
	static char s[30];
	for (s[0] = 0; x; x /= 10) s[++s[0]] = x % 10 | '0';
	for (; s[0]; putchar(s[s[0]--])); putchar('\n');
}

template <class T> inline bool smin(T&x, const T&y) { return y < x ? x = y, 1 : 0; }
template <class T> inline bool smax(T&x, const T&y) { return x < y ? x = y, 1 : 0; }

typedef long long ll;
typedef std::pair<int, int> pii;
#define fi first
#define se second
const int N(3e5 + 5);
int n, m, cnt, id[N];
std::vector<int> g[N], e[N];
#define pb push_back
inline void addg(int x, int y) { g[x].pb(y), g[y].pb(x); }
inline void adde(int x, int y) { e[x].pb(y), e[y].pb(x); }
pii a[N], p[N];
std::map<pii, int> mp;

int mem_pool[N * 10], *ptr = mem_pool;
struct BIT1 {
	int *c, n;
	inline void alc(int sz) { n = sz, c = ptr, ptr += sz; }
	inline void add(int p, int x) {
		for (; p <= n; p += p & -p)
			smin(c[p - 1], x);
	}
	inline int ask(int p) {
		int r = 1e9;
		for (; p; p -= p & -p)
			smin(r, c[p - 1]);
		return r;
	}
} t1[N];
struct BIT2 : BIT1 {
	inline void add(int p, int x) {
		for (; p; p -= p & -p)
			smin(c[p - 1], x);
	}
	inline int ask(int p) {
		int r = 1e9;
		for (; p <= n; p += p & -p)
			smin(r, c[p - 1]);
		return r;
	}
} t2[N];

void init() {
	n = rd;
	REP(i, 1, n) p[i].fi = rd, p[i].se = rd;
	std::sort(p + 1, p + 1 + n);
	REP(i, 1, n) mp[p[i]] = i;
	static int vis[N];
	int q = 1;
	REP(i, 1, n) {
		int j = i + 1, x = p[i].fi;
		while (j <= n && p[j].fi == x && p[j].se == p[j - 1].se + 1) ++j;
		a[++cnt] = pii(i, --j);
		REP(k, i + 1, j) adde(k, k - 1);
		while (q < i && p[q].fi < x - 1) ++q;
		REP(k, i, j) {
			while (p[q].fi == x - 1 && p[q].se < p[k].se) ++q;
			if (p[q].fi == x - 1 && p[q].se == p[k].se) {
				if (vis[id[q]] != cnt)
					vis[id[q]] = cnt, addg(cnt, id[q]);
				adde(k, q);
				//	printf("add!!! (%d %d) -> (%d %d)\n", p[k].fi, p[k].se, p[q].fi, p[q].se);
			}
				
			id[k] = cnt;
		}
		i = j;
	}
//	m = n;
	n = cnt;
	REP(i, 1, n) t1[i].alc(a[i].se - a[i].fi + 1), t2[i].alc(a[i].se - a[i].fi + 1);
	memset(mem_pool, 0x3f, int(ptr - mem_pool) << 2);
	//std::cerr << "initend\n";
}

int minSize, all, rt, siz[N];
bool vis[N];

void findrt(int x) {
	vis[x] = 1, siz[x] = 1;
	int max = 0;
	for (int y : g[x])
		if (!vis[y]) {
			findrt(y);
			siz[x] += siz[y];
			smax(max, siz[y]);
		}
	smax(max, all - siz[x]);
	if (smin(minSize, max)) rt = x;
	vis[x] = 0;
}
int dep[N], fa[N];
pii d[N][22];
void divide(int x) {
//	std::cerr << "divide!  " << x << "\n";
	static int q[N], l, r;
	l = 1, r = 0;
	REP(i, a[x].fi, a[x].se) {
		q[++r] = i;
		d[i][dep[x]] = pii(i - a[x].fi + 1, 0);
	}
	vis[x] = 1;
	while (l <= r) {
		const int &u = q[l++];
		for (int &v : e[u])
			if (!vis[id[v]] && !d[v][dep[x]].fi) {
				d[v][dep[x]] = d[u][dep[x]];
				++d[q[++r] = v][dep[x]].se;
			}
	}
	int nowSize = all;
	for (int y : g[x])
		if (!vis[y]) {
			minSize = all = siz[y] < siz[x] ? siz[y] : nowSize - siz[x];
			findrt(y);
			dep[rt] = dep[x] + 1, fa[rt] = x;
			divide(rt);
		}
}

void update(int x) {
	for (int y = id[x]; y; y = fa[y]) {
		auto &u = d[x][dep[y]];
		t1[y].add(u.fi, u.se - u.fi);
		t2[y].add(u.fi, u.se + u.fi);
	}
}
int ask(int x) {
	int ans = 1e9;
	for (int y = id[x]; y; y = fa[y]) {
		auto &u = d[x][dep[y]];
		smin(ans, t1[y].ask(u.fi) + u.fi + u.se);
		smin(ans, t2[y].ask(u.fi) - u.fi + u.se);
	}
	return ans < 1e8 ? ans : -1;
}
int main() {
//	freopen("2.in" ,"r", stdin);
//	freopen("")
	init();
	minSize = all = n, findrt(1);
	divide(rt);
//	std::cerr << "divideend\n";
//	REP(i, 1, m) {
//		printf("(%d %d) %d %d %d\n", p[i].fi, p[i].se, d[i][0].se, d[i][1].se, d[i][2].se);
//	}
	m = rd;
	
	while (m--) {
		int op = rd, x = rd, y = rd, i = mp[pii(x, y)];
		//	std::cerr << x << " " << y << " " << i << "\n";
		if (op == 1) update(i);
		else printf("%d\n", ask(i));
	}
	return 0;
}
/*
  7
1 2
1 3
2 3
3 1
3 2
3 3
4 2
5
2 3 2
1 4 2
2 1 2
1 3 3
2 2 3
*/