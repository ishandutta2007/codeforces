#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,dp[5050][5050],res;
char a[5050],b[5050];
int main(){
	cin>>n>>m>>a+1>>b+1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i]==b[j]){
				dp[i][j]=max(dp[i-1][j-1]+2,dp[i][j-1]-1);dp[i][j]=max(dp[i][j],0);
			}
			else{
				dp[i][j]=max(dp[i-1][j-1]-2,dp[i][j-1]-1);
				dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
				dp[i][j]=max(dp[i][j],0);
			}
			res=max(res,dp[i][j]);
		}
	}
	printf("%d\n",res);
}