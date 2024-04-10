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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 3005;
const int P = 1e9+7;
ll f[N][N], s[N][N], g[N], m, n;
int h[N], ne[N], to[N], tot;
ll jie[N], inv[N];
void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

void dfs(int x) {
	for (int i = 1;i <= n; i++) f[x][i] = 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; dfs(y);
		for (int j = 1;j <= n; j++)
			f[x][j] = f[x][j] * s[y][j] % P;
	}
	for (int i = 1;i <= n; i++) 
		s[x][i] = (s[x][i-1] + f[x][i]) % P;	
}

ll C(ll n, ll m) {
	return jie[n] * inv[m] % P * inv[n-m] % P;
}

ll CC(ll n, ll m) {
	ll res = inv[m];
	for (ll i = n;i > n - m; i--) 
		res = res * i % P;
	return res;
}

int main() {
	read(n), read(m);
	for (int i = 2, f;i <= n; i++) read(f), add(f,  i);
	inv[0] = inv[1] = jie[0] = jie[1] = 1;
	for (int i = 2;i <= n; i++) 
		inv[i] = (P - P / i) * inv[P % i] % P,
		jie[i] = jie[i-1] * i % P;
	for (int i = 2;i <= n; i++)
		inv[i] = inv[i] * inv[i-1] % P;
	
	
	dfs(1);
	for (int i = 1;i <= n; i++) {
		g[i] = f[1][i];
		for (int j = 1;j < i; j++)
			g[i] -= C(i - 1, i - j) * g[j] % P;
		g[i] = (g[i] % P + P) % P;
	}
	
	ll ans = 0;
	for (int i = 1;i <= min(n, m); i++)
		(ans += CC(m, i) * g[i]) %= P;
	
	write(ans);
	return 0;
}