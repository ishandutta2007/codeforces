
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
const int N = 3005;
int t[N][N], x[N], y[N], b[N];
int ux[N], uy[N], dx[N], dy[N], cnt[N];
ll inv[N], fac[N], ans, m, n, r;
inline ll C(int n, int m) {
	if (n < m) return 0;
	return fac[n] * inv[m] % P * inv[n-m] % P;
}
inline int Sum(int x, int y, int l, int r) {
	if (x < l || y < r) return 0;
	return t[x][y] - t[l-1][y] - t[x][r-1] + t[l-1][r-1];
}
int main() {
	read(n), read(m), read(r);
	inv[0] = inv[1] = fac[0] = fac[1] = 1;
	for (int i = 2;i <= n; i++)
		inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= n; i++)
		fac[i] = fac[i-1] * i % P, inv[i] = inv[i-1] * inv[i] % P;
	for (int i = 1;i <= n; i++) {
		read(x[i]), read(y[i]), read(b[i]);
		t[x[i]][y[i]]++;
	}
	for (int i = 1;i <= 1000; i++)
		for (int j = 1;j <= 1000; j++)
			t[i][j] = t[i][j] + t[i-1][j] + t[i][j-1] - t[i-1][j-1];
	ll all = C(n, m);
	for (int i = 1;i <= n; i++)  {
		ux[i] = max(1ll, x[i] - r);
		uy[i] = max(1ll, y[i] - r);
		dx[i] = min(1000ll, x[i] + r);
		dy[i] = min(1000ll, y[i] + r);
		cnt[i] = Sum(dx[i], dy[i], ux[i], uy[i]);
	}
	for (int i = 1;i <= n; i++) {
		ans = (ans + (all - C(n - cnt[i], m) + P) * b[i] % P * b[i]) % P;
		for (int j = 1;j <= n; j++) {
			if (i == j) continue;
			int tux = max(ux[i], ux[j]);
			int tuy = max(uy[i], uy[j]);
			int tdx = min(dx[i], dx[j]);
			int tdy = min(dy[i], dy[j]);
			int cnt1 = cnt[j] - Sum(tdx, tdy, tux, tuy);
			ll t = C(n - cnt[i], m) + C(n - cnt[j], m) - C(n - cnt[i] - cnt1, m);
			ans = (ans + (all - t + 2 * P) * b[i] % P * b[j]) % P;
		}
	}
	write((ans % P + P) % P);
	return 0;
}