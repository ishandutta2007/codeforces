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

const int N=100100;
ll dp[N];
ll a[N],b[N],c[N];
int n;

ll solvedp(int i){
	if(i<0)return 0;
	if(~dp[i])return dp[i];
	if(a[i+1]==b[i+1])return dp[i]=0;
	return dp[i]=max(abs(a[i+1]-b[i+1]),i?(c[i]-max(a[i+1],b[i+1])+min(a[i+1],b[i+1])+1+solvedp(i-1)):0);
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>c[i];
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)cin>>b[i];
		for(int i=0;i<n;++i)dp[i]=-1;
		ll res=0;
		for(int i=1;i<n;++i){
			res=max(res,c[i]+solvedp(i-1)+1);
		}
		cout<<res<<endl;
	}
}