#include <bits/stdc++.h>
#define maxn 3086

using namespace std;

typedef long long ll;

int t;
int n, m;
pair<int, ll> f[maxn][maxn], g[maxn];
vector<int> v[maxn];
int x, y;
int a[maxn];
int siz[maxn];

inline pair<int, ll> operator + (pair<int, ll> a, pair<int, ll> b){
	return {a.first + b.first, a.second + b.second};
}

void dfs(int i, int fa){
	siz[i] = 1;
	f[i][1] = {0, a[i]};
	for(int j = 2;j <= n;j++) f[i][j] = {0, -1e18};
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		for(int j = 1;j <= n;j++) g[j] = {0, -1e18};
		for(int k = 1;k <= siz[i];k++){
			for(int l = 1;l <= siz[to] && k + l - 1 <= m;l++){
				g[k + l] = max(g[k + l], f[i][k] + (pair<int, ll>){f[to][l].first + (f[to][l].second > 0), 0});
				g[k + l - 1] = max(g[k + l - 1], f[i][k] + f[to][l]);
			}
		}
		memcpy(f[i], g, sizeof(g));
		siz[i] += siz[to];
	}
	for(int j = min(siz[i], m);j;j--){
		//f[i][j + 1] = max(f[i][j + 1], {f[i][j].first + (f[i][j].second > 0), 0});
		//printf("%d %d %d %lld--\n", i, j, f[i][j].first, f[i][j].second);
	}
}


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			a[i] = -a[i] + x;
			v[i].clear();
		}
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		dfs(1, 0);
		printf("%d\n", f[1][m].first + (f[1][m].second > 0)); 
	}
}