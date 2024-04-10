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

int a[1005][1005];
int f[1005],g[1005],ff[1005],gg[1005];

int main()
{
	#ifdef LOCAL_TEST
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d ",&a[i][j]);
	for (int i=1;i<=max(n,m);i++)
	{
		f[i]=i;
		g[i]=i;
	}
	while (q--)
	{
		char c;
		int x,y;
		scanf("%c%d%d ",&c,&x,&y);
		if (c=='c')
		{
			swap(f[x],f[y]);
		}
		else if (c=='r')
		{
			swap(g[x],g[y]);
		}
		else printf("%d\n",a[g[x]][f[y]]);
	}
	return 0;
}