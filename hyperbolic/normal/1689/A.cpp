#include <stdio.h>
#include <algorithm>
char x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s%s",x+1,y+1);
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+b+1);
		
		int p1 = 1, p2 = 1;
		int type = 0, count = 0;
		while(p1<=a&&p2<=b)
		{
			if(x[p1]<y[p2])
			{
				if(type==2)
				{
					printf("%c",x[p1++]);
					type = 1, count = 1;
				}
				else if(count==c)
				{
					printf("%c",y[p2++]);
					type = 2, count = 1;
				}
				else
				{
					printf("%c",x[p1++]);
					type = 1, count++;
				}
			}
			else
			{
				if(type==1)
				{
					printf("%c",y[p2++]);
					type = 2, count = 1;
				}
				else if(count==c)
				{
					printf("%c",x[p1++]);
					type = 1, count = 1;
				}
				else
				{
					printf("%c",y[p2++]);
					type = 2, count++;
				}
			}
		}
		printf("\n");
	}
}