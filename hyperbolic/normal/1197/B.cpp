#include <stdio.h>

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int max = x[1];
	int ind = 1;
	
	for(int i=2;i<=a;i++)
	{
		if(max<x[i])
		{
			max = x[i];
			ind = i;
		}
	}
	for(int i=1;i<ind;i++)
	{
		if(x[i+1]<x[i])
		{
			printf("NO");
			return 0;
		}
	}
	for(int i=ind+1;i<=a;i++)
	{
		if(x[i]<x[i+1])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}