#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll n;cin>>n;
		int res=0;
		while(n>=2050){
			ll num=2050;
			while(num*10<=n)num*=10;
			n-=num;
			++res;
		}
		if(n)cout<<-1<<"\n";
		else cout<<res<<"\n";
	}
}