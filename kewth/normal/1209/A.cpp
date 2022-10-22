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

const int maxn = 105;
int a[maxn];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		if (a[i]) {
			int x = a[i];
			++ ans;
			for (int j = i; j <= n; j ++)
				if (a[j] % x == 0)
					a[j] = 0;
		}
	printf("%d\n", ans);
}