#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m;
int d[M];
vector<int>g[M];
int dp[M],siz[M];
void dfs(int u,int fa){
	if(g[u].size()==1)siz[u]=1;
	int sum=0;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			siz[u]+=siz[v];
			sum+=siz[v]==1;
			dp[u]+=dp[v];
		}
	}
	if(sum)dp[u]+=sum-1;
}
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)g[i].clear(),dp[i]=siz[i]=0;
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	if(n==1){
		puts("0");
		return;
	}
	int root=0;
	for(int i=1;i<=n;++i){
		if(g[i].size()>2)root=i;
	}
	if(root==0){
		puts("1");
		return;
	}
	dfs(root,0);
	printf("%d\n",dp[root]);
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 4
1 -1 1 1
-1 1 -1 1
1 -1 1 1

*/