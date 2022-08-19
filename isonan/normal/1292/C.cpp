#include <cstdio>
#include <algorithm>

long long f[3001][3001],ans;
int n,head[3001],nxt[6001],b[6001],k,size[3001],fa[3001],ord[3001],now;
bool vis[3001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	fa[x]=f;
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x),size[x]+=size[b[i]];
}
void getans(int x,int F){
	ord[++now]=x;
	if(F){
		f[fa[x]][x]=size[x]*(n-size[x]);
		for(int tem=fa[x];tem>1;tem=fa[tem])
			f[fa[tem]][x]=std::max(f[tem][x],f[fa[tem]][fa[x]])+size[x]*(n-size[tem]);
		for(int j=1;j<now;j++){
			int i=ord[j];
			if(!f[i][x])f[i][x]=std::max(std::max(f[i][fa[x]],f[fa[x]][i]),f[fa[i]][x])+size[x]*size[i];
		}
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F)getans(b[i],x);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	getans(1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=std::max(ans,f[i][j]);
	printf("%lld\n",ans);
}