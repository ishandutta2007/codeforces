#include <bits/stdc++.h>
using namespace std;

const int MAXN=105,INF=0x3f3f3f3f;

int f[MAXN][3];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		f[i][0]=min(min(f[i-1][0],f[i-1][1]),f[i-1][2])+1;
		if (a&1) f[i][1]=min(f[i-1][0],f[i-1][2]);
		else f[i][1]=INF;
		if (a>>1&1) f[i][2]=min(f[i-1][0],f[i-1][1]);
		else f[i][2]=INF;
	}
	printf("%d",min(min(f[n][0],f[n][1]),f[n][2]));
	return 0;
}