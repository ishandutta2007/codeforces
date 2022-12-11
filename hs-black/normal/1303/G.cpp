
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

const int N = 250005;
#define ls p << 1
#define rs ls | 1
struct Line { ll k, b; }L[N<<2], O;
void clear(int l, int r, int p) {
	L[p] = O; if (l == r) return;
	int mid = (l + r) >> 1;
	clear(l, mid, ls), clear(mid + 1, r, rs);
}
inline ll calc(Line A, ll x) { return A.k * x + A.b; }
bool cmp(Line A, Line B, ll p) { return calc(A, p) >= calc(B, p); }
void insert(int l, int r, Line t, int p) {
	if (!L[p].k && !L[p].b) return L[p] = t, void();
	int tl = cmp(L[p], t, l), tr = cmp(L[p], t, r);
	if (tl == tr) return !tl && (L[p] = t, 0), void();
	int mid = (l + r) >> 1, tm = cmp(L[p], t, mid);
	if (!tm) swap(L[p], t), tl = !tl;
	if (tl) insert(mid + 1, r, t, rs);
	else insert(l, mid, t, ls);
}
ll query(int l, int r, ll x, int p) {
	if (!L[p].k && !L[p].b) return 0;
	ll res = calc(L[p], x);
	if (l == r) return res;
	int mid = (l + r) >> 1;
	if (x <= mid) Mx(res, query(l, mid, x, ls));
	else Mx(res, query(mid + 1, r, x, rs));
	return res;
}

int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}
int siz[N], vis[N], Siz, lim, mx, rt;
void getrt(int x, int fa) {
	int mx = 0; siz[x] = 1;
	for (int i = h[x], y; i; i = ne[i]) {
		if (vis[y = to[i]] || y == fa) continue;
		getrt(y, x), siz[x] += siz[y], Mx(mx, siz[y]); 
	}
	Mx(mx, Siz - siz[x]);
	if (mx < lim) lim = mx, rt = x;
}

int dep[N], len[N], bl[N], Len, tp, n;
ll s1[N], s2[N], s[N], val[N], ans;
void getdis(int x, int fa, ll v1, ll v2, ll sum, int fr) {
	if (x != rt && !fr) fr = x;
	int fl = 0; dep[x] = dep[fa] + 1; Mx(Len, dep[x]);
	for (int i = h[x], y; i; i = ne[i]) {
		if (vis[y = to[i]] || y == fa) continue;
		fl = 1, getdis(y, x, v1 + sum + val[y], 
			v2 + dep[x] * val[y], sum + val[y], fr);
	}
	if (!fl) s1[++tp] = v1, s2[tp] = v2, s[tp] = sum - val[rt], bl[tp] = fr, len[tp] = dep[x];
}

void solve(int x) {
	vis[x] = 1; tp = Len = 0; getdis(x, 0, val[x], 0, val[x], 0), Len++;
	for (int l = 1, r = 1;l <= tp; l = r + 1, r = l) {
		while (r <= tp && bl[r + 1] == bl[r]) r++;
		for (int i = l;i <= r; i++) Mx(ans, s1[i] + query(1, Len, len[i], 1));
		for (int i = l;i <= r; i++) insert(1, Len, (Line){s[i], s2[i]}, 1);
	}
	Mx(ans, val[x] + query(1, Len, 1, 1));
	clear(1, Len, 1);
	for (int r = tp, l = tp;r >= 0; r = l - 1, l = r) {
		while (l >= 1 && bl[l - 1] == bl[l]) l--;
		for (int i = l;i <= r; i++) Mx(ans, s1[i] + query(1, Len, len[i], 1));
		for (int i = l;i <= r; i++) insert(1, Len, (Line){s[i], s2[i]}, 1);
	}
	clear(1, Len, 1);
	int tsz = Siz;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (vis[y]) continue;
		rt = y, lim = Siz = siz[y] > siz[x] ? tsz - siz[x] : siz[y];
		getrt(y, x), solve(rt);
	}
}

int main() {
//	freopen ("hs.in","r",stdin);
	read(n);
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	for (int i = 1;i <= n; i++) read(val[i]);
	lim = Siz = n, rt = 1, getrt(1, 0), solve(rt), write(ans);
	return 0;
}