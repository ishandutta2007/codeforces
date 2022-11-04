#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	ll sm=0;
	int n;cin>>n;
	for(int i=0;i<n;++i){
		int a;cin>>a;
		sm+=a;
	}
	ll def=sm/n;
	ll over=sm-def*n;
	cout<<over*(n-over)<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}