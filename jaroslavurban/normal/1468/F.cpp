#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;


struct pair_hash{
	inline size_t operator()(const pair<int,int>&p) const{
		return (ll(p.first)*31+p.second)%ll(1e9+7);
	}
};

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		unordered_map<pair<int,int>,int,pair_hash>upper,lower;
		for(int i=0;i<n;++i){
			int x,y,dx,dy;cin>>x>>y>>dx>>dy;
			if(dy-y==0){
				if(dx-x>0)++upper[make_pair(0,0)];
				else ++lower[make_pair(0,0)];
			}
			else{
				int ddx=dx-x,ddy=dy-y;
				if(dy-y<0)++lower[make_pair(ddx/__gcd(ddx,ddy),ddy/__gcd(ddx,ddy))];
				else ++upper[make_pair(ddx/__gcd(ddx,ddy),ddy/__gcd(ddx,ddy))];
			}
		}
		ll res=0;
		for(auto it=lower.begin();it!=lower.end();++it){
			res+=ll(it->second)*upper[it->first];
		}
		cout<<res<<endl;
	}
}