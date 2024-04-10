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
long long MOD,n,ans,i;
void Main(){
	n=read();ans=1;MOD=998244353;
	for (i=1;i<=n/2;i++) ans=ans*i % MOD;
	if (n&1) puts("0");
	else printf("%lld\n",ans*ans % MOD);
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
 return 0;
}