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
long long j,n,K,tot,a[1001010],G,i;
void Main(){
n=read();K=read();tot=0;
for (i=1;i<=n;i++) a[i]=read();
for (i=30;i>=0;i--){G=0;
	for (j=1;j<=n;j++)
	    if ((a[j]&(1<<i))==0) G++;
    if (K>=G){
    	K-=G;
    	tot+=(1<<i);
	}
}
printf("%lld\n",tot);
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}