#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
const int M=4e5+9;
int n,m,q,num,tot;
int a[M],va[M],dfn[M],dep[M],l[M][21],r[M][21],f[M][21];
int p[M];
vector<int>g[M];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void dfs(int u){
	for(int i=1;i<=19;++i)f[u][i]=f[f[u][i-1]][i-1];
	l[u][0]=r[u][0]=u;
	dfn[u]=++tot;
	for(auto v:g[u]){
		f[v][0]=u;
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
int Min(int x,int y){
	return dfn[x]<dfn[y]?x:y;
}
int Max(int x,int y){
	return dfn[x]>dfn[y]?x:y;
}
int askl(int x,int y){
	int k=log2(y-x+1);
	return Min(l[x][k],l[y-(1<<k)+1][k]);
}
int askr(int x,int y){
	int k=log2(y-x+1);
	return Max(r[x][k],r[y-(1<<k)+1][k]);
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;--i){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;--i){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
void work(){
	cin>>n>>m>>q;
	num=n;
	tot=0;
	for(int i=1;i<=n+n;++i)p[i]=i,va[i]=0,g[i].clear();
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		if(find(u)!=find(v)){
			++num;
			u=find(u);
			v=find(v);
			p[u]=num;
			p[v]=num;
			va[num]=i;
			g[num].eb(u);
			g[num].eb(v);
		}
	}
	dfs(num);
	for(int j=1;j<=20;++j){
		for(int i=1;i+(1<<j)-1<=num;++i){
			l[i][j]=Min(l[i][j-1],l[i+(1<<j-1)][j-1]);
			r[i][j]=Max(r[i][j-1],r[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		int mi=askl(x,y),ma=askr(x,y);
		cout<<va[lca(mi,ma)]<<" ";
	}
	cout<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
5 5 5
1 2
1 3
2 4
3 4
3 5
1 4
3 4
2 2
2 5
3 5
*/