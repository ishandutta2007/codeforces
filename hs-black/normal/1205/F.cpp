/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int N = 102;
int n, k;
struct node {
	int ok; int pn, pk;
	node(int o = 0, int n = 0, int k = 0) { ok = o, pn = n, pk = k; }
}f[N][N * N];
void prework(int n, int k) {
	for (int i = 1;i <= n; ++i) f[i][i * (i - 1) / 2] = node(1, 0, 0);
	for (int i = 4;i <= n; ++i) f[i][1] = node(1, 0, 0);
	for (int i = 3;i <= n; ++i) {
		int lim = i * (i - 1) / 2;
		for (int j = 2;j <= lim; ++j) {
			for (int k = 2;k < i && !f[i][j].ok && k * (k - 1) / 2 < j; ++k) {
				int t1 = k, t2 = k * (k - 1) / 2;
				if (f[t1][t2].ok && f[i - t1 + 1][j - t2].ok)
					f[i][j] = node(1, t1, t2);
			}
			for (int k = 4;k < i && !f[i][j].ok; ++k) {
				int t1 = k, t2 = 1;
				if (f[t1][t2].ok && f[i - t1 + 1][j - t2].ok)
					f[i][j] = node(1, t1, t2);
			}
		}
	}
}

int ans[N], cur[N], T;
void con(int n) {
	int l = 3, nw = 0;
	while (l <= n) cur[++nw] = l, l += 2;
	cur[++nw] = 1;
	l = n - (n & 1);
	while (l >= 1) cur[++nw] = l, l -= 2;
}
int solve(int n, int k) {
	if (!f[n][k].pn) {
		if (n != 2 && k == 1) con(n), memcpy(ans, cur, n * 4 + 20);
		else for (int i = 1;i <= n; ++i) ans[i] = i;
		return n == 2 || k != 1;
	}
	int t1 = n - f[n][k].pn + 1, t2 = f[n][k].pn;
	int pr = solve(t1, k - f[n][k].pk), tt = ans[t1];
	for (int i = 1;i <= t1; ++i)
		if (ans[i] > tt) ans[i] += t2 - 1;
	if (f[n][k].pk == 1 && f[n][k].pn != 2) {
		con(t2);
		for (int i = t1;i <= n; ++i) ans[i] = cur[i - t1 + 1] + tt - 1;
		return 0;
	} else {
		for (int i = t1;i <= n; ++i) ans[i] = tt + i - t1;
		if (pr == 1) reverse(ans + t1, ans + n + 1), pr = 2;
		else pr = 1;
		return pr;
	}
}

int main() {
	for (read(T), prework(100, 10000); T; --T) {
		read(n), read(k), k -= n;
		if (k < 0 || !f[n][k].ok) { puts("NO"); continue; }
		solve(n, k), puts("YES");
		for (int i = 1;i <= n; ++i)
			write(ans[i], " \n"[i == n]);
	}
	return 0;
}

/*
1
3 5

3 6

*/