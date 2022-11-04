#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	ll n,x,t;cin>>n>>x>>t;
	ll in=min(n,t/x);
	ll goodk=n-in;
	ll res=in*goodk;
	res+=in*(in-1)/2;
	cout<<res<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}