#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		x[0] = -1;
		
		if(b==1)
		{
			for(int i=1;i<=a;i++)
			{
				if(x[i]!=x[1])
				{
					printf("-1\n");
					goto u;
				}
			}
			printf("1\n");
		}
		else
		{
			int count = 0;
			for(int i=1;i<=a;i++) if(x[i]!=x[i-1]) count++;
			
			if(count<=b) printf("1\n");
			else
			{
				printf("%d\n",(count-b-1)/(b-1)+2);
			}
		}
		
		u:;
	}
}