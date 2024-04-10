#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int f[maxn][20][2], g[maxn][20][2];
vector<int> v[maxn];
int x, y;
int a[maxn], ans[maxn];

void dfs1(int i, int fa){
	f[i][0][0] = a[i];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		for(int k = 0;k < m - 1;k++){
			f[i][k + 1][0] ^= f[to][k][0];
			f[i][k + 1][1] ^= f[to][k][1];
		}
		f[i][0][1] ^= f[to][m - 1][0];
		f[i][0][0] ^= f[to][m - 1][1];
	}
}

void dfs2(int i, int fa){
	for(int j = 0;j < m;j++) ans[i] ^= f[i][j][1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		for(int k = 0;k < m - 1;k++){
			g[i][k + 1][0] = f[i][k + 1][0] ^ f[to][k][0];
			g[i][k + 1][1] = f[i][k + 1][1] ^ f[to][k][1];
		}
		g[i][0][1] = f[i][0][1] ^ f[to][m - 1][0];
		g[i][0][0] = f[i][0][0] ^ f[to][m - 1][1];
		for(int k = 0;k < m - 1;k++){
			f[to][k + 1][0] ^= g[i][k][0];
			f[to][k + 1][1] ^= g[i][k][1];
		}
		f[to][0][1] ^= g[i][m - 1][0];
		f[to][0][0] ^= g[i][m - 1][1];
		dfs2(to, i);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	dfs1(1, 0), dfs2(1, 0);
	for(int i = 1;i <= n;i++) printf("%d ", ans[i] != 0);
}