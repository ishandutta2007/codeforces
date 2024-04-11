#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
long long dp[200099][2],n,c,a[200099],x;
int main(){
	dp[0][1]=1e18;
	cin>>n>>c;
	f(i,1,n)
		cin>>a[i];
	cout<<0<<" ";
	f(i,1,n){
		cin>>x;
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i];
		dp[i][1]=min(dp[i-1][0]+c,dp[i-1][1])+x;
		cout<<min(dp[i][0],dp[i][1])<<" ";
	}
}