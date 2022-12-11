#pragma GCC optimize(3, "inline")
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


const int N = 1000005, P = 1e9+7;
ll f[N], inv2 = (P + 1) / 2, n;
ll F[131072], A[131072], B[131072], C[131072], T[131072];
int siz[N], cnt[N];

inline void add(ll &x, ll y) {
	x += y, x >= P && (x -= y);
}


inline void fwt_or(ll *f, int len ,ll x = 1) {
    for (int p = 2, k = 1;p <= len; p <<= 1, k <<= 1) 
        for (int i = 0;i < len; i += p) 
            for (int j = 0;j < k; j++) 
            	if (~x) f[i+j+k] = (f[i+j+k] + f[i+j]) % P;
                else f[i+j+k] = (f[i+j+k] - f[i+j] + P) % P;
}

inline void fwt_and(ll *f, int len, ll x = 1) {
    for (int p = 2, k = 1;p <= len; p <<= 1, k <<= 1) 
        for (int i = 0;i < len; i += p) 
            for (int j = 0;j < k; j++) 
            	if (~x) f[i+j] = (f[i+j+k] + f[i+j]) % P;
                else f[i+j] = (f[i+j] - f[i+j+k] + P) % P;
}

inline void fwt_xor(ll *f, int len, ll opt = 1) {
    for (int p = 2, k = 1;p <= len; p <<= 1, k <<= 1) 
        for (int i = 0;i < len; i += p) 
            for (int j = 0;j < k; j++) {
            	ll x = f[i+j], y = f[i+j+k];
                f[i+j] = (x + y) % P;
                f[i+j+k] = (x + P - y) % P;
                if (opt==-1) f[i+j] = f[i+j] * inv2 % P, f[i+j+k] = f[i+j+k] * inv2 % P;
            }
}


int main() {
	read(n); f[1] = siz[1] = 1;
	for (int i = 2;i < 131072; i++) {
		f[i] = (f[i-1] + f[i-2]) % P;
		siz[i] = siz[i>>1] + (i & 1);
	}
	int mx = 0;
	for (int i = 1, s;i <= n; i++) 
		read(s), F[s]++, B[s]++, C[s]++, Mx(mx, s);
	int len = 1;
	while (len <= mx) len <<= 1;
	fwt_xor(C, len, 1);
	for (int i = 0;i < len; i++) C[i] = C[i] * C[i] % P;
	fwt_xor(C, len, -1);
	
	for (int i = 0;i < len; i++) { 
		A[i] += F[0] * F[i];
		for (int s = i; s; s = (s - 1) & i)
			(A[i] += F[s] * F[i ^ s]) %= P;
	}
	
	for (int j = 0;j < len; j++) 
		A[j] = A[j] * f[j] % P, B[j] = B[j] * f[j] % P, C[j] = C[j] * f[j] % P;
	fwt_and(A, len, 1), fwt_and(B, len, 1), fwt_and(C, len, 1);
	for (int j = 0;j < len; j++)
		A[j] = A[j] * B[j] % P * C[j] % P;
	fwt_and(A, len, -1);
	ll ans = 0;
	for (int i = 1;i < len; i <<= 1) ans = (ans + A[i]) % P;
	write(ans);
	return 0;
}
/*
10
131071 153 15325 15 0 99 215 3 2 41 

*/