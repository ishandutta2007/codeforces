#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
pair<ll,ll>ranges[N];
int n;
ll s;

bool pos(ll m){
	ll sm=0;
	vector<pair<ll,ll>>r;
	for(int i=0;i<n;++i)if(ranges[i].second>=m)r.push_back(ranges[i]);
	else sm+=ranges[i].first;
	if(r.size()<=n/2)return false;
	sort(r.begin(),r.end());
	for(int i=0;i<r.size();++i)if(r.size()-i-1>=n/2+1)sm+=r[i].first;
	else sm+=max(r[i].first,m);
	return sm<=s;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>s;
		for(int i=0;i<n;++i)cin>>ranges[i].first>>ranges[i].second;
		ll l=0,r=s+1;
//		for(int i=0;i<=s;++i)cout<<pos(i)<<endl;
		while(l<r){
			ll m=(l+r)/2;
			if(pos(m))l=m+1;
			else r=m;
		}
		cout<<l-1<<endl;
	}
}