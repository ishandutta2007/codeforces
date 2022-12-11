
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

const int N = 5005;
ll g[N], f[N][N], t[N], x[N], n;
inline ll jzp(ll x) { return x > 0 ? x : -x; } 
int main() {
	read(n);
	for (int i = 1;i <= n; i++)	read(t[i]), read(x[i]);
	memset(g, 0x3f, sizeof(g)); g[0] = 0;
	for (int i = 0;i < n; i++) {
		if (g[i] <= t[i]) {
			Mn(g[i + 1], max(g[i] + jzp(x[i + 1] - x[i]), t[i]));
			for (int j = i + 2;j <= n; j++)
				f[i + 1][j] |= max(t[i], jzp(x[j] - x[i]) + g[i]) + jzp(x[j] - x[i + 1]) <= t[i + 1];
		}
		for (int j = i + 2;j <= n; j++)
			f[i + 1][j] |= f[i][j] && jzp(x[i] - x[i + 1]) <= t[i + 1] - t[i];
		if (i + 2 <= n && f[i][i + 1]) {
			Mn(g[i + 2], max(t[i] + jzp(x[i + 2] - x[i]), t[i + 1]));
			for (int j = i + 3;j <= n; j++) 
				f[i + 2][j] |= max(t[i] + jzp(x[i] - x[j]), t[i + 1]) + jzp(x[j] - x[i + 2]) <= t[i + 2];
		}
	}
	puts(g[n] <= t[n] || f[n - 1][n] ? "YES" : "NO");
	return 0;
}