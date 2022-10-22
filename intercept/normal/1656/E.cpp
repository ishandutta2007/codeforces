#include<bits/stdc++.h>
using namespace std;
int n;
int d[100009],ans[100009];
vector<int>g[100009];
void dfs(int u,int fa,int o){
	if(o)ans[u]=1+(g[u].size()-1);
	else ans[u]=-1-(g[u].size()-1);
	for(auto v:g[u]){
		if(v!=fa)dfs(v,u,o^1);
	}
}
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}