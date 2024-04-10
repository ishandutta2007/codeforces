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

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int P = 998244353;
const int N = 300050;
int h[N], ne[N<<1], to[N<<1], tot, n, q;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int dep[N], siz[N], son[N], f[N], Top[N], dfn[N], dw[N], num;
void dfs1(int x, int fa) {
	dep[x] = dep[f[x] = fa] + (siz[x] = 1);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x), siz[x] += siz[y];
		if (siz[son[x]] < siz[y]) son[x] = y;
	}
}

void dfs2(int x, int topf) {
	dw[topf] = x; Top[x] = topf; dfn[x] = ++num;
	if (!son[x]) return; dfs2(son[x], topf);
	for (int i = h[x], y; i; i = ne[i]) 
		if ((y = to[i]) != son[x] && y != f[x]) dfs2(y, y);
}

ll d[N], s[N];
void Add(ll *d, int x, ll k) {
	for ( ; x <= n; x += x & -x) d[x] = (d[x] + k) % P;
}

void add(ll *d, int l, int r, int k) {
	Add(d, l, k), Add(d, r + 1, -k);
}

ll sum(ll *d, int x) {
	ll res = 0;
	for ( ; x ; x -= x & -x) res = (res + d[x]) % P;
	return res;
}


ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P, mi >>= 1;
	}
	return res;
}


ll tag[N], inv;

void change(int x, ll d) {
	if (x != 1) add(s, 1, n, siz[x] * d % P), add(s, dfn[x], dfn[x] + siz[x] - 1, -siz[x] * d % P);
	if (son[x]) add(::d, dfn[x] + 1, dfn[dw[Top[x]]], (n - siz[son[x]]) * d % P);
	(tag[x] += d) %= P;
}

ll query(int x) {
	ll ans = (tag[x] * n + sum(d, dfn[x]) + sum(s, dfn[x])) % P; x = Top[x];
	while (x != 1) {
		(ans += tag[f[x]] * (n - siz[x])) %= P;
		(ans += sum(d, dfn[f[x]])) %= P, x = Top[f[x]];
	}
	return (ans + P);
}

int main() {
	read(n), read(q), inv = fpw(n, P - 2);
	for (int i = 1, x, y; i < n ; i++) 
		read(x), read(y), add(x, y), add(y, x);
	dfs1(1, 0), dfs2(1, 1);
	while (q--) {
		int op, x, y; read(op), read(x);
		if (op == 1) read(y), change(x, y);
		else printf ("%lld\n", query(x) * inv % P); 
	}
	return 0;
}

/*

5 12
1 2
1 3
2 4
2 5
1 1 1
2 1
2 2
2 3
2 4
2 5
1 2 2
2 1
2 2
2 3
2 4
2 5

*/