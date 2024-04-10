#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
//id:1 2 3 4
//   1 2 2 3
//1 2 4;1 3 4;
long long x,y,V1[1001010],V2[1001010],now,tot,Testing,a[1001010],b[1001010],c[1001010],suf[1001010],suff[1001010],n,i,R,sum1,sum2,sum3,sum;
int main()
{
	/* +- 
	// =+- 
	//
	*/
	for (Testing=read();Testing;Testing--)
	    {  
	    n=read();
	    for (i=1;i<=n;i++) V1[i]=V2[i]=0;
		for (i=1;i<=n;i++) x=read(),y=read(),V1[x]++,V2[y]++,a[i]=x,b[i]=y;
		tot=n*(n-1)*(n-2)/6;now=0;
		for (i=1;i<=n;i++) now+=(V1[a[i]]-1)*(V2[b[i]]-1);
		printf("%lld\n",tot-now);
		} 
	return 0;
}