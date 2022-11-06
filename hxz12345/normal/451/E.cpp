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
#define MOD 1000000007
long long ans,i,up,qwq,n,m,ifac,a[1001010],sta,dif,tot,final;
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p) if (y&1) ans=ans*x % p;return ans;
}
int main()
{
	n=read();m=read();
	ifac=1;
	for (i=1;i<=n-1;i++) ifac=ifac*i % MOD;ifac=pow(ifac,MOD-2,MOD);
	for (i=1;i<=n;i++) a[i]=read();
	final=(1<<n)-1;
	for (sta=0;sta<=final;sta++){
		dif=1;tot=0;
		for (i=1;i<=n;i++)
		    if (sta&(1<<(i-1))) dif=MOD-dif,tot=tot+a[i]+1;
		if (tot<=m){
			tot=m-tot;
			up=tot+n-1;qwq=1;
			for (i=1;i<=n-1;i++) qwq=qwq*((up-i+1) % MOD) % MOD;
			qwq=qwq*ifac % MOD;
			ans=(ans+qwq*dif) % MOD;
	     }
	}
	printf("%lld\n",ans);
	return 0;
}