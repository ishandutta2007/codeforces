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
long long n,m,l,r,mid,ans;
bool check(long long mid)
{
	long long sum=0;
	while (mid>0)
	     {
	     	sum+=mid;mid/=m;
	     	if (sum>=n) return 1;
		 }
	return 0;
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();m=read();
	l=1;r=n;
	while (l<=r)
	    {
	    	mid=(l+r)/2;
	    	if (check(mid))
	    	    {
	    	    	ans=mid;r=mid-1;
				}
			else l=mid+1;
		}
	printf("%lld\n",ans);
return 0;
}