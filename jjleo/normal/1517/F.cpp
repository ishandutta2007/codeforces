#include <bits/stdc++.h>
#define maxn 305

using namespace std;

const int p = 998244353;

int n;
int x, y, r;
vector<int> v[maxn];
int f[maxn][maxn][2], dep[maxn];
int g[maxn][maxn][2];

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

void dfs(int i, int fa){
	dep[i] = 0;
	f[i][0][0] = f[i][0][1] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		
		for(int k = 0;k <= dep[i];k++){
			for(int l = 0;l <= dep[to];l++){
				add(g[i][max(k, l + 1)][0], 1ll * f[i][k][0] * f[to][l][0] % p);
				if(l + 1 + k <= r) add(g[i][l + 1][1], 1ll * f[i][k][0] * f[to][l][1] % p);
				else add(g[i][k][0], 1ll * f[i][k][0] * f[to][l][1] % p);
				if(k + 1 + l <= r) add(g[i][k][1], 1ll * f[i][k][1] * f[to][l][0] % p);
				else add(g[i][l + 1][0], 1ll * f[i][k][1] * f[to][l][0] % p);
				add(g[i][min(k, l + 1)][1], 1ll * f[i][k][1] * f[to][l][1] % p);
			}
		}
		dep[i] = max(dep[i], dep[to] + 1);
		for(int k = 0;k <= dep[i];k++){
			f[i][k][0] = g[i][k][0], f[i][k][1] = g[i][k][1];
			g[i][k][0] = g[i][k][1] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	int ans = n;
	for(int i = 1;i <= n;i++) ans = (ans + ans) % p;
	for(r = 0;r <= n;r++){
		memset(f, 0, sizeof(f));
		dfs(1, 0);
		for(int i = 0;i <= dep[1];i++) ans = (ans + p - f[1][i][1]) % p;
	}
	for(int i = 1;i <= n;i++) ans = 1ll * ans * (p + 1 >> 1) % p;
	printf("%d", ans);
}