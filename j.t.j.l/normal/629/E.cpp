#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

int n, m;
vector<int> E[MAXN];
int dep[MAXN], fa[20][MAXN];
ll son[MAXN];
ll f[MAXN], g[MAXN];

void dfs1(int u, int Fa){
	fa[0][u] = Fa;
	dep[u] = dep[Fa] + 1;
	son[u] = 1; f[u] = 0;
	for(int i = 0; i < E[u].size(); i++)
		if (E[u][i] != Fa){
			int v = E[u][i];
			dfs1(v, u);
			son[u] += son[v];
			f[u] += f[v] + son[v];
		}
}

void dfs2(int u, int fa){
	for(int i = 0; i < E[u].size(); i++)
		if (E[u][i] != fa){
			int v = E[u][i];
			g[v] = g[u] + (n - son[u] + 1) + f[u] - (f[v] + son[v]) + (son[u] - son[v] - 1);
			dfs2(v, u);
		}
}

void prelca(){
	int maxdep = 0;
	for(int i = 1; i <= n; i++){
	//	lvl[dep[i]].push_back(i);
		maxdep = max(maxdep, dep[i]);
	}
	
	for(int i = 1; (1 << i) <= maxdep; i++){
		for(int j = 1; j <= n; j++)
			fa[i][j] = fa[i-1][fa[i-1][j]];
		/*for(int j = 1; j <= maxdep; j++){
			for(int k = 0; k < lvl[j].size(); k++)
				
		}*/
	}
}

double work(int x, int y){
	if (dep[x] > dep[y])
		swap(x,y);
	
//	cout<<endl;
//	cout<<x<<' '<<y<<endl;
		
	int u = x, v = y, w = v;
	while(dep[v] > dep[u]){
		int p = (int)(log(dep[v] - dep[u]) / log(2));
		w = v;
		v = fa[p][v];
	}
	while(dep[w] > dep[v] && fa[0][w] != v){
		int p = (int)(log(dep[w] - dep[v] - 1) / log(2));
		w = fa[p][w];
	}
	for(int i = (int)(log(dep[v]) / log(2)); i >= 0; i--){
		if (fa[i][u] != fa[i][v]){
			u = fa[i][u];
			v = fa[i][v];
		}
	}
	while(u != v){
		u = fa[0][u], v = fa[0][v];
	}
	
//	cout<<u<<' '<<v<<' '<<w<<endl;
	
	if (u == x){
		return ((g[w] - n + son[w]) * son[y] + f[y] * (n - son[w])) * 1.0 / (son[y] * (n - son[w])) + (1 + dep[y] - dep[x]);
	}
	else{
		return (f[x] * son[y] + f[y] * son[x] + son[x] * son[y] * (dep[x] - dep[u] + dep[y] - dep[u] + 1)) * 1.0 / (son[x] * son[y]);
	}
}	

int main(){
	srand(time(NULL));
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		E[i].clear();
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	int root = rand() % n + 1;
//	cout<<root<<endl;
	dep[0] = 0;
	dfs1(root, 0);
	g[root] = 0;
	dfs2(root, 0);
	
//	for(int i = 1; i <= n; i++)
//		cout<<i<<' '<<dep[i]<<' '<<son[i]<<' '<<f[i]<<' '<<g[i]<<endl;
	
	prelca();
	
/*	for(int i = 0; (1 << i) <= n; i++){
		for(int j = 1; j <= n; j++)
			cout<<fa[i][j]<<' '; cout<<endl;
	}
	cout<<endl;
*/	
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%.10lf\n", work(x, y));
	}
	return 0;
}