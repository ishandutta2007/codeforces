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
long long n,m,i,x,y,a[400100];
int main()
{
   n=read();m=read();
   for (i=1;i<=n;i++) a[i]=read();
   sort(a+1,a+n+1);
   x=0;
   for (i=1;i<n;i++) x=gcd(x,a[i+1]-a[i]);
   for (i=1;i<=m;i++)
       {
       	y=read();
       	y=gcd(a[1]+y,x);
       	printf("%lld ",y);
	   }
   return 0;
}