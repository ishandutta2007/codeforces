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
int i,n,m,x,a[1010100];
int main()
{
	n=read();m=read();x=(n-m)/2+1;
	if (x!=0)
	   	 { for (i=n-x+1;i>0;i-=x) a[i]=1;}
	for (i=1;i<=n;i++) printf("%d",a[i]);
	puts("");
    return 0;
}