#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll n;cin>>n;
		bool pos=false;
		for(int i=0;i*2020<=n;++i)
			if((n-i*2020)%2021==0)
				pos=true;
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}