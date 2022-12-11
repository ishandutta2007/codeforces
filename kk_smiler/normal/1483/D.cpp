#include <bits/stdc++.h>
using namespace std;
int T,n,m,q,lim[610][610],u[360000],v[360000],w[360000];
long long d[610][610],up[610];
bool can[360000];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=(i!=j)*1e17,lim[i][j]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		d[u[i]][v[i]]=d[v[i]][u[i]]=w[i];
	}
	for(int k=1;k<=n;k++) for(int j=1;j<=n;j++) for(int i=1;i<=n;i++) d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
	scanf("%d",&q);
	for(int i=1,u,v,l;i<=q;i++){
		scanf("%d%d%d",&u,&v,&l);
		lim[u][v]=lim[v][u]=l;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) up[j]=0;
		for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) up[k]=max(up[k],lim[i][j]-d[k][j]);
		for(int j=1;j<=m;j++) if(d[i][u[j]]+w[j]<=up[v[j]]||d[i][v[j]]+w[j]<=up[u[j]]) can[j]=true;
	}
	int ans=0;
	for(int i=1;i<=m;i++) if(can[i]) ans++;
	printf("%d\n",ans);
}
int main(){
	if(0) scanf("%d",&T);
	else T=1;
	while(T--) solve();
}