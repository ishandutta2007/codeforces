#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n+3);
	for(int i=1;i<=n;++i)cin>>a[i];
	ll res=0;
	for(int i=1;i<=n+1;++i){
		res+=abs(a[i]-a[i-1]);
		res-=max(0,a[i]-max(a[i-1],a[i+1]));
	}
	cout<<res<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}