#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=2005;

int d[MAXN][MAXN];
LL dis[MAXN];
bool vis[MAXN];

int main()
{
	int n,_min=INT_MAX;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			scanf("%d",&d[i][j]);
			d[j][i]=d[i][j];
			_min=min(_min,d[i][j]);
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j)
				d[i][j]-=_min;
	for (int i=1;i<=n;i++)
	{
		int _min=INT_MAX;
		for (int j=1;j<=n;j++)
			if (i!=j)
				_min=min(_min,d[i][j]);
		dis[i]=_min*2;
	}
	dis[0]=LLONG_MAX;
	for (int k=1;k<n;k++)
	{
		int v=0;
		for (int i=1;i<=n;i++)
			if (!vis[i]&&dis[v]>dis[i])
				v=i;
		vis[v]=true;
		for (int i=1;i<=n;i++)
			dis[i]=min(dis[i],dis[v]+d[v][i]);
	}
	LL dt=(LL)_min*(n-1);
	for (int i=1;i<=n;i++)
		printf("%lld\n",dis[i]+dt);
	return 0;
}