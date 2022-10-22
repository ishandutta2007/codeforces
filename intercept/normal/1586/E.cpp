#include<bits/stdc++.h>
using namespace std;
const int M=3e5+9;
int n,m,q;
int b[M],p[M],f[M],dep[M];
vector<int>g[M],Q[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int u,int fa){
	p[u]=fa;
	dep[u]=dep[fa]+1;
	for(auto v:g[u]){
		if(v!=fa)dfs(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(find(u)!=find(v)){
			g[u].push_back(v);
			g[v].push_back(u);
			f[find(u)]=find(v);
		}
	}
	scanf("%d",&q);
	for(int i=1,u,v;i<=q;++i){
		scanf("%d%d",&u,&v);
		b[u]^=1;
		b[v]^=1;
		dfs(v,0);
		Q[i].push_back(dep[u]);
		for(int j=1,l=dep[u];j<=l;++j){
			Q[i].push_back(u);
			u=p[u];
		}
	}
	int sum=0;
	for(int i=1;i<=n;++i)sum+=b[i];
	if(sum){
		puts("NO");
		printf("%d\n",sum/2);
	}
	else {
		puts("YES");
		for(int i=1;i<=q;++i){
			printf("%d\n",Q[i][0]);
			for(int j=1;j<=Q[i][0];++j)printf("%d ",Q[i][j]);
			puts("");
		}
	}
	return 0;
}