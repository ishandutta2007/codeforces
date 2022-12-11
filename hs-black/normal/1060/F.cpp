#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define db double
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 55;
int h[N], to[N<<1], ne[N<<1];
int tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[tot] = y, h[x] = tot;
}

int siz[N], n;
db jie[N], dp[N][N], g[N];
db t[N];

inline db C(int n, int m) {
	if (n < m) return 0;
	return jie[n] / (jie[m] * jie[n-m]);
}

void dfs(int x, int fa) {
	siz[x] = 1, dp[x][0] = 1;
	for (int i = 1;i <= n; i++) dp[x][i] = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs (y, x);
		for (int j = 0;j <= siz[y]; j++) {
			g[j] = 0;
			for (int k = 0;k < j; k++) g[j] += 0.5 * dp[y][k];
			g[j] += (siz[y] - j) * dp[y][j];
		}
		for (int j = siz[x] + siz[y]; ~j; --j) t[j] = 0;
		for (int j = 0;j < siz[x]; j++) {
			for (int k = 0;k <= siz[y]; k++) 
				t[j + k] += dp[x][j] * g[k] *
				C(j + k, j) * C(siz[x] + siz[y] - 1 - j - k, siz[x] - 1 - j);
		}
		siz[x] += siz[y];
		for (int j = 0;j < siz[x]; j++) dp[x][j] = t[j];
	}
}


int main() {
	read(n);
	for (int i = 1;i < n; i++) {
		int x, y; read(x), read(y);
		add(x, y), add(y, x);
	}
	jie[0] = 1;
	for (int i = 1;i <= n; i++) jie[i] = jie[i-1] * i;
	for (int i = 1;i <= n; i++) 
		dfs(i, 0), printf ("%.10lf\n", dp[i][n-1] / jie[n-1]);
	return 0;
}