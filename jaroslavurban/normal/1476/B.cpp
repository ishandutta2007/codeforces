#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		ll n,k;cin>>n>>k;
		vector<ll>p(n);
		for(int i=0;i<n;++i)cin>>p[i];
		ll sm=p[0];
		ll res=0;
		for(int i=1;i<n;++i){
			res=max((p[i]*100)/k+!!(p[i]*100%k)-sm,res);
			sm+=p[i];
		}
		cout<<res<<endl;
	}
}