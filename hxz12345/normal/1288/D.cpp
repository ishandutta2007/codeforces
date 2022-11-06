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
int x,son[10010][3],i,j,l,r,mid,ans,f[1010000],e[1010000],a[301000][10],final,n,m;
bool check(int mid)
{
	int i,j,k,x;
	bool flag;
	for (i=0;i<=final;i++) f[i]=0;
	for (i=1;i<=n;i++)
	    {
	    	x=0;
	    	for (j=1;j<=m;j++) 
	    	    {
				x=x*2;
	    	    if (a[i][j]>=mid) x=x+1;
			    }
			if (x==final) return true;
			f[x]=f[x]+1;
		}
	for (i=0;i<=(1<<m)-1;i++)
	   if (f[i]>0)
	      {
	      	  f[i]--;
	      	  for (j=0;j<=(1<<m)-1;j++)
	      	    if (f[j]>0)
	      	       if ((i|j)==final)
	      	          return true;
	      	f[i]++;
		  }
	return false;
}
int main()
{
	n=read();m=read();final=(1<<m)-1;
	for (i=1;i<=n;i++)
	    {
	    	for (j=1;j<=m;j++)
	    	    a[i][j]=read();
		}
	l=1;r=1000000000;
	while (l<=r)
	     {
	     	mid=(l+r)/2;
	     	if (check(mid))
	     	    {
	     	    	ans=mid;l=mid+1;
				 }
		else r=mid-1;
		  } 
	for (i=0;i<=final;i++) f[i]=0;
	for (i=1;i<=n;i++)
	    {
	    	x=0;
	    	for (j=1;j<=m;j++) 
	    	    {
				x=x*2;
	    	    if (a[i][j]>=ans) x=x+1;
			    }
			if (x==final)
			    {
			    	printf("%d %d\n",i,i);
			    	return 0;
				}
			e[i]=x;f[x]++;
			if (f[x]==1) son[x][1]=i;
			else son[x][2]=i;
		}
	for (i=0;i<=(1<<m)-1;i++)
	   if (f[i]>0)
	      {
	      	  f[i]--;
	      	  for (j=0;j<=(1<<m)-1;j++)
	      	    if (f[j]>0)
	      	       if ((i|j)==final)
	      	          {
	      	          	if (i==j) 
	      	          	   {
	      	          	   	printf("%d %d",son[j][1],son[j][2]);
							   }
						else printf("%d %d",son[i][1],son[j][1]);
						return 0;
						}
	      	f[i]++;
		  }
    return 0;
}