#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> G[N];
int col[N];
int val[N << 2];
int ind = 0;

int dfs(int u, int p) {
	col[u] = 1-col[u];
	val[ind++] = u;
	for(auto v : G[u]) {
		if(v == p)
			continue;
		dfs(v, u);
		col[u] = 1-col[u];
		val[ind++] = u;
		if(!col[v]) {
			col[u] = 1-col[u];
			val[ind++] = v;
			val[ind++] = u;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &col[i]);
		col[i] = (col[i]+1)/2;
	}
	for(int i=1; i<n; i++) {
		int u, v;
		scanf("%d %d", &u, &v); u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	col[0] = 1-col[0];
	dfs(0, -1);
	if(!col[0]) ind--;
	for(int i=0; i<ind; i++) {
		printf("%d ", val[i]+1);
	}
	printf("\n");
}