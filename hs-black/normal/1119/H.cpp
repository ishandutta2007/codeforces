/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int P = 998244353;

ll fpw(ll x, ll mi) {
//	write(mi);
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

int lim;
inline int mod(int x) { return x >= P ? x - P : x; }
void FWT(int *f) {
	for (int i = 1;i < lim; i <<= 1)
		for (int j = 0;j < lim; j += (i << 1))
			for (int k = 0;k < i; ++k) {
				int x = f[j + k], y = f[j + k + i];
				f[j + k] = x + y, f[i + j + k] = x - y;
			}
}
void FFWT(int *f) {
	for (int i = 1;i < lim; i <<= 1)
		for (int j = 0;j < lim; j += (i << 1))
			for (int k = 0;k < i; ++k) {
				int x = f[j + k], y = f[j + k + i];
				f[j + k] = mod(x + y), f[i + j + k] = mod(x - y + P);
			}
}

const int N = 200500;
int g1[N], g2[N], g3[N], g4[N], n, k;
ll x, y, z;
int main() {
	read(n), read(k); lim = 1 << k;
	read(x), read(y), read(z); int all = 0;
	for (int i = 1, a, b, c;i <= n; ++i) {
		read(a), read(b), read(c), b ^= a, c ^= a;
		all ^= a, ++g1[b], ++g2[c], ++g3[b ^ c];
	}
	FWT(g1), FWT(g2), FWT(g3);
	ll t1 = (x + y + z) % P, t2 = (x + y - z + P) % P, t3 = (P + x - y + z) % P, t4 = (2 * P + x - y - z) % P;
	for (int i = 0;i < lim; ++i) {
		ll res = 1; int c1;
		res = res * fpw(t1, c1 = (n + g1[i] + g2[i] + g3[i]) / 4) % P;
		res = res * fpw(t2, (n + g1[i] - 2 * c1) / 2) % P;
		res = res * fpw(t3, (n + g2[i] - 2 * c1) / 2) % P;
		res = res * fpw(t4, (n + g3[i] - 2 * c1) / 2) % P;
		g4[i] = res;
	}
	FFWT(g4);
	ll inv = fpw(lim, P - 2);
	for (int i = 0;i < lim; ++i) 
		write(g4[i ^ all] * inv % P, ' ');
	return 0;
}