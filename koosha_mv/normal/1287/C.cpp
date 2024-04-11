#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
int n,dp[103][103][2],a[103],z;
int main(){
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(i,0,103){f(j,0,103) dp[i][j][0]=dp[i][j][1]=1e9;}dp[0][0][0]=0;dp[0][0][1]=0;
	f(i,1,n+1){
		f(j,0,i+1){
			if(a[i]%2==0) dp[i][j][0]=min(dp[i-1][j-1][0],dp[i-1][j-1][1]+1);
			if(a[i]%2==1 || a[i]==0) dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1]);
		}
	}
	cout<<min(dp[n][n/2][0],dp[n][n/2][1]);
}