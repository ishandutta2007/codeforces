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
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 2000050;
int vis[N], st[N], tp, ans[N], v[N], n;
int ne[N<<1], to[N<<1], w[N<<1], h[N], tot = 1;
inline void adde(int x, int y, int z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
void dfs(int x) {
	for (int &i = h[x]; i; i = ne[i]) if (!vis[i]) {
		int t = i;
		vis[i] = vis[i ^ 1] = 1;
		dfs(to[i]); st[++tp] = w[t ^ 1], st[++tp] = w[t];
	}
}

int deg[N];
int main() {
	read(n);
	for (int i = 0;i < n; ++i)
		read(v[i << 1 | 1]), read(v[i + 1 << 1]);
	for (int i = 0;i <= 20; ++i) {
		int all = (1 << i) - 1, fl = 1;
		memset(deg, 0, 4 << i);
		memset(h, 0, 4 << i), tot = 1, tp = 0;
		for (int j = 1, x, y;j <= 2 * n; j += 2) {
			x = v[j] & all, y = v[j + 1] & all;
			adde(x, y, j), adde(y, x, j + 1), ++deg[x], ++deg[y];
		}
		for (int i = 0;i <= all; ++i)
			if (deg[i] & 1) { fl = 0; break; }
		if (fl) {
			memset(vis, 0, sizeof(vis));
			dfs(v[1] & all);
			if (tp != 2 * n) fl = 0;
		}
		if (!fl) {
			write(i - 1);
			for (int i = 1;i <= 2 * n; ++i) write(ans[i], ' ');
			return 0;
		}
		memcpy(ans, st, sizeof(st));
	}
	write(20);
	for (int j = 1;j <= 2 * n; ++j) write(ans[j], ' ');
	return 0;
}