#include <stdio.h>
struct str{
	int x0;
	int y0;
}y[2510];
char x[60][60],z[110][110];
int main()
{
	int a,i,j,k,count=1;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%s",x[i]+1);
	}
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=a;j++)
		{
			if(x[i][j]=='o')
			{
				y[count++]={i,j};
			}
		}
	}
	count--;
	
	for(i=-(a-1);i<=(a-1);i++)
	{
		for(j=-(a-1);j<=(a-1);j++)
		{
			for(k=1;k<=count;k++)
			{
				if(1<=i+y[k].x0&&i+y[k].x0<=a)
				{
					if(1<=j+y[k].y0&&j+y[k].y0<=a)
					{
						if(x[i+y[k].x0][j+y[k].y0]=='.')
						{
							break;
						}
					}
				}
			}
			if(k>count)
			{
				z[a+i][a+j]='x';
			}
		}
	}
	
	for(i=-(a-1);i<=(a-1);i++)
	{
		for(j=-(a-1);j<=(a-1);j++)
		{
			if(z[a+i][a+j]=='x')
			{
				for(k=1;k<=count;k++)
				{
					if(1<=i+y[k].x0&&i+y[k].x0<=a)
					{
						if(1<=j+y[k].y0&&j+y[k].y0<=a)
						{
							x[i+y[k].x0][j+y[k].y0]='.';
						}
					}
				}
			}
		}
	}
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=a;j++)
		{
			if(x[i][j]!='.')
			{
				printf("NO");
				return 0;
			}
		}
	}
	z[a][a]='o';
	printf("YES\n");
	for(i=1;i<=2*a-1;i++)
	{
		for(j=1;j<=2*a-1;j++)
		{
			if(z[i][j]==0) printf(".");
			else printf("%c",z[i][j]);
		}
		printf("\n");
	}
}