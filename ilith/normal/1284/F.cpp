#include<bits/stdc++.h>
#define pbk emplace_back
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pii;
const int N=3e5+7;
int n,u,v,sz[N],sn[N],d[N],fa[N],tp[N],F[N],id[N],C,sq[N];
int fd(int x){return F[x]==x?x:F[x]=fd(F[x]);}
vector<int>a[N],b[N];
void dfs(int x,int f){
	d[x]=d[fa[x]=f]+1,sz[x]=1;
	for(int to:a[x])if(to!=f){
		dfs(to,x),sz[x]+=sz[to];
		if(sz[to]>sz[sn[x]])sn[x]=to;
	}
}
void Dfs(int x,int f){
	tp[x]=f,sq[id[x]=++C]=x;
	if(sn[x])Dfs(sn[x],f);
	for(int to:a[x])if(to!=fa[x]&&to!=sn[x])Dfs(to,to);
}
vector<pii>f,g;
void LCA(int u,int v){
	while(tp[u]!=tp[v]){
		if(d[tp[u]]<d[tp[v]])g.pbk(id[tp[v]],id[v]),v=fa[tp[v]];
		else f.pbk(id[tp[u]],id[u]),u=fa[tp[u]];
	}
	if(d[u]<d[v])g.pbk(id[u],id[v]);
	else f.pbk(id[v],id[u]);
}
void link(int u,int v){printf("%d %d ",sq[u],sq[v]),F[fd(u)]=fd(v);}
void del(int u,int v){
	f.clear(),g.clear(),LCA(u,v);
	reverse(g.begin(),g.end());
	int h=0,fl=0,O=fd(id[u]);
	for(pii k:f){
		int l=k.fi,r=k.se;
		if(fd(r)!=O)link(r,h),fl=1;
		if(!fl&&fd(l)!=O){
			ROF(i,18,0)if(r-(1<<i)>l&&fd(r-(1<<i))==O)r-=(1<<i);
			link(r,r-1),fl=1;
		}
		if(fl)return void(printf("%d %d\n",u,v));
		h=l;
	}
	for(pii k:g){
		int l=k.fi,r=k.se;
		if(fd(l)!=O)link(l,h),fl=1;
		if(!fl&&fd(r)!=O){
			ROF(i,18,0)if(l+(1<<i)<r&&fd(l+(1<<i))==O)l+=(1<<i);
			link(l,l+1),fl=1;
		}
		if(fl)return void(printf("%d %d\n",u,v));
		h=r;
	}
}
void DFS(int x,int f){
	for(int to:b[x])if(to!=f)DFS(to,x);
	if(f)del(x,f);
}
int main(){
	scanf("%d",&n);
	FOR(i,2,n)scanf("%d%d",&u,&v),a[u].pbk(v),a[v].pbk(u);
	FOR(i,2,n)scanf("%d%d",&u,&v),b[u].pbk(v),b[v].pbk(u);
	dfs(1,0),Dfs(1,1);
	FOR(i,1,n)F[i]=i;
	printf("%d\n",n-1);
	DFS(1,0);
	return 0;
}