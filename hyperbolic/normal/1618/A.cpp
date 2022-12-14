#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=7;i++) scanf("%d",&x[i]);
		
		if(x[1]+x[2]==x[3] && x[1]+x[4] == x[5] && x[2]+x[4] == x[6] && x[1]+x[2]+x[4]==x[7])
		{
			printf("%d %d %d\n",x[1],x[2],x[4]);
			goto u;
		}
		
		if(x[1]+x[2]==x[4] && x[1]+x[3] == x[5] && x[2]+x[3] == x[6] && x[1]+x[2]+x[3]==x[7])
		{
			printf("%d %d %d\n",x[1],x[2],x[3]);
			goto u;
		}
		u:;
	}
}