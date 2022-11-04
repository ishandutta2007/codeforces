#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	ll n;cin>>n;
	ll res=LLONG_MAX;
	for(ll a=0;a<=10;++a)
		for(ll b=0;b<=10;++b)
			for(ll c=0;c<=10;++c){
				ll slices=a*6+b*8+c*10;
				ll tim=a*15+b*20+c*25;
				if(slices<=n){
					res=min(res,tim+(n-slices+5)/6*15);
				}else res=min(res,tim);
			}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}