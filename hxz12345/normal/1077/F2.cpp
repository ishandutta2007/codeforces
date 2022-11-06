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
long long l,r,q[10010],g[5010],num,ans,i,j,k,len,n,m,e[100000],f[5010];
int main()
{
	n=read();len=read();m=read();
	for (i=1;i<=n;i++) e[i]=read();
	for (i=1;i<=len;i++) f[i]=e[i];
	for (num=2;num<=m;num++)
	     {
	     	for (i=1;i<=n;i++) g[i]=0;
	     	l=1;r=0;
	     	 for (i=1;i<=min(len*num,n);i++)
	     	      {
	     	      	while ((l<=r)&&(q[l]<i-len)) l++;
	     	      	if (l<=r) g[i]=f[q[l]]+e[i];
	     	      	while ((l<=r)&&(f[i]>f[q[r]])) r--;
	     	      	r++;q[r]=i;
				   }
			for (i=1;i<=n;i++) f[i]=g[i];
		 }
	for (i=n-len+1;i<=n;i++) ans=max(ans,f[i]);
	if (ans==0) ans=-1;
	printf("%lld\n",ans);
	return 0;
}