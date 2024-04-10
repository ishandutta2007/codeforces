#include <cstdio>
#include <algorithm>

int head[100001],nxt[200001],b[200001],k,n,q,dep[100001],f[100001],g[100001],size[100001],fa[100001];
long long ans,v[100001];
bool vis[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			v[x]+=1ll*size[x]*size[b[i]];
			size[x]+=size[b[i]];
		}
	v[x]+=1ll*size[x]*(n-size[x]-1);
	ans+=v[x];
	v[x]+=n-1;
	++size[x];
}
long long C(int x){
	return (1ll*x*(x-1)*(x-2));
}
void merge(int x,int y){
//	printf("merge %d %d\n",x,y);
	int w=find(y);
	ans+=1ll*(v[x]-1ll*size[x]*(n-size[x]))*g[w];
//	printf("%lld\n",ans);
	ans+=1ll*(v[w]-1ll*size[x]*(n-size[x]))*g[x];
	f[x]=w;
	g[w]+=g[x];
	v[w]+=v[x];
	v[w]-=1ll*size[x]*(n-size[x]);
//	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	for(int i=1;i<=n;i++)g[i]=1;
	printf("%lld\n",ans<<1);
	scanf("%d",&q);
	for(int i=1,u,v;i<=q;i++){
		scanf("%d%d",&u,&v);
		for(;;){
			u=find(u),v=find(v);
			if(u==v)break;
			if(dep[u]<dep[v])std::swap(u,v);
			merge(u,fa[u]);
		}
		printf("%lld\n",ans<<1);
	}
}