#include <bits/stdc++.h>
using namespace std;

int n,i,j;
int a[1005][1005];
int g[1005],f[1005],p[1005],c,cnt;

void solve(int lx,int ly,int sx,int sy)
{
	int i,j;
	for (i=0;i<lx;i++)
	{
		for (j=0;j<ly;j++)
		{
			a[sx+i][sy+j]=cnt++;
		}
	}
}

int main()
{
	scanf("%d",&n);
		
	for (i=1;i<=n/4;i++)
	{
		for (j=1;j<=n/4;j++)
		{
			solve(4,4,(i-1)*4,(j-1)*4);
		}
	}
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	
	return 0;
}