#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,k;cin>>n>>k;
		ll res=1;
		for(int i=0;i<k;++i)res=res*n%ll(1e9+7);
		cout<<res<<endl;
	}
}