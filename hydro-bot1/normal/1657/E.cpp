// Hydro submission #6287228b7a0749f0176f1973@1653023372601
#include<bits/stdc++.h>
using namespace std;
#define maxn 260
int n,k;
const long long mod=998244353;
long long dp[maxn][maxn],fac[maxn],inv[maxn];
long long fp(long long a,int b){
	long long sum=1;
	while(b){
		if(b&1){
			sum=(sum*a)%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
long long c(int a,int b){
	return fac[a]*inv[a-b]%mod*inv[b]%mod;
}
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
	n=read();k=read();fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[n]=fp(fac[n],mod-2);
	for(int i=n;i;i--){
		inv[i-1]=inv[i]*i%mod;
	}
	dp[k+1][n-1]=1;
	long long ans=0;
	for(int i=k;i;i--){
		for(int j=n-1;j;j--){
			for(int o=0;o<=j;o++){
				dp[i][j-o]+=(dp[i+1][j]*c(j,o)%mod)*fp(k-i+1,o*(j-o)+(o*(o-1)/2))%mod;
				dp[i][j-o]%=mod;
			}
		}
//		for(int j=n;j;j--){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
		ans=ans+dp[i][0];ans%=mod;
	}
	cout<<ans;
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}