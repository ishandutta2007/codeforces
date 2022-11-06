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
long long j,lst,now,mx,X,Y,n,ans,x,i;
int fre[10001000],pre[10001000];
int main()
{
	n=read();ans=1000000000000000000;
	for (i=1;i<=n;i++)
	     {
	     	x=read();
			if (fre[x]==1)
			     if (x<ans)
				     {
				     	ans=x;X=pre[x];Y=i;
					 }
	     	fre[x]++;pre[x]=i;
			mx=max(mx,x);
		 }
	for (i=1;i<=mx;i++)
	     {
	     	lst=0;now=0;
	     	for (j=1;j<=mx/i;j++)
	            if (fre[i*j]>0)
				    {
				    	if (lst==0) lst=i*j;
				    	else 
				    	    {
				    	    	if (lst*j<ans)
				    	    	    {
				    	    	    	ans=lst*j;
				    	    	    	X=pre[lst];Y=pre[i*j];  	
									}
							break;
							}
				    }
		 }
	if (X>Y) swap(X,Y);
	printf("%lld %lld\n",X,Y);
return 0;
}