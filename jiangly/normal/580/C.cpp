#include<bits/stdc++.h>
const int MAXN=100000;
int N,M,ans;
std::vector<int>e[MAXN+5];
bool cat[MAXN+5];
void dfs(int u,int fa,int cnt){
	if(cnt>M)
		return;
	bool is_leaf=1;
	for(auto v:e[u]){
		if(v==fa)
			continue;
		is_leaf=0;
		dfs(v,u,cat[v]?cnt+1:0);
	}
	ans+=is_leaf;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)
		scanf("%d",&cat[i]);
	for(int i=1;i<N;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,cat[1]);
	printf("%d\n",ans);
	return 0;
}