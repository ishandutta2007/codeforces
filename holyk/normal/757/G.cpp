#include <bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

#define gc getchar()
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
	for (; s[0]; putchar(s[s[0]--]));
	putchar('\n');
}

template <class T> inline bool smin(T&x, const T&y) { return y < x ? x = y, 1 : 0; }
template <class T> inline bool smax(T&x, const T&y) { return x < y ? x = y, 1 : 0; }

typedef long long ll;
#define pb push_back
const int N(4e5 + 5), P((1 << 30) - 1);
int n, m, a[N];
struct Edge { int v, w, ne; };
bool vis[N];
namespace OldTree {
Edge e[N];
int head[N >> 1], tot, deg[N >> 1];
inline void add(int x, int y, int z) { 
	e[++tot] = {y, z, head[x]}, head[x] = tot;
	e[++tot] = {x, z, head[y]}, head[y] = tot;
	++deg[x], ++deg[y];
}
} // OldTree
namespace TwoTree {
Edge e[N << 1];
int head[N], tot, cnt;
inline void add(int x, int y, int z) { 
	e[++tot] = {y, z, head[x]}, head[x] = tot;
	e[++tot] = {x, z, head[y]}, head[y] = tot;
//	std::cerr << "TwoTreeAdd: " << x << " -> " << y << " " << z << "\n";
}
void build(int x) {
	vis[x] = 1;
	int p = 0, q = x;
	for (int i = OldTree::head[x]; i; i = OldTree::e[i].ne) {
		const int &y = OldTree::e[i].v, &w = OldTree::e[i].w;
		if (vis[y]) continue;
		if (++p == 1) add(x, y, w);
		else if (p == OldTree::deg[x] - (x != 1)) add(q, y, w);
		else add(q, ++cnt, 0), add(q = cnt, y, w);
		build(y);
	}
	vis[x] = 0;
}
int dep[N], st[20][N << 1], id[N], dfn;
inline int get(int x, int y) { return dep[x] < dep[y] ? x : y; }
inline int lca(int x, int y) {
	x = id[x], y = id[y];
	if (x > y) std::swap(x, y);
	int k = std::__lg(y - x + 1);
	return get(st[k][y], st[k][x + (1 << k) - 1]);
}
ll d[N];
inline ll dis(int x, int y) { return d[x] + d[y] - (d[lca(x, y)] << 1); }
void go(int x) {
	vis[x] = 1;
	st[0][++dfn] = x;
	for (int i = head[x], y; i; i = e[i].ne)
		if (!vis[y = e[i].v]) {
			dep[y] = dep[x] + 1;
			d[y] = d[x] + e[i].w;
			go(y), st[0][++dfn] = x;
		}
	id[x] = dfn;
	vis[x] = 0;
}
void init() {
	cnt = n;
	build(1);
	go(1);
	REP(i, 1, 19) REP(j, 1 << i, dfn)
		st[i][j] = get(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
	n = cnt;
//	puts("twotreeinfo:");
//	REP(i, 1, n) printf("d[%d] = %lld\n", i, d[i]);
}
} // TwoTree
namespace PersistentCentroidTree {
using TwoTree::head;
using TwoTree::e;
using TwoTree::dis;
int all, minSize, root, sz[N];
void findrt(int x) {
	vis[x] = 1;
	sz[x] = 1;
	int max = 0;
	for (int i = head[x], y; i; i = e[i].ne)
		if (!vis[y = e[i].v]) {
			findrt(y), sz[x] += sz[y];
			smax(max, sz[y]);
		}
	smax(max, all - sz[x]);
	if (smin(minSize, max)) root = x;
	vis[x] = 0;
}
struct Node {
	int s[3], id, sz;
	ll w1, w2;
} t[N * 30];
int dep[N];
std::vector<int> to[N];
void divide(int x) {
//	std::cerr << "divide  " <<  x << "\n";
	int nowSize = all;
	vis[x] = 1;
	t[x].id = x;
	for (int i = head[x], y; i; i = e[i].ne)
		if (!vis[y = e[i].v]) {
			minSize = all = sz[y] < sz[x] ? sz[y] : nowSize - sz[x];
			findrt(y);
			dep[root] = dep[x] + 1;
			to[root] = to[x];
			REP(j, 0, 2) if (!t[x].s[j]) {
				t[x].s[j] = root, to[root].pb(j);
				break;
			}
			divide(root);
		}
}
void ins(int &o, int x, int fa) {
	static int cnt = n;
	t[++cnt] = t[o], o = cnt;
//	tr[y].id = z;
//	std::cerr <<
	++t[o].sz;
	t[o].w1 += dis(t[o].id, x);
    if (fa) t[o].w2 += dis(t[fa].id, x);
	
//	std::cerr << "ins  " << x << " " << o << "\n";
//	printf("ins  x = %d, o = %d, sz[o] = %d, w1[o] = %lld, w2[o] = %lld\n",
//x, o, t[o].sz, t[o].w1, t[o].w2
//		);
	if (t[o].id == x) return;
	ins(t[o].s[to[x][dep[t[o].id]]], x, o);
}
int rt[N];
ll ask(int o, int x) {
	ll ans = 0;
	REP(i, 0, dep[x] - 1) {
		int v = t[o].s[to[x][i]];
		ans += (t[o].sz - t[v].sz) * dis(x, t[o].id) + t[o].w1 - t[v].w2;
		o = v;
	}
	//std::cerr << "ask! " << o << " " << x << "   " << t[o].w1 << "\n";
	return ans + t[o].w1;
}
void solve() {
	minSize = all = n;
	findrt(1), divide(rt[0] = root);
	
//	std::cerr << "divide,end\n";y
//	REP(i, 1, n) printf("dep[%d] = %d\n", i, dep[i]);
	
	REP(i, 1, a[0]) ins(rt[i] = rt[i - 1], a[i], 0);
//	return;
	//	std::cerr << "ins"
//	REP(i, 1, n << 3) printf("sz[%d] = %d\n", i, t[i].sz);
//	std::cerr << "add, end\n";
	ll ans = 0;
	auto read = [&] { return (ans & P) ^ (int)rd; };
	while (m--) {
		int op = rd, l, r, x;
		if (op == 1) {
			l = read(), r = read(), x = read();
			printf("%lld\n", ans = ask(rt[r], x) - ask(rt[l - 1], x));
		} else {
			x = read();
			std::swap(a[x], a[x + 1]);
			ins(rt[x] = rt[x - 1], a[x], 0);
		}
	}
}
} // PersistentCentroidTree
int rt[N];
int main() {
	//freopen("1.in", "r", stdin);
	a[0] = n = rd, m = rd;
	REP(i, 1, n) a[i] = rd;
	REP(i, 2, n) {
		int x = rd, y = rd, z = rd;
		OldTree::add(x, y, z);
	}
	TwoTree::init();
//	std::cerr << "twotree,end\n";
	PersistentCentroidTree::solve();
	return 0;
}