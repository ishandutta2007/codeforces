#include<cstdio>

int a[1000][1000];

int main()
{
	int i,j,n,m,r=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)r^=a[i][i];
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&j);
		if(j==3)printf("%d",r);
		else
		{
			r=1-r;
			scanf("%*d");
		}
	}
}