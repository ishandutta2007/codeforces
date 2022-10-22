#include<bits/stdc++.h>
using namespace std;
int n,q,k,a[110000],dep[110000],fa[110000],sz[110000],son[110000],top[110000];
int edgenum,vet[210000],Next[210000],Head[110000];
int cnt,dfn[110000]; bool vis[110000];
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
bool cmp(int x,int y){ return dfn[x]<dfn[y];}
void dfs1(int u,int f){
	dep[u]=dep[f]+1; fa[u]=f; sz[u]=1;
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=f){
			dfs1(vet[e],u);
			sz[u]+=sz[vet[e]];
			if (sz[vet[e]]>sz[son[u]]) son[u]=vet[e];
		}
}
void dfs2(int u,int t){
	top[u]=t; dfn[u]=++cnt;
	if (son[u]) dfs2(son[u],t);
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa[u]&&vet[e]!=son[u]) dfs2(vet[e],vet[e]);
}
int LCA(int u,int v){
	while (top[u]!=top[v]){
		if (dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	if (dep[u]<dep[v]) swap(u,v);
	return v;
}
int f[110000];
int dfs(int u){
	int res=0,sum=0;
	for (int e=Head[u];e;e=Next[e]){
		res+=dfs(vet[e]);
		sum+=f[vet[e]];
	}
	Head[u]=0;
	if (vis[u]) res+=sum,f[u]=1;
	else if (sum>1) res++,f[u]=0;
	else f[u]=sum;
	return res;
}
int s[110000];
void solve(){
	for (int i=1;i<=k;i++)
		if (vis[fa[a[i]]]){
			puts("-1");
			return;
		}
	sort(a+1,a+k+1,cmp);
	int top=1; s[1]=a[1];
	for (int i=2;i<=k;i++){
		int u=LCA(s[top],a[i]);
		while (dep[u]<dep[s[top-1]]){
			addedge(s[top-1],s[top]);
			top--;
		}
		if (u!=s[top]){
			addedge(u,s[top]);
			if (u==s[top-1]) top--;
			else s[top]=u;
		}
		s[++top]=a[i];
	}
	while (top>1) addedge(s[top-1],s[top]),top--;
	printf("%d\n",dfs(s[1]));
	edgenum=0;
}
int main(){
	scanf("%d",&n);
	int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	dfs1(1,0); dfs2(1,1);
	
	edgenum=0;
	for (int i=1;i<=n;i++) Head[i]=0;
	scanf("%d",&q);
	while (q--){
		scanf("%d",&k);
		for (int i=1;i<=k;i++){
			scanf("%d",&a[i]);
			vis[a[i]]=true;
		}
		solve();
		for (int i=1;i<=k;i++) vis[a[i]]=false;
	}
	return 0;
}