#include<bits/stdc++.h>
using namespace std;
const int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
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
long long ans1,ans2,ans,b[5000000],c[5000000],t,w,e[2010][2010],f[2010][2010],a[2010][2010],n,m,val,i,j,x,y;
int main()
{
	n=read();m=read();val=read();
	for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++)
	      a[i][j]=read();
	for (i=1;i<=n;i++)
	   for (j=1;j<=m;j++)
	        {
	        	f[i][j]=2000000000000000000;
	        	e[i][j]=2000000000000000000;
			}
    t=1;w=1;b[1]=1;c[1]=1;e[1][1]=0;
    while (t<=w)
        {
        	for (i=0;i<4;i++)
        	     {
        	     	x=b[t]+d[i][0];y=c[t]+d[i][1];
        	     	if ((x>=1)&&(x<=n)&&(y>=1)&&(y<=m)&&(a[x][y]!=-1)&&(e[b[t]][c[t]]+val<e[x][y]))
        	     	     {
        	     	     	w++;b[w]=x;c[w]=y;e[x][y]=e[b[t]][c[t]]+val;
						  }
				 }
        	t++;
		}
	t=1;w=1;b[1]=n;c[1]=m;f[n][m]=0;
    while (t<=w)
        {
        	for (i=0;i<4;i++)
        	     {
        	     	x=b[t]+d[i][0];y=c[t]+d[i][1];
        	     	if ((x>=1)&&(x<=n)&&(y>=1)&&(y<=m)&&(a[x][y]!=-1)&&(f[b[t]][c[t]]+val<f[x][y]))
        	     	     {
        	     	     	w++;b[w]=x;c[w]=y;f[x][y]=f[b[t]][c[t]]+val;
						  }
				 }
        	t++;
		}
	ans=e[n][m];
	ans1=3000000000000000000;ans2=3000000000000000000;
	for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++)
	     if (a[i][j]>0)
	        {
	        	ans1=min(ans1,f[i][j]+a[i][j]);
	        	ans2=min(ans2,e[i][j]+a[i][j]);
			}
	ans=min(ans,ans1+ans2);
	if (ans>=1000000000000000100) puts("-1");
	else printf("%lld\n",ans);
   return 0;
}