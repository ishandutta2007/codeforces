#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int e=-(1e9),n,mat[301][301],dp[301*2][301][301];
int main(){
	cin>>n;
	f(i,1,n+1){f(j,1,n+1){cin>>mat[i][j];}}
	f(i,2,2*n+1){dp[i][0][0]=e,dp[i][i][i]=e,dp[i][i][0]=e,dp[i][0][i]=e;}
	memset(dp,0xcc,sizeof(dp));
	dp[2][1][1]=mat[1][1];
	f(i,3,n*2+1){
		f(j,1,min(i,n+1)){
			f(k,1,min(i,n+1)){
				if(i-k<=n && i-j<=n){
					dp[i][j][k]=max(max(dp[i-1][j-1][k-1],dp[i-1][j-1][k]),max(dp[i-1][j][k-1],dp[i-1][j][k]))+mat[j][i-j]+mat[k][i-k]-((j==k)*mat[j][i-j]);
				}
			}
		}
	}
	cout<<dp[n*2][n][n];
}