#include<bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

#ifdef holyk
#define gc getchar()
#else
const int SIZE(1 << 21 | 1);
char buf[SIZE], *iS, *iT;
#define gc (iS == iT ? iT = buf + fread(iS = buf, 1, SIZE, stdin), iS == iT ? EOF : *iS++ : *iS++)
#endif
struct Reader {
    template<typename T>inline operator T() {
        char c, p = 0; T w;
        for(; !isdigit(c = gc); c == '-' && (p = 1));
        for(w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
        return p ? -w : w;
    }
} read;

template<class T>inline bool smin(T&x, const T&y){return y < x ? x = y, 1 : 0;}
template<class T>inline bool smax(T&x, const T&y){return x < y ? x = y, 1 : 0;}

typedef unsigned long long u64;
const int P(998244353), N(1 << 19 | 5);
const u64 PL(u64(P) * P);

inline int fpow(int x, int k = P - 2){
	int r = 1;
	for(; k; k >>= 1, x = 1ll * x * x % P)if(k & 1)r = 1ll * r * x % P;
	return r;
}

void dft(int *a, int n){
	static u64 b[N];
	static std::vector<int*> W;
	static int nw, rev[N];
	const int nl = __builtin_ctz(n);
	if(nw != n){
		REP(i, 1, n - 1)rev[i] = rev[i >> 1] >> 1 | (i & 1) << nl - 1;
		nw = n;
	}
	REP(i, 0, n - 1)b[rev[i]] = a[i] < 0 ? a[i] + P : a[i];
	while((int)W.size() < nl){
		int l = 1 << W.size() + 1, w = fpow(3, (P - 1) / l);
		int *t = new int[l], *last;
		if(W.size())last = W.back(); t[0] = 1;
		REP(i, 1, l - 1)t[i] = i & 1 ? 1ll * t[i - 1] * w % P : last[i >> 1];
		W.push_back(t);
	}
	for(int i = 1, u = 0; i < n; i <<= 1, ++u)
		for(int j = 0; j < n; j += i << 1){
			u64 *x = b + j, *y = x + i, t;
			for(int k = 0, *w = W[u]; k < i; ++k, ++x, ++y, ++w)
				t = *y % P * u64(*w), *y = *x + PL - t, *x += t,
				u == 17 && i < n && (*x %= P, *y %= P);	
		}
	REP(i, 0, n - 1)a[i] = b[i] % P;
}
inline void idft(int *a, int n){
	const int inv = fpow(n); dft(a, n);
	REP(i, 0, n - 1)a[i] = 1ll * inv * a[i] % P;
	std::reverse(a + 1, a + n);
}
void poly_inv(int n, int *a, int *b){
	static int c[N], d[N];
	memset(b, 0, n << 2);
	b[0] = fpow(a[0]);
	for(int u = 1, k = 2; u < n; u <<= 1, k <<= 1){
		memcpy(c, a, k << 2), memcpy(d, b, u << 2);
		dft(b, k), dft(c, k);
		REP(i, 0, k - 1)c[i] = 1ll * c[i] * b[i] % P;
		idft(c, k);
		REP(i, u, k - 1)c[i] = P - c[i], c[i - u] = 0;
		dft(c, k);
		REP(i, 0, k - 1)b[i] = 1ll * b[i] * c[i] % P;
		idft(b, k);
		memcpy(b, d, u << 2);
	}
}

#define shift(x) (x & 1 ? x + P >> 1 : x >> 1)

inline void poly_sqrt(int n, int *a, int *b){
	static int c[N], d[N], dftb[N], dftc[N];
	memset(b, 0, n << 2);
	dftb[0] = b[0] = 1, c[0] = 1;
	for(int u = 1, k = 2; k <= n; u <<= 1, k <<= 1){	
		REP(i, 0, u - 1){
			dftb[u + i] = a[i] + a[u + i] - dftb[i];
			if(dftb[u + i] < 0)dftb[u + i] += P;
			dftb[i] = 0;	
		}
		memcpy(dftc, c, k << 2);
		dft(dftb, k), dft(dftc, k);
		REP(i, 0, k - 1)dftb[i] = 1ll * dftb[i] * dftc[i] % P;
		idft(dftb, k);
		REP(i, u, k - 1)b[i] = shift(dftb[i]);
		
		if(k < n){
			//inv
			memcpy(dftb, b, k << 2), memcpy(d, c, u << 2);	
			dft(dftb, k);
			REP(i, 0, k - 1)c[i] = 1ll * dftb[i] * dftc[i] % P;
			idft(c, k);
			memset(c, 0, u << 2);
			REP(i, u, k)c[i] = P - c[i];
			dft(c, k);
			REP(i, 0, k - 1)c[i] = 1ll * c[i] * dftc[i] % P;
			idft(c, k);
			memcpy(c, d, u << 2);
			
			REP(i, 0, k - 1)dftb[i] = 1ll * dftb[i] * dftb[i] % P;
			idft(dftb, k);
		}
	}
}
int main(){
	static int n = read, m = read, a[N], b[N];
	while(n--)a[(int)read] = P - 4; ++a[0];
	n = 1 << std::__lg(m) + 1;
	poly_sqrt(n, a, b), ++b[0], poly_inv(n, b, a);
	REP(i, 1, m)printf("%d\n", (a[i] << 1) % P);
	return 0;
}