#include <cstdio>
#include <cstring>
#include <algorithm>

int n,K,r,head[200001],nxt[400001],b[400001],k,q[200001],h,t,Q;
int dep[200001],fa[200001][21],f[200001];
int adj[200001],dis[200001];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
}
int lca(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int jump(int x,int y,int LCA,int l){
	if(dep[x]-dep[LCA]>=l){
		for(int i=20;~i;--i)
			if((1<<i)<=l)l-=(1<<i),x=fa[x][i];
		return x;
	}
	else{
		l=dep[x]+dep[y]-(dep[LCA]<<1)-l;
		for(int i=20;~i;--i)
			if((1<<i)<=l)l-=(1<<i),y=fa[y][i];
		return y;
	}
}
int main(){
	scanf("%d%d%d",&n,&K,&r);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	memset(dis,-1,sizeof dis);
	dfs(1,0);
	for(int i=1,tem;i<=r;i++){
		scanf("%d",&tem);
		q[++t]=tem;
		dis[tem]=0;
		adj[tem]=tem;
	}
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(!~dis[b[i]])dis[b[i]]=dis[q[h]]+1,q[++t]=b[i],adj[b[i]]=adj[q[h]];
	}
	for(int i=1,fu,fv;i<=k;i+=2)
		if((fu=find(adj[b[i]]))!=(fv=find(adj[b[i+1]]))&&dis[b[i]]+dis[b[i+1]]<K)f[fu]=fv;
	scanf("%d",&Q);
	for(int i=1,a,b;i<=Q;i++){
		scanf("%d%d",&a,&b);
		int LCA=lca(a,b),fu=dis[a]<=K?find(adj[a]):0,fv=dis[b]<=K?find(adj[b]):0;
		if(dep[a]+dep[b]-(dep[LCA]<<1)<=K){puts("YES");continue;}
		int l=1,r=K,mid;
		while(l<=r){
			mid=(l+r)>>1;
			int v=jump(a,b,LCA,mid);
			if(dis[v]+mid<=K)fu=find(adj[v]),l=mid+1;
			else r=mid-1;
		}
		l=1,r=K;
		while(l<=r){
			mid=(l+r)>>1;
			int v=jump(b,a,LCA,mid);
			if(dis[v]+mid<=K)fv=find(adj[v]),l=mid+1;
			else r=mid-1;
		}
		if(fu==fv&&fu)puts("YES");
		else puts("NO");
	}
}