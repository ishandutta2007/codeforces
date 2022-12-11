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
const int N = 220500;
int k, n;
inline int mod(int x) { return x >= P ? x - P : x; }

ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

#define vec vector<int>
ll E[N]; int lim, r[N];
void dft(vec &A) {
	for (int i = 0;i < lim; ++i)
		if (r[i] > i) swap(A[i], A[r[i]]);
	for (int i = 1;i < lim; i <<= 1) 
		for (int j = 0;j < lim; j += (i << 1)) {
			vec::iterator f = A.begin() + j, g = f + i; ll *e = E + i;
			for (int k = 0;k < i; ++k) {
				int x = f[k], y = e[k] * g[k] % P;
				f[k] = mod(x + y), g[k] = mod(x + P - y);
			}
		}
}

void idft(vec &A) {
	dft(A); ll inv = fpw(lim, P - 2);
	reverse(A.begin() + 1, A.begin() + lim);
	for (int i = 0;i < lim; ++i) A[i] = A[i] * inv % P;
}

void prework(void) {
	lim = 1;
	while (lim <= 2 * k) lim <<= 1;
	int len = lim >> 1;
	for (int i = 0;i < lim; ++i)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) ? len : 0);
	E[1] = 1;
	for (int i = 2;i < lim; i <<= 1) {
		ll *e0 = E + (i >> 1), *e1 = E + i;
		ll w = fpw(3, (P - 1) / (i << 1));
		for (int j = 0;j < i; j += 2)
			e1[j] = e0[j >> 1], e1[j | 1] = e1[j] * w % P;
	}
}

struct node {
	vec f[2][2];
	node(void) { for (int i = 0;i <= 1; ++i) f[i][0].resize(lim), f[i][1].resize(lim); }
	vec * operator [](int x) { return f[x]; }
	void clear(int st = 0) {
		for (int i = 0;i <= 1; ++i)
			for (int j = 0;j <= 1; ++j)
				for (int k = st;k < lim; ++k) f[i][j][k] = 0;
	}
	void out() {
		for (int i = 0;i <= 1; ++i)
			for (int j = 0;j <= 1; ++j) {
				for (int k = 0;k < lim; ++k) write(f[i][j][k], ' ');
				puts("");
			}
		puts("");
	}
		
};

void add(vec &a, vec &x, vec &y) {
	for (int i = 0;i < lim; ++i)
		a[i] = (a[i] + 1ll * x[i] * y[i]) % P;
}

int main() {
	read(n), read(k), prework();
	node res, X, tmp;
	res[0][0][0] = res[1][1][0] = 1;
	X[0][0][0] = X[0][0][1] = X[0][1][0] = X[1][0][1] = 1;
	for (--n ; n; ) {
		for (int i = 0;i <= 1; ++i)
			for (int j = 0;j <= 1; ++j)
				dft(X[i][j]);
		if (n & 1) {
			tmp = res;
			for (int i = 0;i <= 1; ++i)
				for (int j = 0;j <= 1; ++j)
					dft(tmp[i][j]);
			res.clear();
			for (int i = 0;i <= 1; ++i)
				for (int j = 0;j <= 1; ++j)
					for (int k = 0;k <= 1; ++k)
						add(res[i][j], tmp[i][k], X[k][j]);
			for (int i = 0;i <= 1; ++i)
				for (int j = 0;j <= 1; ++j)
					idft(res[i][j]);
			res.clear(k + 1);
		}
		n >>= 1;
		if (n) {
			tmp = X, X.clear();
			for (int i = 0;i <= 1; ++i)
				for (int j = 0;j <= 1; ++j)
					for (int k = 0;k <= 1; ++k)
						add(X[i][j], tmp[i][k], tmp[k][j]);
			for (int i = 0;i <= 1; ++i)
				for (int j = 0;j <= 1; ++j)
					idft(X[i][j]);
			X.clear(k + 1);
		}
//		res.out(), X.out();
	}
	for (int i = 1;i <= k; ++i) 
		write((0ll + res[0][0][i] + res[0][0][i-1] + res[1][0][i]) % P, ' ');
	return 0;
}

/*

100000000 30000

*/