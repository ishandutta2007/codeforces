
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

const int N = 1050;
int n, d, P;
ll inv[N], dp[N];
ll C(ll n, int m) {
	ll res = inv[m];
	while (m) res = res * n % P, --n, --m;
	return res;
}

ll f[12][N][N];

int main() {
	read(n), read(d), read(P);
	if (n == 1 || n == 2) return write(1), 0;
	inv[0] = inv[1] = dp[1] = 1;
	for (int i = 2;i <= d; i++) inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= d; i++) inv[i] = inv[i-1] * inv[i] % P;
	for (int i = 0;i <= n; i++) f[0][1][i] = 1;
	for (int i = 2;i <= n; i++) {
		int lim = min(d, i - 1);
		for (int j = 1;j <= lim; j++) {
			f[j][i][1] = i == j + 1;
			for (int k = 2;k + k <= n; k++) {
				f[j][i][k] = f[j][i][k-1];
				for (int t = 1;t <= j && t * k < i; t++) 
					f[j][i][k] = (f[j][i][k] + f[j-t][i-t*k][k-1] * C(dp[k] + t - 1, t) % P) % P;
			}
		}
		dp[i] = f[d-1][i][i-1];
	}
	ll ans = 0;
	if (n & 1) ans = f[d][n][n / 2];
	else ans = (f[d][n][n / 2 - 1] + C(dp[n / 2] + 1, 2)) % P;
	write(ans);
	return 0;
}