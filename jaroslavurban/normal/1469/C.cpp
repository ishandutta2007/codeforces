#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll n,k;cin>>n>>k;
		vector<ll>h(n);
		for(int i=0;i<n;++i)cin>>h[i];
		ll mn=h[0],mx=h[0];
		bool pos=true;
		for(int i=1;i<n;++i){
			if(h[i]>mx+(k-1)||h[i]+(k-1)<mn-(k-1)){pos=false;break;}
			ll nmn=max(h[i],mn-(k-1));
			ll nmx=min(h[i]+(k-1),mx+(k-1));
			if(nmn>nmx){pos=false;break;}
			mn=nmn;mx=nmx;
		}
		if(pos&&mn==h[n-1])cout<<"YES\n";
		else cout<<"NO\n";
	}
}