#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
bool can[N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	can[0]=true;
	for(int i=0;i<N;++i)
		if(can[i])
			for(ll j=11;j<ll(1e9);j=j*10+1)
				if(i+j<N)
					can[i+j]=true;
	int tc;cin>>tc;
	while(tc--){
		ll x;cin>>x;
		if(x>=N)cout<<"YES\n";
		else{
			if(can[x])cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}