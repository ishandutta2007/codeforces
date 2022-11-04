#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int a,b,c;cin>>a>>b>>c;
		int s=a+b+c;
		int r=(7*s)/9;
		if(r+(r/7)*2!=s||(7*s)%9||r%7||(r-1)/7>=a||(r-1)/7>=b||(r-1)/7>=c)cout<<"NO\n";
		else cout<<"YES\n";
	}
}