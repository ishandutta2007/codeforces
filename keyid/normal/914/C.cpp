#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

const int MAXN=1005,MOD=1000000007;

char s[MAXN];
int dp[MAXN],C[MAXN][MAXN];

int main()
{
	int k;
	scanf("%s%d",s,&k);
	if (k==0)
	{
		printf("1");
		return 0;
	}
	int l=strlen(s),ans=0;
	dp[0]=-10;
	for (int i=2;i<MAXN;i++)
	{
		int k=__builtin_popcount(i);
		dp[i]=dp[k]+1;
	}
	for (int i=0;i<MAXN;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	int cnt=0;
	for (int i=0;i<l;i++)
		if (s[i]=='1')
		{
			for (int j=0;j+cnt<MAXN&&j<=l-i-1;j++)
				if (dp[j+cnt]+1==k)
				{
					ans=(ans+C[l-i-1][j])%MOD;
				}
			cnt++;
		}
	if (dp[cnt]+1==k)
		ans=(ans+1)%MOD;
	if (k==1)
		ans=(ans+MOD-1)%MOD;
	printf("%d",ans);
	return 0;
}