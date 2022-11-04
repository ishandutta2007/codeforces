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
		vector<ll>nums(n);
		for(int i=0;i<n;++i)cin>>nums[i];
		sort(nums.begin(),nums.end());
		ll gc=nums[0]-nums[1];
		for(int i=1;i<n-1;++i)gc=__gcd(gc,nums[i]-nums[i+1]);
		bool pos=false;
		for(int i=0;i<n;++i)if((k-nums[i])%gc==0)pos=true;
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}