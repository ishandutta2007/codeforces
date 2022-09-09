#include<cstdio>

using namespace std;

int a[10000],cnt[10000];
const long long MOD=998244353;
long long add(long long x,long long y){return x+y>=MOD?x+y-MOD:x+y;}
long long sub(long long x,long long y){return x>=y?x-y:x+MOD-y;}
long long fast_pow(long long b,long long p)
{
	long long ans=1;
	while(p)
	{
		if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;
	}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}
long long fac[10000],invf[10000];

void init_fac(int n)
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
	invf[n]=INV(fac[n]);for(int i=n-1;i>=0;i--)invf[i]=invf[i+1]*(i+1)%MOD;
}
long long C(int n,int m)
{
	if(m==0)return 1;
	if(n<0||m<0||n<m)return 0;return fac[n]*invf[m]%MOD*invf[n-m]%MOD;
}

long long dp[10000],f[10000];

int main()
{
	init_fac(5000);
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
		dp[0]=1;int sum=0;
		for(int i=n;i>=1;i--)
		{
			if(cnt[i]==0)continue;
			for(int j=0;j<=n/2;j++){f[j]=dp[j];dp[j]=0;}
			for(int k=0;k<=n/2;k++)
			for(int j=0;j<=1&&k+j<=n/2;j++)
			{
				if(k<n/2)
				dp[k+j]=add(dp[k+j],f[k]*C(k-1-(sum-k),cnt[i]-j)%MOD);
				else
				dp[k+j]=add(dp[k+j],f[k]*C(k-(sum-k),cnt[i]-j)%MOD);
			}
			//for(int j=0;j<=n/2;j++)printf("%lld ",dp[j]);puts("");
			sum+=cnt[i];
		}
		printf("%lld\n",dp[n/2]);
		
		for(int i=1;i<=n;i++)f[i]=dp[i]=cnt[i]=a[i]=0;
	}
}