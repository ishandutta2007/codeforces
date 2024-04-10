#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		bool res=false;
		for(int i=0;i<n;++i){
			int a;cin>>a;
			bool pos=true;
			for(int j=1;j*j<=a;++j)if(j*j==a){pos=false;break;}
			res|=pos;
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
}