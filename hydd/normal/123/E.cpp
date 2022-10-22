#include<cstdio>
using namespace std;
typedef long long ll;
int n,u,v,x[210000],y[210000],sz[210000];
double ans,s[210000],e[210000],sum;
int edgenum,vet[410000],Next[410000],Head[210000];
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs1(int u,int fa){
	sz[u]=1;
	int v;
	for (int ee=Head[u];ee;ee=Next[ee]){
		v=vet[ee];
		if (v!=fa){
			dfs1(v,u);
			sz[u]+=sz[v];
		}
	}
	sum+=e[u]*sz[u];
}
void dfs2(int u,int fa){
	ans-=s[u]*sum;
	int v;
	for (int ee=Head[u];ee;ee=Next[ee]){
		v=vet[ee];
		if (v!=fa){
			sum-=e[u]*sz[u]; sum-=e[v]*sz[v];
			sz[u]-=sz[v]; sz[v]+=sz[u];
			sum+=e[u]*sz[u]; sum+=e[v]*sz[v];
			dfs2(v,u);
			sum-=e[v]*sz[v]; sum-=e[u]*sz[u];
			sz[v]-=sz[u]; sz[u]+=sz[v];
			sum+=e[v]*sz[v]; sum+=e[u]*sz[u];
		}
	}
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	ll sumx=0,sumy=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		sumx+=x[i]; sumy+=y[i];
	}
	for (int i=1;i<=n;i++){
		s[i]=1.0*x[i]/sumx;
		e[i]=1.0*y[i]/sumy;
	}
	ans=n;
	dfs1(1,0); dfs2(1,0);
	printf("%.12lf\n",ans);
	return 0;
}