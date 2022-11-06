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
long long T,n,i,j;
int a[1010][1010];
//
int main()
{
	for (T=read();T;T--)
	    {
	    	   n=read(); 
	    	   for (i=1;i<=n;i++)
	    	     for (j=1;j<=n;j++)
	    	         a[i][j]=0;
			   for (i=1;i<=n;i++) a[i][i]=1,a[i][n-i+1]=1;
	    	   if (n % 2==1)
	    	      a[n/2][(1+n)/2]=1,a[(1+n)/2][n/2]=1;
	    	    for (i=1;i<=n;i++)
	    	       { 
	    	       for (j=1;j<=n;j++)
	    	          printf("%d ",a[i][j]);
	    	        puts("");
				   }
		}
	return 0;
}