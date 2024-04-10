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
#include <vector>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	/* inline operator ll () { ll x; return scanf("%lld", &x), x; } */
	/* template<class T> inline void operator () (T &x) { x = *this; } */
	/* template<class T, class ...A> inline void operator () (T &x, A &...a) */
	/* { x = *this; this -> operator () (a...); } */
} read;

const int maxn = 500005;
std::vector<int> G[maxn];
std::vector<int> V[maxn];
int val[maxn];
int ans[maxn], ap;

int main () {
	int n = read, m = read;
	for (int i = 1; i <= m; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++) V[read].push_back(i);
	for (int i = 1; i <= n; i ++) {
		for (int u : V[i]) {
			std::set<int> mex;
			for (int v : G[u])
				mex.insert(val[v]);
			for (int x = 1; x < i; x ++)
				if (!mex.count(x))
					return puts("-1"), 0;
			if (mex.count(i))
				return puts("-1"), 0;
			val[u] = i;
			ans[++ ap] = u;
		}
	}
	for (int i = 1; i <= ap; i ++)
		printf("%d ", ans[i]);
	puts("");
}