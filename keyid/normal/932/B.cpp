#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

const int MAXN=1000005;

int cnt[10][MAXN],g[MAXN];

void preprocess(int n)
{
	for (int i=1;i<=n;i++)
		if (i<10)
			g[i]=i;
		else
		{
			int d=1,t=i;
			while (t)
			{
				int x=t%10;
				if (x)
					d*=x;
				t/=10;
			}
			g[i]=g[d];
		}
	for (int i=1;i<=n;i++)
		cnt[g[i]][i]++;
	for (int i=1;i<=9;i++)
		for (int j=1;j<=n;j++)
			cnt[i][j]+=cnt[i][j-1];
}

int main()
{
	preprocess(1000000);
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",cnt[k][r]-cnt[k][l-1]);
	}
	return 0;
}