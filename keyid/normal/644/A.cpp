#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if (a*b<n)
	{
		printf("-1");
		return 0;
	}
	int c0,c1;
	if (n&1)
	{
		c0=n;
		c1=n-1;
	}
	else
	{
		c0=n-1;
		c1=n;
	}
	for (int i=0;i<a;i++)
	{
		for (int j=0;j<b;j++)
			if (i+j&1)
			{
				printf("%d ",max(0,c1));
				c1-=2;
			}
			else
			{
				printf("%d ",max(0,c0));
				c0-=2;
			}
		puts("");
	}
	return 0;
}