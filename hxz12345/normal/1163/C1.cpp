#include<bits/stdc++.h>
using namespace std;
int c[200000],d[200000],a[200000],b[200000],e1[20000],e2[20000],e3[20000],e4[20000];
int xx1,yy1,xx2,yy2,k,n,i,j,x,y,w,z,sum;
bool flag;
int gcd(int x,int y)
{
	if (y==0) return x;
	int ans=gcd(y, x % y);return ans;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	    {
	    	cin>>e1[i]>>e2[i];
		}
	for (i=1;i<=n;i++)
	    for (j=1;j<i;j++)
	        {
			flag=true;
	        for (k=1;k<i;k++)
	          if (k!=j)
	            {
	            	xx1=e1[j]-e1[i];yy1=e2[j]-e2[i];
	            	xx2=e1[k]-e1[i];yy2=e2[k]-e2[i];
	            	if (xx1*yy2==xx2*yy1)
	            	    {
	            	    	flag=false;break;
						}
				}
			if (flag)
			    {
			    	x=e1[j]-e1[i];y=e2[j]-e2[i];
			    	if ((x!=0)&(y!=0))
			    	    {
			    	    	z=gcd(abs(x),abs(y));
			    	    	x/=z;y/=z;
						}
					w++;a[w]=y;b[w]=x;
				}
	    }
	for (i=1;i<=w;i++)
	   for (j=i+1;j<=w;j++)
	       if (a[i]*b[j]!=a[j]*b[i])
	           sum++;
	cout<<sum<<endl;
	return 0;
}