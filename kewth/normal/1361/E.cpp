
/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Just Run this (Type !!sh in Vim).

 * Solution:
  To be updated after "Accept".

 * Digression:
   dfs 

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <random>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 100005;
std::vector<int> G[maxn];
int cover[maxn], keycover[maxn];
bool vis[maxn], ins[maxn];
bool isans[maxn];

int Root;
void force (int u) {
	vis[u] = ins[u] = 1;
	for (int v : G[u])
		if (!vis[v])
			force(v);
		else if (!ins[v])
			Root = 0;
	ins[u] = 0;
}

int tmp[maxn], tp;
void dfs (int u) {
	tmp[++ tp] = u;
	vis[u] = 1;
	for (int v : G[u])
		if (!vis[v]) {
			/* debug("%d -> %d\n", u, v); */
			dfs(v);
			cover[u] += cover[v];
			keycover[u] += keycover[v];
		}
		else { // ins[v] = 1
			/* debug(" (%d -> %d)\n", u, v); */
			++ cover[u];
			-- cover[v];
			keycover[u] += v;
			keycover[v] -= v;
		}
}

int main () {
	std::mt19937 engine(19260817);
	int T = read;
	while (T --) {
		int n = read, m = read;
		for (int i = 1; i <= n; i ++) G[i].clear();
		for (int i = 1; i <= m; i ++) {
			int u = read, v = read;
			G[u].push_back(v);
		}
		std::uniform_int_distribution<int> Rand(1, n);
		int test = 80;
		Root = 0;
		while (!Root and test --) {
			std::fill(vis, vis + n + 1, 0);
			force(Root = Rand(engine));
		}
		if (!Root) {
			puts("-1");
			continue;
		}
		std::fill(cover, cover + n + 1, 0);
		std::fill(keycover, keycover + n + 1, 0);
		std::fill(vis, vis + n + 1, 0);
		tp = 0;
		dfs(Root);
		isans[Root] = 1;
		int tot = 1;
		for (int i = 2; i <= tp; i ++) {
			int u = tmp[i];
			if (cover[u] == 1)
				isans[u] = isans[keycover[u]];
			else
				isans[u] = 0;
			tot += isans[u];
		}
		if (tot * 5 >= n) {
			for (int i = 1; i <= n; i ++)
				if (isans[i])
					printf("%d ", i);
			puts("");
		}
		else
			puts("-1");
	}
}