#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
const ll mod=998244353;
ll Ksm(ll a,ll b)
{
	if(!b)
		return 1ll;
	if(b%2)
		return Ksm(a*a%mod,b/2)*a%mod;
	return Ksm(a*a%mod,b/2);
}
ll dp[550][550];
ll fact[550];
ll KSM[550][550];
ll c[550][550];
ll CC(int n,int k)
{
	return fact[n]*Ksm(fact[k],mod-2)%mod*Ksm(fact[n-k],mod-2)%mod;
}
ll ksm(ll a,ll b)
{
	return KSM[a][b];
}
ll C(int n,int k)
{
	return c[n][k];
}
int main()
{
	fact[0]=1;
	for(int i=1;i<550;i++)
		fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<550;i++)
		for(int j=0;j<550;j++)
		{
			KSM[i][j]=Ksm(i,j);
			if(i>=j)
				c[i][j]=CC(i,j);
		}
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=0;i<=x;i++)
		dp[0][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=x;j++)
		{
			if(j<i)
			{
				dp[i][j]=ksm(j,i);
//				printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
				continue;
			}
			for(int k=0;k<=i;k++)
				dp[i][j]=(dp[i][j]+dp[k][j-i+1]*ksm(i-1,i-k)%mod*C(i,k)%mod)%mod;
//			printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
		}
	printf("%lld\n",dp[n][x]);
	return 0;
}