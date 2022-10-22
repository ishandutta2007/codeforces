#include<iostream>
using namespace std;
long long dp[1009][1009][2];
long long n1,n2,k1,k2,t=0,e=1e8,n;
int main(){
	cin>>n1>>n2>>k1>>k2;
	n=n1+n2;
	dp[0][0][0]=1;
	dp[0][0][1]=1;
	for(int i = 1; i <= n; i++){
		for(long long j = 0; j <= i; j++){
			for(long long p=1;p<=min(k1,j);p++){
				dp[i][j][0]+=dp[i-p][j-p][1];dp[i][j][0]=dp[i][j][0]%e;
			}
			for(int p=1;p<=min(k2,i-j);p++){
				dp[i][j][1]+=dp[i-p][j][0];dp[i][j][1]=dp[i][j][1]%e;
			}
		}
	}
	cout<<(dp[n1+n2][n1][0]+dp[n1+n2][n1][1])%e;
}