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
int n,f[5001010],a[1001010],b[1010101],final,now,sta,i;
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();final=4194303;
	for (i=1;i<=n;i++)  
	    {
	    	a[i]=read();b[i]=final-a[i];
		    f[a[i]]=i;
	    }
	
	for (now=0;now<final;now++)
	   for (i=1;i<=22;i++)
	       if ((now&(1<<(i-1)))==0)
	           {
	           	sta=now|(1<<(i-1));
	           	if ((f[sta]==0)) f[sta]=max(f[sta],f[now]);
		       }
	for (i=1;i<=n;i++)
	   if (f[b[i]]==0) printf("-1 ");
	else printf("%d ",a[f[b[i]]]);
return 0; 
}