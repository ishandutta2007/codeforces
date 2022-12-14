#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	int min = 2000000001;
	int count = 0;
	
	for(int i=1;i<a;i++)
	{
		int t = x[i+1]-x[i];
		if(min>t)
		{
			min = t;
			count = 1;
		}
		else if(min==t) count++;
	}
	printf("%d %d",min,count);
}