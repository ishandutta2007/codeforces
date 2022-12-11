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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 550, M = 15000;
int cnt, m, n;

struct node {
	int x, y, w;
	bool operator < (const node &i) const {
		return w > i.w;
	}
}ed[M];

namespace MxFlow {
	int h[N], ne[M], to[M], w[M], tot = 1;
	void add(int x, int y, int z) {
		ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
	}
	
	int dep[N], cur[N], s, t;
	bool bfs(void) {
		memset(dep, 0, n * 4 + 50);
		queue<int> q;
		dep[s] = 1, q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int i = h[x], y; i; i = ne[i]) {
				if (dep[y = to[i]] || !w[i]) continue;
				dep[y] = dep[x] + 1, q.push(y);
			}
		}
		if (!dep[t]) return 0;
		for (int i = 1;i <= n; i++) cur[i] = h[i];
		return 1;
	}
	
	int dfs(int x, int lim) {
		if (x == t || !lim) return lim;
		int res = 0, fl;
		for (int &i = cur[x]; i; i = ne[i]) {
			int y = to[i]; if (dep[y] != dep[x] + 1) continue;
			fl = dfs(y, min(w[i], lim));
			w[i^1] += fl, w[i] -= fl, res += fl, lim -= fl;
			if (!lim) return res;
		}
		return res;
	}
	
	int Maxflow(int x, int y) {
		int ans = 0;
		for (int i = 2;i <= tot; i += 2)
			w[i] += w[i^1], w[i] = w[i^1] = w[i] >> 1;
		while (bfs()) ans += dfs(s, 1e6);
		return ans;
	}
	
	int col[N], p[N], tp[N];
	void Col(int x) {
		col[x] = 1;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; if (col[y]) continue;
			if (!w[i]) continue; Col(y);
		}
	}
	
	void solve(int l, int r) {
		if (l >= r) return;
		int cut = Maxflow(s = p[l], t = p[r]);
		memset(col, 0, sizeof(col)), Col(s);
		int tl = l - 1, tr = r + 1;
		for (int i = l;i <= r; i++)
			if (col[p[i]]) tp[++tl] = p[i];
			else tp[--tr] = p[i];
		ed[++cnt] = (node){p[r], p[l], cut};
		for (int i = l;i <= r; i++) p[i] = tp[i];
		solve(l, tl), solve(tr, r);	
	}	
	
	void init() {
		read(n), read(m);
		for (int i = 1, x, y, z;i <= m; i++) {
			read(x), read(y), read(z);
			add(x, y, z), add(y, x, z);
		}
		for (int i = 1;i <= n; i++) p[i] = i;
		solve(1, n);
	}
	
}

int f[N], h[N], t[N], ans;

int main() {
	MxFlow::init(), sort(ed + 1, ed + cnt + 1);
	for (int i = 1;i <= n; i++) t[i] = h[i] = f[i] = i;
	for (int i = 1;i <= cnt; i++) {
		int fx = h[ed[i].x], fy = t[ed[i].y]; f[fx] = fy;
		for (int x = t[fx]; x != h[ed[i].y]; x = f[x])
			h[x] = h[ed[i].y], t[x] = t[ed[i].x];
		fx = h[ed[i].y]; t[fx] = t[ed[i].x], ans += ed[i].w;
	}
	int x = t[1]; write(ans);
	for ( ; f[x] != x; x = f[x]) printf ("%d ", x);
	printf ("%d\n", x);
	return 0;
}

/*

6 9
1 2 1 
2 3 3 
4 2 3 
4 3 5
1 3 3 
1 5 3 
2 6 2  
5 3 4 
6 1 3  
3
1 4
2 4
2 3

*/