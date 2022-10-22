#if 0
2020.05.22

  
   2-sat 

        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 1000005;
std::vector<int> G[maxn];
bool ins[maxn];
int stack[maxn], sp;
int dfn[maxn], low[maxn], ip;
int belong[maxn], bp;
std::vector<int> con[maxn];

void dfs (int u) {
	low[u] = dfn[u] = ++ ip;
	stack[++ sp] = u;
	ins[u] = 1;
	for (int v : G[u])
		if (!dfn[v]) {
			dfs(v);
			low[u] = std::min(low[u], low[v]);
		} else if (ins[v])
			low[u] = std::min(low[u], low[v]);
	if (low[u] == dfn[u]) {
		++ bp;
		while (stack[sp + 1] != u) {
			int x = stack[sp --];
			ins[x] = 0;
			belong[x] = bp;
			con[bp].push_back(x);
		}
	}
}

std::vector<int> D[maxn];
bool vis[maxn];
void rebuild () {
	for (int u = 1; u <= bp; u ++) {
		vis[u] = 1;
		for (int x : con[u])
			for (int v : G[x])
				if (!vis[belong[v]]) {
					D[u].push_back(belong[v]);
					vis[belong[v]] = 1;
				}
		for (int x : con[u])
			for (int v : G[x])
				vis[belong[v]] = 0;
		vis[u] = 0;
	}
}

bool mark[maxn];
int main () {
	int T = read;
	/* bool shit = T == 40000; */
	/* int tid = 0; */
	while (T --) {
		int n = read, m = read;
		for (int i = 1; i <= m; i ++) {
			int u = read, v = read;
			if (u != v) G[u].push_back(v);
		}
		for (int i = 1; i <= n; i ++)
			if (!dfn[i])
				dfs(i);
		rebuild();
		/* if (shit) { */
		/* 	++ tid; */
		/* 	if (tid == 49) { */
		/* 		for (int i = 1; i <= n; i ++) */
		/* 			for (int j : G[i]) */
		/* 				printf("%d %d\n", i, j); */
		/* 		return 0; */
		/* 	} */
		/* 	continue; */
		/* } */
		if (bp == 1) puts("No");
		else {
			puts("Yes");
			for (int i = 1; i <= bp; i ++)
				if (D[i].empty()) {
					printf("%d %d\n", int(con[i].size()), n - int(con[i].size()));
					for (int x : con[i]) {
						printf("%d ", x);
						mark[x] = 1;
					}
					puts("");
					for (int j = 1; j <= n; j ++)
						if (!mark[j])
							printf("%d ", j);
					puts("");
					break;
				}
		}
		for (int i = 1; i <= n; i ++) {
			G[i].clear();
			con[i].clear();
			D[i].clear();
			stack[i] = ins[i] = dfn[i] = low[i] = mark[i] = belong[i] = vis[i] = 0;
		}
		ip = sp = bp = 0;
	}
}