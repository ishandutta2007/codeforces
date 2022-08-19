#include<bits/stdc++.h>
const int MAXN=100000;
std::vector<int>e[MAXN+5];
int N,ans;
int a[MAXN+5],rev[MAXN+5];
void dfs(int u,int fa,int c1,int c2){
	if(c1!=a[u]){
		c1^=1;
		rev[u]=1;
		++ans;
	}
	for(auto v:e[u]){
		if(v==fa)
			continue;
		dfs(v,u,c2,c1);
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
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=N;++i){
		int b;
		scanf("%d",&b);
		a[i]^=b;
	}
	dfs(1,0,0,0);
	printf("%d\n",ans);
	for(int i=1;i<=N;++i)
		if(rev[i])
			printf("%d\n",i);
	return 0;
}