#include <stdio.h>
#define MAX 1000000000

int x[50];
int main()
{
	int a,b;
	int query;
	scanf("%d%d",&a,&b);
	
	printf("1\n");
	fflush(stdout);
	scanf("%d",&query);
	if(query==0) return 0;
	x[1] = query;
	for(int i=2;i<=b;i++)
	{
		printf("1\n");
		fflush(stdout);
		scanf("%d",&query);
		x[i] = query;
	}
	
	int min = 1, max = a;
	int count = 1;
	while(min<=max)
	{
		int h = (min+max)/2;
		printf("%d\n",h);
		fflush(stdout);
		scanf("%d",&query);
		if(query==0) return 0;
		if((query*x[(count-1)%b+1])==1) min = h+1;
		else max = h-1;
		count++;
	}
}