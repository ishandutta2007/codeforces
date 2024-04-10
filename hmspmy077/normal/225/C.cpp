#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int f[1005][1005],x[1005][1005],y[1005][1005];

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
		freopen("c.out","w",stdout);
	#endif
	int n,m,l,r;
	scanf("%d%d%d%d ",&n,&m,&l,&r);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			char c;
			scanf("%c ",&c);
			x[i][j]=x[i-1][j]+x[i][j-1]-x[i-1][j-1]+(c=='#');
			y[i][j]=y[i-1][j]+y[i][j-1]-y[i-1][j-1]+(c=='.');
		}
	}
	for (int i=1;i<=m;i++)
	{
		f[i][0]=f[i][1]=n*m+1;
		for (int j=0;j<i;j++) if (i-j>=l && i-j<=r)
		{
			f[i][1]=min(f[i][1],f[j][0]+x[n][i]-x[n][j]);
			f[i][0]=min(f[i][0],f[j][1]+y[n][i]-y[n][j]);
		}
	}
	cout<<min(f[m][0],f[m][1])<<endl;
	return 0;
}