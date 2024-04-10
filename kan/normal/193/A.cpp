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

const int maxn=55;

char a[maxn][maxn];
int was[maxn][maxn];
int n,m;

void go(int x,int y)
{
	if (was[x][y]==1) return;
	if (a[x][y]!='#') return;
	was[x][y]=1;
	go(x-1,y);
	go(x+1,y);
	go(x,y-1);
	go(x,y+1);
}

inline bool check(int x,int y)
{
	a[x][y]='.';
	int kv=0;
	memset(was,0,sizeof(was));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) if (a[i][j]=='#' && (was[i][j]==0))
		{
			kv++;
			go(i,j);
		}
	}
	a[x][y]='#';
	return kv>1;
}

int main()
{
	cin >> n >> m;
	int kv=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			if (a[i][j]=='#') kv++;
		}
	}
	if (kv<=2)
	{
		cout << -1 << endl;
		return 0;
	}
	int ans=2;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) if (a[i][j]=='#')
		{
			if (check(i,j)) ans=1;
		}
	}
	cout << ans << endl;
	return 0;
}