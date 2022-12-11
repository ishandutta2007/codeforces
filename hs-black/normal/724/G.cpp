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

const int N = 100500;
const int M = 200500;
int m, n; ll w[M<<1];
int h[N], ne[M<<1], to[M<<1], tot;
inline void add(int x, int y, ll z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

ll B[70], s[N], d[N], S, t;
inline void insert(ll x) {
	for (int i = 60; i >= 0; i--) if (x >> i & 1) {
		if (!B[i]) { B[i] = x, S++; break; }
		else x ^= B[i];
	}
}

int vis[N];
void dfs(int x, ll v) {
	vis[x] = 1, d[x] = v, s[++t] = x;
	for (int i = h[x]; i; i = ne[i]) 
		if (vis[to[i]]) insert(v ^ d[to[i]] ^ w[i]);
		else dfs(to[i], v ^ w[i]);
}

const int P = 1e9+7;
ll ans;
int main() {
	read(n), read(m);
	for (int i = 1;i <= m; i++) {
		ll x, y, z; read(x), read(y), read(z);
		add(x, y, z), add(y, x, z); 
	}
	for (int i = 1;i <= n; i++) if (!vis[i]) {
		memset(B, 0, sizeof(B)), S = t = 0, dfs(i, 0);
		if (t == 1) continue;
		ll s1 = (1ll << (S - 1)) % P, s2 = (1ll << S) % P;
		for (int j = 0;j < 60; j++) {
			ll c = (1ll << j) % P; 
			bool f = 0;
			for (int k = 0;k < 60; k++)
				if (B[k] >> j & 1) f = 1;
			if (f) ans = (ans + t * (t - 1) / 2 % P * s1 % P * c) % P;
			else {
				ll x = 0;
				for (int i = 1;i <= t; i++) x += (d[s[i]] >> j & 1);
				ans = (ans + x * (t - x) % P * s2 % P * c) % P;
			}
		}
	}
	write(ans);
	return 0;
}