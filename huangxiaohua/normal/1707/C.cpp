#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[205000],fa[205000],x,y,dep[200500],g[200500][21];
vector<int> v[1005000];
vector<pair<int,int> >nmsl;
int find(int x){
	return(fa[x]==x?x:fa[x]=find(fa[x]));	
}
void dfs(int x,int fa){
	g[x][0]=fa;
	for(int i=1;i<=20;i++)g[x][i]=g[g[x][i-1]][i-1];
	for(auto i:v[x])if(i!=fa){
		dep[i]=dep[x]+1;dfs(i,x);
	}
}
pair<int,int> lca(int x,int y){
	for(int i=20;i>=0;i--){
		if(dep[y]-(1<<i)>dep[x])y=g[y][i];
	}
	if(g[y][0]==x){
		return {x,y};
	}
	for(int i=20;i>=0;i--){
		if(g[x][i]!=g[y][i]){
			x=g[x][i];y=g[y][i];
		}
	}
	return {g[x][0],x};
}
void dfs3(int x,int fa){
	for(auto i:v[x]){
		if(i==fa)continue;
		f[i]+=f[x];dfs3(i,x);
	}
}
int main() {
    ios::sync_with_stdio(0);
    cin>>n>>t;
    for(i=1;i<=n;i++)fa[i]=i;
    while(t--){
    	cin>>x>>y;
    	if(find(x)!=find(y)){
    		v[x].push_back(y);v[y].push_back(x);
    		x=find(x);y=find(y);
    		fa[x]=y;
		}
		else{
			nmsl.push_back({x,y});
		}
	}
	dfs(1,1);
	for(auto [x,y]:nmsl){
		if(dep[x]>dep[y])swap(x,y);
		auto [i,j]=lca(x,y);
		//printf("NMSL%d %d %d %d\n",x,y,i,j);
		if(i==x){
			f[j]++;f[y]--;
		}
		else{
			f[1]++;
			f[x]--;f[y]--;
		}
	}
	dfs3(1,0);
	for(i=1;i<=n;i++)cout<<!f[i];
}