#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		ll a,b,c,d;cin>>a>>b>>c>>d;
		if(c<=d){
			if(b*c>=a)cout<<a<<endl;
			else cout<<-1<<endl;
			continue;
		}
		if(b*d>=a){
			cout<<a<<endl;
			continue;
		}
		if(d*(c/d)*b+(c%d)*b<a){
			cout<<-1<<endl;
			continue;
		}
		ll x=a/(b*d)+!!(a%(b*d));
		cout<<a*x-b*d*((x-1)*x/2)<<endl;
	}
}