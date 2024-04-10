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

const int N = 100500;
const int P = 1e9 + 7;
int h[N], ne[N<<1], to[N<<1], tot;
inline void adde(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

ll inv[N], Inv[N], ans;
int l[N], r[N], L[N], R[N], D[N], vis[N], st;
int siz[N], Siz, lim, rt;
void getrt(int x, int fa) {
	int mx = 0; siz[x] = 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa || vis[y]) continue;
		getrt(y, x), siz[x] += siz[y], Mx(mx, siz[y]);
	}
	Mx(mx, Siz - siz[x]);
	if (mx < lim) lim = mx, rt = x;
}

ll mx, n;

inline void add(ll &x, int y) {
	x += y, x >= P && (x -= P);
}

struct Bin {
	ll d1[N], d2[N];
	void Add(int x, ll c) {
		if (!x) return;
		ll v = c * x % P;
		for (; x <= mx; x += x & -x) 
			add(d1[x], c), add(d2[x], v);
	}
	
	ll sum(int x) {
		ll res = 0, t = x + 1, ta = 0;
		for (; x; x -= x & -x) 
			res += d1[x], ta += d2[x];
		res %= P, ta %= P;
		return (res * t + P - ta) % P; 
	}
	
	ll sum(int l, int r) {
		return (sum(r) - sum(l - 1) + P) % P;
	}
}A, B;

void dfs(int x, int fa, int dis) {
	L[++st] = l[x], R[st] = r[x], Inv[st] = inv[x], D[st] = dis;
	ans = (ans + ((ll)dis * A.sum(l[x], r[x]) + B.sum(l[x], r[x])) % P * inv[x]) % P;
	for (int i = h[x], y; i; i = ne[i]) 
		if ((y = to[i]) != fa && !vis[y]) dfs(y, x, dis + 1);
}

 
void solve(int x) {
	vis[x] = 1; A.Add(r[x] + 1, P - inv[x]); A.Add(l[x], inv[x]);
	L[st = 1] = l[x], R[st] = r[x], Inv[st] = inv[x], D[st] = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (vis[y]) continue;
		int nw = st + 1; dfs(y, x, 1);
		for (; nw <= st; nw ++) {
			A.Add(R[nw] + 1, P - Inv[nw]);
			A.Add(L[nw], Inv[nw]);
			B.Add(R[nw] + 1, (P - Inv[nw]) * D[nw] % P);
			B.Add(L[nw], Inv[nw] * D[nw] % P);
		}
	}
	while (st) {
		A.Add(R[st] + 1, Inv[st]);
		A.Add(L[st], P - Inv[st]);
		B.Add(R[st] + 1, Inv[st] * D[st] % P);
		B.Add(L[st], (P - Inv[st]) * D[st] % P);
		st--;
	}
	int tmp = Siz;
	for (int i = h[x]; i ; i = ne[i]) {
		int y = to[i]; if (vis[y]) continue;
		Siz = lim = siz[y] > siz[x] ? tmp - siz[x] : siz[y];
		rt = y, getrt(y, x), solve(rt);
	}
}

ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

int main() {
	read(n); ll mul = 1;
	for (int i = 1;i <= n; i++) {
		read(l[i]), read(r[i]); Mx(mx, (ll)r[i]);
		mul = mul * (r[i] - l[i] + 1) % P;
		inv[i] = fpw(r[i] - l[i] + 1, P - 2);
	}
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), adde(x, y), adde(y, x);
	rt = lim = Siz = n, getrt(1, 0), solve(rt);
	write((P + ans) * mul % P);
	return 0;
}

/*

10 
15 415
12 456 
152 486
321 4156
2453 4352 
453 456
4 4 
452 5342
465 45652
453 453

1 5
1 4
4 2
1 3
3 6
8 4
7 5
9 1
10 5
 

*/