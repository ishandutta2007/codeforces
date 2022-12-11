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

const int N = 300500;
struct Gragh {
	int h[N], to[N], ne[N], tot;
	inline void add(int x, int y) {
		ne[++tot] = h[x], to[h[x] = tot] = y;
	}
}A, B, C, D;

int fat[N], siz[N], dfn[N], id[N], f[N], cnt, m, n;
void dfs(int x) {
	id[dfn[x] = ++cnt] = x;
	for (int i = A.h[x], y; i; i = A.ne[i])
		if (!dfn[y = A.to[i]]) fat[y] = x, dfs(y);
}

int sdom[N], idom[N], val[N];
int find(int x) {
	if (x == f[x]) return x;
	int rt = find(f[x]);
	if (dfn[sdom[val[f[x]]]] < dfn[sdom[val[x]]]) 
	val[x] = val[f[x]];
	return f[x] = rt;
}

void tarjan(void) {
	for (int k = cnt;k >= 2; k--) {
		int x = id[k];
		for (int i = B.h[x], y; i; i = B.ne[i]) {
			if (!dfn[y = B.to[i]]) continue; find(y);
			dfn[sdom[val[y]]] < dfn[sdom[x]] && (sdom[x] = sdom[val[y]]);
		}
		C.add(sdom[x], x);
		f[x] = fat[x], x = fat[x];
		for (int i = C.h[x], y; i;i = C.ne[i]) {
			find(y = C.to[i]);
			if (sdom[val[y]] == x) idom[y] = x;
			else idom[y] = val[y];
		}
		C.h[x] = 0;
	}
	for (int k = 2;k <= cnt; k++) {
		int x = id[k];
		sdom[x] != idom[x] && (idom[x] = idom[idom[x]]);
		D.add(idom[x], x);
	}
}

void get(int x) {
	siz[x] = 1;
	for (int i = D.h[x]; i; i = D.ne[i])
		get(D.to[i]), siz[x] += siz[D.to[i]];
}

struct edges {
	int x, y, z;
}ed[N];

int h[N], ne[N<<1], to[N<<1], w[N<<1], vis[N], tot, s;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

ll dis[N];
priority_queue<pair<ll, int> > q;
void diji(void) {
	memset(dis, 0x3f, sizeof(dis));
	q.push(MP(0, s)); dis[s] = 0;
	while (q.size()) {
		int x = q.top().se; q.pop();
		if (vis[x]) continue; vis[x] = 1;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; 
			if (dis[y] > dis[x] + w[i]) {
				dis[y] = dis[x] + w[i];
				q.push(MP(-dis[y], y));
			}
		}
	}
	for (int i = 1;i <= m; i++) {
		int x = ed[i].x, y = ed[i].y;
		if (dis[y] < dis[x]) swap(x, y);
		if (dis[y] == dis[x] + ed[i].z) 
			A.add(x, y), B.add(y, x);
	}
}
	

int main() {
	read(n), read(m), read(s);
	for (int i = 1, x, y, z;i <= m; i++) {
		read(x), read(y), read(z);
		add(x, y, z), add(y, x, z);
		ed[i] = (edges){x, y, z};
	}
	diji();
	for (int i = 1;i <= n; i++)
		f[i] = val[i] = sdom[i] = i;
	dfs(s), tarjan(), get(s);
	int ans = 0;
	for (int i = 1;i <= n; i++) 
		if (i != s) Mx(ans, siz[i]);
	write(ans);
	return 0;
}