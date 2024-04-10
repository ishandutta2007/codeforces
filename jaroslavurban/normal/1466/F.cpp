#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// proper dsu
vector<int>p,sz;

int find(int u){return p[u]==u?u:p[u]=find(p[u]);}

void uni(int u,int v){
	u=find(u);v=find(v);
	if(u!=v){
		if(sz[u]>sz[v])swap(u,v);
		p[u]=p[v];
		sz[v]+=sz[u];
	}
}
// proper dsu


struct edge{
	int f,t;
	ll w;
	bool operator<(const edge&a)const{return w<a.w;}
};

// g has to be {weight, to}
// change input to edges if it's convenient dude
vector<edge>kruskal(vector<vector<pair<ll,int>>>&g){
	int n=g.size();
	vector<edge>edges;
	for(int i=0;i<n;++i)
		for(auto e:g[i])
			edges.push_back({i,e.second,e.first});
	sort(edges.begin(),edges.end());
	sz.assign(n,0);
	p.resize(n);iota(p.begin(),p.end(),0);
	vector<edge>res;
	for(auto e:edges)
		if(find(e.f)!=find(e.t)){
			uni(e.f,e.t);
			res.push_back(e);
		}
	return res;// edges of spaning tree
}


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n,m;cin>>n>>m;
	vector<vector<pair<ll,int>>>g(m+1);
	for(int i=0;i<n;++i){
		int u[2]={m+1,m+1};
		int k;cin>>k;
		for(int j=0;j<k;++j)cin>>u[j];
		--u[0];--u[1];
		g[u[0]].push_back({i,u[1]});
		g[u[1]].push_back({i,u[0]});
	}
	auto edges=kruskal(g);
	ll res=1;
	for(int i=0;i<edges.size();++i)res=res*2%ll(1e9+7);
	cout<<res<<" "<<edges.size()<<endl;
	for(auto e:edges)cout<<e.w+1<<" ";
	cout<<endl;
}