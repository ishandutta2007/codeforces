#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

typedef long long LL;
typedef pair <int,int> pii;

const int MAXM=1000007,INF=0x7f7f7f7f;

int cnt[MAXM],dp[7][7],tmp[7][7];

void update(int &a,int b)
{
	if (b>a)
		a=b;
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	for (int i=0;i<7;i++)
		for (int j=0;j<7;j++)
			dp[i][j]=-INF;
	dp[0][0]=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<7;j++)
			for (int k=0;k<7;k++)
				tmp[j][k]=-INF;
		for (int j=0;j<7;j++)
			for (int k=0;k<7;k++)
				for (int l=0;l<=j&&l<=k&&l<=cnt[i];l++)
					update(tmp[k-l][cnt[i]-l-3*max(0,(cnt[i]-l-4)/3)],dp[j][k]+(j-l)/3+l+max(0,(cnt[i]-l-4)/3));
		memcpy(dp,tmp,sizeof(dp));
	}
	int ans=0;
	for (int i=0;i<7;i++)
		for (int j=0;j<7;j++)
			ans=max(ans,dp[i][j]+i/3+j/3);
	printf("%d",ans);
	return 0;
}