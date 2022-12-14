#include <stdio.h>
int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int dist = x[2]-x[1];
	for(int i=2;i<a;i++)
	{
		if(x[i+1]-x[i]!=dist)
		{
			printf("%d",x[a]);
			return 0;
		}
	}
	printf("%d",x[a]+dist);
}