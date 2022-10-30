#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

const int p = 998244353;

int n, m;
int f[maxn][maxn], g[maxn], siz[maxn];
vector<int> v[maxn];
int x, y;

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p; 
}

void dfs(int i, int fa){
	siz[i] = 1, f[i][0] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
	}
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		for(int j = 0;j <= siz[i] + siz[to];j++) g[j] = 0;
		for(int j = 0;j <= siz[i] && j <= m;j++){
			for(int k = 0;k <= siz[to] && k <= m;k++){
				if(j + k + 1 <= m) add(g[max(j, k + 1)], 1ll * f[i][j] * f[to][k] % p);
				add(g[j], 1ll * f[i][j] * f[to][k] % p);
			}
		} 
		for(int j = 0;j <= siz[i] + siz[to];j++) f[i][j] = g[j];
		siz[i] += siz[to];
	}
} 

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1, 0);
	int ans = 0;
	for(int i = 0;i <= m;i++) add(ans, f[1][i]);
	printf("%d", ans);
}