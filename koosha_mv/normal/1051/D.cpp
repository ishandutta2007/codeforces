#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
long long e=998244353,dp[1099][2099][4];
int main(){
	dp[0][0][0]=1,dp[0][0][1]=1,dp[0][0][2]=1,dp[0][0][3]=1;
	long long n,k;
	cin>>n>>k;
	dp[1][2][0]=1;
	dp[1][2][1]=1;
	dp[1][1][3]=1;
	dp[1][1][2]=1;
	f(i,2,n+1){
		f(j,1,k+1){
			dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j-2][1]+dp[i-1][j-1][2]+dp[i-1][j-1][3])%e;
			dp[i][j][1]=(dp[i-1][j-2][0]+dp[i-1][j][1]+dp[i-1][j-1][2]+dp[i-1][j-1][3])%e;
			dp[i][j][2]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%e;
			dp[i][j][3]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j-1][2]+dp[i-1][j][3])%e;
		}
	}
	cout<<(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%e;

}