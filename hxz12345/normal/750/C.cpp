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
long long n,lft,rit,x,y,sum,i;
int main()
{
/*	x+a>=1900
	x+a<1900
	x<1900-a
	x>=1900-a;*/
	n=read();
	lft=-1000000000;rit=1000000000;
	for (i=1;i<=n;i++)
	     {
	     	x=read();y=read();
	     	if (y==1) lft=max(lft,1900-sum);
	     	if (y==2) rit=min(rit,1900-sum);
	     	sum+=x;
		 }
	if (lft>=rit) puts("Impossible");
	else if (rit==1000000000) puts("Infinity");
	else printf("%lld\n",rit-1+sum);
   return 0;
}