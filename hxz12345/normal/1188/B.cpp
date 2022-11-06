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
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
map<long long,int> e;
long long n,MOD,sum,z,K,i,x,y;
int main()
{
	n=read();MOD=read();K=read();
	for (i=1;i<=n;i++)
	   {
	   	x=read();
	   	z=x*x % MOD;z=z*x % MOD;z=z*x % MOD;z=((z-K*x) % MOD+MOD) % MOD;
		e[z]++;sum+=e[z]-1;
		}   
	printf("%lld\n",sum);
	return 0;
}