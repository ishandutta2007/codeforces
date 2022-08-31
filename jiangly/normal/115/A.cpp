#include<bits/stdc++.h>
const int MAXN=2000;
int n;
int fa[MAXN+5];
std::vector<int>e[MAXN+5];
int dep[MAXN+5];
int ans;
void dfs(int u){
	ans=std::max(ans,dep[u]+1);
	for(auto v:e[u]){
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&fa[i]);
		if(fa[i]!=-1){
			e[fa[i]].push_back(i);
		}
	}
	for(int i=1;i<=n;++i){
		if(fa[i]==-1){
			dfs(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}