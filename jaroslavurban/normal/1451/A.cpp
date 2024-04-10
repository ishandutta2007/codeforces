#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		ll n;cin>>n;
		if(n==1){cout<<0<<endl;continue;}
		if(n==2){cout<<1<<endl;continue;}
		if(n==3){cout<<2<<endl;continue;}
		if(n%2==0){cout<<2<<endl;continue;}
		if(n%2==1){cout<<3<<endl;continue;}
	}
}