#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const int M=2e5+9;
int n;
int siz[M],f[M][23],dep[M];
ll ans[M];
vector<int>g[M];
void dfs(int u,int fa){
	siz[u]=1;
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=21;++i)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v!=fa)dfs(v,u),siz[u]+=siz[v];
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=21;i>=0;--i){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=21;i>=0;--i){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int find(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=21;i>=0;--i){
		if(dep[f[x][i]]>dep[y])x=f[x][i];
	}
	if(x)return x;
}
bool pd(int a,int b,int c){
	int w=lca(a,b);
	if((lca(c,w)==w&&lca(a,c)==c)||(lca(c,w)==w&&lca(b,c)==c))return 1;
	return 0;
}
void work(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		u++;
		v++;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	int l=0,r=0;
	ans[0]=1ll*n*(n-1)/2;
	for(int u=1;u<=n;++u){
		if(!l){
			l=u;
			ll sum=1;
			for(auto v:g[u])sum+=siz[v];
			for(auto v:g[u]){
				sum-=siz[v];
				ans[u]+=1ll*sum*siz[v];
			}
			continue;
		}
		
		if(!r)r=u;
		if(!pd(l,r,u)&&!pd(l,u,r)&&!pd(u,r,l))break;
		if(dep[l]>dep[r])swap(l,r);
		if(lca(u,l)==l&&lca(u,r)!=u&&lca(u,r)!=r)l=u;
		else if(lca(u,r)==r)r=u;
		if(dep[l]>dep[r])swap(l,r);
		if(lca(l,r)==l){
			int w=find(lca(l,r),r);
			ans[u]=1ll*(n-siz[w])*siz[r];
		}
		else {
			ans[u]=1ll*siz[l]*siz[r];
		}
	}
	for(int i=0;i<=n;++i){
		ans[i]=ans[i]-ans[i+1];
		printf("%lld ",ans[i]);
		ans[i]=0;
		g[i].clear();
		dep[i]=0;
		
	}
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
4
1 0
2 1
3 1

*/