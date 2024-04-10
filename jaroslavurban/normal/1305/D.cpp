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

const int N=1010;
vector<int>g[N];
bool vis[N];

int main(){
	int n;cin>>n;
	for(int i=1;i<n;++i){
		int u,v;cin>>u>>v;
		--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n/2;++i){
		int u=-1,v=-1;
		for(int i=0;i<n;++i)
			if(g[i].size()==1&&u==-1)u=i;
			else if(g[i].size()==1){v=i;break;}
		cout<<"? "<<u+1<<" "<<v+1<<endl;
		g[g[u][0]].erase(remove(g[g[u][0]].begin(),g[g[u][0]].end(),u));
		g[u].clear();
		if(g[v].size())g[g[v][0]].erase(remove(g[g[v][0]].begin(),g[g[v][0]].end(),v));
		g[v].clear();
		vis[u]=vis[v]=1;
		int w;cin>>w;	
		if(w-1==u||w-1==v){
			cout<<"! "<<w<<endl;
			return 0;
		}
	}	
	int w;
	for(int i=0;i<n;++i)if(!vis[i])w=i;
	cout<<"! "<<w+1<<endl;
}