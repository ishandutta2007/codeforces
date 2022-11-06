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
int i,j;
int make(int x,int y)
{
	for (int z=y;z;z/=10) x=x*10;
	x=x+y;return x;
}
long long T,x,y,z,tot,sum;
int main()
{
	T=read();
	for (;T;T--)
	    {
	    	x=read();y=read();
	    	tot=0;sum=0;
	    	for (z=y;z;z/=10) sum++,tot+=z % 10;
	    	if (tot!=sum*9) sum--;
	    	printf("%lld\n",sum*x);
		}
    return 0;
}