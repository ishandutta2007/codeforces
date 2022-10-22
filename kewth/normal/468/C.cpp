#if 0
date +%Y.%m.%d

 k  x  f(x) + 1 = f(x + 10^k) 
 f(x)  f(x + 10^k) - 1 
 0  10^k - 1  f(x)  a  p  0  a - p - 1  f(x) 
 a - p  10^k + a - p - 1  f(x)  a  0 
 p 
p  0  10^k-1 
 p = sum(0~9) 10^(k-1) k 

 O(1)  O(1) 
 x / m * y  long double  long long 
 long long  long double  long long  INT64_MAX 
#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef long double ld;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

inline ll mul(ll x, ll y, ll m) {
	x %= m;
	y %= m;
	ll tmp = x * y - ll(ld(x) / m * y + 0.5) * m;
	return tmp < 0 ? tmp + m : tmp;
}

int main() {
	ll a = read;
	ll k = 18;
	ll po10 = 1;
	for(int i = 0; i < k; i ++)
		po10 *= 10;
	ll p = mul(po10 / 10, 45 * k, a);
	printf("%lld %lld\n", a - p, po10 + a - p - 1);
}