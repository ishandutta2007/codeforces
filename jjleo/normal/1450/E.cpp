#include <bits/stdc++.h>
#define maxn 205

using namespace std;

int n, m;
int x, y, z;
vector<int> v[maxn];
int d[maxn][maxn];
bool vis[maxn], col[maxn];

void dfs(int i){
	vis[i] = true;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(vis[to]){
			if(col[to] ^ col[i] ^ 1) printf("NO"), exit(0);
			continue;
		}
		col[to] = col[i] ^ 1;
		dfs(to);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	memset(d, 0x3f, sizeof(d));
	for(int i = 1;i <= n;i++) d[i][i] = 0;
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back(y), v[y].push_back(x);
		if(z){
			d[x][y] = min(d[x][y], 1);
			d[y][x] = min(d[y][x], -1);
		}else{
			d[x][y] = min(d[x][y], 1);
			d[y][x] = min(d[y][x], 1);
		}
	}
	dfs(1);
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
			} 
		}
	}
	for(int i = 1;i <= n;i++) if(d[i][i] < 0) return printf("NO"), 0;
	puts("YES");
	int x = 1, ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(d[i][j] > ans) ans = d[i][j], x = i;
		}
	}
	printf("%d\n", ans);
	for(int i = 1;i <= n;i++) printf("%d ", d[x][i]);
}