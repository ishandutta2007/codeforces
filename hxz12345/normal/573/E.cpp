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
long long ans,n,i,a[1001010],j;
long long f[1001010];
int main()
{
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++){
		f[i]=f[i-1]+i*a[i];
		for (j=i-1;j>=1;j--)
		     f[j]=max(f[j],f[j-1]+j*a[i]);
	}
	for (i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%lld\n",ans);
return 0;
}
//dp[i][j] ij