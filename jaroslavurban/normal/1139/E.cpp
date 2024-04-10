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

const int N=5000;
vector<int>g[N]; //potential -> club
int p[N],c[N],R[N],res[N],vis[N];
vector<pair<int,int>>e;
int m,n,d;

bool dfs(int potential){
	if(potential==N||g[potential].empty()||vis[potential])return false;
	vis[potential]=true;
	for(auto club:g[potential]){
		if(R[club]==-1||dfs(R[club])){
			R[club]=potential;
			return true;
		}
	}
	return false;
}

int main(){
	cin>>m>>n;
	for(int i=0;i<m;++i)cin>>p[i];
	for(int i=0;i<m;++i){
		cin>>c[i];--c[i];
		g[p[i]].push_back(c[i]);
	}
	memset(R,-1,sizeof(R));
	cin>>d;
	for(int i=0;i<d;++i){
		int s;cin>>s;--s;
		e.push_back({p[s],c[s]});
		auto it=g[p[s]].begin();
		for(;*it!=c[s];++it){}
		g[p[s]].erase(it);
	}
	int cur=0;
	for(int i=0;i<d;++i){
		memset(vis,0,sizeof(vis[0])*(cur+1));
		while(dfs(cur)){++cur;memset(vis,0,sizeof(vis[0])*(cur+1));}
//		cerr<<cur<<endl;
//		cerr<<e.back().first<<" "<<e.back().second<<endl;
		g[e.back().first].push_back(e.back().second);
		res[d-i-1]=cur;
		e.pop_back();
	}
	for(int i=0;i<d;++i)cout<<res[i]<<endl;
}