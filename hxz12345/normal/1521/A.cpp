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
long long T,A,B;
int main()
{
	T=read();
	for (;T;T--)
	    {
	    	A=read();B=read();
	    	if ((A % (A*B)==0)||((A*B+A) % (A*B)==0)) puts("NO");
	    	else
	    	       {
	    	    	puts("YES");
	    	    	printf("%lld %lld %lld\n",A,A*B,A*(B+1));
	    	       }
		}
   return 0;
}