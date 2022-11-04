#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,k1,k2,w,b;cin>>n>>k1>>k2>>w>>b;
		w-=min(k1,k2);
		b-=n-max(k1,k2);
		w-=abs(k1-k2)/2;
		b-=abs(k1-k2)/2;
		if(w<=0&&b<=0)cout<<"YES\n";
		else cout<<"NO\n";
	}
}