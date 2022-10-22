/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d

 * Solution:
  

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

const int maxn = 100005;
ll a[maxn];

int main () {
	ll n = read;
	int m = read;
	ll d = read;

	for (int i = 1; i <= m; i ++) read(a[i]);

	int ans = 0;
	ll R = 0;
	for (int l = 1, r; l <= m; l = r + 1) {
		if (R < a[l])
			R += (a[l] - R + d - 1) / d * d;
		r = l;
		while (r < m and a[r + 1] <= R) ++ r;
		++ ans;
		R += r - l + 1;
	}

	printf("%d\n", ans);
}