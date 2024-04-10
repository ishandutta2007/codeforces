
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <ctime>
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

//#pragma GCC optimize(2)
const int N = 305, Q = 2005000, C = 1005;
int col[N][N], cc[N][N], id[N][N], f[Q<<2], ans[Q], x[Q], y[Q], c[Q], tc[Q], cnt, m, n, q;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int check(int x, int y) {
	int n = id[x][y], del = -1;
	for (int i = 0;i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i], tn = find(id[tx][ty]);
		if (col[tx][ty] == col[x][y] && tn != find(n)) f[tn] = n, del++;
	}
	return del;
}

int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(m), read(q);
	for (int i = 0;i <= n + 1; i++) col[i][0] = col[i][m+1] = -1;
	for (int i = 0;i <= m + 1; i++) col[0][i] = col[n+1][i] = -1;
	for (int i = 1;i <= n; i++) for (int j = 1;j <= m; j++) ++cnt, f[id[i][j] = cnt] = cnt;
	for (int i = 1;i <= q; i++) {
		read(x[i]), read(y[i]), read(c[i]);
		int &pre = cc[x[i]][y[i]];
		tc[i] = pre, pre = c[i];
	}
	ans[0] = 1;
	for (int i = 1;i <= q; i++) 
		col[x[i]][y[i]] = c[i], ++cnt, f[id[x[i]][y[i]] = cnt] = cnt, ans[i] -= check(x[i], y[i]);
	cnt = 0;
	for (int i = 1;i <= n; i++) for (int j = 1;j <= m; j++) ++cnt, f[id[i][j] = cnt] = cnt;
	for (int i = 1;i <= n; i++) for (int j = 1;j <= m; j++) check(i, j);
	for (int i = q;i >= 1; i--)
		col[x[i]][y[i]] = tc[i], ++cnt, f[id[x[i]][y[i]] = cnt] = cnt, ans[i] += check(x[i], y[i]);
	for (int i = 1;i <= q; i++) ans[i] += ans[i-1], write(ans[i]);
	return 0;
}