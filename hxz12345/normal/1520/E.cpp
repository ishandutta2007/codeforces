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
long long lft,rit,T,n,i,w,ans,answer,sum,tot;
long long f[1001000],a[1001000];
string s;
int main()
{
	T=read();
	for (;T;T--)
	    {
	    	n=read();cin>>s;w=0;
	    	for (i=0;i<=n;i++) f[i]=0;
	    	for (i=1;i<=n;i++)
	    	  	if (s[i-1]=='*') 
	    	  	    {w++;a[w]=i;}
	    	ans=0;sum=0;
	    	for (i=1;i<=w;i++)
	    	   {
			   f[a[i]-i]++;
			   if (a[i]-i==0) sum++;
	    	   ans=ans+abs(a[i]-i);
	           }
	        answer=ans;
	    	lft=2;rit=w+1;tot=1;
	    	while (rit<=n)
	    	    {
	    	    	ans=ans+sum-(w-sum);
	    	    	sum=sum+f[tot];
	    	    	answer=min(answer,ans);
	    	    	tot++;
	    	    	lft++;rit++;
				}
			printf("%lld\n",answer);
		}
   return 0;
}