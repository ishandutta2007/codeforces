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
 
const int N=500010;
vector<int>g[N],lvl[N];
int n,m;
int d[N],par[N];

void dfs(int u,int p){
	d[u]=d[p]+1;
	par[u]=p;
	lvl[d[u]].push_back(u);
	for(auto v:g[u])if(par[v]==-1)dfs(v,u);
}

void dfr(int u){
	cout<<u+1<<'\n';
	if(u)dfr(par[u]);
}
 
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m;
		for(int i=0;i<=n;++i)g[i].clear();
		for(int i=0;i<=n;++i)lvl[i].clear();
		for(int i=0;i<=n;++i)par[i]=-1;
		for(int i=0;i<m;++i){
			int u,v;cin>>u>>v;--u;--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		d[0]=0;
		dfs(0,0);
		if(lvl[(n+1)/2].size()){
			cout<<"PATH\n"<<(n+1)/2<<'\n';
			dfr(lvl[(n+1)/2][0]);
		}
		else{
			cout<<"PAIRING\n"<<(n+3)/4<<'\n';
			for(int i=1,pr=0;lvl[i].size()&&pr<(n+3)/4;++i)
				for(int j=0;j+1<lvl[i].size()&&pr<(n+3)/4;j+=2,++pr)
					cout<<lvl[i][j]+1<<" "<<lvl[i][j+1]+1<<'\n';
		}
	}
}