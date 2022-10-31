// Hydro submission #6353cece7bbe1bb6d493ad1a@1666436815001
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
typedef long long ll;
const int M=2005,N=4005;
int n,t[M],v;
ll c[M],dp[N],ans=2e12;//ans 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%lld",&t[i],&c[i]);
		t[i]++;//t"" 
		v=max(v,t[i]);
	}
	v+=n;// 
	memset(dp,0x7f,sizeof(dp));dp[0]=0;//dp 
	for(int i=1;i<=n;i++)
		for(int j=v;j>=t[i];j--)
			dp[j]=min(dp[j],dp[j-t[i]]+c[i]);//01 
	for(int i=n;i<=v;i++)
		ans=min(ans,dp[i]);// 
	printf("%lld",ans);
    return 0;
}