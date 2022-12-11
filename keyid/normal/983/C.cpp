#include <bits/stdc++.h>
using namespace std;

const int MAXN=2005,MAXS=1953125;

int dp[MAXN][225][9],id[MAXS],BASE[10];
vector <int> sta;

void update(int &a,int b)
{
	if (a>b)
		a=b;
}

int main()
{
	int n;
	scanf("%d",&n);
	memset(dp,0x3f,sizeof(dp));
	for (int i=0;i<9;i++)
		dp[0][0][i]=i;
	for (int i=0;i<MAXS;i++)
	{
		int t=i,c=0;
		while (t)
		{
			c+=t%5;
			t/=5;
		}
		if (c<4)
		{
			sta.push_back(i);
			id[i]=sta.size();
		}
	}
	BASE[0]=1;
	for (int i=1;i<10;i++)
		BASE[i]=BASE[i-1]*5;
	for (int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		for (int j:sta)
		{
			int t=j+BASE[b];
			for (int k=a;k<9;k++)
			{
				t=t/BASE[k+1]*BASE[k+1]+t%BASE[k];
				if (id[t])
					update(dp[i][id[t]-1][k],dp[i-1][id[j]-1][a]+k-a);
			}
			t=j+BASE[b];
			for (int k=a;k>=0;k--)
			{
				t=t/BASE[k+1]*BASE[k+1]+t%BASE[k];
				if (id[t])
					update(dp[i][id[t]-1][k],dp[i-1][id[j]-1][a]+a-k);
			}
		}
		for (int j=1;j<9;j++)
			for (int k:sta)
				update(dp[i][id[k/BASE[j+1]*BASE[j+1]+k%BASE[j]]-1][j],dp[i][id[k]-1][j-1]+1);
		for (int j=7;j>=0;j--)
			for (int k:sta)
				update(dp[i][id[k/BASE[j+1]*BASE[j+1]+k%BASE[j]]-1][j],dp[i][id[k]-1][j+1]+1);
	}
	int ans=INT_MAX;
	for (int i=0;i<9;i++)
		ans=min(ans,dp[n][0][i]);
	printf("%d",ans+2*n);
	return 0;
}