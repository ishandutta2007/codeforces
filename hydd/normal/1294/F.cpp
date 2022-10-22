/*********************************************************************
 * Source - lyp
 * ProblemCF1294F
 * Authorhydd
 * Date2020/10/13
*********************************************************************/
#include<cstdio>
#include<vector>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
int n,u,v,w; bool vis[210000];
int dep[210000],fa[210000];
vector<int> vec[210000];
void dfs(int u,int f){
	dep[u]=dep[f]+1; fa[u]=f;
	for (int v:vec[u])
		if (v!=f) dfs(v,u);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
		if (dep[i]>dep[u]) u=i;
	dfs(u,0);
	for (int i=1;i<=n;i++)
		if (dep[i]>dep[v]) v=i;

	int ans=dep[v]-1;
	int x=v;
	while (x) vis[x]=1,x=fa[x];
	
	x=v;
	while (x){
		dep[x]=0;
		for (int p:vec[x])
			if (!vis[p]) dfs(p,x);
		x=fa[x];
	}
	
	dep[0]=-1;
	for (int i=1;i<=n;i++)
		if (i!=u&&i!=v&&dep[i]>dep[w]) w=i;
	printf("%d\n",dep[w]+ans);
	printf("%d %d %d\n",u,v,w);
	return 0;
}