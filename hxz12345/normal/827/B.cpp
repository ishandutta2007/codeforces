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
int u,n,K,x,y,now,final,i,j;
int main()
{
	n=read();K=read();x=(n-1)/K;u=(n-1) % K;
	if (u==1) printf("%d\n",2*x+1);
	else if (u==0) printf("%d\n",2*x);
	else printf("%d\n",2*x+2);
	now=1;
	for (i=1;i<=K;i++)
	     {
	     	printf("1 %d\n",now+1);
	     	if (i<=u) final=(n-1)/K+1;else final=(n-1)/K;
	        for (j=1;j<final;j++) now++,printf("%d %d\n",now,now+1);
	        now++;
		 }
    return 0;
}