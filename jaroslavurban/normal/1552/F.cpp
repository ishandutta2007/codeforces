#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct P{
	int x,y,s;
	bool operator<(const P&a){return x<a.x;}
};

void ProGamerMove(){
	int n,mod=998244353;cin>>n;
	vector<P>ports(n);
	for(auto&[x,y,s]:ports)cin>>x>>y>>s;
	vector<ll>pref{0};
	ll res=ports.back().x+1;
	for(int i=0;i<n;++i){
		auto[x,y,s]=ports[i];
		int j=lower_bound(ports.begin(),ports.end(),P{y,y,y})-ports.begin();
		ll mysm=x-y+pref.back()-pref[j];
		pref.push_back((pref.back()+mysm)%mod);
		if(s)res=(res+mysm)%mod;
	}
	res=(res+mod)%mod;
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}