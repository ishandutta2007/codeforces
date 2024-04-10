#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
vector<pair<int,int>>g[N];
int n,m;
ll dp[N][4];
#define tup tuple<ll,int,int>
// 1 = took min, 2 = took biggest

main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v,w;cin>>u>>v>>w;--u;--v;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	memset(dp,-1,sizeof(dp));
	priority_queue<tup,vector<tup>,greater<tup>>q; // dist,id,state;
	q.push({0,0,0});
	while(q.size()){
		ll dis=get<0>(q.top());
		int u=get<1>(q.top());
		int state=get<2>(q.top());
		q.pop();
		if(~dp[u][state])continue;
		dp[u][state]=dis;
		for(auto e:g[u])q.push({dis+e.first,e.second,state});
		if(!(state&1))
			for(auto e:g[u])q.push({dis+2*e.first,e.second,state|1});
		if(!(state&2))
			for(auto e:g[u])q.push({dis,e.second,state|2});
		if(!(state&3))
			for(auto e:g[u])q.push({dis+e.first,e.second,state|3});
	}
	for(int i=1;i<n;++i)cout<<dp[i][3]<<" ";cout<<endl;
}