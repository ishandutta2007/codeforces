#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n=2,m;cin>>m;
	vector<vector<int>>f(2,vector<int>(m)),pref(f);
	for(auto&vec:f)
		for(auto&v:vec)
			cin>>v;
	for(int i=0;i<2;++i)partial_sum(f[i].begin(),f[i].end(),pref[i].begin());
	int sm=pref[0][m-1]+pref[1][m-1],res=INT_MAX;
	auto query=[&](int l,int r,int i){
		return (r-1>=0?pref[i][r-1]:0)-(l-1>=0?pref[i][l-1]:0);
	};
	for(int i=0;i<m;++i)res=min(res,max(query(i+1,m,0),query(0,i,1)));
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}