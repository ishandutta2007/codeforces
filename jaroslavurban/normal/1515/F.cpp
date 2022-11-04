#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100;
vector<pair<int,int>>g[N];
ll a[N];
int vis[N];
int n,m,x;
vector<int>fr,rv;

void dfs(int u){
	vis[u]=true;
	for(auto[i,v]:g[u]){
		if(vis[v])continue;
		dfs(v);
		if(a[u]+a[v]>=x){
			a[u]=a[u]+a[v]-x;
			fr.push_back(i);
		}else rv.push_back(i);
	}
}


signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>x;
	for(int i=0;i<n;++i)cin>>a[i];
	if(accumulate(a,a+n,0ll)<x*ll(n-1)){cout<<"NO\n";return 0;}
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back({i,v});
		g[v].push_back({i,u});
	}
	dfs(0);
	cout<<"YES\n";
	for(auto f:fr)cout<<f+1<<"\n";
	reverse(rv.begin(),rv.end());
	for(auto r:rv)cout<<r+1<<"\n";
}