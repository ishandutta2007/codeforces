
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

const int N = 200050;
int h[N], ne[N], to[N], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int f[N][18], dep[N], w[N], m, n;
ll sum[N], S, L;
void dfs(int x) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		f[y][0] = x, sum[y] = sum[x] + w[y];
		for (int j = 1;f[y][j-1]; j++) 
			f[y][j] = f[f[y][j-1]][j-1];
		dep[y] = dep[x] + 1, dfs(y);
	}
}

int get(int x) {
	if (sum[x] <= S && dep[x] <= L) return 1;
	int y = x;
	for (int i = 17;i >= 0; i--) {
		int t = f[y][i]; if (!t) continue;
		if (dep[x] - dep[t] + 1 > L) continue;
		if (sum[x] - sum[t] + w[t] > S) continue;
		y = f[y][i];
	}
	return dep[y];
}

int dp[N], g[N];
void efs(int x) {
	g[x] = dep[x] + 1;
	for (int i = h[x], y; i; i = ne[i]) 
		efs(y = to[i]), dp[x] += dp[y], Mn(g[x], g[y]);
	if (g[x] > dep[x]) dp[x]++, g[x] = get(x);
}

int main() {
	read(n), read(L), read(S);
	for (int i = 1;i <= n; i++) {
		read(w[i]); if (w[i] > S) return write(-1), 0; 
	}
	for (int i = 2, f;i <= n; i++) read(f), add(f, i);
	sum[1] = w[1], dep[1] = 1, dfs(1), efs(1);
	return write(dp[1]), 0;
}