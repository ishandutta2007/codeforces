#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long n,m,i,MOD,sum,tot,fac[4001010],ifac[4001010];
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	    if (y&1) ans=ans*x % p;
	return ans;
}
int main()
{
	n=read();m=read();MOD=998244353;
	fac[0]=1;for (i=1;i<=n+m;i++) fac[i]=fac[i-1]*i % MOD;
    ifac[n+m]=pow(fac[n+m],MOD-2,MOD);
    for (i=n+m-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1) % MOD;
    sum=0;
    for (i=1;i<=n+1;i++) {
    	tot=fac[n]*ifac[n-i+1] % MOD*m % MOD;
    	tot=tot*fac[n+m-i] % MOD*ifac[n+m] % MOD;
    	sum=(sum+tot*i) % MOD;
    	//fac[n+m]*ifac[n+m-i]
    }
    tot=0;
    for (i=1;i<=n;i++) tot=(tot+ifac[i]*fac[i-1]) % MOD;
    tot=tot*m % MOD;
    tot=(tot+1) % MOD;
    printf("%lld\n",sum*tot % MOD);
return 0;
}