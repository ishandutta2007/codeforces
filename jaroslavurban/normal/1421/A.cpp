#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		ll a,b,x=0;cin>>a>>b;	
		for(ll i=0;i<33;++i)
			if(((1<<i)&a)&&(1<<i)&b)
				x|=(1<<i);
		cout<<(x^a)+(x^b)<<endl;
	}
}