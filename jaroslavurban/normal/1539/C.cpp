#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	ll n,k,x;cin>>n>>k>>x;
	vector<ll>a(n),diffs;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=0;i+1<n;++i)if(a[i+1]-a[i]>x)diffs.push_back((a[i+1]-a[i]-1)/x);
	sort(diffs.begin(),diffs.end());
	ll groups=diffs.size()+1;
	for(int i=0;i<diffs.size();++i)if(k>=diffs[i]){
		--groups;k-=diffs[i];
	}
	cout<<groups<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}