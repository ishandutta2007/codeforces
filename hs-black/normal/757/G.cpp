#pragma GCC optimize(3, "inline") 
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
inline void write(F x, char ed = '\n')
{
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

const int N = 500500;
struct Tree {
	int ls, rs;
	ll vl, vr, sl, sr;
	#define sl(p) tree[p].sl
	#define sr(p) tree[p].sr
	#define ls(p) tree[p].ls
	#define rs(p) tree[p].rs
	#define vl(p) tree[p].vl
	#define vr(p) tree[p].vr
}tree[N * 32];

int rt[N], nodecnt, cnt, n, q;
namespace Conquer {
	const int N = 1500050;
	int h[N], ne[N<<1], to[N<<1], w[N<<1], tot = 1;
	inline void add(int x, int y, int z) {
		ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
	}
	int Siz, siz[N], vis[N], las[N], lim, ed;
	inline void adde(int x, int y, int z) { 
		add(x, y, z), add(y, x, z); 
//		write(x, ' '), write(y, ' '), write(z); 
	}
	
	void get(int x, int fa) {
		siz[x] = 1;
		for (int i = h[x], y; i; i = ne[i]) {
			if ((y = to[i]) == fa || vis[i]) continue;
			get(y, x), siz[x] += siz[y];
			int tp = max(siz[y], Siz - siz[y]);
			if (tp < lim) lim = tp, ed = i;
		}
	}
	
	void dfs(int x, int fa, ll Dis, int ty) {
		if (x <= n) {
			++nodecnt, !rt[x] && (rt[x] = nodecnt);
			if (ls(las[x]) == -1) ls(las[x]) = nodecnt;
			else rs(las[x]) = nodecnt;
			if (!ty) ls(nodecnt) = -1, vl(nodecnt) = Dis, sl(nodecnt)++;
			else rs(nodecnt) = -1, vr(nodecnt) = Dis, sr(nodecnt)++;
			las[x] = nodecnt;
		}
		for (int i = h[x], y; i; i = ne[i])
			if ((y = to[i]) != fa && !vis[i])
				dfs(y, x, Dis + w[i], ty);
	}
	
	void conquer(int x, int S) {
		if (S <= 1) return;
		Siz = lim = S, get(x, 0), vis[ed] = vis[ed ^ 1] = 1;
		int tx = to[ed], ty = to[ed ^ 1];
//		write(tx, ' '), write(ty);
		dfs(tx, 0, 0, 0), dfs(ty, 0, w[ed], 1);
		conquer(ty, S - siz[tx]), conquer(tx, siz[tx]);
	}
}

int h[N], ne[N<<1], to[N<<1], w[N<<1], las[N], tot;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

void dfs(int x, int fa) {
	for (int i = h[x], y; i; i = ne[i]) {
		if ((y = to[i]) == fa) continue; dfs(y, x);
		if (!las[x]) Conquer::adde(las[x] = x, y, w[i]);
		else {
			Conquer::adde(las[x], ++cnt, 0);
			Conquer::adde(las[x] = cnt, y, w[i]);
		}
	}
}

int update(int pre, int nw) {
	int rt = ++nodecnt; tree[rt] = tree[pre];
	vl(rt) += vl(nw), vr(rt) += vr(nw), sl(rt) += sl(nw), sr(rt) += sr(nw);
	if (sl(nw) > 0) ls(rt) = update(ls(rt), ls(nw));
	if (sr(nw) > 0) rs(rt) = update(rs(rt), rs(nw));
	return rt;
}

ll query(int nw, int p1, int p2) {
	if (sl(nw) > 0) 
		return query(ls(nw), ls(p1), ls(p2)) + vr(p2) - vr(p1) + (sr(p2) - sr(p1)) * vl(nw);
	if (sr(nw) > 0) 
		return query(rs(nw), rs(p1), rs(p2)) + vl(p2) - vl(p1) + (sl(p2) - sl(p1)) * vr(nw);
	return 0;
}

const int B = (1 << 30) - 1;
ll ans, T[N], p[N];
int main() {
	read(n), read(q), cnt = n;
	for (int i = 1;i <= n; i++) read(p[i]);
	for (int i = 1, x, y, z;i < n; i++)
		read(x), read(y), read(z), add(x, y, z), add(y, x, z);
	dfs(1, 0), Conquer::conquer(1, cnt), tree[0] = tree[nodecnt+10];
	for (int i = 1;i <= nodecnt; i++) Mx(ls(i), 0), Mx(rs(i), 0);
	for (int i = 1;i <= n; i++) T[i] = update(T[i-1], rt[p[i]]);
	while (q--) {
		ll op, x, y, z; read(op);
		if (op == 1) {
			read(x), read(y), read(z);
			x = ans ^ x, y ^= ans, z ^= ans;
			write(ans = query(rt[z], T[x - 1], T[y]));
			ans &= B;
		}
		else {
			read(x), x ^= ans, swap(p[x], p[x+1]);
			T[x] = update(T[x-1], rt[p[x]]);
		}
	}
	return 0;
}

/*

5 4
4 5 1 3 2
4 2 4
1 3 9
4 1 4
4 5 2
1 1 3 3
2 3
2 2
1 1 3 3

*/