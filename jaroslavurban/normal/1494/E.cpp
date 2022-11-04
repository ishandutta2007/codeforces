#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

set<pair<int,int>>same,diff;
map<pair<int,int>,char>g;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n,m;cin>>n>>m;
	while(m--){
		char t;cin>>t;
		if(t=='+'){
			int u,v;char c;cin>>u>>v>>c;
			g[{u,v}]=c;
			if(g.count({v,u})){
				diff.insert({u,v});
				diff.insert({v,u});
				if(g[{v,u}]==c){
					same.insert({u,v});
					same.insert({v,u});
				}
			}
		}
		else if(t=='-'){
			int u,v;cin>>u>>v;
			g.erase({u,v});
			diff.erase({u,v});
			diff.erase({v,u});
			same.erase({u,v});
			same.erase({v,u});
		}else if(t=='?'){
			int k;cin>>k;
			if(same.size()||((k&1)&&diff.size()))cout<<"YES\n";
			else cout<<"NO\n";
		}else assert(0);
	}
}