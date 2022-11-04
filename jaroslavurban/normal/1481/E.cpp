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

const int N=500100;
int dp[N],a[N],l[N],r[N],suf[N],found[N];
int n;

//main(){
//	cin.tie(0);ios::sync_with_stdio(0);
//	cin>>n;
//	for(int i=0;i<n;++i)cin>>a[i];
//	for(int i=0;i<n;++i)r[a[i]]=i;
//	for(int i=n-1;i>=0;--i)l[a[i]]=i;
//	for(int i=n-1;i>=0;--i)suf[i]=++found[a[i]];
//	for(int i=1;i<=n;++i)dp[i]=max(dp[i-1],r[a[i-1]]==i-1?found[a[i-1]]+dp[l[a[i-1]]]:0);
//	int res=0;
//	for(int i=1;i<=n;++i)res=max(res,dp[i]+suf[i]);
//	cout<<n-res<<endl;
//}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)r[a[i]]=i;
	for(int i=n-1;i>=0;--i)l[a[i]]=i;
	for(int i=n-1;i>=0;--i)suf[i]=++found[a[i]];
	int res=0;
	for(int i=0;i<n;++i){
		dp[i]=max(i?dp[i-1]:0,r[a[i]]==i?(l[a[i]]?dp[l[a[i]]-1]:0)+found[a[i]]:0);
		res=max(res,dp[i]+suf[i+1]);
	}
	cout<<n-res<<endl;
	// sry
}