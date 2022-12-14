#include <stdio.h>

char x[110][110];
int doQuery0()
{
	printf("next 0 1 2 3 4 5 6 7 8 9\n");
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	return a;
}

int doQuery1()
{
	printf("next 1 2 3 4 5 6 7 8 9\n");
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	return a;
}

int doQuery2()
{
	printf("next 2 3 4 5 6 7 8 9\n");
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	return a;
}

int main()
{
	int a;
	for(int i=1;;i++)
	{
		int b = doQuery1();
		int c = doQuery2();
		if(c==2)
		{
			a = c;
			break;
		}
	}
	
	for(int i=1;;i++)
	{
		int b = doQuery0();
		if(b==1)
		{
			printf("done");
			fflush(stdout);
			return 0;
		}
	}
}