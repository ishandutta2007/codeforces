#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n,x;cin>>n>>x;
		if(n<=2)cout<<1<<endl;
		else cout<<(n-2+2*x-1)/x<<endl;
	}
}