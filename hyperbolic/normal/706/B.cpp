#include <stdio.h>
#include <algorithm>
int a;
int x[100010];
int func(int k)
{
	int min = 1,max = a, ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(x[h]>k) max = h-1;
		else
		{
			ans = h;
			min = h+1;
		}
	}
	return ans;
}
int main()
{
	int b,c;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&c);
		printf("%d\n",func(c));
	}
}