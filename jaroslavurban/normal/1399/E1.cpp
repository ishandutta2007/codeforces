#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

const int N=100100;
ll n,s;
vector<pair<int,int>>g[N];
priority_queue<pair<ll,ll>>q;//total,k
ll sm;
vector<int>nc,ww;

int dfs(int u,int p){
	int c=0;
	for(auto e:g[u])if(p!=e.first){
		int cc=dfs(e.first,u);
		sm+=(ll)cc*e.second;
		q.push({(ll)cc*e.second-(ll)cc*(e.second/2),nc.size()});
		nc.push_back(cc);
		ww.push_back(e.second);
		c+=cc;
	}
	return c+(c==0);
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>s;
		sm=0;
		nc.clear();
		ww.clear();
		for(int i=0;i<n;++i)g[i].clear();
		while(q.size())q.pop();
		for(int i=0;i<n-1;++i){
			int u,v,w;cin>>u>>v>>w;
			--u;--v;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		dfs(0,0);
		int res=0;
		while(sm>s){
			auto e=q.top();q.pop();
			sm-=e.first;
			assert(e.second<ww.size());
			assert(ww.size()==nc.size());
			ww[e.second]/=2;
			q.push({(ll)nc[e.second]*ww[e.second]-(ll)nc[e.second]*(ww[e.second]/2),e.second});
			++res;
		}
		cout<<res<<endl;
	}
}