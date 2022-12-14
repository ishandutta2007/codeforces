#include <stdio.h>
#include <algorithm>

int x[100010],y[100010];
int x1[100010],y1[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	if(x[1]!=y[1])
	{
		printf("No");
		return 0;
	}
	if(x[a]!=y[a])
	{
		printf("No");
		return 0;
	}
	for(int i=1;i<a;i++) x1[i] = x[i+1]-x[i];
	for(int i=1;i<a;i++) y1[i] = y[i+1]-y[i];
	std::sort(x1+1,x1+a);
	std::sort(y1+1,y1+a);
	for(int i=1;i<a;i++)
	{
		if(x1[i]!=y1[i])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}