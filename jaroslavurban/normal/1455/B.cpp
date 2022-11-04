#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int x;cin>>x;
		int cur=0;
		int i=1;
		for(;cur+i<=x;++i)cur+=i;
		if(cur==x)cout<<i-1<<endl;
		else if(cur+i-1==x)cout<<i+1<<endl;
		else cout<<i<<endl;
	}
}