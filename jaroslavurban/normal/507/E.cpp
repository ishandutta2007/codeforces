#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

#define inf 1e9

vector<vector<pair<int,int>>>g;

int main(){
	int n,m;cin>>n>>m;
	g.resize(n);
	int ones=0;
	vector<tuple<int,int,int>>roads(m);
	for(int i=0;i<m;++i){
		int u,v,k;cin>>u>>v>>k;
		roads[i]={u,v,!k};
		ones+=k;
		--u;--v;
		g[u].push_back({v,k});
		g[v].push_back({u,k});
	}
	vector<int>dist(n);
	vector<int>broken(n);
	dist[0]=1;
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto e:g[u]){
			int v=e.first;
			bool b=e.second;
			if(!dist[v]){
				broken[v]=broken[u]+!b;
				dist[v]=dist[u]+1;
				q.push(v);
			}
			if(dist[v]-1==dist[u])broken[v]=min(broken[v],broken[u]+!b);
		}
	}
	set<pair<int,int>>uneffected;
	set<pair<int,int>>repaired;
	int u=n-1;
	while(u){
		int mndist=inf,mnbr=inf,v;
		bool br;
		for(auto e:g[u])
			if((dist[e.first]==mndist&&broken[e.first]+!e.second<mnbr)||dist[e.first]<mndist){
				v=e.first;
				mndist=dist[v];
				mnbr=broken[v]+!e.second;
				br=!e.second;
			}
		if(!br)uneffected.insert({u,v});
		else repaired.insert({u,v});
		u=v;
	}
	cout<<ones-uneffected.size()+repaired.size()<<endl;
	for(int i=0;i<m;++i){
		int u=get<0>(roads[i]),v=get<1>(roads[i]),z=get<2>(roads[i]);
		pair<int,int>xd={u-1,v-1};
		pair<int,int>dx={v-1,u-1};
		if(!uneffected.count(xd)&&!uneffected.count(dx)&&(!z||repaired.count(xd)||repaired.count(dx)))
			cout<<u<<" "<<v<<" "<<z<<endl;
	}
}