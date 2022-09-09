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

const int maxn=1505;

int was[maxn][maxn];
pair<int,int> sm[maxn][maxn];
char p[maxn][maxn];
int n,m,sx,sy;

bool go(int x,int y,int sx,int sy);

bool move(int x,int y,int sx,int sy)
{
	if (x<0)
	{
		sx--;
		x=n-1;
	}
	if (x>=n)
	{
		sx++;
		x=0;
	}
	if (y<0)
	{
		sy--;
		y=m-1;
	}
	if (y>=m)
	{
		sy++;
		y=0;
	}
	return go(x,y,sx,sy);
}

bool go(int x,int y,int sx,int sy)
{
	if (p[x][y]=='#') return false;
	if (was[x][y]==1)
	{
		if (sm[x][y].first!=sx || sm[x][y].second!=sy) return true;
		return false;
	}
	was[x][y]=1;
	sm[x][y]=make_pair(sx,sy);
	bool res=false;
	res=res || move(x-1,y,sx,sy);
	res=res || move(x+1,y,sx,sy);
	res=res || move(x,y-1,sx,sy);
	res=res || move(x,y+1,sx,sy);
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	char c;
	scanf("%c",&c);
	for (int i=0;i<n;i++)
	{
		while (c!='#' && c!='.' && c!='S') scanf("%c",&c);
		for (int j=0;j<m;j++)
		{
			p[i][j]=c;
			if (p[i][j]=='S') sx=i,sy=j;
			scanf("%c",&c);
		}
	}
	memset(was,0,sizeof(was));
	if (go(sx,sy,0,0))
	{
		cout << "YES\n";
	} else
	{
		cout << "NO\n";
	}
	return 0;
}