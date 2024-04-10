// Hydro submission #62e5f06eae2854bd138e33f5@1659236463046
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=400007;
int n;
struct E{
	int u,v;
}e[maxn<<1];
int first[maxn],nt[maxn<<1],ES;
void add(int u,int v){
	e[++ES]=(E){u,v};
	nt[ES]=first[u];
	first[u]=ES;
	return ;
}
int fa[maxn],sz[maxn];
int rt;
void dfs1(int u){
	int v;
	sz[u]=1;
	bool f=true;
	for(int i=first[u];i;i=nt[i]){
		v=e[i].v;
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>n/2) f=false;
	}
	if(n-sz[u]>n/2) f=false;
	if(f) rt=u;
	return ;
}
int Max[maxn][2];
void dfs2(int u){
	int v;
	sz[u]=1;
	for(int i=first[u];i;i=nt[i]){
		v=e[i].v;
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs2(v);
		sz[u]+=sz[v];
		if(sz[v]>n/2) continue;
		if(sz[v]>Max[u][0]) Max[u][1]=Max[u][0],Max[u][0]=sz[v];
		else if(sz[v]>Max[u][1]) Max[u][1]=sz[v];
	}
	return ;
}
int cut[maxn];
bool ans[maxn];
void dfs3(int u,int maxx){
	int v;
	cut[u]=maxx;
	for(int i=first[u];i;i=nt[i]){
		v=e[i].v;
		if(v==fa[u]) continue;
		if(n-sz[u]<=n/2) maxx=max(maxx,n-sz[u]); 
		if(Max[u][0]==sz[v]) dfs3(v,max(maxx,Max[u][1]));
		else dfs3(v,max(maxx,Max[u][0]));
	}
	if(n-sz[u]-cut[u]<=n/2||u==rt) ans[u]=true;
	return ;
}
int main(){
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs1(1);
	fa[rt]=0;
	dfs2(rt);
	dfs3(rt,0);
	for(int i=1;i<=n;i++)
	if(ans[i]) putchar('1'),putchar(32);
	else putchar('0'),putchar(32);
	return 0;
}