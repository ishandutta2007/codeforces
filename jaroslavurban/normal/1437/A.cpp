#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		ll l,r;cin>>l>>r;
		if(2*l>r)cout<<"YES\n";
		else cout<<"NO\n";
	}
}