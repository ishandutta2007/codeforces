#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,q,id,k,ans,top;
int dfn[M],dep[M],s[M],t[M],f[M][23],d[M];
vector<int>g[M],e[M];
bool vis[M];
void dfs(int u,int fa){
	dfn[u]=++id;
	dep[u]=dep[f[u][0]=fa]+1;
	for(int i=1;i<=19;++i)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v!=fa)dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;--i)
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
	for(int i=19;i>=0;--i)
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return u==v?u:f[u][0];
}
void dp(int u){
	d[u]=0;
	for(auto v:e[u]){dp(v);d[u]+=d[v];}
	if(vis[u])ans+=d[u],d[u]=1;
	else ans+=d[u]>1,d[u]=(d[u]==1); 
	
} 
int calc(){
	for(int i=1;i<=k;++i)
		if(vis[t[i]]&&vis[f[t[i]][0]])return -1;
	dp(s[1]);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		ans=0,top=0;
		scanf("%d",&k);
		for(int j=1;j<=k;++j)scanf("%d",&t[j]),vis[t[j]]=1;
		sort(t+1,t+k+1,[&](const int&l,const int&r){return dfn[l]<dfn[r];});
		for(int j=2,h=k;j<=h;++j)t[++k]=lca(t[j],t[j-1]);
		sort(t+1,t+k+1,[&](const int&l,const int&r){return dfn[l]<dfn[r];});
		k=unique(t+1,t+k+1)-t-1;
		for(int j=1;j<=k;++j){
			int u=t[j];
			while(top&&dfn[s[top]]>dfn[lca(u,s[top])])top--;
			if(top)e[s[top]].eb(u); 
			s[++top]=u;
		}
		printf("%d\n",calc());
		for(int j=1;j<=k;++j)vis[t[j]]=0,e[t[j]].clear();
	}
	return 0;
}