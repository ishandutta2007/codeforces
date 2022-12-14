#include <stdio.h>
struct str{
	int type;
	int x0;
	int y0;
	int z0;
}query[10010];
int x[110][110];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++)
	{
		scanf("%d",&query[i].type);
		if(query[i].type==1) scanf("%d",&query[i].x0);
		else if(query[i].type==2) scanf("%d",&query[i].x0);
		else if(query[i].type==3) scanf("%d%d%d",&query[i].x0,&query[i].y0,&query[i].z0);
	}
	for(int i=c;i>=1;i--)
	{
		if(query[i].type==1)
		{
			int d = query[i].x0;
			int e = x[d][b];
			for(int j=b;j>1;j--) x[d][j] = x[d][j-1];
			x[d][1] = e;
		}
		else if(query[i].type==2)
		{
			int d = query[i].x0;
			int e = x[a][d];
			for(int j=a;j>1;j--) x[j][d] = x[j-1][d];
			x[1][d] = e;
		}
		else if(query[i].type==3)
		{
			x[query[i].x0][query[i].y0] = query[i].z0;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
}