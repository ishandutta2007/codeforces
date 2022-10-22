#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=3e5+9;
int n,q,sz=0;
int c[M],dep[M],f[M][25];
ll d[M],val[M*23];
int ls[M*23],rs[M*23],rt[M*23];
mt19937_64 rnd(time(0));
vector<int>g[M];
void insert(int&root,int las,int l,int r,int x){
	root=++sz;
	val[root]=val[las]^d[x];
	if(l==r)return;
	ls[root]=ls[las];
	rs[root]=rs[las];
	int mid=l+r>>1;
	if(x<=mid)insert(ls[root],ls[las],l,mid,x);
	else insert(rs[root],rs[las],mid+1,r,x);
}
void dfs(int u,int fa){
	dep[u]=dep[f[u][0]=fa]+1;
	insert(rt[u],rt[fa],1,n,c[u]);
	for(int i=1;i<=21;++i)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u])if(v!=fa)dfs(v,u); 
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=21;i>=0;--i)
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
	for(int i=21;i>=0;--i)
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return u==v?u:f[u][0]; 
}
int query(int u,int v,int w,int z,int l,int r,int x,int y){
	if(x<=l&&r<=y&&(val[u]^val[v]^val[w]^val[z])==0)return -1;
	if(l==r)return l;
	int mid=l+r>>1,p=-1;
	if(x<=mid)p=query(ls[u],ls[v],ls[w],ls[z],l,mid,x,y);
	if(p==-1&&y>mid)p=query(rs[u],rs[v],rs[w],rs[z],mid+1,r,x,y);
	return p;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]),d[i]=rnd();
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	for(int i=1,u,v,x,y,w,z;i<=q;++i){
		scanf("%d%d%d%d",&u,&v,&x,&y);
		z=f[w=lca(u,v)][0];
		printf("%d\n",query(rt[u],rt[v],rt[w],rt[z],1,n,x,y));
	}
	return 0;
}