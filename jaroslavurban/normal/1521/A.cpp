#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll a,b;cin>>a>>b;
		if(b==1)cout<<"NO\n";
		else if(b==2){
			cout<<"YES\n";
			cout<<a<<" "<<3*a<<" "<<4*a<<endl;
		}
		else{
			cout<<"YES\n";
			cout<<(b-1)*a<<" "<<a<<" "<<a*b<<"\n";
		}
	}
}