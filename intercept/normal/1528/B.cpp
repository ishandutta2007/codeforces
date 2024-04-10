#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=1e6+9;
int n;
int dp[M],b[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i){
			b[j]=(b[j]+1)%mod;
		}
	}
	for(int i=1;i<=n;++i){
		dp[i]=(dp[i-1]+b[i])%mod;     
		dp[i]=(dp[i]+dp[i-1])%mod;
	}
	printf("%d\n",(dp[n]-dp[n-1]+mod)%mod);
	return 0;
}