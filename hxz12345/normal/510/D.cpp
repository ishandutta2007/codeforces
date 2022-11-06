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
unordered_map<int,int> f;
long long t,w,x,tem,n,i,a[100100],b[100100];
int f2[30000000];
int main()
{
	n=read();
	for (i=1;i<=n;i++){a[i]=read();tem=gcd(tem,a[i]);}
	if (tem!=1){puts("-1");return 0;}
	for (i=1;i<=n;i++) b[i]=read();
    t=1;w=1;f2[1]=0;f[0]=0;
    while (t<=w)
         {
         	for (i=1;i<=n;i++)
         	   {
         	   	x=gcd(f2[t],a[i]);
         	   	if (f[x]==0)
         	   	    {
         	   	    	w++;f2[w]=x;f[x]=f[f2[t]]+b[i];
						}
				else
				    if (f[f2[t]]+b[i]<f[x])
				         {
				         	f[x]=f[f2[t]]+b[i];
				         	w++;f2[w]=x;
						 }
				}
         	t++;
		 }
	printf("%d\n",f[1]);
   return 0;
}