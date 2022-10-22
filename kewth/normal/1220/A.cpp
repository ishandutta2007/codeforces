#if 0
date +%Y.%m.%d


        
          
        
            
           
        
          
   CopyRight :)
      
#endif
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
char s[maxn];

int main () {
	int n = read;
	scanf("%s", s + 1);

	int tot = 0;
	for (int i = 1; i <= n; i ++)
		if (s[i] == 'n')
			++ tot;

	for (int i = 1; i <= tot; i ++) printf("1 ");
	for (int i = 1; i <= (n - tot * 3) / 4; i ++) printf("0 ");
	puts("");
}