#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	ll tt;cin>>tt;
	while(tt--){
		ll a,b;cin>>a>>b;
		if(a%b){cout<<a<<endl;continue;}
		unordered_map<ll,ll>pall,pb;
		ll bb=b,aa=a;
		for(ll i=2;i*i<=bb;++i)
			if(bb%i==0){
				while(bb%i==0){++pb[i];bb/=i;}
				while(aa%i==0){++pall[i];aa/=i;}
			}
		if(bb!=1){while(aa%bb==0){++pall[bb];aa/=bb;}}	
		if(bb!=1){pb[bb]=1;bb/=bb;}
		ll bst=1e18;
		for(auto it:pb){
			ll lost=pall[it.first]-(it.second-1);
			ll lst=1;
			while(lost--)lst*=it.first;
			bst=min(bst,lst);
		}
		cout<<a/bst<<endl;
	}
}