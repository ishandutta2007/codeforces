
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

const int N = 20500;
int f[205][N], g[2][N], a[N], b[N], n, m, p;

int F(int x, int y) {
	return (a[x] + b[y]) % p;
}

bool pre[205][N];
int dp[205][N], s[2*N], tp;
void solve(int L, int R, int *g, int &st) {
	int t = R - L;
	memcpy(dp[t], g, m * 4 + 30);
	for (int i = m;i >= 1; i--)
		if (dp[t][i] == dp[t][i+1] + F(n - R, m - i))
			pre[t][i] = 1;
		else pre[t][i] = 0;
	for (int i = R - 1;i >= L; i--) {
		t = i - L;
		for (int j = m;j >= 1; j--) {
			if (dp[t][j+1] > dp[t+1][j]) 
				dp[t][j] = dp[t][j+1], pre[t][j] = 1;
			else dp[t][j] = dp[t+1][j], pre[t][j] = 0;
			dp[t][j] += F(n - i, m - j);
		}
	}
	t = L;
	while (L <= R) {
		if (pre[L-t][st]) st++, s[++tp] = 1;
		else L++, L <= R && (s[++tp] = 0);
	}
}

int main() {
	read(n), read(m), read(p); int sq = sqrt(n);
	for (int i = 0;i < n; i++) read(a[i]);
	for (int j = 0;j < m; j++) read(b[j]);
	int pre = 0, nw = 1;
	for (int i = n;i >= 1; i--) {
		memset(g[nw], 0, m * 4 + 29);
		for (int j = m;j >= 1; j--) 
			g[nw][j] = max(g[pre][j], g[nw][j+1]) + F(n - i, m - j);
		if ((i - 1) % sq == 0) memcpy(f[(i - 1) / sq], g[nw], m * 4 + 29);
		swap(nw, pre);
	}
	write(f[0][1]); int st = 1;
	for (int i = 1, j = 0;i <= n; i += sq, j++) {
		int L = i, R = min(i + sq, n);
		if (i + sq >= n) 
			for (int k = m;k >= 1; k--)
				f[j+1][k] = f[j+1][k+1] + F(0, m - k);
		f[j+1][m+1] = -1;
		solve(L, R, f[j+1], st);
	}
	while (tp) putchar(s[tp--] ? 'S' : 'C');
	return 0;
}