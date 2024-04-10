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

#include <cmath>
const int N = 1105000;
#define ld double
struct com {
	ld x, y;
	com (ld xx = 0, ld yy = 0) :x(xx), y(yy) {}
	com operator + (com &b) { return com(x + b.x, y + b.y); }
	com operator - (com &b) { return com(x - b.x, y - b.y); }
	com operator * (com &b) { return com(x * b.x - y * b.y, x * b.y + y * b.x); }
}E[N], A[N], B[N], C[N];

int r[N], lim;
void dft(com *A) {
	for (int i = 0;i < lim; ++i)
		if (r[i] > i) swap(A[i], A[r[i]]);
	for (int i = 1;i < lim; i <<= 1)
		for (int j = 0;j < lim; j += (i << 1)) {
			com *f = A + j, *g = f + i, *e = E + i;
			for (int k = 0;k < i; ++k) {
				com x = f[k], y = g[k] * e[k];
				f[k] = x + y, g[k] = x - y;
			}
		}
}

void idft(com *A) {
	dft(A), reverse(A + 1, A + lim);
	for (int i = 0;i < lim; ++i) A[i].x /= lim, A[i].y /= lim;
}

const ld Pi = acos(-1.0);
void prework(void) {
	E[1] = com(1, 0), lim = 1;
	while (lim < 490019 * 2) lim <<= 1;
	int len = lim >> 1;
	for (int i = 0;i < lim; ++i)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) ? len : 0);
	for (int i = 2;i < lim; i <<= 1) {
		com *e0 = E + (i >> 1), *e1 = E + i;
		com w = com(cos(Pi / i), sin(Pi / i));
		for (int j = 0;j < i; j += 2)
			e1[j] = e0[j >> 1], e1[j | 1] = e1[j] * w;
	}
}

const int P = 490019;
ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

int ta[N], tb[N], m, n, c; ll mi[N];
inline void add(int &x, int y) { x += y, x >= P && (x -= P); }
int main() {
	read(n), read(m), read(c), mi[0] = 1;
	for (int i = 1;i < P; ++i) mi[i] = mi[i-1] * c % P;
	for (int i = 0, x;i < n; ++i) 
		read(x), add(ta[(1ll * i * i) % (P - 1)], x);
	for (int i = 0, x;i < m; ++i)
		read(x), add(tb[(1ll * i * i * i) % (P - 1)], x);
	prework();
	for (int i = 0;i < P - 1; ++i) {
		ta[i] = 1ll * ta[i] * mi[P - 1 - 1ll * i * (i - 1) / 2 % (P - 1)] % P;
		tb[i] = 1ll * tb[i] * mi[P - 1 - 1ll * i * (i - 1) / 2 % (P - 1)] % P;
		int t1 = ta[i] >> 10, t2 = ta[i] - (t1 << 10);
		int t3 = tb[i] >> 10, t4 = tb[i] - (t3 << 10);
		A[i] = com(t1, t2), B[i] = com(t1, -t2), C[i] = com(t3, t4);
	}
	dft(A), dft(B), dft(C);
	for (int i = 0;i < lim; ++i) 
		A[i] = A[i] * C[i], B[i] = B[i] * C[i];
	idft(A), idft(B);
	ll ans = 0;
	for (int i = 0;i < 2 * P; ++i) {
		ll t1 = ((A[i].x + B[i].x) / 2 + 0.5);
		ll t2 = ((A[i].y + B[i].y) / 2 + 0.5);
		ll t3 = (B[i].x - t1 + 0.5);
		ll t4 = (A[i].y - t2 + 0.5);
		ll t = ((t1 % P << 20) + ((t2 + t4) % P << 10) + t3) % P;
		ans = (ans + mi[1ll * i * (i - 1) / 2 % (P - 1)] * t) % P;
	}
	write((ans % P + P) % P);
	return 0;
}

/*

(At + B)(Ct + D) = ACt^2 + (AD+BC)t + BD

A + Bi
C + Di

AC-BD + (AD+BC)
AC+BD + (AD-BC)
 
*/