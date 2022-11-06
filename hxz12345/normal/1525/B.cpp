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
int T,n,xx,yy,i,x;
bool flag;
int main()
{
	T=read();
	for (;T;T--)
	    {
	    	n=read();xx=0;yy=0;flag=true;
	    	for (i=1;i<=n;i++)
	    	    {
	    	    	x=read();
	    	    	if (x!=i) flag=false;
	    	    	if (x==1) xx=i;
	    	    	if (x==n) yy=i;
				}
			if (flag) puts("0");
			else  if ((xx==1)||(yy==n)) puts("1");
			else if ((xx!=n)||(yy!=1)) puts("2");
			else puts("3");
		}
    return 0;
}