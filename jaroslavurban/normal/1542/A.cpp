#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	int sm=0;
	for(int i=0;i<2*n;++i){
		int a;cin>>a;sm+=a&1;
	}
	if(sm==n)cout<<"Yes\n";
	else cout<<"No\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}