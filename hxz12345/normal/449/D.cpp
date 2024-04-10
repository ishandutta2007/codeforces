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
long long sum,FF,V[2001010],j,tag[2001010],fre[2001010],up,val,n,tot,MOD,a[2001010],fac[2001010],ifac[2001010],F[2001010],sta,i;
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p) if (y&1) ans=ans*x % p;return ans;
}
long long C(long long n,long long m){
	if ((n<m)||(n<0)||(m<0)) return 0;
	return fac[n]*ifac[m] % MOD*ifac[n-m] % MOD;
}
int main()
{
	//freopen("count.in","r",stdin);
	//freopen("count.out","w",stdout);
	n=read();up=1048576;MOD=1e9+7;
	for (i=1;i<=n;i++) a[i]=read(),tag[a[i]]++;
	fac[0]=1;for (i=1;i<=up;i++) fac[i]=fac[i-1]*i % MOD;
	ifac[up]=pow(fac[up],MOD-2,MOD);
	for (i=up-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1) % MOD;
	for (i=1;i<=up;i++) fre[i]=fre[i^(i&-i)]+1;
	for (i=1;i<=up;i++) if (fre[i]&1) fre[i]=1;
	else fre[i]=MOD-1;
	for (i=0;i<=19;i++)
	   for (j=1048576;j>=1;j--)
	        if ((j&(1<<i))==0) tag[j]=tag[j]+tag[j^(1<<i)];
	for (i=1;i<=up;i++) sum=(sum+fre[i]*(pow(2,tag[i],MOD)-1) % MOD) % MOD;
	sum=pow(2,n,MOD)-sum-1;
	sum=(sum % MOD+MOD) % MOD;
	printf("%lld\n",sum);
return 0;
}