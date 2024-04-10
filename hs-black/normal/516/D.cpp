/*
  
 | _ _|
  ` _x 
   /  |
  /  c ?
 | |||
 | (c_c_)_)
 
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
inline void Mx(T &x, T y) { x < y && (x = y, 0); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 200500;
int h[N], ne[N<<1], to[N<<1], w[N<<1], tot, n;
ll dis[N], ans[N]; int vis[N], siz[N], f[N], q;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}
void dfs1(int x, int fa) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x), Mx(dis[x], w[i] + dis[y]);
	}
}

//int rt;
void dfs2(int x, int fa, ll d) {
	ans[x] = dis[x], Mx(ans[x], d);
//	if (ans[x] < ans[rt] || !rt) rt = x;
	ll mx1 = d, mx2 = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		if (dis[y] + w[i] > mx1) mx2 = mx1, mx1 = dis[y] + w[i];
		else if (dis[y] + w[i] > mx2) mx2 = dis[y] + w[i];
	}
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		if (dis[y] + w[i] == mx1) dfs2(y, x, mx2 + w[i]);
		else dfs2(y, x, mx1 + w[i]);
	}
}

int id[N];
bool cmp(int x, int y) { return ans[x] < ans[y]; }
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
	read(n);
	for (int i = 1, x, y, z;i < n; i++) 
		read(x), read(y), read(z), add(x, y, z), add(y, x, z);
	dfs1(1, 0), dfs2(1, 0, 0), read(q);
	for (int i = 1;i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1;i <= q; i++) {
		ll x; int pre = n, res = 0; read(x);
		for (int j = 1;j <= n; j++)
			siz[j] = 1, f[j] = j, vis[j] = 0;
		for (int j = n;j >= 1; j--) {
			vis[id[j]] = 1;
			while (ans[id[pre]] - ans[id[j]] > x)
				siz[find(id[pre])]--, pre--;
			for (int k = h[id[j]]; k; k = ne[k]) {
				int y = to[k]; if (!vis[y]) continue; y = find(y);
				if (y == find(id[j])) continue;
				siz[id[j]] += siz[y], f[y] = id[j], Mx(res, siz[id[j]]);
			}
		}
		write(res);
	}
	return 0;
}