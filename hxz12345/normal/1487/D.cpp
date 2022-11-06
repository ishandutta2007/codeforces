#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long T,n,l,r,ans,mid,act;
int main()
{
	for (T=read();T;T--)
	    {
	    	n=read();
	    	l=1;r=sqrt(2*n-1);ans=0;
	    	while (l<=r)
	    	    {
	    	    	mid=(l+r)/2;
	    	    	act=2*mid-1;
	    	    	if ((act*act+1)/2<=n)
	    	    	    {
	    	    	    	ans=mid;l=mid+1;
						}
					else r=mid-1;
				}
		printf("%lld\n",ans-1);
		}
	return 0;
}