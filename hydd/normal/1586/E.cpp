#include<bits/stdc++.h>
using namespace std;
int n,m,q,deg[310000],x[310000],y[310000],ans;
int dep[310000],fa[310000]; bool vis[310000];
int cnta,a[310000],cntb,b[310000];
vector<int> vec[310000],tmp[310000],Ans[310000];
void dfs(int u,int f){
	if (vis[u]) return;
	dep[u]=dep[f]+1; fa[u]=f;
	vis[u]=true; if (f){ vec[u].push_back(f); vec[f].push_back(u);}
	for (int v:tmp[u]) dfs(v,u);
}
int main(){
	scanf("%d%d",&n,&m); int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		tmp[u].push_back(v);
		tmp[v].push_back(u);
	}
	dfs(1,0);
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
		u=x[i]; v=y[i]; cnta=0; cntb=0;
		deg[u]^=1; deg[v]^=1;
		if (dep[u]<dep[v]){
			while (dep[v]>dep[u]) b[++cntb]=v,v=fa[v];
		} else{
			while (dep[u]>dep[v]) a[++cnta]=u,u=fa[u];
		}
		while (u!=v){
			a[++cnta]=u,u=fa[u];
			b[++cntb]=v,v=fa[v];
		}
		for (int j=1;j<=cnta;j++) Ans[i].push_back(a[j]);
		Ans[i].push_back(u);
		for (int j=cntb;j>=1;j--) Ans[i].push_back(b[j]);
	}
	int tot=0;
	for (int i=1;i<=n;i++)
		if (deg[i]&1) tot++;
	if (tot){
		puts("NO");
		printf("%d\n",(tot+1)>>1);
		return 0;
	}
	puts("YES");
	for (int i=1;i<=q;i++){
		printf("%d\n",(int)Ans[i].size());
		for (int v:Ans[i]) printf("%d ",v);
		putchar('\n');
	}
	return 0;
}