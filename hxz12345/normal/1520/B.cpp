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
long long T,n,len,x,sum,i,j;
int main()
{
	T=read();
	for (;T;T--)
	    {
	      n=read();len=0;
	      for (x=n;x;x/=10) len++;
	      sum=(len-1)*9;
	      for (i=1;i<=9;i++)
	         {
	         	x=0;
	         	for (j=1;j<=len;j++) x=x*10+i;
	         	if (x>n) break;
	         	sum++;
			 }
		printf("%lld\n",sum);
		}
   return 0;
}