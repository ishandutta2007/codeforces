#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	ll n,a,b;cin>>n>>a>>b;
	for(ll cn=1;cn<=n;cn*=a){
		ll cx=n-cn;
		if(cx%b){
			if(a==1)break;
			continue;
		}
		cx/=b;
		cout<<"Yes\n";
		return;
	}
	cout<<"No\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}