#include<bits/stdc++.h>
const int MAXN=200000;
int N,ans;
std::vector<int>e[MAXN+5];
int c[MAXN+5];
template<class T>const T&max(const T&a,const T&b){
	return a>b?a:b;
}
void dfs(int u,int fa){
	ans=max(ans,int(e[u].size()+1));
	int cur=1;
	while(c[u]==cur||c[fa]==cur)
		++cur;
	for(auto v:e[u]){
		if(v==fa)
			continue;
		c[v]=cur++;
		dfs(v,u);
		while(c[u]==cur||c[fa]==cur)
			++cur;
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
	c[1]=1;
	dfs(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=N;++i)
		printf("%d ",c[i]);
	return 0;
}