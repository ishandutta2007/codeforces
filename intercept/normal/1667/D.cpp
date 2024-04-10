#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=2e5+9;
int n,flag=0;
int dp[M];
vector<int>g[M],s[M][2];
vector<pii>ans;
void dfs(int u,int fa){
	if(fa&&g[u].size()==1)return;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			if(dp[v]){
				s[u][0].emplace_back(v);
			}
			else s[u][1].emplace_back(v);
		}
	}
	for(int i=0;i<min(s[u][0].size(),s[u][1].size());++i){
   		if(g[u].size()%2==1)ans.emplace_back(u,s[u][1][i]);
		ans.emplace_back(u,s[u][0][i]);
		ans.emplace_back(s[u][0][i],dp[s[u][0][i]]);
		if(g[u].size()%2==0)ans.emplace_back(u,s[u][1][i]);
	}
	if(s[u][0].size()==s[u][1].size())return;
	if(s[u][0].size()==s[u][1].size()+1){
		if(u!=1){
			int x=*s[u][0].rbegin();
			ans.emplace_back(u,x);
			ans.emplace_back(x,dp[x]);
		}
		else {
			//puts("NO");
			flag=1;
		}
		return;
	}
	if(s[u][0].size()==s[u][1].size()-1){
		int x=*s[u][1].rbegin();
		if(u==1){
			ans.emplace_back(u,x);
		}
		else{
			dp[u]=x;
		}
		return;
	}
	if(s[u][0].size()==s[u][1].size()-2){
		if(u==1){
			//puts("NO");
			flag=1;
		}
		else{
			int x=*s[u][1].rbegin();
			dp[u]=x;
			ans.emplace_back(u,s[u][1][s[u][1].size()-2]);
		}
		return;
	}
	//puts("NO");
	flag=1;
}
int ca=0;
void work(){
	++ca;
	scanf("%d",&n);
	flag=0;
	ans.clear();
	for(int i=1;i<=n;++i)dp[i]=0,g[i].clear(),s[i][0].clear(),s[i][1].clear();
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1,0);
	if(flag){
		puts("NO");
	}
	else{
		puts("YES");
		for(auto o:ans){
			printf("%d %d\n",o.fi,o.se);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
3
8
1 3
3 8
8 6
6 2
6 7
7 5
3 4
5
1 2
1 3
1 4
4 5
5
1 2
2 3
2 4
4 5
*/