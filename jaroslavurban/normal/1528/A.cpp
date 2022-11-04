#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int l[N],r[N];
vector<int>g[N];
int n;

pair<ll,ll>dfs(int u,int p){
	ll resl=0,resr=0;
	for(auto v:g[u])if(v!=p){
		auto[s,t]=dfs(v,u);
		resl+=max(s+abs(l[u]-l[v]),t+abs(l[u]-r[v]));
		resr+=max(s+abs(r[u]-l[v]),t+abs(r[u]-r[v]));
	}
	return {resl,resr};
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		for(int i=0;i<n;++i)g[i].clear();
		for(int i=0;i<n;++i)cin>>l[i]>>r[i];
		for(int i=0;i<n-1;++i){
			int u,v;cin>>u>>v;--u;--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		auto[l,r]=dfs(0,0);
		cout<<max(l,r)<<"\n";
	}
}