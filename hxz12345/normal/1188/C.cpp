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
long long a[10010],answer[1000000];
long long e[1010][1010],f[1010][1010];
long long lft,chs,tem,MOD,n,K,i,j,X,sum,ans1,ans2;
int main()
{
	n=read();K=read();MOD=998244353;
	for (i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (chs=0;chs<=100000;chs++)
	   if ((chs*(K-1)<=a[n]))
	        {
	        	X=chs;
	        	lft=0;ans1=0;
	        	for (i=1;i<=n;i++)
	        	    {
	        	    	f[i][1]=1;e[i][1]=i;
	        	    	for (j=2;j<=K;j++)
	        	    	    {
	        	    	    	e[i][j]=e[i-1][j];
	        	    	    	while ((lft+1<i)&&(a[i]-a[lft+1]>=X)) lft++;
	        	    	    	f[i][j]=e[lft][j-1];
	        	    	    	e[i][j]=(e[i][j]+f[i][j]) % MOD;
	        	    	    	/*for (k=1;k<i;k++)
	        	    	    	   if (a[i]-a[k]>=X)
	        	    	    	       f[i][j]=f[i][j]+f[k][j-1];*/
							}
						ans1=(ans1+f[i][K]) % MOD;
					}
				answer[chs]=ans1;
			}
	for (chs=0;chs<=100000;chs++)
	   if ((chs*(K-1)<=a[n]))
	       sum=(sum+chs*(answer[chs]-answer[chs+1]+MOD) % MOD) % MOD;
	printf("%lld\n",sum);
    return 0;
}