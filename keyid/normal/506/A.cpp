#include <bits/stdc++.h>
using namespace std;

const int MAXN=30005;

int g[MAXN],f[MAXN][500];

int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	for (int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		g[p]++;
	}
	memset(f,-1,sizeof(f));
	f[d][250]=0;
	int ans=0;
	for (int i=d;i<=30000;i++)
		for (int k=-245;k<=245;k++)
			if (f[i][k+250]!=-1)
			{
				f[i][k+250]+=g[i];
				ans=max(ans,f[i][k+250]);
				int l=d+k;
				for (int j=-1;j<=1;j++)
				{
					int x=l+j;
					if (x>0&&i+x<=30000)
						f[i+x][x-d+250]=max(f[i+x][x-d+250],f[i][k+250]);
				}
			}
	printf("%d",ans);
	return 0;
}