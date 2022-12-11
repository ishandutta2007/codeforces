
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

const int N = 400500;
int h[N], ne[N<<1], to[N<<1], tot = 1;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int To[N], vis[N], rt, siz, block;
void dfs(int x, int in) {
	vis[x] = 1; block++;
	for (int i = h[x]; i; i = ne[i]) {
		if (i == in) continue;
		int y = to[i]; To[x] = y;
		if (vis[y]) { 
			if (rt != -1) {
				siz = 1;
				for (int t = To[y]; t != y; t = To[t]) siz++;
			}
			rt = -1;
			continue;
		}
		dfs(y, i ^ 1);
	}
}

const int P = 1e9+7;
ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

int n, x;
int main() {
	read(n);
	for (int i = 1;i <= n; i++) 
		read(x), add(x, i), add(i, x);
	ll ans = 1;
	for (int i = 1;i <= n; i++) {
		if (!vis[i]) {
			block = 0, siz = 0, rt = 0, dfs(i, 0);
			ans = ans * fpw(2, block - siz) % P * (fpw(2, siz) + P - 2) % P;
		}
	}
	write(ans);
	return 0;
}