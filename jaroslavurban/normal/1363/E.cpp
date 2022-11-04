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
#define inf 1e9+1

vector<vector<int>>g;
vector<int>a,b,c;

ll res;
pair<int,int> solve(int u,int p,int bp){
	int zeros=0,ones=0;
	for(int v:g[u])if(p!=v){
		auto p=solve(v,u,min(bp,a[v]));
		zeros+=p.first;ones+=p.second;
	}
	if(b[u]!=c[u]){
		zeros+=c[u];ones+=!c[u];
	}
	int over=min(zeros,ones);
	res+=2*over*ll(bp);
	zeros-=over;
	ones-=over;
	return {zeros,ones};
}

int main(){
	int n;cin>>n;
	g.resize(n);a.resize(n);b.resize(n);c.resize(n);
	for(int i=0;i<n;++i)cin>>a[i]>>b[i]>>c[i];
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto p=solve(0,0,a[0]);
	if(!p.first&&!p.second)cout<<res<<endl;
	else cout<<-1<<endl;
}