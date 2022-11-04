#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>d(n);
	for(int i=0;i<n;++i)cin>>d[i];
	sort(d.begin(),d.end());
	ll res=d.back(),psm=0,cnt=0;
	for(int i=1;i<n;++i){
		ll csm=psm+(cnt+1)*(d[i]-d[i-1]);
		++cnt;
		res-=csm;
		psm=csm;
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}