#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 100005
#define ll long long
ll dp[N][205][2],ans,s1[204],s2[205];
int n,i,a[N],j;
int main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i];
	if(a[1]==-1)for(i=1;i<=200;++i)dp[1][i][0]=1;
	else dp[1][a[1]][0]=1;
	for(i=2;i<=n;++i){
		if(a[i]!=-1){
			for(j=1;j<a[i];++j){
				dp[i][a[i]][0]+=dp[i-1][j][0]+dp[i-1][j][1];
			}
			dp[i][a[i]][1]+=dp[i-1][a[i]][0]+dp[i-1][a[i]][1];
			for(j=a[i]+1;j<=200;++j)dp[i][a[i]][1]+=dp[i-1][j][1];
			dp[i][a[i]][0]%=mod;
			dp[i][a[i]][1]%=mod;
		}
		else{
			for(j=1;j<=200;++j)s1[j]=s1[j-1]+dp[i-1][j][0];
			for(j=1;j<=200;++j)s2[j]=s2[j-1]+dp[i-1][j][1];
			for(j=1;j<=200;++j){
				dp[i][j][0]=(s1[j-1]+s2[j-1])%mod;
				dp[i][j][1]=(dp[i-1][j][0]+s2[200]-s2[j-1])%mod;
			}
		}
	}
	for(i=1;i<=200;++i)ans+=dp[n][i][1];
	cout<<(ans%mod+mod)%mod;
}