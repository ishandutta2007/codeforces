#if 0
2020.05.16

  
   S  f(S)  S  T f(T) 
 f(S) 
   k  g(k) 

   x, y 
 x, y 
    g(x) + g(y) - (x g(0) + g(y + 1) + y g(0) + g(x + 1))/2
   g(x) = 2^x - 1 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 505, mod = 1000000007;
int a[maxn];
int tot[maxn];
ll f[maxn];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) {
		read(a[i]);
		if (a[i] != -1) ++ tot[a[i]];
	}

	for (int i = 1; i <= n; i ++)
		f[i] = (f[i - 1] * 2 + 1) % mod;

	ll begin = 0;
	for (int i = 1; i <= n; i ++)
		begin += f[tot[i]];
	begin %= mod;
	ll end = f[n - 1];
	printf("%lld\n", (end - begin + mod) % mod);
}