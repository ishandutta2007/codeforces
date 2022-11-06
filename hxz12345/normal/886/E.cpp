// Problem: E. Maximum Element
// Contest: Codeforces -  2018 -   3
// URL: https://codeforces.com/contest/886/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read()
{
  int x=0,f=1;char ch=getchar();
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
long long f[1000100],MOD,n,m,ans,x,sum,i;
int main()
{
	n=read();m=read();MOD=1000000007;
	f[0]=1;ans=n;
	for (i=1;i<=n;i++)
	    {
	    	x=pow(i,MOD-2,MOD);sum=(sum+f[i-1]) % MOD;
	    	if (i>m) sum=(sum-f[i-m-1]+MOD) % MOD;
	    	f[i]=sum*x % MOD;
	    	ans=(ans-f[i-1]+MOD) % MOD;
		}
   for (i=1;i<n;i++) ans=ans*i % MOD;
   printf("%lld\n",ans);
   return 0;
}