#include<bits/stdc++.h>
using namespace std;
int T,n,i,x,y,w1,w2;
long long a[200000],b[200000];
double sum;
int main()
{
	cin>>T;
	while (T--)
	     {
	     	cin>>n;w1=0;w2=0;
	     	for (i=1;i<=2*n;i++) 
	     	    {
	     	    	cin>>x>>y;
	     	    	if (x==0) { w1++;a[w1]=abs(y);}
				else {w2++;b[w2]=abs(x);}
				 }
			sort(a+1,a+n+1);sort(b+1,b+n+1);sum=0;
			for (i=1;i<=n;i++)
			   sum=sum+sqrt(a[i]*a[i]+b[i]*b[i]);
			printf("%.15f\n",sum);
		 }
	return 0;
}