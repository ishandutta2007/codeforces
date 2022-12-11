#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1010000],n,A[1010000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); A[k1]++;
	}
	int ans=0;
	for (int i=1;i<=1000000;i++){
		dp[i]+=A[i]; ans=max(ans,dp[i]);
		for (int j=i*2;j<=1000000;j+=i) dp[j]=max(dp[j],dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}