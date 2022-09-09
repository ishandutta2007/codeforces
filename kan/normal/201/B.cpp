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

const ll linf=1000000000000000000LL;
const int maxn=1005;

int c[maxn][maxn];
ll sx[maxn],sy[maxn];
int n,m;

inline ll d(ll x,ll y)
{
	return abs((4*x)-(2+4*(y-1)))*abs((4*x)-(2+4*(y-1)));
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) scanf("%d",&c[i][j]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) sx[i]+=c[i][j],sy[j]+=c[i][j];
	}
	ll mindx=linf;
	int minx,miny;
	for (int i=0;i<=n;i++)
	{
		ll curd=0;
		for (int j=1;j<=n;j++) curd+=sx[j]*d(i,j);
		if (curd<mindx)
		{
			mindx=curd;
			minx=i;
		}
	}
// 	cerr << mindx << endl;
	ll mindy=linf;
	for (int i=0;i<=m;i++)
	{
		ll curd=0;
		for (int j=1;j<=m;j++) curd+=sy[j]*d(i,j);
		if (curd<mindy)
		{
			mindy=curd;
			miny=i;
		}
	}
// 	cerr << mindy << endl;
	cout << mindx+mindy << endl;
	cout << minx <<' ' << miny << endl;
	return 0;
}