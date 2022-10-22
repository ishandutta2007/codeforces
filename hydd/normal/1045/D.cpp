#include<cstdio>
using namespace std;
int n,q,fa[110000];
double p[110000],sum[110000];
int edgenum,vet[210000],Next[210000],Head[110000];
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u){
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa[u]){
			fa[vet[e]]=u;
			dfs(vet[e]);
		}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]);
	int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v); u++; v++;
		addedge(u,v); addedge(v,u);
	}
	p[0]=1; dfs(1); double ans=0;
	for (int i=1;i<=n;i++){
		ans+=p[fa[i]]*(1-p[i]);
		sum[fa[i]]+=(1-p[i]);
	}
	scanf("%d",&q);
	int x; double y;
	while (q--){
		scanf("%d%lf",&x,&y); x++;
		ans-=p[fa[x]]*(1-p[x]);
		ans-=p[x]*sum[x];
		sum[fa[x]]-=(1-p[x]);
		p[x]=y;
		sum[fa[x]]+=(1-p[x]);
		ans+=p[x]*sum[x];
		ans+=p[fa[x]]*(1-p[x]);
		printf("%.5lf\n",ans);
	}
	return 0;
}