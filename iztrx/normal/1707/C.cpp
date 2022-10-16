#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define mod 998244353
int f[N],t,n,m,cnt,dep[N],i,X[N],Y[N],u,v,vis[N],fa[N],FA[N][20];
vector<int>son[N];
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void dfs(int now,int fat){
	fa[now]=fat;
	FA[now][0]=fat;
	dep[now]=dep[fat]+1;
	for(i=1;i<=17;++i)FA[now][i]=FA[FA[now][i-1]][i-1]; 
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			dfs(T,now);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);int i;
	for(i=17;~i;--i){
		if(dep[FA[x][i]]>=dep[y])x=FA[x][i];
	}
	if(x==y)return x;
	for(i=17;~i;--i){
		if(FA[x][i]!=FA[y][i])x=FA[x][i],y=FA[y][i];
	}
	return fa[x];
}
void dfs0(int now,int fat){
	vis[now]+=vis[fat];
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			dfs0(T,now);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	t=1;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;++i)f[i]=i,son[i].clear(),vis[i]=0;cnt=0;
		for(i=1;i<=m;++i){
			cin>>u>>v;
			if(find(u)!=find(v))son[u].push_back(v),son[v].push_back(u),f[find(u)]=f[find(v)]; 
			else X[++cnt]=u,Y[cnt]=v;//,cout<<u<<" "<<v<<"\n";
		}
		dfs(1,0);
		int nd=0;
		for(i=1;i<=cnt;++i){
			u=X[i],v=Y[i];
			if(dep[u]>dep[v])swap(u,v);
			if(lca(u,v)==u){
				++vis[v];
				for(int j=17;~j;--j)if(dep[FA[v][j]]>dep[u]) v=FA[v][j];
				--vis[v];
			}
			else ++vis[u],++vis[v],++nd;
		}
		dfs0(1,0);
		for(i=1;i<=n;++i){
			if(vis[i]==nd)cout<<1;
			else cout<<0;
		}cout<<'\n';
	}
}