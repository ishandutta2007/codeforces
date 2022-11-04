#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n,m;cin>>n>>m;
		bool found=false;
		for(int i=0;i<n;++i){
			int a,b,c,d;cin>>a>>b>>c>>d;
			if(b==c)found=true;
		}
		if(found&&(m%2==0))cout<<"YES\n";
		else cout<<"NO\n";
	}
}