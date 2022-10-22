/*********************************************************************
	Problem:CF868E
	Author:hydd
	Date:2020/7/22
*********************************************************************/
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int INF=0x3f3f3f3f;
int n,s,m,sz[55],f[110][55][55],deg[55];
int edgenum=1,vet[110],val[110],Next[110],Head[55];
void addedge(int u,int v,int cost){
	vet[++edgenum]=v;
	val[edgenum]=cost;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u,int f){
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=f){
			dfs(vet[e],u);
			sz[u]+=sz[vet[e]];
		}
}
int solve(int now,int x,int y){
	if (!x&&!y) return 0;
	if (~f[now][x][y]) return f[now][x][y];
	int u=vet[now];
	if (deg[u]==1){//
		if (y==0) return 0;
		f[now][x][y]=solve(now^1,y,0)+val[now];
		return f[now][x][y];
	}
	int g[55]; memset(g,0,sizeof(g));
	g[0]=INF;
	for (int e=Head[u];e;e=Next[e])
		if (e!=(now^1)){
			for (int i=x;i>=1;i--)
				for (int j=i;j>=1;j--)
					g[i]=max(g[i],min(g[i-j],solve(e,j,x+y-j)+val[e]));
		}
	f[now][x][y]=g[x];
	return f[now][x][y];
}
int main(){
	scanf("%d",&n); int u,v,cost;
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&cost);
		deg[u]++; deg[v]++;
		addedge(u,v,cost); addedge(v,u,cost);
	}
	scanf("%d%d",&s,&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&u);
		sz[u]++;
	}
	dfs(s,0);
	memset(f,-1,sizeof(f));
	int ans=INF;
	for (int e=Head[s];e;e=Next[e])
		ans=min(ans,solve(e,sz[vet[e]],m-sz[vet[e]])+val[e]);
	printf("%d\n",ans);
	return 0;
}