#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		ll x,y,k;cin>>x>>y>>k;
		ll need=y*k+k;
		if(need<=x){
			cout<<1+k<<endl;
			continue;
		}
		cout<<1+(need-x)/(x-1)+!!((need-x)%(x-1))+k<<endl;
	}
}