#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=5005,MAXK=2505,INF=0x3f3f3f3f;

int a[MAXN],dp[2][MAXK][4],mn[MAXK];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int m=(n+1)/2;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	int now=1,last=0;
	for (int i=1;i<=n+1;i++)
	{
		memset(dp[now],0x3f,sizeof(dp[now]));
		int t[3]={a[i-1],min(a[i-1],i>1?a[i-2]-1:INF),min(a[i-1],a[i]-1)};
		int t2[3]={a[i],min(a[i-1]-1,a[i]),min(a[i+1]-1,a[i])};
		for (int j=0;j<=m;j++)
		{
			int tmp=min(min(dp[last][j][0],dp[last][j][1]),min(dp[last][j][2],dp[last][j][3]));
			dp[now][j][0]=tmp;
			dp[now][j][1]=tmp+max(0,a[i]-(a[i-1]-1));
			dp[now][j][2]=tmp+max(0,a[i]-(a[i+1]-1));
			for (int k=0;k<3;k++)
				if (t[k]<a[i])
					dp[now][j][3]=min(dp[now][j][3],dp[last][j][k]);
		}
		if (i>1)
			for (int k=0;k<=2;k++)
				if (t2[k]<a[i-1])
					for (int l=1;l<=m;l++)
					{
						dp[now][l][k]=min(dp[now][l][k],dp[last][l-1][3]+a[i]-t2[k]);
					}
		swap(now,last);
	}
	for (int i=1;i<=m;i++)
	{
		int ans=INF;
		for (int j=0;j<4;j++)
			ans=min(ans,dp[last][i][j]);
		printf("%d ",ans);
	}
	return 0;
}