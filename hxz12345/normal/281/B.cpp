#include<bits/stdc++.h>
using namespace std;
long long ans1,ans2,z,dom,x,y,n,dominator,molecule,l,r,mid,mol,xx1,yy1,xx2,yy2,xx,yy,i;
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
int main()
{
	cin>>x>>y>>n;
	dominator=1;molecule=1000000;
	for (i=1;i<=n;i++)
	     {
	     	dom=i*y;
	     	l=1;r=10000000000;mol=0;
	     	while (l<=r)
	     	     {
	     	     	mid=(l+r)/2;
	     	     	if (i*x-mid*y>=0)
	     	     	    {
	     	     	    	mol=mid;l=mid+1;
						  }
					else r=mid-1;
				  }
			xx1=i*x-mol*y;yy1=mol;
		    l=1;r=10000000000;mol=0;
	     	while (l<=r)
	     	     {
	     	     	mid=(l+r)/2;
	     	     	if (i*x-mid*y<0)
	     	     	    {
	     	     	    	mol=mid;r=mid-1;
						  }
					else l=mid+1;
			      }
			xx2=-(i*x-mol*y);yy2=mol;
			if (xx1>xx2)
			     {
			     	xx1=xx2;
			     	xx=i;yy=yy2;
				 }
			else 
			        {
			        	xx=i;yy=yy1;
					}
			z=molecule*dom-dominator*xx1;
			if (z>0)
			    {
			    	ans1=yy;ans2=i;
			    	dominator=dom;molecule=xx1;
				}
		 }
	if (ans1==0) cout<<ans1<<"/"<<ans2<<endl;
	else
	    {
	    	z=gcd(ans1,ans2);ans1/=z;ans2/=z;
	    	cout<<ans1<<"/"<<ans2<<endl;
		}
	return 0;
}