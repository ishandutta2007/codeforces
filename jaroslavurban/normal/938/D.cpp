#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);



const int N=200010;
const ll inf=1e18;
vector<pair<int,ll>>g[N];
ll pr[N];
ll bpr[N];
int n,m;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		ll u,v,w;cin>>u>>v>>w;--u;--v;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=0;i<n;++i)cin>>pr[i];
	for(int i=0;i<n;++i)bpr[i]=pr[i];

	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	for(int i=0;i<n;++i)q.push({pr[i],i});
	while(!q.empty()){
		auto u=q.top();q.pop();
		if(u.first!=bpr[u.second])continue;
		for(auto e:g[u.second])
			if(bpr[e.first]>u.first+2*e.second){
				bpr[e.first]=u.first+2*e.second;
				q.push({bpr[e.first],e.first});
			}
	}
	for(int i=0;i<n;++i)cout<<bpr[i]<<" ";cout<<endl;
}