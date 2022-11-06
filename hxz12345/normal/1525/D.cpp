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
int tot,m,n,i,a[10000],f[5010][5010],b[10010],j,ans,k;
int main()
{
	n=read();
	for (i=1;i<=n;i++) 
	    {
	    	a[i]=read();if (a[i]==1) b[++m]=i;
	    }
	for (i=1;i<=m;i++)
	    for (j=1;j<=n;j++)
	       f[i][j]=1000000000;
    for (i=1;i<=n;i++)
	    if (a[i]==0) f[1][i]=abs(b[1]-i);
	for (i=2;i<=m;i++)
	     {
	     	k=1;tot=1000000000;
	     for (j=1;j<=n;j++)
		     if (a[j]==0)
			     {
			       while (((k<=j)||(a[k]==1))&&(k<=n)) k++;
				   if (k>n) break;
				   tot=min(tot,f[i-1][j]);
				   f[i][k]=min(f[i][k],tot+abs(b[i]-k));
			     }
	    }
	ans=1000000000;
	for (i=1;i<=n;i++)
	    ans=min(ans,f[m][i]);
	printf("%d\n",ans);
    return 0; 
}