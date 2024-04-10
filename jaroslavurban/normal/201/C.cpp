#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

const int N=100100;
ll dp[N][3];
ll a[N],n;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n-1;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		dp[i][1]=max(dp[i][1],dp[i][0]);
		dp[i][2]=max(dp[i][2],dp[i][1]);
		if(a[i]>=2)dp[i+1][0]=max(dp[i+1][0],dp[i][0]+a[i]-a[i]%2);
		if(a[i]>=1)dp[i+1][1]=max(dp[i+1][1],dp[i][1]+a[i]-!(a[i]%2));
		if(a[i]>=2)dp[i+1][2]=max(dp[i+1][2],dp[i][2]+a[i]-a[i]%2);
	}
	ll res=0;
	for(int i=0;i<=n;++i)res=max(res,dp[i][2]);
	cout<<res<<endl;
}