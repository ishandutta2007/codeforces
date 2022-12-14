#include <stdio.h>

char x[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		//2
		for(int i=1;i+1<=a;i++)
		{
			if(x[i]=='a'&&x[i+1]=='a')
			{
				printf("2\n");
				goto u;
			}
		}
		
		//3
		for(int i=1;i+2<=a;i++)
		{
			if(x[i]=='a'&&x[i+2]=='a')
			{
				printf("3\n");
				goto u;
			}
		}
		
		//4
		for(int i=1;i+3<=a;i++)
		{
			if(x[i]=='a'&&x[i+3]=='a')
			{
				if(x[i+1]!=x[i+2])
				{
					printf("4\n");
					goto u;
				}
			}
		}
		
		//7
		for(int i=1;i+6<=a;i++)
		{
			if(x[i]=='a'&&x[i+3]=='a'&&x[i+6]=='a')
			{
				if(x[i+1]!=x[i+4])
				{
					printf("7\n");
					goto u;
				}
			}
		}
		printf("-1\n");
		u:;
	}
}