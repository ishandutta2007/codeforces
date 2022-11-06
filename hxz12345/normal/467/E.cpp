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
map<int,int> fre,lst;
long long n,i,x,tot,f[1001000],q[1001000],w,ans;
int main()
{    
   n=read();
   for (i=1;i<=n;i++)
        {
        	 x=read();
        	 if (fre[x]==3) lst[x]=x;
        	 if (lst[x])
        	     {
        	     	tot++;f[tot]=lst[x];tot++;f[tot]=x;tot++;f[tot]=lst[x];tot++;w=0;f[tot]=x;fre.clear();lst.clear();
        	     	continue;
				 }
			while ((w)&&(fre[x]>=1)&&(q[w]!=x)) {lst[q[w]]=x;fre[q[w]]--;w--;}
			fre[x]++;w++;q[w]=x;
		}
	printf("%d\n",tot);
	for (i=1;i<=tot;i++) printf("%d ",f[i]);
return 0;
}