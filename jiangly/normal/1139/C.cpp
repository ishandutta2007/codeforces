#include<bits/stdc++.h>
const int MAXN=100000,P=1e9+7;
std::vector<int>e[MAXN+5];
int N,ans,K;
bool vis[MAXN+5];
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)
			ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
int dfs(int u){
	vis[u]=1;
	int sz=1;
	for(auto v:e[u]){
		if(vis[v])
			continue;
		sz+=dfs(v);
	}
	return sz;
}
int main(){
	scanf("%d%d",&N,&K);
	for(int i=1;i<N;++i){
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		if(x)
			continue;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans=Pow(N,K);
	for(int i=1;i<=N;++i)
		if(!vis[i])
			ans=(ans-Pow(dfs(i),K)+P)%P;
	printf("%d\n",ans);
	return 0;
}