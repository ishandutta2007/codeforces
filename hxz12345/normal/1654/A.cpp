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
long long n,a[1001010],mx,lft,rit,i;
void Main(){ 
n=read();a[n+1]=0;
for (i=1;i<=n;i++) a[i]=read();
mx=0;
for (i=1;i<n;i++) mx=max(mx,a[i]+a[i+1]);
for (lft=1;lft<n;lft++)
   for (rit=lft+1;rit<=n;rit++)
       mx=max(mx,a[rit]+a[lft-1]),mx=max(mx,a[lft]+a[rit+1]);
printf("%lld\n",mx);
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
    return 0;
}