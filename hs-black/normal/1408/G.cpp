
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

const int N = 2050, M = N << 1;
int f[M], to[N][N], p[N], L[M], R[M], cnt, st[N], num, n;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
pair<int, int> ed[N*N];
int ch[M][2], siz[N];
const int P = 998244353;
bool in(int x, int y) {
	return L[x] >= L[y] && L[x] <= R[y];
}

#define ls ch[x][0]
#define rs ch[x][1]
ll dp[M][N]; int w[N][N];
bool check(int x) {
	int sz = siz[x], tp = n * n, prev = 0;
	for (int i = L[x]; i <= R[x]; i++) {
		int t = st[i];
		while (p[t] < sz && in(to[t][p[t]+1], x)) p[t]++;
		if (p[t] != sz) return 0;
		if (p[t] != n) Mn(tp, w[t][to[t][p[t]+1]]);
		Mx(prev, w[t][to[t][p[t]]]);
		if (prev > tp) return 0;
	}
	return 1;
}

void dfs(int x) {
	if (x <= n) {
		st[++num] = x, L[x] = R[x] = num;
		dp[x][1] = siz[x] = 1; return;
	}
	dfs(ls), dfs(rs);
	L[x] = L[ls], R[x] = R[rs];
	siz[x] = R[x] - L[x] + 1;
	for (int i = 1;i <= siz[ls]; i++) 
		for (int j = 1;j <= siz[rs]; j++)
			dp[x][i + j] = (dp[x][i + j] + dp[ls][i] * dp[rs][j]) % P;
	dp[x][1] += check(x);
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) 
		for (int j = 1;j <= n; j++)
			read(w[i][j]), ed[w[i][j]] = MP(i, j);
	for (int i = 1;i <= n; i++) p[i] = 1, f[i] = i;
	int lim = n * (n - 1) / 2; cnt = n;
	for (int i = 1;i <= lim; i++) {
		int x = ed[i].fi, y = ed[i].se;
		to[x][++p[x]] = y, to[y][++p[y]] = x;
		x = find(x), y = find(y);
		if (x == y) continue;
		++cnt, ch[cnt][0] = x, ch[cnt][1] = y;
		f[x] = f[y] = f[cnt] = cnt;
	}
	for (int i = 1;i <= n; i++) p[i] = 1;
	dfs(cnt);
	for (int i = 1;i <= n; i++) write(dp[cnt][i], ' ');
	return 0;
}