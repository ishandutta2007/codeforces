#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,mod,i,j,ans;
int fac[250005],inv[250005],fiv[250005];

int main()
{
	cin>>n>>mod;
	fac[0]=fac[1]=inv[1]=fiv[0]=fiv[1]=1;
	for (i=2;i<=250000;i++)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fiv[i]=1ll*fiv[i-1]*inv[i]%mod; 
	}
	
	for (i=1;i<=n;i++)
	{
		ans=(ans+1ll*(n-i+1)*(n-i+1)%mod*fac[i]%mod*fac[n-i])%mod;
	}
	
	cout<<ans<<endl;
	
	return 0;
}