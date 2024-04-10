#include<cstdio>

using namespace std;

const long long MOD=1e9+7;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}


int n;
int a[20];long long p[20][20];
long long dp[1<<14];

long long calc(int s,int t)
{
	long long ans=1;
	for(int i=0;i<n;i++)
	{
		if(s&(1<<i))
		{
			for(int j=0;j<n;j++)if(t&(1<<j))ans=ans*p[i][j]%MOD;
		}
	}
	return ans;
}
int cntbit[1<<14];

int main()
{
	scanf("%d",&n);for(int i=0;i<n;i++)scanf("%d",&a[i]);int U=(1<<n)-1;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j)p[i][j]=a[i]*INV(a[i]+a[j])%MOD;
	long long ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		long long x=calc(i,U^i);dp[i]=x;//printf("%lld\n",x);
		for(int j=i;j;j=(j-1)&i)
		{
			if(j==i)continue;
			dp[i]=sub(dp[i],dp[j]*calc(i^j,U^i)%MOD);
		}
		cntbit[i]=cntbit[i>>1]+(i&1);ans=add(ans,cntbit[i]*dp[i]%MOD);
	}
	printf("%lld",ans);
}