
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

const int N = 5050000;
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}
int dfn[N], low[N], vis[N], st[N], tp, cnt, siz[N], n;
void tarjan(int x) {
	dfn[x] = low[x] = ++cnt;
	vis[x] = 1, st[++tp] = x;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (!dfn[y]) tarjan(to[i]), Mn(low[x], low[y]);
		else if (vis[y]) Mn(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		int z;
		while (z = st[tp--]) {
			siz[x]++; if (z == x) break;
		}
	}
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) 
		for (int j = 1, x;j <= n; j++) {
			read(x); if (x) add(i, j);
		}
	tarjan(1);
	if (siz[1] != n) puts("NO");
	else puts("YES");
	return 0;
}