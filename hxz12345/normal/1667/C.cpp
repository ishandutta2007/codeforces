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
long long n,tot,i;
int main()
{
	n=read();
	tot=n-(n+1)/3;
	printf("%lld\n",tot);
	for (i=1;i<=(tot+1)/2;i++) printf("%lld %lld\n",i,2*i-1);
	for (i=1;i<=tot/2;i++) printf("%lld %lld\n",i+(tot+1)/2,i*2);
return 0;
}