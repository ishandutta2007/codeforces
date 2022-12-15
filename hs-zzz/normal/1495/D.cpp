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

const int N = 405, M = 805;
int f[N][N]; 
int ne[M<<1], to[M<<1], h[N], tot;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }

int vis[N];
int find(int x, int anc) {
	vis[x] = 1;
	if (x == anc) return 1;
	int fa = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; 
		if (f[y][anc] + 1 == f[x][anc]) {
			if (fa) return 0;
			fa = y;
		}
	}
	if (!fa) return 0;
	return find(fa, anc);
}
const int P = 998244353;
int n, m;
ll solve(int A, int B) {
	memset(vis, 0, sizeof(vis));
	if (!find(B, A)) return 0;
	ll res = 1;
	for (int x = 1;x <= n; ++x) if (!vis[x]) {
		int fa = 0;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i];
			if (f[y][A] + 1 == f[x][A] && f[y][B] + 1 == f[x][B]) 
				fa++;
		}
		res = res * fa % P;
	}
	return res;
}
ll ans[N][N];
int main() {
	read(n), read(m);
	memset(f, 0x3f, sizeof(f));
	for (int i = 1;i <= n; ++i) f[i][i] = 0;
	for (int i = 1, x, y;i <= m; ++i)
		read(x), read(y), add(x, y), add(y, x), f[x][y] = f[y][x] = 1;
	for (int k = 1;k <= n; ++k)
		for (int i = 1;i <= n; ++i)
			for (int j = 1;j <= n; ++j)
				Mn(f[i][j], f[i][k] + f[k][j]);
	for (int i = 1;i <= n; ++i) {
		ll res = 1;
		for (int j = 1;j <= n; ++j) if (i != j) {
			int fa = 0;
			for (int t = h[j]; t; t = ne[t])
				if (f[i][to[t]] + 1 == f[i][j]) fa++;
			res = res * fa % P;
		}
		ans[i][i] = res;
		for (int j = i + 1;j <= n; ++j) 
			ans[i][j] = ans[j][i] = solve(i, j);
	}
	for (int i = 1;i <= n; ++i, puts(""))
		for (int j = 1;j <= n; ++j)
			write(ans[i][j], ' ');
	return 0;
}