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

const int N = 1<<20;
int n;
int part[N][2];
bool vis[N];
vector<pair<int,int>>g[N];
vector<int>res;

void dfs(int u){
	vis[u]=true;
	for(auto v:g[u])
		if(!vis[v.first])
			dfs(v.first);
}

bool check(int mask){
	for(int i=0;i<=mask;++i)g[i].clear(),vis[i]=false;
	for(int i=0;i<n;++i){
		int u=part[i][0]&mask;
		int v=part[i][1]&mask;
		g[u].push_back({v,2*i+1});
		g[v].push_back({u,2*i});
	}
	int c=0;
	for(int i=0;i<=mask;++i)
		if(g[i].size()%2)return false;
		else if(!vis[i]&&g[i].size()){
			++c;
			dfs(i);
		}
//	for(int i=0;i<=mask;++i){
//		cerr<<i<<endl;
//		for(auto u:g[i])cerr<<u.second<<" ";
//		cerr<<endl;
//	}
	return c==1;
}

void construct(int u,int id=-1){
	//cerr<<id+1<<" "<<(id^1)+1<<endl;
	while(g[u].size()){
		auto v=g[u].back();g[u].pop_back();
		if(vis[v.second/2])continue;
		vis[v.second/2]=true;
		construct(v.first,v.second);
	}
	if(~id){
		res.push_back(id);
		res.push_back(id^1);
	}
}

int build(int mask){
	for(int i=0;i<n;++i)vis[i]=false;
	for(int i=0;1;++i)
		if(g[i].size()){
			construct(i);
			break;
		}
	cout<<mask<<endl;
	for(auto u:res)cout<<u+1<<" ";
	cout<<endl;
	return 0;
}

int main(){
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>part[i][0]>>part[i][1];
	for(int i=20;i>=0;--i)
		if(check((1<<i)-1))
			return build(i);
}