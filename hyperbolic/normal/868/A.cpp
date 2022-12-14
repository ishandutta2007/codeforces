#include <stdio.h>
char x[10];
char y[110][10];
int main()
{
	int a;
	scanf("%s",x+1);
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y[i]+1);
		if(y[i][1]==x[1]&&y[i][2]==x[2])
		{
			printf("YES");
			return 0;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(y[i][2]==x[1]&&y[j][1]==x[2])
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
}