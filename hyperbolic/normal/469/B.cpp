#include <stdio.h>
struct str{
	int x0;
	int y0;
}x[1010],y[1010];
int main()
{
	int a,b,c,d,e,f,i,j,k,count=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=1;i<=a;i++)
	{
		scanf("%d%d",&e,&f);
		x[i]={e,f};
	}
	for(i=1;i<=b;i++)
	{
		scanf("%d%d",&e,&f);
		y[i]={e,f};
	}
	for(i=c;i<=d;i++)
	{
		for(j=1;j<=a;j++)
		{
			for(k=1;k<=b;k++)
			{
				if((x[j].x0-y[k].y0-i)*(i+y[k].x0-x[j].y0)>=0)
				{
					count++;
					goto u;
				}
			}
		}
		u:;
	}
	printf("%d",count);
}