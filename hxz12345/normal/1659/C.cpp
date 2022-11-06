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
long long n,A,B,a[1001010],b[1001010],c[1001010],ans,G,i;
void Main(){
n=read();A=read();B=read();ans=1e18;
for (i=1;i<=n;i++) a[i]=read(),b[i]=c[i]=a[i]-a[i-1];
for (i=1;i<=n;i++) b[i]*=(A+B);
for (i=2;i<=n;i++) b[i]+=b[i-1];
long long G=0;
for (i=n;i>=1;i--) G+=c[i]*(n-i+1)*B,ans=min(ans,G+b[i-1]);
printf("%lld\n",ans);
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}