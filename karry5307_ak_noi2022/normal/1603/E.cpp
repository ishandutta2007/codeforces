#include<cstdio>
#include<cstring>

using namespace std;

int n,fr,dif;long long MOD;

int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}

long long fac[300000],invf[300000];
void init_fac(int n)
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
	invf[n]=INV(fac[n]);for(int i=n-1;i>=0;i--)invf[i]=invf[i+1]*(i+1)%MOD;
}

long long dp[400][400][50];

long long calc(int cnt,int sum,int cur)
{
	if(dp[cnt][sum][cur]!=-1)return dp[cnt][sum][cur];
	long long &ans=dp[cnt][sum][cur];ans=0;
	if(cur<=dif-1&&cnt<cur)return ans;
	if(cur==dif){if(cnt<n)ans=invf[n-cnt];return ans;}
	int x=n+1-cur-fr;
	for(int j=0;cnt+j<=n&&sum+j*x<=fr;j++)
	{
		ans=add(ans,calc(cnt+j,sum+j*x,cur+1)*invf[j]%MOD);
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&MOD);init_fac(n);
	long long ans=0;
	for(dif=0;dif<=32;dif++)
	{
		memset(dp,-1,sizeof(dp));
		fr=n+1-dif;ans=add(ans,calc(0,0,0));
	}
	printf("%lld",ans*fac[n]%MOD);
}