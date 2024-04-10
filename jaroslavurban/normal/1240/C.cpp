#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500100;
vector<pair<int,int>>g[N];
vector<ll>diff[N];
ll dp[N][2];
ll n,k;

ll dfs(int u,int p,int mns){
	if(~dp[u][mns])return dp[u][mns];
	dp[u][0]=dp[u][1]=0;
	for(auto e:g[u])if(e.first!=p)dp[u][1]=(dp[u][0]+=dfs(e.first,u,0));
	for(auto e:g[u])if(e.first!=p)diff[u].push_back(dfs(e.first,u,1)-dfs(e.first,u,0)+e.second);
	sort(diff[u].rbegin(),diff[u].rend());
	for(int i=0;i<diff[u].size()&&i<k&&diff[u][i]>0;++i){
		dp[u][0]+=diff[u][i];
		if(i<k-1)dp[u][1]=dp[u][0];
	}
	return dp[u][mns];
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>k;
		for(int i=0;i<n;++i)for(int j=0;j<2;++j)dp[i][j]=-1;
		for(int i=0;i<n;++i)diff[i].clear();
		for(int i=0;i<n;++i)g[i].clear();
		for(int i=0;i<n-1;++i){
			int u,v,w;cin>>u>>v>>w;--u;--v;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		cout<<dfs(0,0,0)<<endl;
	}
}