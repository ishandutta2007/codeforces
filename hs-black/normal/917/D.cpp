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
inline void write(F x, char ed = '\n')
{
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

const int N = 105;
const int P = 1e9+7;
ll dp[N][N][2], f[N][2], siz[N];

int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

void dfs(int x, int fa) {
	dp[x][0][0] = dp[x][0][1] = siz[x] = 1;
	for (int i = h[x], y; i; i = ne[i]) {
		if ((y = to[i]) == fa) continue; dfs(y, x);
		memcpy(f, dp[x], sizeof(f));
		memset(dp[x], 0, sizeof(dp[x]));
		for (int j = 0;j < siz[x] + siz[y]; j++) {
			for (int k = 0;k <= min(siz[x] - 1, (ll)j); k++) {
				dp[x][j][0] = (dp[x][j][0] + f[k][0] * dp[y][j-k][1]) % P;
				dp[x][j][1] = (dp[x][j][1] + f[k][1] * dp[y][j-k][1]) % P;
				if (j != k) {
					dp[x][j][0] = (dp[x][j][0] + f[k][0] * dp[y][j-k-1][0]) % P;
					dp[x][j][1] = (dp[x][j][1] + f[k][1] * dp[y][j-k-1][0] + f[k][0] * dp[y][j-k-1][1]) % P;
				}
			}
		} siz[x] += siz[y];
	}
}

ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P )
		if (mi & 1) res = res * x % P;
	return res;
}

ll mi[N], C[N][N], n;
int main() {
	read(n);
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	dfs(1, 0);  mi[0] = fpw(n, P - 2) % P;
	for (int i = 1;i <= n; i++) mi[i] = mi[i-1] * n % P;
	C[0][0] = 1;
	for (int i = 1;i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1;j <= n; j++) 	
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
	}
	for (int i = 0;i <= n - 1; i++) dp[1][i][1] = dp[1][i][1] * mi[n-i-1] % P;
	for (int i = 0;i <= n - 1; i++) {
//		write(dp[1][i][1] * mi[n-i-1] % P, ' ');
		ll ans = 0;
		for (int k = i;k <= n - 1; k++)
			if ((k - i) & 1) ans -= C[k][i] * dp[1][k][1] % P;
			else ans += C[k][i] * dp[1][k][1] % P;
		write(((ans % P) + P) % P, ' ');
	}
	return 0;
}