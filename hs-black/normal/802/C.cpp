
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

const int N = 200058;
int ne[N], to[N], h[N], w[N], d[N], tot = 1;
inline void add(int x, int y, int c, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = c, d[tot] = z;
}
inline void adde(int x, int y, int fl, int w) {
	add(x, y, fl, w), add(y, x, 0, -w);
}

const int inf = 0x3f3f3f3f;
int dis[N], vis[N], s, t;
int a[N], c[N], n, k, cnt;
queue<int> q;
bool spfa(void) {
	memset(dis, 0x3f, cnt * 4 + 50);
	memset(vis, 0, cnt * 4 + 50);
	q.push(s), dis[s] = 0;
	while (q.size()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; 
			if (!w[i] || dis[y] <= dis[x] + d[i]) continue;
			dis[y] = dis[x] + d[i]; if (!vis[y]) q.push(y), vis[y] = 1;
		}
	}
	if (dis[t] >= inf) return 0; 
	return 1;
}

int dfs(int x, int lim) {
	if (!lim || x == t) return lim;
	int res = 0, fl; vis[x] = 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (vis[y]) continue;
		if (!w[i] || dis[y] != dis[x] + d[i]) continue;
		fl = dfs(y, min(lim, w[i]));
		res += fl, lim -= fl;
		w[i] -= fl, w[i^1] += fl;
		if (!lim) return res;
	}
	return res;
}

int pre[N], ans;
int main() {
	read(n), read(k), cnt = 2 * n, s = ++cnt, t = ++cnt;
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1;i <= n; i++) read(c[i]);
	for (int i = 1;i <= n; i++) {
		adde(s, i, 1, 0), adde(i, i + n, 1, 0), adde(i + n, t, 1, 0);
		if (i < n) adde(i, i + 1, k - 1, 0);
		if (pre[a[i]]) adde(i - 1, pre[a[i]] + n, 1, -c[a[i]]);
		ans += c[a[i]], pre[a[i]] = i;
	}
	while (spfa()) 
		ans += dfs(s, inf) * dis[t];
	write(ans);
	return 0;
}