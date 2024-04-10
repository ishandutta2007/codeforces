
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#include <assert.h>
const int N = 400050;
int h[N], ne[N<<1], to[N<<1], w[N<<1], tot = 1, s, t;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
	assert(z > 0);
}
inline void adde(int x, int y, int z) { add(x, y, z), add(y, x, z); }
int used[N], st[N], rnum[N], tp;
struct Graph {
	int f[N], vis[N], tag[N], s, t; ll dis[N];
	priority_queue<pair<ll, int> > q;
	void dijistra(bool use) {
		memset(dis, 0x3f, sizeof(dis));
		q.push(MP(0, s)), dis[s] = 0;
		while (q.size()) {
			int x = q.top().se; q.pop();
			if (vis[x]) continue; vis[x] = 1;
			for (int i = h[x]; i; i = ne[i]) {
				int y = to[i];
				if (dis[y] > dis[x] + w[i]) {
					dis[y] = dis[x] + w[i], f[y] = i ^ 1;
					q.push(MP(-dis[y], y));
				}
			}
		}
//		write(dis[t]); 
		if (use) return;
		int nw = t;
		for (; nw != s; nw = to[f[nw]]) 
			used[f[nw] >> 1] = 1, st[++tp] = nw;
		st[++tp] = s;
		reverse(st + 1, st + tp + 1);
		for (int i = 1;i <= tp; i++) rnum[st[i]] = i;
	}
	int ttt;
	void dfs(int x, int t) {
		tag[x] = t;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i];
			if (tag[y] || dis[y] != dis[x] + w[i]) continue;
			dfs(y, used[i >> 1] ? y : t);
		}
	}
	int main(int use) {
		ttt = use;
		dijistra(use), dfs(s, s);
		return 0;
	}
}G, rG;

namespace SEG {
	#define ls p << 1
	#define rs ls | 1
	const ll inf = 0x3f3f3f3f3f3f3f3f;
	ll mn[N], ans;
	void build(int p, int l, int r) {
		mn[p] = inf; if (l == r) return ;
		int mid = (l + r) >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
	}
	void change(int p, int l, int r, int L, int R, ll x) {
		if (L <= l && r <= R) return Mn(mn[p], x);
		int mid = (l + r) >> 1;
		if (L <= mid) change(ls, l, mid, L, R, x);
		if (mid < R) change(rs, mid + 1, r, L, R, x);
	}
	void query(int p, int l, int r, int x, ll &ans) {
		Mn(ans, mn[p]); if (l == r) return;
		int mid = (l + r) >> 1;
		if (x <= mid) query(ls, l, mid, x, ans);
		else query(rs, mid + 1, r, x, ans);
	}
	ll query(int num) {
		ans = inf; query(1, 1, tp - 1, num, ans);
		return ans;
	}
	int main() {
		build(1, 1, tp - 1); 
		for (int i = 2;i <= tot; i++) {
			if (used[i >> 1]) continue;
			int x = to[i], y = to[i^1];
			ll t1 = G.dis[x] + w[i] + rG.dis[y];
			x = rnum[G.tag[x]], y = rnum[rG.tag[y]];
//			write(x, ' '), write(y);
			if (x == y || !x) continue; 
			if (x > y) swap(x, y);
			change(1, 1, tp - 1, x, y - 1, t1);
		}
		return 0;
	}
}

int n, m, q;
int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	read(n), read(m), read(q);
	for (int i = 1, x, y, w;i <= m; i++) 
		read(x), read(y), read(w), adde(x, y, w);
	G.s = rG.t = 1, G.t = rG.s = n;
	G.main(0), rG.main(1), SEG::main();
//	return 0;
	while (q--) {
		int nx; ll tw; read(nx), read(tw);
		int x = to[nx << 1], y = to[nx << 1 | 1];
		if (!used[nx]) {
			ll t = min(G.dis[x] + tw + rG.dis[y], rG.dis[x] + tw + G.dis[y]);
			write(min(G.dis[n], t)); continue;
		}
		if (used[nx] && tw < w[nx << 1]) { write(G.dis[n] - w[nx << 1] + tw); continue; }
		write(min(G.dis[n] - w[nx<<1] + tw, SEG::query(min(rnum[x], rnum[y]))));
	}
	return 0;
}