#include <stdio.h>

int x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int dist = 0;
	for(int i=a;i>=1;i--)
	{
		if(x[i]!=x[1])
		{
			dist = dist>(i-1)?dist:(i-1);
			break;
		}
	}
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=x[a])
		{
			dist = dist>(a-i)?dist:(a-i);
			break;
		}
	}
	printf("%d",dist);
}