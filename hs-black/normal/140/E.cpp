//#pragma GCC optimize(3, "inline")
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
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

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

ll m, n, P;

const int N = 5005;
ll f[N][N]; 

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P; mi >>= 1;
	}
	return res;
}

const int M = 1005000;
ll A[N], jie[N];
ll g[2][N];

void init(void) {
	A[0] = jie[0] = f[0][0] = 1;
	int lim = min(5000ll, m);
	for (int i = 1;i <= lim; i++)
		A[i] = A[i-1] * (m - i + 1) % P;
	for (int i = 1;i <= lim; i++)
		jie[i] = jie[i-1] * i % P;
	for (int i = 1;i <= 5000; i++)
		for (int j = 1;j <= min(lim, i); j++) 
			f[i][j] = (f[i-1][j-1] + f[i-1][j] * (j - 1)) % P;
	
}

int main() {
	read(n), read(m), read(P);
	ll sum = 1, tmp = 0; init();
	for (int i = 1;i <= n; i++) {
		ll nw = i & 1, pr = !nw, l; read(l);
		for (int j = 1;j <= min(l, m); j++) {
			g[nw][j] = f[l][j] * ((A[j] * sum - jie[j] * g[pr][j]) % P) % P;
			tmp += g[nw][j];
		}
		sum = (tmp % P + P) % P, tmp = 0;
		memset(g[pr], 0, sizeof(g[pr]));
	}
	printf ("%lld\n", sum);
	return 0;
}