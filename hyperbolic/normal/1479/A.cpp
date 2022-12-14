#include <stdio.h>
int getQuery(int k)
{
	printf("? %d\n",k);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int main()
{
	int a;
	scanf("%d",&a);
	int min = 1, max = a;
	while(max-min>=1)
	{
		int h = (min+max)/2;
		int t1 = getQuery(h);
		int t2 = getQuery(h+1);
		if(t1<t2) max = h;
		else min = h+1;
	}
	printf("! %d",(min+max)/2);
	fflush(stdout);
}