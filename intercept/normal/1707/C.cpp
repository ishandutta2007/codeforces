#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m;
vector<pii>g[M];
int f[M],dp[M];
bool vis[M<<1];
int df=0;
int p[M][20],dep[M],d[M],b[M],L[M],R[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;--i){
		if(dep[p[x][i]]>=dep[y])x=p[x][i];
	}
	if(x==y)return x;
	for(int i=17;i>=0;--i){
		if(p[x][i]!=p[y][i]){
			x=p[x][i];
			y=p[y][i];
		}
	}
	return p[x][0];
}
void dfs(int u,int fa){
	L[u]=++df;
	p[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<=17;++i)p[u][i]=p[p[u][i-1]][i-1];
	for(auto o:g[u]){
		int v=o.fi,w=o.se;
		if(vis[w]&&v!=fa){
			dfs(v,u);
		}
	}
	R[u]=df;
}
void solve(int u,int fa){
	d[u]+=d[fa];
	for(auto o:g[u]){
		int v=o.fi,w=o.se;
		if(vis[w]&&v!=fa){
			solve(v,u);
		}
	}
}
int lk(int x,int k){
	for(int i=17;i>=0;--i){
		if(k>>i&1)x=p[x][i];
	}
	return x;
}
void change(int u){
	;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v,i);
		g[v].eb(u,i);
		if(find(u)!=find(v)){
			f[find(u)]=find(v);
			vis[i]=1;
		}
	}
	dfs(1,0);
	int rex=0;
	for(int i=1;i<=n;++i){
		for(auto o:g[i]){
			int u=i;
			if(!vis[o.se]&&o.fi>u){
				int v=o.fi;
				if(abs(dep[u]-dep[v])==1)continue;
				int w=lca(u,v);
				if(dep[u]>dep[v])swap(u,v);
				if(u==w){
					d[v]--;
					d[lk(v,dep[v]-dep[u]-1)]++;
				}
				else{
					rex++;
					d[w]++;
					d[u]--;
					d[v]--;
					int l=L[w],r=R[w];
					b[l]++;
					b[r+1]--;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)b[i]+=b[i-1];
	solve(1,0);
	
	for(int i=1;i<=n;++i)putchar('0'+(d[i]==0&&b[L[i]]==rex));
	return 0;
}
/*
5 5
1 2
3 5
1 3
3 2
4 2


*/