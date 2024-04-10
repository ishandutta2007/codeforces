#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=1005,MOD=1000000007;

int dp[MAXN][MAXN];

int get_inv(int x)
{
	if (x==1) return 1;
	return (LL)(MOD-MOD/x)*get_inv(MOD%x)%MOD;
}

int main()
{
	int k,pa,pb;
	scanf("%d%d%d",&k,&pa,&pb);
	int p1=(LL)pa*get_inv(pa+pb)%MOD,p2=(LL)pb*get_inv(pa+pb)%MOD;
	for (int j=1;j<=k;j++)
		dp[k][j]=(k+get_inv(p2)-1LL+MOD)%MOD;
	for (int i=k-1;i>=1;i--)
	{
		for (int j=1;j<=k;j++)
		{
			dp[i][j]=(LL)p1*dp[i+1][j]%MOD;
			if (i<=j)
				dp[i][j]=(dp[i][j]+(LL)p2*(dp[i][j-i]+i))%MOD;
			else
				dp[i][j]=(dp[i][j]+(LL)p2*i)%MOD;
		}
	}
	printf("%d",dp[1][k]);
	return 0;
}