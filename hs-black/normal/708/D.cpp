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

ll ans;
const int N = 2505;
int h[N], ne[N<<1], to[N<<1], w[N<<1], v[N<<1], cnt, s, t, m, n, tot = 1;

inline void add(int x, int y, int z, int c) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z, v[tot] = c;
}
inline void adde(int x, int y, int z, int c) { add(x, y, z, c), add(y, x, 0, -c); }
int vis[N], dis[N];
queue<int> q;
bool spfa(void) {
	memset(vis, 0, cnt * 4 + 24);
	memset(dis, 0x3f, cnt * 4 + 24); 
	vis[s] = 1, dis[s] = 0, q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i];
			if (w[i] && dis[y] > dis[x] + v[i]) {
				dis[y] = dis[x] + v[i];
				if (!vis[y]) q.push(y), vis[y] = 1;
			}
		}
	}
	return dis[t] < 1e9;
}

int tim = 1;
int dfs(int x, int lim) {
	if (x == t || !lim) return lim;
	int res = 0, fl; vis[x] = tim;
	for (int i = h[x], y; i ; i = ne[i]) {
		if (dis[y = to[i]] != dis[x] + v[i] || vis[y] == tim) continue;
		fl = dfs(y, min(lim, w[i]));
		w[i] -= fl, w[i ^ 1] += fl, res += fl, lim -= fl;
		if (!lim) break;
	}
	return res;
}

int deg[N];
int main() {
	read(n), read(m); s = 1, t = cnt = n, s = ++cnt, t = ++cnt;
	for (int i = 1, x, y, c, f;i <= m; ++i) {
		read(x), read(y), read(c), read(f), deg[x] += f, deg[y] -= f;
		if (c <= f) ans += f - c, adde(y, x, c, 1), adde(y, x, f - c, 0), adde(x, y, 1e8, 2);
		else adde(y, x, f, 1), adde(x, y, c - f, 1), adde(x, y, 1e8, 2);
	}
	for (int i = 1;i <= n; ++i) 
		if (deg[i] < 0) adde(s, i, -deg[i], 0);
		else adde(i, t, deg[i], 0);
	adde(n, 1, 1e9, 0);
	while (spfa()) {
		ll res = 0;
		while (res = dfs(s, 2e9))
			++tim, ans += res * dis[t];
	}
	write(ans);
	return 0;
}