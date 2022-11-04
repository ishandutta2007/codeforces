#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N=200100;
int fibs[N];
unordered_set<int>g[N];
map<pair<int,int>,int>dp;
 
bool isfib(int root,int sz){
	if(!fibs[sz])return false;
	if(sz==1)return true;
	if(dp.count({root,sz}))return dp[{root,sz}];
	bool pos=false;
	function<int(int,int)>dfsz=[&](int u,int p){
		int res=1;
		vector<int>sg(g[u].begin(),g[u].end());
		for(auto v:sg)if(v!=p){
			int brsz=dfsz(v,u);
			if(pos)return 1;
			if(fibs[brsz]&&fibs[sz-brsz]){
				g[u].erase(v);
				g[v].erase(u);

				if(isfib(v,brsz)&&isfib(root,sz-brsz))pos=true;
				g[u].insert(v);
				g[v].insert(u);
			}
			if(pos)return 1;
			res+=brsz;
		}
		return res;
	};
	dfsz(root,root);
	return dp[{root,sz}]=pos;
}
 
main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int f1=0,f2=1;
	for(int i=0;i<30;++i){
		int tmp=f1+f2;
		f1=f2;
		f2=tmp;
		if(f2<N)fibs[f2]=true;
	}
	int n;cin>>n;
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].insert(v);
		g[v].insert(u);
	}
	cout<<(isfib(0,n)?"YES\n":"NO\n");
}