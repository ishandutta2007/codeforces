#include<bits/stdc++.h>
const int MAXN=5005,P=998244353;
int n,ans;
int a[MAXN],cnt[MAXN];
int dp[MAXN][MAXN];
int inv[MAXN];
int Pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%P;
		}
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		++cnt[a[i]];
		inv[i]=Pow(i,P-2);
	}
	for(int i=1;i<=n;++i){
		dp[1][a[i]]=(dp[1][a[i]]+inv[n])%P;
	}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=n;++j){
			dp[i-1][j]=(dp[i-1][j-1]+dp[i-1][j])%P;
		}
		for(int j=1;j<=n;++j){
			ans=(ans+1ll*(dp[i-1][j]-dp[i-1][j-1]+P)*(cnt[j]-1)%P*inv[n-i+1])%P;
			dp[i][j]=1ll*dp[i-1][j-1]*cnt[j]%P*inv[n-i+1]%P;
		}
	}
	printf("%d\n",ans);
	return 0;
}