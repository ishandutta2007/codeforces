#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+5;
int n,k;
ll ans;
int tot_edge;
int head[N],next[N<<1],to[N<<1];
int sz[N];
void link(int u,int v){
	++tot_edge;
	to[tot_edge]=v;
	next[tot_edge]=head[u];
	head[u]=tot_edge;
}
void dfs(int u,int fa){
	for(int i=head[u];i;i=next[i]){
		int v=to[i];
		if(v==fa){
			continue;
		}
		dfs(v,u);
		sz[u]+=sz[v];
	}
	ans+=std::min(sz[u],2*k-sz[u]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k*2;++i){
		int u;
		scanf("%d",&u);
		++sz[u];
	}
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		link(u,v);
		link(v,u);
	}
	dfs(1,0);
	printf("%I64d\n",ans);
	return 0;
}