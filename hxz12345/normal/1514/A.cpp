#include<bits/stdc++.h>
using namespace std;
bool flag;
long long y,T,n,x,i,l,r,mid;
int main()
{
	cin>>T;
	for (;T;T--)
	    {
	    	cin>>n;flag=false;
	    	for (i=1;i<=n;i++)
	    	    {
	    	    	cin>>x;
	    	    	l=1;r=100000;y=0;
	    	    	while (l<=r)  
	    	    	    {
	    	    	    	mid=(l+r)/2;
	    	    	    	if (mid*mid==x)
	    	    	    	    {
	    	    	    	    	y=mid;break;
								}
							else if (mid*mid>x) r=mid-1;
							else l=mid+1;
						}
				   if (y==0) flag=true;
				}
		if (flag) puts("YES");
		else puts("NO");
		}
	return 0;
}