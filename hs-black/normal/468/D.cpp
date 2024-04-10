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

#include <set>
const int N = 105005;
int ne[N<<1], to[N<<1], w[N<<1], h[N], tot, n;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

ll dep[N];
int siz[N], col[N], rt, lim = 1e9;
set<int> st[N];
set<pair<int, int> > S, So;
void dfs1(int x, int fa) {
	siz[x] = 1; int mn = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x), siz[x] += siz[y], Mx(mn, siz[y]);
	}
	Mx(mn, n - siz[x]);
	if (mn < lim) lim = mn, rt = x;
}

ll ans;
void dfs2(int x, int fa, int c) {
	col[x] = c, st[c].insert(x), ans += dep[x], siz[x] = 2;
	for (int i = h[x], y; i; i = ne[i])
		if ((y = to[i]) != fa) {
			dep[y] = dep[x] + w[i];
			dfs2(y, x, c);
			siz[x] += siz[y];
		}
}

void del(int x) {
	S.erase(MP(siz[x], x));
	--siz[x];
	S.insert(MP(siz[x], x));
}

void Del(int x) {
	So.erase(MP(*st[x].begin(), x));
	st[x].erase(st[x].begin());
	if (st[x].size()) So.insert(MP(*st[x].begin(), x));
}

int main() {
	read(n);
	for (int i = 1, x, y, z;i < n; ++i)
		read(x), read(y), read(z), add(x, y, z), add(y, x, z);
	dfs1(1, 0), col[rt] = rt, st[rt].insert(rt), S.insert(MP(1, rt));
	So.insert(MP(rt, rt)), st[rt].insert(rt);
	for (int i = h[rt], y; i; i = ne[i]) {
		dep[y = to[i]] = w[i];
		dfs2(y, rt, y), S.insert(MP(siz[y], y));
		So.insert(MP(*st[y].begin(), y));
	}
	write(ans * 2), siz[rt] = 2;
	for (int i = 1;i <= n; ++i) {
		int x = col[i], nb;
		auto t = So.begin();
		auto nw = *S.rbegin();
		if (t->se == x && x != rt) ++t;
//		tt = *t;
		nb = t->se;
		if (!(nw.se == x || nw.se == nb || nw.fi <= n - i)) nb = nw.se;
		write(*st[nb].begin(), ' ');
		del(x), del(nb), Del(nb);
	}
	return 0;
}