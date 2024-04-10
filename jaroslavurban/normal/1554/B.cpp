#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,k,mx=300;cin>>n>>k;
	vector<int>a(n);
	for(auto&v:a)cin>>v;
	ll res=LLONG_MIN;
	for(int j=0;j<n;++j)
		for(int i=j-1;i>=max(j-mx,0);--i)
			res=max(res,(i+1)*ll(j+1)-k*ll(a[i]|a[j]));
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