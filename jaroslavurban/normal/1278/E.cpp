#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

const int N=500010;
int a[2*N],s[N][2];
int n;
vector<int>g[N];
bool vis[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;
		--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int mxi=0;
	stack<int>q;
	vis[0]=true;
	q.push(0);
	while(!q.empty()){
		auto u=q.top();q.pop();
		for(auto v:g[u])
			if(!vis[v]){
				vis[v]=true;
				q.push(v);
				s[v][0]=++mxi;
			}
		s[u][1]=++mxi;
	}
	for(int i=0;i<n;++i)cout<<s[i][0]+1<<" "<<s[i][1]+1<<'\n';
}