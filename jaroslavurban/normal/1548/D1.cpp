#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	array<array<ll,2>,2>cnt={};
	for(int i=0,x,y;i<n;++i)cin>>x>>y,++cnt[x>>1&1][y>>1&1];
	ll res=0;
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			res+=cnt[i>>1][i&1]*(cnt[i>>1][i&1]-1)*(cnt[j>>1][j&1]-(i==j)*2)/(2+4*(i==j));
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}