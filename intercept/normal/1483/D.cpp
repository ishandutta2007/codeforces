#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=609;
const ll INF=1ll<<60;
int n,m,q,ans;
struct P{int u,v,l;}e[M*M];
bool vis[M*M];
ll d[M][M],f[M][M],val[M];
void work(int x){
	for(int i=1;i<=n;++i)val[i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			val[j]=max(val[j],f[x][i]-d[i][j]);
		}
	}
	for(int i=1;i<=m;++i){
		int u=e[i].u,v=e[i].v,l=e[i].l;
		if(d[x][u]+l<=val[v]||d[x][v]+l<=val[u])vis[i]=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
		d[i][j]=INF;
	for(int i=1;i<=n;++i)d[i][i]=0;
	for(int i=1,u,v,l;i<=m;++i){
		scanf("%d%d%d",&u,&v,&l);
		d[u][v]=d[v][u]=l;
		e[i]=P{u,v,l};
	}
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j){
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	} 
	scanf("%d",&q);
	for(int i=1,u,v,l;i<=q;++i){
		scanf("%d%d%d",&u,&v,&l);
		f[u][v]=max(f[u][v],1ll*l);
		f[v][u]=max(f[v][u],1ll*l);
	}
	for(int i=1;i<=n;++i)work(i);
	for(int i=1;i<=m;++i)ans+=vis[i];
	printf("%d\n",ans);
	return 0;
}
/*
4 6
1 2 1
2 3 1
3 4 1
1 3 3
2 4 3
1 4 5
1
1 4 4
*/