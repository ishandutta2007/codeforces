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

#pragma GCC optimize(2)
const int N = 605;
int w[N][N], uf[N][N];
int n, q, m;
int f[N][N], vis[N]; ll dis[N];
#include <ctime>
void solve(int s, int *f) {
//	int c = clock();
	static int vis[N];
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	for (int i = 1;i <= n; ++i) {
		int x = 0;
		for (int j = 1;j <= n; ++j)
			if (!vis[j] && (!x || dis[j] < dis[x])) x = j;
		vis[x] = 1;
		for (int y = 1;y <= n; ++y)
			Mn(dis[y], dis[x] + w[x][y]);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1;i <= n; ++i) {
		int x = 0;
		for (int j = 1;j <= n; ++j)
			if (!vis[j] && (!x || f[j] > f[x])) x = j;
		vis[x] = 1;
		for (int y = 1;y <= n; ++y) {
			Mx(f[y], f[x] - w[x][y]);
			if (dis[y] <= f[x] - w[x][y]) uf[x][y] = uf[y][x] = 1;
		}
	}
//	write(clock() - c);
}

int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(m); memset(w, 0x3f, sizeof(w));
	for (int i = 1, x, y, z;i <= m; ++i)
		read(x), read(y), read(z), w[x][y] = w[y][x] = z;
	read(q);
	for (int i = 1, x, y, z;i <= q; ++i)
		read(x), read(y), read(z), Mx(f[x][y], z), Mx(f[y][x], z);
	for (int i = 1;i <= n; ++i) solve(i, f[i]);
	int ans = 0;
	for (int i = 1;i <= n; ++i)
		for (int j = i + 1;j <= n; ++j) 
			ans += uf[i][j];
	write(ans);
	return 0;
}