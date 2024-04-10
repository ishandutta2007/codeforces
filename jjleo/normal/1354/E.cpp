#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

int n, m;
int n1, n2, n3;

vector<int> v[maxn];
int x, y;

bool vis[maxn];
int a[maxn][2], col[maxn];
int cnt;
bool f[maxn][maxn], g[maxn][maxn];
int opt[maxn];
char s[maxn];

void dfs1(int i, int x, int y){
	++a[x][y], vis[i] = true, col[i] = y;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(!vis[to]) dfs1(to, x, y ^ 1);
		else if(col[to] == col[i]){
			printf("NO");
			exit(0);
		}
	}
}

void dfs2(int i, int x){
	vis[i] = true;
	if(!x){
		s[i] = '2';
	}else{
		if(n1) s[i] = '1', --n1;
		else s[i] = '3';
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(!vis[to]) dfs2(to, x ^ 1);
	}
}

int main(){
	scanf("%d%d%d%d%d", &n, &m, &n1, &n2, &n3);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) if(!vis[i]) dfs1(i, ++cnt, 0);
	f[0][0] = true;
	for(int i = 1;i <= cnt;i++){
		//printf("%d %d %d--\n", i, a[i][0], a[i][1]);
		for(int j = 0;j <= n2;j++){
			if(j - a[i][0] >= 0 && f[i - 1][j - a[i][0]]) f[i][j] = true, g[i][j] = 0;
			if(j - a[i][1] >= 0 && f[i - 1][j - a[i][1]]) f[i][j] = true, g[i][j] = 1;
		}
	}
	if(!f[cnt][n2]) return printf("NO"), 0;
	puts("YES");
	int x = n2;
	for(int i = cnt;i;i--){
		opt[i] = g[i][x], x -= a[i][opt[i]];
	}
	cnt = 0, memset(vis, 0, sizeof(vis));
	for(int i = 1;i <= n;i++) if(!vis[i]) dfs2(i, opt[++cnt]);
	for(int i = 1;i <= n;i++) printf("%c", s[i]);
}