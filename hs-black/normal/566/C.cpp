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

const int N = 200500;
int h[N], ne[N<<1], to[N<<1], w[N<<1], tot, P, n;
double ans = 1e20;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

int siz[N], vis[N], val[N], Siz, lim, rt;
void get_rt(int x, int fa) {
	siz[x] = 1; int mx = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa || vis[y]) continue;
		get_rt(y, x), siz[x] += siz[y]; Mx(mx, siz[y]);
	}
	Mx(mx, Siz - siz[x]);
	if (mx < lim) lim = mx, rt = x;
}

double d[N], sum, sumd;
void dfs(int x, int fa, int dis, int num) {
	sum += pow(dis, 1.5) * val[x], d[num] += pow(dis, 0.5) * 1.5 * val[x];
	for (int i = h[x], y; i; i = ne[i]) 
		if ((y = to[i]) != fa) dfs(y, x, dis + w[i], num);
}

void solve(int x) {
	if (vis[x]) return; 
	get_rt(x, 0), vis[x] = 1, sum = sumd = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; d[y] = 0;
		dfs(y, x, w[i], y), sumd += d[y];
	}
	if (sum < ans) ans = sum, P = x;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (sumd - d[y] * 2 >= 0) continue;
		Siz = siz[y], lim = 998224353, get_rt(y, 0);
		solve(rt); break;
	}
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(val[i]);
	for (int i = 1, x, y, z; i < n ; i++) 
		read(x), read(y), read(z), add(x, y, z), add(y, x, z);
	Siz = n, lim = 1919810, get_rt(1, 0), solve(rt);
	printf ("%d %.8lf\n", P, ans);
	return 0;
}