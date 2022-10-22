#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=609;
int n,m,tot=0;
int g[M][M];
ll dis[M][M];int vis[M],in[M];
void dij(int s,ll *d){
	for(int i=1;i<=n;++i){
		if(g[s][i])d[i]=g[s][i];
		else d[i]=1ll<<50;
		vis[i]=0;
	}
	for(int i=1;i<=n;++i){
		int u;
		ll mi=1ll<<50;
		for(int j=1;j<=n;++j)if(mi>d[j]&&!vis[j])mi=d[j],u=j;
		vis[u]=1;
		if(d[u%n+1]>d[u]+1)d[u%n+1]=d[u]+1;
		for(int x=1;x<=n;++x){
			int v=(x+d[u]-1)%n+1;
			if(g[u][x]&&d[v]>d[u]+g[u][x])d[v]=d[u]+g[u][x];
		}
	}
	d[s]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		u++;v++;
		g[u][v]=w;
	}
	for(int i=1;i<=n;++i)dij(i,dis[i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%lld ",dis[i][j]);
		}
		printf("\n");
	}
	return 0;
}