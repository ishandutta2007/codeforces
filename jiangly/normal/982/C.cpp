#include<bits/stdc++.h>
const int MAXN=100000;
std::vector<int>e[MAXN+5];
int N,ans;
int dfs(int u,int fa){
	int sz=1;
	for(auto v:e[u]){
		if(v==fa)
			continue;
		sz+=dfs(v,u);
	}
	if(!(sz&1)){
		sz=0;
		++ans;
	}
	return sz;
}
int main(){
	scanf("%d",&N);
	if(N&1){
		puts("-1");
		return 0;
	}
	for(int i=1;i<N;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",ans-1);
	return 0;
}