#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long y,T,a[200000],x,n,m,i,p,sum;
int main()
{
	cin>>T;
	while (T--)
	   {
	   	cin>>n>>m;
	   	for (i=1;i<=n;i++) cin>>a[i];
	   	sort(a+1,a+n+1);x=-1;
	   	sum=1;
	   	for (i=2;i<=n;i++)
	   	    if (a[i]!=a[i-1]) sum++;
	    if (m==0) cout<<sum<<endl;
	    else 
	       {
	   	  if (a[1]!=0) 
	   	    {
	   	    p=(a[n]+1)/2;sum++;
	   	    for (i=1;i<=n;i++)
	   	    	if (p==a[i]) { sum--;break;}
			cout<<sum<<endl;
			}
	   	else {
		     for (i=2;i<=n;i++)
	   	          if (a[i]-a[i-1]-1>0) {
	   	          	x=a[i-1]+1;break;
				    } 
			y=a[n];
			if (x==-1) 
			  {
			  	cout<<sum+m<<endl;
			  }
		   else
		       {
		       	p=(x+y+1)/2;sum++;
	   	    for (i=1;i<=n;i++)
	   	    	if (p==a[i]) { sum--;break;}
	   	    	cout<<sum<<endl;
			   }
		}
	}
	   }
}