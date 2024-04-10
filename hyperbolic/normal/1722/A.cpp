#include <stdio.h>
#include <algorithm>
#include <string.h>

char x[110],y[110];
int main()
{
	x[1] = 'T', x[2] = 'i', x[3] = 'm', x[4] = 'u', x[5] = 'r';
	std::sort(x+1,x+6);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",y+1);
		if(a!=5) printf("NO\n");
		else
		{
			std::sort(y+1,y+a+1);
			for(int i=1;i<=a;i++)
			{
				if(x[i]!=y[i])
				{
					printf("NO\n");
					goto u;
				}
			}
			printf("YES\n");
			u:;
		}
	}
}