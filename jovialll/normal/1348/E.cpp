#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
int n,k,i,a[N],b[N],j,l,dp[N][N];
ll ans1,ans2,ans;
int main(){
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>a[i]>>b[i],ans1+=a[i],ans2+=b[i];
	dp[0][0]=1;
	for(i=1;i<=n;++i){
		for(j=0;j<k;++j){
			dp[i][j]=dp[i-1][j];
			if(!dp[i][j]){
			for(l=0;l<k;++l){
				if(a[i]>=(k+j-l)%k&&b[i]>=k-((k+j-l)%k))dp[i][j]|=dp[i-1][l];
			}
			}
		}
	}
	ans=ans1/k+ans2/k;
	for(i=0;i<k;++i){
		if(dp[n][i]){
			ans=max(ans,(ans1-i)/k+(ans2+i)/k);
		}
	}
	cout<<ans<<"\n";
	return 0;
}