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
int a[maxn];

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) read(a[i]);

	/* if (n == 1) { */
	/* 	if (a[1] & 1) puts("sjfnb"); */
	/* 	else puts("cslnb"); */
	/* 	return 0; */
	/* } */

	std::sort(a + 1, a + n + 1);
	int shit = 0;
	for (int i = 1; i < n; i ++)
		if (a[i] == a[i + 1]) {
			if (a[i] == 0)
				return puts("cslnb"), 0;
			++ shit;
			-- a[i];
			break;
		}

	for (int i = 1; i < n; i ++)
		if (a[i] == a[i + 1])
			return puts("cslnb"), 0;

	for (int i = 1; i <= n; i ++)
		shit += a[i] - i + 1;

	if (shit & 1) puts("sjfnb");
	else puts("cslnb");
}