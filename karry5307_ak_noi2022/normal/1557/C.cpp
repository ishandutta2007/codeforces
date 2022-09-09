#include<cstdio>

using namespace std;

const int MOD=1e9+7;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}

int pw2[400000];
void init_2(int x)
{
	pw2[0]=1;for(int i=1;i<=x;i++)pw2[i]=add(pw2[i-1],pw2[i-1]);
}
long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}

int main()
{
	init_2(200000);
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0,k=0;scanf("%d%d",&n,&k);
		if(n&1)
		{
			long long x=add(pw2[n-1],1);printf("%lld\n",fast_pow(x,k));continue;
		}
		long long ans=0,pre=1;
		for(int i=k-1;i>=0;i--)
		{
			ans=add(ans,pre*fast_pow(2,(long long)i*n)%MOD);
			pre=pre*(pw2[n-1]-1)%MOD;
		}
		ans=add(ans,pre);printf("%lld\n",ans);
	}
}