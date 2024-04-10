/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Just Run this (Type !!sh in Vim).

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 1505, mod = 1000000007;

struct num {
	int val;
	num(int val = 0): val(val) { }
};
inline num operator * (num x, num y) { return num(1ll * x.val * y.val % mod); }
inline num& operator *= (num &x, num y) { return x = x * y; }
inline num operator + (num x, num y) { int v = x.val + y.val; return num(v >= mod ? v - mod : v); }
inline num& operator += (num &x, num y) { return x = x + y; }
inline num operator - (num x, num y) { int v = x.val - y.val; return num(v < 0 ? v + mod : v); }
inline num& operator -= (num &x, num y) { return x = x - y; }
inline num operator ^ (num x, int k) {
	num res = 1;
	while(k) {
		if(k & 1) res *= x;
		x *= x;
		k >>= 1;
	}
	return res;
}
inline num& operator ^= (num &x, int k) { return x = x ^ k; }
// The module is supposed to be a prime
inline num operator / (num x, num y) { return x * (y ^ (mod - 2)); }
inline num& operator /= (num &x, num y) { return x = x / y; }

num p[maxn];
num g[maxn][maxn];
num R[maxn][maxn];

int main () {
	int n = read, m = read;
	num q(read);
	q /= num(read);
	int K = read;

	p[0] = (1 - q) ^ K;
	for (int i = 1; i <= m; i ++)
		p[i] = p[i - 1] * q / (1 - q) * (K - i + 1) / i;
	if (q.val == 1 and K <= m)
		p[K] = 1;

	g[0][m] = 1;
	R[0][m] = 1;

	for (int i = 1; i <= n; i ++) {
		num a = p[0], b = 0;
		for (int r = 1; r <= m; r ++) {
			g[i][r] = p[m - r] * ((R[i - 1][m] - R[i - 1][m - r]) * a - b);
			a += p[r];
			b += p[r] * R[i - 1][r];
			R[i][r] = R[i][r - 1] + g[i][r];
			/* debug(" %d", g[i][r].val); */
		}
		/* debug("\n"); */
	}

	printf("%d\n", R[n][m].val);
}