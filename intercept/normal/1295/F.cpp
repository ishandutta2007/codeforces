#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int L[59],R[59];
int a[109],inv[109];
int dp[59][109];
int c(int x,int y,int rex=1){
	for(int i=1;i<=y;++i)rex=1ll*rex*inv[i]%mod;
	for(int i=x;i>=x-y+1;--i)rex=1ll*rex*i%mod;
	return rex;
}
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int main(){
	int ans=1;
	scanf("%d",&n);
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&L[i],&R[i]);
		R[i]++;
		a[++m]=L[i];
		a[++m]=R[i];
		ans=1ll*ans*(R[i]-L[i])%mod;
	}
	sort(a+1,a+m+1);
	m=unique(a+1,a+m+1)-a-1;
	for(int i=0;i<m;++i)dp[n+1][i]=1;
	for(int i=n;i>=1;--i){
		for(int j=1;j<m;++j){
			for(int k=i;k<=n;++k){
				if(L[k]<=a[j]&&R[k]>=a[j+1]){
					dp[i][j]=(dp[i][j]+1ll*dp[k+1][j-1]*c(a[j+1]-a[j]+k-i,k-i+1)%mod)%mod;
				}
				else break;
			}
		}
		for(int j=1;j<m;++j)dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
	}
	ans=1ll*dp[1][m-1]*kpow(ans,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}