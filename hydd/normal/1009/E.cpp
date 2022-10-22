#include<cstdio>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n;
ll a[1100000],pow2[1100000],dp[1100000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	pow2[0]=1;
	for (int i=1;i<=n;i++) pow2[i]=(pow2[i-1]<<1)%Mod;
	dp[1]=a[1]*pow2[n-1]%Mod;
    for(int i=2;i<=n;i++) dp[i]=((dp[i-1]-a[i-1]*pow2[n-i]%Mod+a[i]*pow2[n-i]%Mod)%Mod+Mod)%Mod;
    ll ans=0;
    for (int i=1;i<=n;i++) ans=(ans+dp[i])%Mod;    
    printf("%lld\n",ans);
	return 0;
}