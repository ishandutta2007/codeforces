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
		int n;cin>>n;
		vector<int>a(n),pref(n,-1),suf(n,-1);
		for(int i=0;i<n;++i)cin>>a[i];
		pref[0]=suf[n-1]=0;
		for(int i=1;i<n;++i){
			pref[i]=a[i-1]-pref[i-1];
			if(a[i]-pref[i]<0)break;
		}
		for(int i=n-2;i>=0;--i){
			suf[i]=a[i+1]-suf[i+1];
			if(a[i]-suf[i]<0)break;
		}
		bool pos=pref[n-1]==a[n-1];
		for(int i=0;i<n-1;++i)
			if(~pref[i]&&~suf[i+1]&&a[i+1]>=pref[i]&&a[i+1]-pref[i]==a[i]-suf[i+1])
				pos=true;
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}