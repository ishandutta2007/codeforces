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
long long T,x,j,ans;
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	T=read();
	for (;T;T--)
	    {
	    	x=read();
	    	x--;
	    	for (j=0;j<=5000;j++)
	    	      if (j+j*(j+1)>=x) 
	    	         {
	    	         	ans=j;break;
					 }
			printf("%lld\n",ans+1);
		}
 return 0;
}