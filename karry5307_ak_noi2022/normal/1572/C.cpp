#include<cstdio>
#include<algorithm>
using namespace std;

int TT,n,m;
int a[5000],b[5000];
int lst[5000],nxt[5000];
int dp[5000][5000];

int main()
{
	scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			dp[i][i]=0; lst[i]=n;
		}
		m=0;b[m++]=a[0]-1;
		for(int i=1;i<n;i++)
		{	
			if(a[i]!=a[i-1])b[m++]=a[i]-1;
		}
		for(int i=m-1;i>=0;i--)
		{
			nxt[i]=lst[b[i]];
			lst[b[i]]=i;
		}
		for(int i=1;i<m;i++)
		{
			for(int l=0;l+i<m;l++)
			{
				int r=l+i,pos=nxt[l];
				dp[l][r]=dp[l+1][r];
				while(pos<=r)
				{
					dp[l][r]=max(dp[l][r],dp[l+1][pos-1]+dp[pos][r]+1);
					pos=nxt[pos];
				}
			}
		}
		printf("%d\n",m-1-dp[0][m-1]);
	}
	return 0;
}