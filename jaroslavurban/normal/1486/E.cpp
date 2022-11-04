#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

const int N=200100,W=55;
vector<pair<int,int>>g[N];
ll dp[N][W];
int n,m;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v,w;cin>>u>>v>>w;--u;--v;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	memset(dp,-1,sizeof(dp));
	priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>>q;
	q.push({0,0,0});
	while(q.size()){
		ll c=get<0>(q.top());
		int w=get<1>(q.top());
		int u=get<2>(q.top());
		q.pop();
		if(~dp[u][w])continue;
		dp[u][w]=c;
		for(auto e:g[u])if(dp[e.second][w?0:e.first]==-1)q.push({c+2*w*e.first+e.first*e.first,w?0:e.first,e.second});
	}
	for(int i=0;i<n;++i)cout<<dp[i][0]<<" ";cout<<endl;
}