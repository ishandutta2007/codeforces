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
long long n,a[1001010],G1,G2,G3,i,j,now,ans;
int main()
{
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	ans=1e18;
	for (i=1;i<=n;i++){
		G1=0;G2=0;G3=0;
		for (j=i-1;j>=1;j--) now=(G1/a[j]+1),G1=a[j]*now,G3+=now;
		for (j=i+1;j<=n;j++) now=(G2/a[j]+1),G2=a[j]*now,G3+=now;
		ans=min(ans,G3);
	}
	printf("%lld\n",ans);
return 0;
}