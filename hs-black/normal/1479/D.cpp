/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int N = 605000;
int ne[N<<1], to[N<<1], h[N], a[N], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int id[N], L[N], R[N], cnt, S;
int dep[N], siz[N], son[N], Top[N], f[N];
void dfs1(int x, int fa) {
	id[L[x] = ++cnt] = x;
	dep[x] = dep[f[x] = fa] + (siz[x] = 1);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x), siz[x] += siz[y];
		if (siz[y] > siz[son[x]]) son[x] = y;
	}
	id[R[x] = ++cnt] = x;
}

int Lca(int x, int y) {
	while (Top[x] != Top[y]) {
		if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
		x = f[Top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

void dfs2(int x, int topf) {
	Top[x] = topf; if (son[x]) dfs2(son[x], topf);
	for (int i = h[x], y; i; i = ne[i])
		if ((y = to[i]) != f[x] && y != son[x]) dfs2(y, y);
}

inline bool in(int x, int y) { return L[x] <= L[y] && L[y] <= R[x]; }

#define ull unsigned ll
ull get(void) {
	ull res = rand();
	res = res << 16 ^ rand();
	res = res << 16 ^ rand();
	res = res << 16 ^ rand();
	return res;
}

int ls[N<<5], rs[N<<5], rt[N<<2], Cnt;
ull sum[N<<5];
int change(int p, int l, int r, int x, ull s) {
	int rt = ++Cnt; ls[rt] = ls[p], rs[rt] = rs[p];
	sum[rt] = sum[p] ^ s;
	if (l == r) return rt;
	int mid = (l + r) >> 1;
	if (x <= mid) ls[rt] = change(ls[p], l, mid, x, s);
	else rs[rt] = change(rs[p], mid + 1, r, x, s);
	return rt;
}

int query(int p1, int p2, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		if (!(sum[p2] ^ sum[p1])) return 0;
		if (l == r) return l;
		int mid = (l + r) >> 1;
		int tl = query(ls[p1], ls[p2], l, mid, L, R);
		if (tl) return tl;
		return query(rs[p1], rs[p2], mid + 1, r, L, R);
	}
	int mid = (l + r) >> 1, tl = 0;
	if (L <= mid) tl = query(ls[p1], ls[p2], l, mid, L, R);
	if (!tl && R > mid) tl = query(rs[p1], rs[p2], mid + 1, r, L, R);
	return tl;
}
ull val[N];
int n, q;
int main() {
	srand((ll)new char);
	read(n), read(q);
	for (int i = 1;i <= n; ++i) val[i] = get();
	for (int i = 1;i <= n; ++i) read(a[i]);
	for (int i = 1, x, y;i < n; ++i) 
		read(x), read(y), add(x, y), add(y, x);
	dfs1(1, 0), dfs2(1, 1);
	for (int i = 1;i <= cnt; ++i) 
		rt[i] = change(rt[i-1], 1, n, a[id[i]], val[a[id[i]]]);
	for (int i = 1, x, y, l, r;i <= q; ++i) {
		read(x), read(y), read(l), read(r);
		int tl, tr;
		if (L[x] > L[y]) swap(x, y);
		if (in(x, y)) {
			tl = L[x], tr = L[y];
			int ans = query(rt[tr], rt[tl - 1], 1, n, l, r);
			write(ans ? ans : -1);
		}
		else {
			tl = R[x], tr = L[y]; int tt = Lca(x, y);
			int ans = query(rt[tr], rt[tl-1], 1, n, l, r);
			if (ans == a[tt]) ans = ans < r ? query(rt[tr], rt[tl - 1], 1, n, ans + 1, r) : 0;
			else if (!ans && a[tt] >= l && a[tt] <= r) ans = a[tt];
			write(ans ? ans : -1);
		}
	}
	return 0;
}

/*

7 6
2 1 1 2 1 1 1
1 2
2 3
2 4
1 5
5 6
5 7

*/