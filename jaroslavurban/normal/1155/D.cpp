#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300010;
ll a[N];
ll dp[N][3][2]; //might,is,ended // best overall, best from here
int n,x;
main(){
	cin>>n>>x;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=n-1;i>=0;--i){
		dp[i][2][1]=max(a[i],a[i]+dp[i+1][2][1]);
		dp[i][2][0]=max(dp[i][2][1],dp[i+1][2][0]);

		dp[i][1][1]=max({x*a[i],x*a[i]+dp[i+1][1][1],x*a[i]+dp[i+1][2][1]});
		dp[i][1][0]=max({dp[i+1][1][0],dp[i][1][1],dp[i+1][2][0]});

		dp[i][0][1]=max({a[i],a[i]+dp[i+1][0][1],a[i]+dp[i+1][1][1]});
		dp[i][0][0]=max({dp[i][0][1],dp[i+1][0][0],dp[i+1][1][0]});
	}
	cout<<max(dp[0][0][0],dp[0][1][0])<<endl;
}