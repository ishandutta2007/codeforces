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

const int N=1010;
vector<int>g[N];
int n,m;
bool vis[N];
int par[N];
vector<int>nodes;

void construct(int u){
	nodes.push_back(u);
	if(par[u]!=u)construct(par[u]);
}

pair<int,int>getmid(int u){
	nodes.clear();
	bool dep[N]={};
	queue<int>q;
	q.push(u);
	dep[u]=1;
	while(!q.empty()){
		u=q.front();q.pop();
		vis[u]=true;
		for(auto v:g[u])
			if(!dep[v]){
				dep[v]=dep[u]+1;
				q.push(v);
			}
	}
	for(int i=0;i<N;++i)dep[i]=0;
	q.push(u);
	dep[u]=1;
	par[u]=u;
	while(!q.empty()){
		u=q.front();q.pop();
		for(auto v:g[u])
			if(!dep[v]){
				dep[v]=dep[u]+1;
				q.push(v);
				par[v]=u;
			}
	}
	construct(u);
	return {nodes.size(),nodes[nodes.size()/2]};
}


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<pair<int,int>>mids;
	for(int i=0;i<n;++i)
		if(!vis[i])
			mids.push_back(getmid(i));
	sort(mids.begin(),mids.end());
	reverse(mids.begin(),mids.end());
	int res=0;
	if(mids.size()>=1)res=max(res,mids[0].first);
	if(mids.size()>=2)res=max(res,(mids[0].first+2)/2+(mids[1].first+2)/2);
	if(mids.size()>=3)res=max(res,1+(mids[1].first+2)/2+(mids[2].first+2)/2);
	cout<<res-1<<endl;
	for(int i=1;i<mids.size();++i)
		cout<<mids[0].second+1<<" "<<mids[i].second+1<<endl;
}