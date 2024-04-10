
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

const int P = 1e9 + 7;
const int N = 2005;
const int M = 9005;
const int del = 4302;
vector<int> v[N];
int vis[N], cnt, siz[N], m, n;
int get(int x) {
	int cnt = 0, y = x;
	while (x = y) {
		cnt++, y = 0; vis[x] = 1;
		for (auto t: v[x])
			if (vis[t]) continue;
			else y = t;
	}
	return cnt;
}

inline void add(int &x, int y) { x += y, x >= P && (x -= P); }
int f[N][M], g[N][M];

int main() {
	read(n), read(m);
	for (int i = 1, x, y;i <= m; i++) 
		read(x), read(y), v[x].push_back(y), v[y].push_back(x);
	vis[1] = 1;
	for (auto t: v[1]) if (!vis[t]) siz[++cnt] = get(t);
	int L = del - m, R = del + m;
	f[0][del] = 1, g[cnt+1][del] = 1;
	for (int i = 1;i <= cnt; i++) {
		int t = siz[i] + 1;
		for (int j = L;j <= R; j++) {
			f[i][j] = f[i-1][j];
			if (j + t <= R) add(f[i][j], f[i-1][j+t]);
			if (j - t >= L) add(f[i][j], f[i-1][j-t]);
		}
	}
	for (int i = cnt;i >= 1; i--) {
		int t = siz[i] + 1;
		for (int j = L;j <= R; j++) {
			g[i][j] = g[i+1][j];
			if (j + t <= R) add(g[i][j], g[i+1][j+t]);
			if (j - t >= L) add(g[i][j], g[i+1][j-t]);
		}
	}
	int ans = 0;
	for (int i = 1;i <= cnt; i++) {
		for (int j = 1;j < siz[i]; j++) {
			int ls = siz[i] - j; ls = j - ls;
			for (int k = L;k <= R; k++) 
				if (k + ls >= L && k + ls <= R) add(ans, 1ll * f[i-1][k] * g[i+1][k+ls] % P);
			
		}
		for (int j = 1;j <= siz[i]; j++) {
			int ls = siz[i] + 1 - j; ls = j - ls;
			for (int k = L;k <= R; k++) 
				if (k + ls >= L && k + ls <= R) add(ans, 1ll * f[i-1][k] * g[i+1][k+ls] % P);
			
		}
	}
//	write(ans);
	memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
	f[0][del] = 1, g[cnt+1][del] = 1;
	for (int i = 1;i <= cnt; i++) {
		int t = siz[i] + 1;
		for (int j = L;j <= R; j++) {
			if (j + t <= R) add(f[i][j], f[i-1][j+t]);
			if (j - t >= L) add(f[i][j], f[i-1][j-t]);
		}
	}
//	write(ans);
	for (int i = cnt;i >= 1; i--) {
		int t = siz[i] + 1;
		for (int j = L;j <= R; j++) {
			if (j + t <= R) add(g[i][j], g[i+1][j+t]);
			if (j - t >= L) add(g[i][j], g[i+1][j-t]);
		}
	}
	for (int i = 1;i <= cnt; i++) {
		int ls = siz[i];
		for (int k = L;k <= R; k++) {
			if (k + ls >= L && k + ls <= R) add(ans, 1ll * f[i-1][k] * g[i+1][k+ls] % P);
			if (k - ls >= L && k - ls <= R) add(ans, 1ll * f[i-1][k] * g[i+1][k-ls] % P);
		}
	}
	add(ans, ans);
	add(ans, f[cnt][del]);
	write(ans);
	return 0;
}

/*




*/