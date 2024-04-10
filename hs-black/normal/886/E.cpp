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

const int N = 1000500;
const int P = 1e9+7;
ll n, k;
ll inv[N], jie[N], f[N], g[N];

inline ll C(ll n, ll m) {
	return jie[n] * inv[m] % P * inv[n-m] % P;
}
int main() {
	read(n), read(k);
	inv[0] = inv[1] = jie[0] = jie[1] = 1;
	for (int i = 2;i <= n; i++) 
		inv[i] = (P - P / i) * inv[P % i] % P,
		jie[i] = jie[i-1] * i % P;
	for (int i = 2;i <= n; i++)
		inv[i] = inv[i-1] * inv[i] % P;
	
	f[0] = g[0] = 1;
	for (int i = 1;i <= n; i++) {
		f[i] = (g[i-1] - (i > k ? g[i-k-1] : 0) + P) * jie[i-1] % P;
//		cout << g[i-1] - (i > k ? g[i-k-1] : 0) << ' ', write(f[i]);
		g[i] = (g[i-1] + f[i] * inv[i]) % P;
	}
	
	ll ans = 0;
	for (int i = 1;i <= n; i++)
		ans = (ans + f[i-1] * C(n-1, i-1) % P * jie[n-i]) % P;
	write((jie[n] - ans + P) % P);
	return 0;
}
/*

162 14

*/