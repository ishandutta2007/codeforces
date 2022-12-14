#include <stdio.h>

char x[110][3];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a-2;i++) scanf("%s",x[i]+1);
		
		int control = 0;
		printf("%c%c",x[1][1],x[1][2]);
		for(int i=2;i<=a-2;i++)
		{
			if(x[i-1][2]!=x[i][1])
			{
				control = 1;
				printf("%c",x[i][1]);
			}
			printf("%c",x[i][2]);
		}
		if(control==0) printf("a");
		printf("\n");
	}
}