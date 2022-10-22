/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  2020.06.16

 * Solution:
 * 

  
 k  k = xB + y  1  B - 1  B 
 B (n - B + 1) + B - 1  AB 
 A + B = n  A, B  n/2  n^2/4 

   n^2 * (2/9)  2/9 = 1/3 * 2/3  A  n/3 
B  2n/3 

   u  u 
 n/3 


   u  n/2 
 n/3 
 n/3  2n/3 

   2n/3  n/3 
 n/3 

 * Digression:
   10min  AC  C  nice 

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 1005;
std::vector<int> G[maxn];
int size[maxn], son[maxn];

void dfs (int u, int fa) {
	size[u] = 1;
	son[u] = 0;
	for (int v : G[u])
		if (v != fa) {
			dfs(v, u);
			size[u] += size[v];
			if (size[v] >= size[son[u]])
				son[u] = v;
		}
}

int p1, p2;
void calc1 (int u, int fa, int d) {
	for (int v : G[u])
		if (v != fa) {
			++ p1;
			printf("%d %d %d\n", u, v, p1 - d);
			calc1(v, u, p1);
		}
}
void calc2 (int u, int fa, int d) {
	for (int v : G[u])
		if (v != fa) {
			++ p2;
			printf("%d %d %d\n", u, v, (p1 + 1) * (p2 - d));
			calc2(v, u, p2);
		}
}

int main () {
	int n = read;
	for (int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1, 0);
	int rt = 1;
	while (size[son[rt]] * 2 > n)
		rt = son[rt];
	dfs(rt, 0);

	std::sort(G[rt].begin(), G[rt].end(), [] (int x, int y) {
				return size[x] < size[y];
			});

	int now = 0;
	int sta = 1;
	for (int u : G[rt]) {
		now += size[u];
		if (sta == 1) {
			++ p1;
			printf("%d %d %d\n", rt, u, p1);
			calc1(u, rt, p1);
		}
		if (sta == 2) {
			++ p2;
			printf("%d %d %d\n", rt, u, (p1 + 1) * p2);
			calc2(u, rt, p2);
		}
		if (now * 3 >= n - 1) sta = 2;
	}
}