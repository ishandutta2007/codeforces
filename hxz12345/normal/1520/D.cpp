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
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
		if (y&1) ans=ans*x % p;
	return ans;
}
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
long long ans,T,n,i,x,f[1000000];
int main()
{
	T=read();
	for (;T;T--)
	    {
	    	n=read();
	    	for (i=1;i<=2*n;i++) f[i]=0;
	    	for (i=1;i<=n;i++) 
	    	    {
	    	    	x=read();f[x-i+n]++;
				}
			ans=0;
			for (i=1;i<=2*n;i++) ans=ans+(f[i]*(f[i]-1)/2);
			printf("%lld\n",ans);
		}
   return 0;
}