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

const int N=26;
set<int>g[N]={};
bool vis[N]={};
bool d[N]={};

void dfs(int u){
	if(vis[u])return;
	vis[u]=true;
	for(auto v:g[u])
		dfs(v);
}
int main(){
	ll n;cin>>n;
	for(int i=0;i<n;++i){
		string s;cin>>s;
		sort(s.begin(),s.end());
		s.erase(unique(s.begin(),s.end()),s.end());
		for(int j=0;j<s.size();d[s[j]-'a']=true,++j)
			for(int k=j+1;k<s.size();++k){
				g[s[j]-'a'].insert(s[k]-'a');
				g[s[k]-'a'].insert(s[j]-'a');
			}
	}
	ll res=0;
	for(int i=0;i<N;++i)if(!vis[i]&&d[i]){dfs(i);++res;}
	cout<<res<<endl;
}