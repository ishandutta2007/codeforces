#include<cstdio>

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int i,j,n,m;
		scanf("%d%d",&n,&m);
		m+=2*n;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(m)
		{
			printf("%d %d\n",j,(j+i-1)%n+1);
			m--;
		}
	}
}