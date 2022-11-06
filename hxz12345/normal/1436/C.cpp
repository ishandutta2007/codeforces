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

long long i,MOD,fac[1001010],inv[1001010],ifac[1001010],l,r,mid,ans,up,down,n,x,pos; 
long long C(long long n,long long m)
{
	if ((n<m)||(n<0)||(m<0)) return 0;
	return fac[n]*ifac[n-m] % MOD;
}
int main()
{
	//a[find]=1
	//find=pos
	//
	
	n=read();x=read();pos=read();pos++;
	fac[0]=1;MOD=1e9+7;
	for (i=1;i<=n;i++) fac[i]=fac[i-1]*i % MOD;
	inv[1]=1;ifac[1]=1;ifac[0]=1;
	for (i=2;i<=n;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i] % MOD,ifac[i]=ifac[i-1]*inv[i] % MOD;
	l=0;r=n;
	while (l<r)
	   {
	   	 mid=(l+r)/2;
	   	 if (mid+1<=pos) 
	   	    { 
	   	       if (mid+1!=pos) down++;l=mid+1;
			   }
		else 
		   { 
		      if (mid+1!=pos) up++;
			  r=mid;
		   }
	   }
	ans=C(x-1,down)*C(n-x,up) % MOD*C(n-down-up-1,n-down-up-1) % MOD;
	printf("%lld\n",ans);
	return 0;
}