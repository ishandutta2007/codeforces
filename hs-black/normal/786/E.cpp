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


const int hinf = 1e8;
const int N = 20050;
int st[16][N<<2], f[16][N<<2];
int ans[N], m, n;
int h[N], ne[N<<2], to[N<<2], fat[N], tot;
namespace Flows {
	const int M = 2005500;
	int cur[M], h[M], dep[M], ne[M], to[M], w[M], cnt, s, t, tot = 1;
	inline void add(int x, int y, int z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
	inline void adde(int x, int y, int z = 1e8) { add(x, y, z), add(y, x, 0); }
	int dfs(int x, int lim) {
		if (!lim || x == t) return lim;
		int res = 0, fl;
		for (int &i = cur[x], y; i; i = ne[i]) {
			if (dep[y = to[i]] != dep[x] + 1 || !w[i]) continue;
			fl = dfs(y, min(lim, w[i]));
			lim -= fl, res += fl;
			w[i] -= fl, w[i^1] += fl;
			if (!lim) return res;
		}
		return res;
	}
	queue<int> q;
	bool bfs(void) {
		memset(dep, 0, cnt * 4 + 20);
		dep[s] = 1, q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int i = h[x], y; i; i = ne[i]) 
				if (!dep[y = to[i]] && w[i]) dep[y] = dep[x] + 1, q.push(y);
		}
		if (!dep[t]) return 0;
		memcpy(cur, h, cnt * 4 + 20);
		return 1;
	}
	void outans(void) {
		int res = 0;
		while (bfs()) res += dfs(s, 1e9);
		write(res);
		int t = 0;
		for (int i = 1;i <= m; ++i) t += !dep[ans[i]];
		write(t, ' ');
		for (int i = 1;i <= m; ++i) if (!dep[ans[i]]) write(i, " \n"[!--t]);
		for (int i = 1;i <= n; ++i) t += !!dep[i];
		write(t, ' ');
		for (int i = 1;i <= n; ++i) if (dep[i]) write(fat[i], " \n"[!--t]); 
	}
}
using Flows::cnt;
using Flows::adde;
using Flows::s;
using Flows::t;
using Flows::outans;

inline int nd(int x, int y) {
	return ++cnt, adde(cnt, x, hinf), adde(cnt, y, hinf), cnt;
}

inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; } 
int dep[N];
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1, adde(x, t, 1);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		f[0][y] = x, st[0][y] = y, fat[y] = (i + 1) >> 1;
		for (int i = 1;i <= 14 && f[i-1][y]; ++i) {
			f[i][y] = f[i-1][f[i-1][y]];
			st[i][y] = nd(st[i-1][y], st[i-1][f[i-1][y]]);
		}
		dfs(y, x);
	}
}

inline void addin(int x, int y, int rt) {
	if (dep[x] < dep[y]) swap(x, y);
	adde(s, rt, 1);
	for (int j = 14;j >= 0; --j)
		if (dep[f[j][x]] >= dep[y]) adde(rt, st[j][x]), x = f[j][x];
	if (x == y) return;
	for (int j = 14;j >= 0; --j) if (f[j][x] != f[j][y]) 
		adde(rt, st[j][x]), adde(rt, st[j][y]), x = f[j][x], y = f[j][y];
	return adde(rt, x), adde(rt, y);
}

int main() {
	read(n), read(m), s = cnt = n + 1, t = ++cnt;
	for (int i = 1, x, y;i < n; ++i) 
		read(x), read(y), add(x, y), add(y, x);
	st[0][1] = 1, dfs(1, 0);
	for (int i = 1, x, y;i <= m; ++i) 
		read(x), read(y), addin(x, y, ans[i] = ++cnt);
	outans();
	return 0;
}