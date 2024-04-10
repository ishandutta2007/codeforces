#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=300005,mod=998244353;
int n,ans;
int a[maxn],fac[maxn],nfac[maxn],inv[maxn];
inline int C(int a,int b){
	return a<b? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod;
}
int main(){
	fac[0]=nfac[0]=1;
	for(int i=1;i<maxn;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=i==1? 1:(mod-1ll*(mod/i)*inv[mod%i]%mod),nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
	scanf("%d",&n),n<<=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++)
		ans=(ans-a[i]+mod)%mod;
	for(int i=n/2+1;i<=n;i++)
		ans=(ans+a[i])%mod;
	printf("%d\n",1ll*ans*C(n,n/2)%mod);
	return 0;
}