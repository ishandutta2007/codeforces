#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n);
	for(auto&v:a)cin>>v;
	sort(a.begin(),a.end());
	ll sm=0,tsm=accumulate(a.begin(),a.end(),0ll);
	ld res=-1e18;
	for(int i=1;i<n;++i){
		sm+=a[i-1];
		res=max(res,sm/(ld)i+(tsm-sm)/ld(n-i));
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