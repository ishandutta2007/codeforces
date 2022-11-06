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
int a[1010000],b[1010000],T,n,i,ans;
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	T=read();
	for (;T;T--)
	    {
	    	n=read();
	    	for (i=1;i<=n;i++) a[i]=read();
	    	a[n+1]=0;
	    	for (i=n;i>=1;i--) a[i]=a[i+1]+a[i];
	    	for (i=1;i<=n;i++) b[i]=read(),b[i]+=b[i-1];
			ans=2e9;
	    	for (i=1;i<=n;i++)
	    	   ans=min(ans,max(a[i+1],b[i-1]));
	    	printf("%d\n",ans);
		}
 return 0;
}