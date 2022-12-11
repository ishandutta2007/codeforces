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

const int N = 305000;
int h[N], ne[N<<1], to[N<<1], tot;
inline void adde(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

vector<pair<int, int> > v[N];
int dis[N], rt[N], s[N][2], vis[N], cnt, m, n;
ll dp[N], add[N];
pair<int, ll> p[N];

inline int Node(int x, ll y) { 
	p[++cnt] = MP(x, y); return cnt;
}

inline void Tag(int x, ll t) { add[x] += t, p[x].se += t; }
inline void spread(int x) {
	if (s[x][0]) Tag(s[x][0], add[x]);
	if (s[x][1]) Tag(s[x][1], add[x]);
	add[x] = 0;
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (p[x].se > p[y].se) swap(x, y);
	spread(x);
	s[x][1] = merge(s[x][1], y);
	if (dis[s[x][1]] > dis[s[x][0]]) swap(s[x][0], s[x][1]);
	return dis[x] = dis[s[x][1]] + 1, x;
}

void dfs(int x, int fa) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs(y, x), dp[x] += dp[y];
	}
	vis[x] = 1;
	for (int i = h[x]; i; i = ne[i]) if (to[i] != fa) 
			Tag(rt[to[i]], dp[x] - dp[to[i]]), rt[x] = merge(rt[x], rt[to[i]]);
			
	if (x == 1) return dp[x] = p[rt[x]].se, void();
	for (auto t: v[x]) rt[x] = merge(rt[x], Node(t.fi, t.se + dp[x]));
	while (rt[x] && vis[p[rt[x]].fi]) rt[x] = merge(s[rt[x]][0], s[rt[x]][1]);
	if (!rt[x]) { puts("-1"); exit(0); }
	dp[x] = p[rt[x]].se;
}

int main() {
	read(n), read(m);
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), adde(x, y), adde(y, x);
	for (int i = 1, x, y, w; i <= m; ++i)
		read(x), read(y), read(w), v[x].emplace_back(y, w);
	dfs(1, 0), write(dp[1]);
	return 0;
}