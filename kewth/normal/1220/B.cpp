#if 0
date +%Y.%m.%d


        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <cmath>
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

const int maxn = 1005;
int M[maxn][maxn];

/* int gcd (int a, int b) { */
/* 	if (!b) return a; */
/* 	return gcd( */
/* } */

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			read(M[i][j]);

	int x = int(sqrtl(1ll * M[1][2] * M[1][3] / M[2][3]));

	printf("%d", x);
	for (int i = 2; i <= n; i ++)
		printf(" %d", M[1][i] / x);
	puts("");
}