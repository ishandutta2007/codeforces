#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				int count1 = 0, count2 = 0;
				for(int k=i;k<=j;k++)
				{
					if(x[k]=='a') count1++;
					else count2++;
				}
				if(count1==count2)
				{
					printf("%d %d\n",i,j);
					goto u;
				}
			}
		}
		printf("-1 -1\n");
		u:;
	}
}