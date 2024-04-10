#if 0
date +%Y.%m.%d


        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 200005, maxk = 60;

ll gcd (ll a, ll b) {
	if (!b) return a;
	return gcd(b, a % b);
}

ll a[maxn];
int ak[maxn];
int tot[maxk];
/* std::vector<ll> v[maxk]; */

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) {
		ll x = a[i] = read;
		/* ll x = read; */
		int k = 0;
		while (!(x & 1)) x >>= 1, ++ k;
		++ tot[k];
		ak[i] = k;
		/* v[k].push_back(x << k); */
	}

	int K = 0;
	for (int k = 0; k < maxk; k ++)
		if (tot[k] > tot[K])
		/* if (v[k].size() > v[K].size()) */
			K = k;

	printf("%d\n", n - tot[K]);
	for (int i = 1; i <= n; i ++)
		if (ak[i] != K)
			printf("%lld ", a[i]);
	puts("");
}