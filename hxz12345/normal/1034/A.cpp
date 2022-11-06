#include<bits/stdc++.h>
using namespace std;
int len,exist[20000000],prim[10000000],f[20000000];
int a[2000000];
bool vis[20000000];
int tot,n,i,x,ans,sum,j;
int gcd(int x,int y)
{
	if (y==0) return x;
	int ans=gcd(y,x % y);return ans;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	x=a[1];
	for (i=2;i<=n;i++) x=gcd(x,a[i]); 
	ans=0;
	for (i=1;i<=n;i++) 
	     {
		 a[i]/=x;
		 if (a[i]!=1) exist[a[i]]++;
		 if (a[i]>tot) tot=a[i];
	     }
	for (i=2;i<=tot;i++)
	     {
	     	if (vis[i]==false)
	     	    {
	     	    	len++;prim[len]=i;
				 }
			for (j=1;j<=len,i*prim[j]<=tot;j++)
			    {
			       vis[i*prim[j]]=true;
			       if (i % prim[j]==0) break;
				}
		 }
     for (i=1;i<=len;i++)
	       {
	       	sum=0;
	       	  for (j=1;j<=tot/prim[i];j++)
	       	      sum=sum+exist[j*prim[i]];
	       	ans=max(ans,sum);
		   }
	if (ans==0) puts("-1");
	else printf("%d\n",n-ans);
	return 0;
}