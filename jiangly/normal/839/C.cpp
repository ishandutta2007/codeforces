#include<bits/stdc++.h>
const int MAXN=100000;
int N;
double ans;
std::vector<int>e[MAXN+5];
void dfs(int u,int fa,double p){
	ans+=p;
	for(auto v:e[u]){
		if(v==fa)
			continue;
		dfs(v,u,p/(e[u].size()-(u!=1)));
	}
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<N;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,1);
	printf("%.15lf\n",ans-1);
	return 0;
}