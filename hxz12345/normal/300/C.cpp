#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	    if (y&1) ans=ans*x % p;
	return ans;
}
long long MOD,A,B,n,i,now,ans,fac[1001010],ifac[1001010];
long long C(long long n,long long m)
{
	if ((n<m)||(n<0)||(m<0)) return 0;
	return fac[n]*ifac[n-m] % MOD*ifac[m] % MOD;
}
long long check(long long x)
{
	for (;x;x/=10)
	  if ((x%10!=A)&&(x%10!=B))
	      return false;
	return true;
}
int main()
{
	A=read();B=read();n=read();MOD=1e9+7;
	fac[0]=1;
	for (i=1;i<=n;i++) fac[i]=fac[i-1]*i % MOD;
	ifac[n]=pow(fac[n],MOD-2,MOD);
	for (i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1) % MOD;
    for (i=0;i<=n;i++)
        {
        	now=i*A+B*(n-i);
        	if (check(now))
        	    ans=(ans+C(n,i)) % MOD;
		}
    printf("%lld\n",ans);
	return 0;
}