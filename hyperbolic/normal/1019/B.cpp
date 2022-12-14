#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	if((a/2)%2==1)
	{
		printf("! -1");
		fflush(stdout);
		return 0;
	}
	
	printf("? %d\n",1);
	fflush(stdout);
	int b;
	scanf("%d",&b);
	
	printf("? %d\n",1+(a/2));
	fflush(stdout);
	int c;
	scanf("%d",&c);
	
	if(b==c)
	{
		printf("! 1");
		fflush(stdout);
		return 0;
	}
	else if(b<c)
	{
		int min = 2;
		int max = (a/2);
		while(min<=max)
		{
			int h = (min+max)/2;
			printf("? %d\n",h);
			fflush(stdout);
			int b1;
			scanf("%d",&b1);
			
			printf("? %d\n",h+(a/2));
			fflush(stdout);
			int c1;
			scanf("%d",&c1);
			
			if(b1==c1)
			{
				printf("! %d",h);
				fflush(stdout);
				return 0;
			}
			else if(b1<c1) min = h+1;
			else max = h-1;
		}
		printf("! -1");
		fflush(stdout);
	}
	else
	{
		int min = 2;
		int max = (a/2);
		while(min<=max)
		{
			int h = (min+max)/2;
			printf("? %d\n",h);
			fflush(stdout);
			int b1;
			scanf("%d",&b1);
			
			printf("? %d\n",h+(a/2));
			fflush(stdout);
			int c1;
			scanf("%d",&c1);
			
			if(b1==c1)
			{
				printf("! %d",h);
				fflush(stdout);
				return 0;
			}
			else if(b1<c1) max = h-1;
			else min = h+1;
		}
		printf("! -1");
		fflush(stdout);
	}
}