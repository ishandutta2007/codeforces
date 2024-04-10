#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,k,u,v,dep[410000],sz[410000],tag[410000],fa[410000];
int edgenum,vet[810000],Next[810000],Head[410000];
ll ans;
priority_queue<pii> que;
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	sz[u]=1; tag[u]=1;
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa[u]){
			fa[vet[e]]=u;
			dfs(vet[e]);
			sz[u]+=sz[vet[e]];
		}
	if (tag[u]==sz[u]) que.push(pii(dep[u]-sz[u],u));
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	fa[1]=0; dfs(1); 
	for (int i=1;i<=k;i++){
		u=que.top().second; que.pop();
		tag[fa[u]]+=tag[u];
		if (tag[fa[u]]==sz[fa[u]]) que.push(pii(dep[fa[u]]-sz[fa[u]],fa[u]));
		ans+=dep[u]-sz[u];
	}
	printf("%lld\n",ans);
	return 0;
}