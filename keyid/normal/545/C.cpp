#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXN=100005,INF=0x3f3f3f3f;

struct tree
{
	int x,h;
}a[MAXN];

int f[MAXN][3];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].h);
		for (int j=0;j<3;j++) f[i][j]=-INF;
	}
	a[0].x=INT_MIN;
	a[n+1].x=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0],max(f[i-1][1],f[i-1][2]));
		if (a[i].x-a[i].h>a[i-1].x) f[i][1]=max(f[i][1],max(f[i-1][0],f[i-1][1])+1);
		if (a[i].x-a[i].h>a[i-1].x+a[i-1].h) f[i][1]=max(f[i][1],f[i-1][2]+1);
		if (a[i].x+a[i].h<a[i+1].x) f[i][2]=f[i][0]+1;
	}
	printf("%d",max(f[n][0],max(f[n][1],f[n][2])));
	return 0;
}