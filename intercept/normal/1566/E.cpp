#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n;
int ans,val[M];
vector<int>g[M];
void dfs(int u,int fa){
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			if(!val[v])val[u]=1;
		}
	}
	ans-=val[u];
	ans+=(val[u]==0&&u!=1);
}
void work(){
	ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)g[i].clear(),val[i]=0;
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	printf("%d\n",ans);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
} 
/*
1
6
2 1
2 3
4 5
3 4
3 6
*/