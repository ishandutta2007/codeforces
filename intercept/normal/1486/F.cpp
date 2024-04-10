#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=3e5+9;
int n,m,id=0;
ll ans=0;
int s1[M],s2[M],fat[M],lid[M],dep[M],f[M<<1][29];
vector<int>g[M],d[M];
vector<pii>p[M];
map<int,int>mp[M];
void dfs(int u,int fa){
	dep[f[lid[u]=++id][0]=u]=dep[fat[u]=fa]+1;
	d[u].eb(id);
	for(auto v:g[u])
		if(v!=fa)dfs(v,u),f[++id][0]=u,d[u].eb(id);
}
int Min(int u,int v){return dep[u]<dep[v]?u:v;}
int lca(int u,int v){
	int l=lid[u],r=lid[v],k=log2(r-l+1);
	return Min(f[l][k],f[r-(1<<k)+1][k]);
}
int find(int u,int v){
	if(u==v)return -1;
	int l=lid[u],r=lid[v];
	int x=lower_bound(d[u].begin(),d[u].end(),lid[v])-d[u].begin()-1;
	x=d[u][x];
	return f[x+1][0];
}
void DFS(int u){
	for(auto v:g[u])
		if(v!=fat[u]){
			DFS(v);
			s1[u]+=s1[v];
			s2[u]+=s2[v];
		}
	int sum=s2[u];
	for(auto o:p[u]){
		int x=o.fi,y=o.se;
		ans+=--sum;
		if(y!=-1)ans-=(--s1[y]);
		if(x!=-1)ans-=(--s1[x]),ans+=mp[x][y]++;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	for(int j=1;j<=23;++j){
		for(int i=1;i+(1<<j)-1<=id;++i){
			f[i][j]=Min(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	scanf("%d",&m);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(lid[u]>lid[v])swap(u,v);
		w=lca(u,v);
		s1[u]++;s1[v]++;s1[w]-=2;
		s2[u]++;s2[v]++;s2[w]--;s2[fat[w]]--;
		u=find(w,u);
		v=find(w,v);
		p[w].eb(pii{u,v});
	}
	DFS(1);
	printf("%lld\n",ans);
	return 0;
}
/*


*/