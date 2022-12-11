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

//#pragma GCC optimize(2)
const int P = 998244353;
namespace Poly {
#define poly vector<int> 
#define reg register
	inline int mod(int x) { return x >= P ? x - P : x; }
	inline void Add(int &x, int y) { x += y; if (x >= P) x -= P; }
	template <typename T>
		inline int max(T x, T y) { return x > y ? x : y; }
	template <typename T>
		inline int min(T x, T y) { return x > y ? y : x; }
	int fpw(ll x, int mi) {
		ll res = 1;
		for (; mi; mi >>= 1, x = x * x % P)
			if (mi & 1) res = res * x % P;
		return res;
	}
	const int N = 600500;
	int E[N], r[N], lim;
	inline void Prework(int Maxsize) {
		E[1] = lim = 1;
		while (lim <= Maxsize) lim <<= 1;
		for (int i = 2;i < lim;i <<= 1) {
			int *e0 = E + (i >> 1), *e1 = E + i;
			ll w = fpw(3, (P - 1) / (i << 1));
			for (int j = 0;j < i; j += 2)
				e1[j] = e0[j >> 1], e1[j + 1] = e1[j] * w % P;
		}
	}

	inline void getR(int len = lim >> 1) {
		for (reg int i = 1;i < lim; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) ? len : 0);
	}
	inline int getlen(int Maxsize) { lim = 1; while (lim <= Maxsize) lim <<= 1; return lim; } 
	void init(int Maxsize) { getlen(Maxsize); getR(); }

	inline void Dft(poly &A) {
		for (reg int i = 1;i < lim; ++i)
			if (r[i] < i) std::swap(A[i], A[r[i]]);
		if (lim >= 2) 
			for (reg int j = 0;j < lim; j += 2) {
				int x = A[j], y = A[j+1];
				A[j] = mod(x + y), A[j+1] = mod(P + x - y);
			}
		for (int i = 2;i < lim; i <<= 1) {
			for (int j = 0;j < lim; j += (i << 1)) {
				poly::iterator f = A.begin() + j, g = A.begin() + i + j;
				int *e = E + i;
				for (int k = 0;k < i; ++k) {
					int x = f[k], y = 1ll * g[k] * e[k] % P;
					f[k] = mod(x + y), g[k] = mod(P + x - y);
					++k;
					x = f[k], y = 1ll * g[k] * e[k] % P;
					f[k] = mod(x + y), g[k] = mod(P + x - y);
				}
			}
		}
	}

	inline void iDft(poly &f) { 
		Dft(f), reverse(f.begin() + 1, f.begin() + lim); 
		ll inv = P - (P - 1) / lim;
		for (int i = 0;i < lim; i++) f[i] = f[i] * inv % P;
	}

	poly Mul(poly &a, poly &b) {
		int s1 = a.size(), s2 = b.size();
		if (s1 <= 28 || s2 <= 28) {
			poly ans(s1 + s2 - 1);
			for (reg int i = 0;i < s1 + s2 - 1; ++i) ans[i] = 0;
			for (reg int i = 0;i < s1; ++i)
				for (reg int j = 0;j < s2; ++j)
					Add(ans[i + j], 1ll * a[i] * b[j] % P);
			return ans;
		}
		init(s1 + s2 - 2);
		poly ans(lim); a.resize(lim), b.resize(lim);
		Dft(a), Dft(b);
		for (int i = 0;i < lim; ++i) ans[i] = 1ll * a[i] * b[i] % P;
		return iDft(ans), ans.resize(s1 + s2 - 1), ans;
	}
	poly operator * (poly a, poly b) { return Mul(a, b); }
}

using Poly::Prework;
using Poly::operator*;

const int N = 205000;
int n;
ll fac[N], inv[N];
int main() {
	read(n), fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2;i <= 200000; ++i) 
		fac[i] = fac[i-1] * i % P, inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 1;i <= 200000; ++i)
		inv[i] = inv[i-1] * inv[i] % P;
	auto C = [&](int x, int y) {
		if (y > x || y < 0) return 0ll;
		return fac[x] * inv[y] % P * inv[x-y] % P;
	};
	Prework(10000);
	poly st(2); st[1] = 1;
	int nw = 1, tnw;
	for (int i = 1, a, b;i <= n; ++i) {
		read(a), read(b), tnw = nw + a - b;
		poly res(tnw + nw + 1);
		for (int i = 0;i <= tnw + nw; ++i)  res[i] = C(a + b, a + nw - i);
		poly T = st * res;
		st.clear();
		st.resize(tnw + 1);
		for (int i = 1;i <= tnw; ++i) st[i] = T[i + nw];
		nw = tnw; 
	}
	ll ans = 0;
	for (int i = 1;i <= nw; ++i) ans += st[i];
	write(ans % P);
	return 0;
}

/*

3
24 21
66 64
1 1

*/