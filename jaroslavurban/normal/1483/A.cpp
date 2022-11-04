#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,m;cin>>n>>m;
		vector<vector<int>>g(m);
		vector<int>cnts(n),res(m);
		pair<int,int>mx={0,0};
		for(int i=0;i<m;++i){
			int cnt;cin>>cnt;
			for(int j=0;j<cnt;++j){
				int v;cin>>v;--v;
				g[i].push_back(v);
			}
			mx=max(mx,{++cnts[g[i][0]],g[i][0]});
			res[i]=g[i][0];
		}
		for(int i=0;i<m;++i){
			if(mx.first<=(m+1)/2)break;
			if(g[i][0]==mx.second&&g[i].size()>=2){
				--mx.first;
				res[i]=g[i][1];
			}
		}
		if(mx.first<=(m+1)/2){
			cout<<"YES\n";
			for(auto r:res)cout<<r+1<<" ";cout<<"\n";
		}
		else cout<<"NO\n";
	}
}