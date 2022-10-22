#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n;
ll dp[M][2],s[M][2],ans[M];
vector<int>g[M];
bool cmp(int u){
	return dp[u][0]==dp[u][1]?s[u][0]>s[u][1]:dp[u][0]<dp[u][1];
}
void dfs(int u,int fa){
	s[u][0]=1;
	s[u][1]=g[u].size();
	dp[u][1]=1;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
			s[u][0]+=s[v][cmp(v)];
			s[u][1]+=s[v][0];
		}
	}
} 

void solve(int u,int fa,int o){
	if(o)ans[u]=g[u].size();
	else ans[u]=1;
	for(auto v:g[u]){
		if(v!=fa){
			int no=o?0:cmp(v);
			solve(v,u,no);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	if(n==2){
		cout<<"2 2\n1 1";
		return 0;
	}
	dfs(1,0);
	cout<<dp[1][cmp(1)]<<" "<<s[1][cmp(1)]<<endl;
	solve(1,0,cmp(1));
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	return 0;
}