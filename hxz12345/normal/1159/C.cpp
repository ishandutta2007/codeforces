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
long long flag,i,n,m,y,x,sum,a[1010100],b[1010100];
int main()
{
	n=read();m=read();y=1e9;
	for (i=1;i<=n;i++) a[i]=read(),x=max(x,a[i]),sum+=a[i];
	for (i=1;i<=m;i++) b[i]=read(),y=min(y,b[i]);
    sort(a+1,a+n+1);sort(b+1,b+m+1);
	if (x>y)
	    {
	       puts("-1");return 0;	
		}
	sum*=m;
	for (i=1;i<=m-1;i++) 
	    sum+=b[i]-a[n],flag+=(b[i]==a[n]);
	if (flag==0) sum+=b[m]-a[n-1];
	else sum+=b[m]-a[n];
	printf("%lld\n",sum);
    return 0;
}