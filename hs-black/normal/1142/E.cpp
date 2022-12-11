
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

#include <ctime>
const int N = 205000, M = N;
vector<int> v[N], scc[N];

int h[N], ne[M], to[M], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int col[N], deg[N], m, n, c;
int dfn[N], low[N], vis[N], st[N], cnt, tp;
void dfs(int x) {
	dfn[x] = low[x] = ++cnt, vis[x] = 1, st[++tp] = x;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (!dfn[y]) dfs(y), Mn(low[x], low[y]);
		else if (vis[y]) Mn(low[x], dfn[y]);
	}
	if (low[x] == dfn[x]) {
		int z;
		while (z = st[tp--]) {
			col[z] = x, scc[x].push_back(z), vis[z] = 0;
			if (z == x) break;
		}
	}
}

queue<int> q;
void addin(int x) {
	x = col[x];
	if (scc[x].size()) q.push(scc[x].back()), scc[x].pop_back();
	else for (auto y: v[x]) deg[y]--, !deg[y] && (q.push(y), scc[y].pop_back(), 0);
}

int ask(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	cin >> x; return x;
}

struct edges {
	int x, y;
	edges(int xx = 0, int yy = 0) : x(xx), y(yy) {}
}ed[M];

int main() {
	cin >> n >> m; c = clock();
	for (int i = 1, x, y;i <= m; i++)
		read(x), read(y), add(x, y), ed[i] = edges(x, y);
	for (int i = 1;i <= n; i++) if (!dfn[i]) dfs(i);
	for (int i = 1;i <= m; i++) {
		int x = ed[i].x, y = ed[i].y;
		if (col[x] == col[y]) continue;
		x = col[x], y = col[y];
		v[x].push_back(y), deg[y]++;
	}
	for (int i = 1;i <= n; i++)
		if (col[i] == i && !deg[i]) q.push(i), scc[i].pop_back();
	int las = q.front(); q.pop();
	while (q.size()) {
		int x = q.front(); q.pop();
		ask(las, x) ? (addin(x), 0) : (addin(las), las = x);
	}
	cout << "! " << las << endl; fflush(stdout);
	return 0;
}

/*

4 2
1 3
2 4
1 0 0 1

*/