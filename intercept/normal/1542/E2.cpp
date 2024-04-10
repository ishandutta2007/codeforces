#include<bits/stdc++.h>
using namespace std;
const int M=509;
const int N=M*M+2*M;
int n,mod;
int _s[(N<<1)+2*M],*s=_s+N+M;
int _dp[(N<<1)+2*M],*dp=_dp+N+M;
int _c[(N<<1)+2*M],*c=_c+N+M;
int _D[(N<<1)+2*M],*D=_D+N+M;
int _C[(N<<1)+2*M],*C=_C+N+M;
int main(){
	scanf("%d%d",&n,&mod);
	C[0]=s[0]=s[1]=s[2]=s[3]=1;
	for(int i=2;i<=n;++i){
		for(int j=-i*i/2;j<=i*i/2;++j){
			c[j]=((1ll*c[j-1]-(s[j-1]-s[j-i-1])+s[j+i-1]-s[j-1])%mod+mod)%mod;
			dp[j]=((1ll*dp[j-1]-1ll*i*D[j-1]%mod+1ll*i*D[j]%mod-(s[j-1]-s[j-i-1])+1ll*C[j-1]*i%mod)%mod+mod)%mod;
		}
		for(int j=-i*i-i;j<=i*i+i;++j){
			s[j]=(s[j-1]+c[j])%mod;
			D[j]=dp[j];
			C[j]=c[j];
		}
	}
	int ans=0;
	for(int i=-n*n/2;i<0;++i)ans=(ans+dp[i])%mod;
	printf("%d\n",ans);
	return 0;
}