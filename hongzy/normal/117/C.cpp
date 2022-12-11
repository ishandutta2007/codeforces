#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 5010;

int n, d[N];
bool vis[N];
char G[N][N];

bool dfs(int u, int la) {
	vis[u] = 1;
	for(int v = 1; v <= n; v ++) if(G[u][v] == '1') {
		if(!vis[v]) {
			if(dfs(v, u)) return 1;
		} else {
			if(G[v][la] == '1') {
				printf("%d %d %d\n", u, v, la);
				return 1;
			} 
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", G[i] + 1);
	}
	for(int i = 1; i <= n; i ++) {
		if(!vis[i] && dfs(i, 0)) return 0;
	}
	puts("-1");
	return 0;
}