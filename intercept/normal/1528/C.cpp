#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=3e5+9;
int n,tot,ans;
int f[M][25],dep[M],lid[M],rid[M];
vector<int>g[M],h[M];
bool vis[M];
void dfs(int u,int fa){
	lid[u]=++tot;
	f[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<=23;++i){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(auto v:g[u])dfs(v,u);
	rid[u]=tot;
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=23;i>=0;--i){
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
	}
	if(u==v)return u;
	for(int i=23;i>=0;--i){
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	}
	return f[u][0];
}
int bit[M];
int ask(int i,int rex=0){
	for(;i;i-=i&-i)rex+=bit[i];
	return rex;
}
void add(int i,int v){
	for(;i<=n;i+=i&-i)bit[i]+=v;
}
void change(int l,int r,int v){
	add(l,v);
	add(r+1,-v);
}
void Dfs(int u,int s){
	int sum=s;bool bol=0;
	int w=ask(lid[u]);
	if(w){
		if(lca(u,w)==w){
			bol=1;
			change(lid[w],rid[w],-w);
			vis[w]=0;
			vis[u]=1;
			change(lid[u],rid[u],u);
		}
	}
	else{
		vis[u]=1;
		change(lid[u],rid[u],u);
		sum++;
	}
	ans=max(ans,sum);
	for(auto v:h[u])Dfs(v,sum);
	if(vis[u]){
		change(lid[u],rid[u],-u);
		vis[u]=0;
		if(bol){
			change(lid[w],rid[w],w);
			vis[w]=1;
		}
	}
}
void work(){
	scanf("%d",&n);
	tot=ans=0;
	for(int i=1;i<=n;++i){
		h[i].clear();
		g[i].clear();
		bit[i]=0;
	}
	for(int i=2,u;i<=n;++i){
		scanf("%d",&u);
		h[u].eb(i);
	}	
	for(int i=2,u;i<=n;++i){
		scanf("%d",&u);
		g[u].eb(i);
	}
	dfs(1,0);
	Dfs(1,0);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*


*/