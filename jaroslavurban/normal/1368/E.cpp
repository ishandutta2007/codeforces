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

const int N=200001;
vector<int>g[N];
int d[N];

int main(){
	cin.tie(0);ios_base::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=0;i<n;++i){g[i].clear();d[i]=0;}
		for(int i=0;i<m;++i){
			int u,v;cin>>u>>v;--u;--v;
			g[u].push_back(v);
		}
		vector<int>res;
		for(int u=0;u<n;++u){
			if(d[u]<2)for(auto v:g[u])d[v]=max(d[v],d[u]+1);
			else res.push_back(u);
		}
		cout<<res.size()<<endl;
		for(auto u:res)cout<<u+1<<" ";
		cout<<endl;
	}
}