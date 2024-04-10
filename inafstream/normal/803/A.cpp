#include <bits\stdc++.h>
using namespace std;

int n,m,i,j,a[105][105];
string s;

int main()
{
	scanf("%d%d", &n, &m);
	
	if (n * n < m)
	{
		puts("-1");
		return 0;
	}
	
	for (i=1;i<=n;i++)
	{
		if (m>0)
		{
			a[i][i]=1;
			m--;
		}
		for (j=i+1;j<=n;j++)
		{
			if (m>=2)
			{
				 a[i][j]=a[j][i]=1;
				 m-=2;
			}
		}
	}
	
	if (m)
	{
		puts("-1");
		return 0;
	}
	
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			printf("%d%c",a[i][j],j==n?'\n':' ');
		}
	}
	
	return 0;
}