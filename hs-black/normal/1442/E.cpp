
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

const int N = 200050;
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
int a[N], n, T, dis[N], f[N], rt;
void dfs1(int x, int fa, int c) {
	dis[x] = dis[fa] + (a[x] && c != a[x]);
	if (a[x] && dis[rt] < dis[x]) rt = x;
	for (int i = h[x]; i; i = ne[i]) 
		if (to[i] != fa) dfs1(to[i], x, a[x] ? a[x] : c);
}

void dfs2(int x, int fa) {
	!a[x] && (a[x] = a[fa]), f[x] = 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs2(y, x), Mx(f[x], f[y] + (a[x] != a[y]));
	}
}

int main() {
	for (read(T); T; T--) {
		read(n); tot = 0, memset(h, 0, 4 * n + 20);
		for (int i = 1;i <= n; i++) read(a[i]);
		for (int i = 1, x, y;i < n; i++)
			read(x), read(y), add(x, y), add(y, x);
		rt = 0;
		for (int i = 1;i <= n; i++)
			if (a[i]) { dfs1(i, 0, a[i]); break; }
		if (rt == 0) { write(1); continue; }
		dfs2(rt, 0); write(f[rt] / 2 + 1);
	}
}