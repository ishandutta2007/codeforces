#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=505;

int n;
bool ok[60][2][MAXN][MAXN],ans[MAXN][MAXN],tmp[MAXN][MAXN];
bitset <MAXN> b[2][2][MAXN];

void bit_mark(bool ok[MAXN][MAXN],int d)
{
	for (int i=0;i<2;i++)
		for (int j=1;j<=n;j++)
			b[i][d][j].reset();
	for (int j=1;j<=n;j++)
		for (int k=1;k<=n;k++)
			if (ok[j][k])
			{
				b[0][d][j].set(k);
				b[1][d][k].set(j);
			}
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int u,v,t;
		scanf("%d%d%d",&u,&v,&t);
		ok[0][t][u][v]=true;
	}
	for (int t=1;t<=59;t++)
	{
		for (int v=0;v<2;v++)
			bit_mark(ok[t-1][v],v);
		for (int v=0;v<2;v++)
				for (int i=1;i<=n;i++)
					for (int j=1;j<=n;j++)
							ok[t][v][i][j]=(b[0][v][i]&b[1][v^1][j]).any();
	}
	int now=0;
	LL rans=0;
	for (int i=1;i<=n;i++)
		ans[i][i]=true;
	for (int l=59;l>=0;l--)
	{
		bit_mark(ans,0);
		bit_mark(ok[l][now],1);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				tmp[i][j]=(b[0][0][i]&b[1][1][j]).any();
		bool flag=false;
		for (int i=1;i<=n&&!flag;i++)
			for (int j=1;j<=n&&!flag;j++)
				if (tmp[i][j])
					flag=true;
		if (flag)
		{
			rans|=1LL<<l;
			now^=1;
			memcpy(ans,tmp,sizeof(ans));
		}
	}
	if (rans>1000000000000000000LL) printf("-1");
	else printf("%lld",rans);
	return 0;
}