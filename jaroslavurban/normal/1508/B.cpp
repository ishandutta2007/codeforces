#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll n,k;cin>>n>>k;--k;
		ll mx=-1;
		for(ll i=62;i>=0;--i)if((1ll<<i)&k){mx=i;break;}
		if(mx>n-2){cout<<"-1\n";continue;}
		vector<int>res(n);iota(res.begin(),res.end(),1);
		ll strt=0;
		for(ll i=0;i<=61;++i){
			if((k&(1ll<<i))&&!(k&(1ll<<(i+1))))reverse(res.begin()+n-i-2,res.begin()+n-strt);
			if(!(k&(1ll<<i))&&(k&(1ll<<(i+1))))strt=i+1;
		}
		for(auto i:res)cout<<i<<" ";cout<<"\n";
	}
}