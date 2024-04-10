#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=65;
const int inf=1e9;

int timed[maxn][maxn][maxn];
int d[maxn][maxn][maxn];
int dt[maxn];
int was[maxn];
int n,m,r;

int main()
{
	scanf("%d%d%d",&n,&m,&r);
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int t=0;t<n;t++)
			{
				scanf("%d",&timed[j][t][i]);
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++) d[i][j][0]=inf;
	}
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int t=0;t<n;t++) dt[t]=inf;
			memset(was,0,sizeof(was));
			dt[j]=0;
			int cur=j;
			while (cur!=-1)
			{
				was[cur]=1;
				for (int t=0;t<n;t++)
				{
					dt[t]=min(dt[t],dt[cur]+timed[cur][t][i]);
				}
				cur=-1;
				int mindt=inf;
				for (int t=0;t<n;t++) if (was[t]==0 && dt[t]<mindt)
				{
					mindt=dt[t];
					cur=t;
				}
			}
			for (int t=0;t<n;t++) d[j][t][0]=min(d[j][t][0],dt[t]);
		}
	}
// 	for (int i=0;i<n;i++)
// 	{
// 		for (int j=0;j<n;j++) cout << d[i][j][0] << ' ';
// 		cout << endl;
// 	}
	for (int k=1;k<=n;k++)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				d[i][j][k]=d[i][j][k-1];
				for (int t=0;t<n;t++) d[i][j][k]=min(d[i][j][k],d[i][t][0]+d[t][j][k-1]);
			}
		}
	}
// 	for (int i=0;i<n;i++)
// 	{
// 		for (int j=0;j<n;j++) cout << d[i][j][1] << ' ';
// 		cout << endl;
// 	}
// 	for (int i=0;i<n;i++)
// 	{
// 		for (int j=0;j<n;j++) cout << d[i][j][2] << ' ';
// 		cout << endl;
// 	}
	for (int t=0;t<r;t++)
	{
		int i,j,k;
		scanf("%d%d%d",&i,&j,&k);
		i--,j--;
		k=min(k,n);
// 		cerr << i << ' ' << j << ' ' << k << ' ' << d[i][j][1] << endl;
		printf("%d\n",d[i][j][k]);
	}
	return 0;
}