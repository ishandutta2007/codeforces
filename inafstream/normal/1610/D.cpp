#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
#define mod (1000000007)
using namespace std;


int n,ans;
int fac[200005],inv[200005],fiv[200005];
int cnt[35];

int binom(int x,int y)
{
	return 1ll*fac[x]*fiv[y]%mod*fiv[x-y]%mod;
}

int main()
{
	int i;
	scanf("%d",&n);
	
	fac[0]=fac[1]=inv[1]=fiv[0]=fiv[1]=1;
	for(i=2;i<=n;i++){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fiv[i]=1ll*fiv[i-1]*inv[i]%mod;}
	
	rep(i,n)
	{
		int x;
		scanf("%d",&x);
		cnt[__builtin_ctz(x)]++;
	}
	
/*	int a,b,c,d,r=0;
	for(a=0;a<=cnt[0];a++)for(b=0;b<=cnt[1];b++)for(c=0;c<=cnt[2];c++)for(d=0;d<=cnt[3];d++)if(a+b+c+d)
	{
		int s=a*2+c+d*3,g=0;
		if(a)g=__gcd(g,4);
		if(b)g=__gcd(g,1);
		if(c)g=__gcd(g,2);
		if(d)g=__gcd(g,3);
		if(s%g!=0) cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl,r+=binom(cnt[0],a)*binom(cnt[1],b)*binom(cnt[2],c)*binom(cnt[3],d);
	}
	cout<<r<<endl;*/
	
	ans=1;
	rep(i,n) ans=2ll*ans%mod;
	ans--;
	
	rep(i,30)
	{
		int sum=0,coef=mod-1;
		for(int j=i+1;j<=30;j++) sum+=cnt[j];
		while(sum--) coef=2ll*coef%mod;
		
		for(int j=1;j<=cnt[i];j+=2) ans=(ans+1ll*coef*binom(cnt[i],j))%mod;
	}
	
	cout<<ans<<endl;
	return 0;
}