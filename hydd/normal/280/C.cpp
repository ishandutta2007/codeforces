#include<cstdio>
using namespace std;
int n,u,v,dep[110000];
int edgenum=1,vet[210000],Next[210000],Head[110000];
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa) dfs(vet[e],u);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	dfs(1,0);
	long double ans=0;
	for (int i=1;i<=n;i++) ans+=1.0/dep[i];
	printf("%.20lf\n",(double)ans);
	return 0;
}