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
long long k,f[20000][200],num,n,i,j,vol,val,value,sum;
double x,y,ans;
int main()
{
	n=read();
	for (i=0;i<=10000;i++)
	   for (j=0;j<=100;j++)
	       f[i][j]=100000000;
	f[0][0]=0;
	for (num=1;num<=n;num++)
	     {
	     	vol=read();val=read();value+=val;sum+=vol-val;vol=vol-val;
	     	for (j=10000;j>=val;j--)
	     	    for (k=num;k>=1;k--)
	     	        f[j][k]=min(f[j][k],f[j-val][k-1]+vol);
		 }
   for (i=1;i<n;i++)
         {
         	ans=0;
         	for (j=0;j<=10000;j++)
         	     if (f[j][n-i]!=100000000)
         	          {
         	          	x=j;x/=2;y=value-j;
         	          	if (x<=(sum-f[j][n-i])) y+=x;
         	          	else y=y+sum-f[j][n-i];
         	          	ans=max(ans,y);
					  }
			printf("%.10lf ",ans);
		 }
	x=value;
	printf("%.10lf\n",x);
   return 0;
}