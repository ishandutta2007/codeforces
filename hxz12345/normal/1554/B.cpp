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
long long n,K,a[1001010],i,j,G;
void Main(){
	n=read();K=read();
	for (i=1;i<=n;i++) a[i]=read();
	long long G=-1e18;
    for (i=1;i<=n;i++){
    	for (j=i-500;j<i;j++)
    	   if (j>0)
    	    G=max(G,i*j-K*(a[i]|a[j]));
	}
	printf("%lld\n",G);
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}