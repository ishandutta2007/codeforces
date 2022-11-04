#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		int prev=1e9+1;
		bool dec=true;
		for(int i=0;i<n;++i){
			int a;cin>>a;
			if(a<prev)prev=a;
			else dec=false;
		}
		if(dec)cout<<"NO\n";
		else cout<<"YES\n";
	}
}