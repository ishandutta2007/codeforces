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
int T,n,i,j,x,a[510][510];
int main()
{
	T=read();
	for (;T;T--)
	   {
	n=read();
	if (n==2) puts("-1");
	else
	   {
	x=1;
	if (n % 2==1)
	   {
	for (i=1;i<=n;i++)
	   for (j=1;j<=n;j++)
	          {
	          a[i][j]=x;x=(x+1) % (n*n)+1;
	          }
	    }
   else
       {
       	for (i=1;i<=n/2;i++)
       	      for (j=1;j<=n;j++)
	          {
	          a[i][j]=x;x=(x+1) % (n*n)+1;
	          }
	    x=2;
	    for (i=n/2+1;i<=n;i++)
       	      for (j=1;j<=n;j++)
	          {
	          a[i][j]=x;x=(x+1) % (n*n)+1;
	          }
	   }
	for (i=1;i<=n;i++)
	     {
	     	for (j=1;j<=n;j++)
	     	   printf("%d ",a[i][j]);
	     	printf("\n");
	     }
	}
	}
   return 0;
}