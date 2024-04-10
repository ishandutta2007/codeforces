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
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 200005;
int a[maxn], b[maxn];
std::map<par, int> map;

int main () {
	int n = read;
	ll ans = 0;
	for (int i = 1; i <= n; i ++) ans += a[i] = read;
	int q = read;
	while (q --) {
		int s = read, t = read;
		int &x = map[par(s, t)];
		if (x) {
			-- b[x];
			if (b[x] < a[x]) ++ ans;
		}
		x = read;
		if (x) {
			if (b[x] < a[x]) -- ans;
			++ b[x];
		}
		printf("%lld\n", ans);
	}
}